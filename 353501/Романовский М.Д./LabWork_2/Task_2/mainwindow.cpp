#include "mainwindow.h"
#include "CarDialog.h"
#include "Database.h"
#include "RangeFilter.h"
#include "SelectFilter.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <cstring>
#include <qcombobox.h>
#include <qdialog.h>
#include <qlayoutitem.h>
#include <qmainwindow.h>
#include <qobjectdefs.h>
#include <qpushbutton.h>
#include <qtablewidget.h>
#include <qtypes.h>
#include <qvariant.h>

MainWindow::MainWindow(Database *_db) : ui(new Ui::MainWindow) {
  ui->setupUi(this);
  db = _db;

  ui->mainTable->setColumnCount(Car::PROPERTY_COUNT);

  QList<QString> labels;
  for (int i = 0; i < Car::PROPERTY_COUNT; i++) {
    if (strcmp(Car::PROPERTIES[i].name, "producer") != 0) {
      ui->sortSelector->addItem(Car::PROPERTIES[i].displayName + " <", i + 1);
      ui->sortSelector->addItem(Car::PROPERTIES[i].displayName + " >",
                                -(i + 1));
    }

    labels.push_back(Car::PROPERTIES[i].displayName);
  }

  ui->mainTable->setHorizontalHeaderLabels(labels);

  connect(db, &Database::updated, this, &MainWindow::updateTable);
  updateTable();

  connect(ui->mainTable, &QTableWidget::itemSelectionChanged, this,
          &MainWindow::onSelectedRow);
  onSelectedRow();

  connect(ui->sortSelector, &QComboBox::activated, this,
          &MainWindow::updateTable);

  connect(ui->addEntry, &QPushButton::clicked, this, &MainWindow::onAddEntry);
  connect(ui->deleteEntry, &QPushButton::clicked, this,
          &MainWindow::onDeleteEntry);
  connect(ui->editEntry, &QPushButton::clicked, this, &MainWindow::onEditEntry);

  connect(ui->openFile, &QPushButton::clicked, this, &MainWindow::onOpenFile);
  connect(ui->newFile, &QPushButton::clicked, this, &MainWindow::onNewFile);

  for (int i = 0; i < Car::PROPERTY_COUNT; i++) {
    if (i != 0) {
      QFrame *line = new QFrame();
      line->setFrameShape(QFrame::HLine);
      line->setFrameShadow(QFrame::Sunken);

      ui->filters->addSpacing(10);
      ui->filters->addWidget(line);
      ui->filters->addSpacing(10);
    }

    const Car::Property *prop = &Car::PROPERTIES[i];
    if (prop->step == -1) {
      SelectFilter *f = new SelectFilter(prop, db);
      f->setupUI(ui->filters);
      connect(f, &SelectFilter::changed, this, &MainWindow::updateTable);
      filters.push_back(QSharedPointer<Filter>(f));
    } else {
      RangeFilter *f = new RangeFilter(prop);
      f->setupUI(ui->filters);
      connect(f, &RangeFilter::changed, this, &MainWindow::updateTable);
      filters.push_back(QSharedPointer<Filter>(f));
    }
  }
}

void MainWindow::updateTable() {
  QList<QSharedPointer<Car>> filtered;

  for (qsizetype i = 0; i < db->count(); i++) {
    QSharedPointer<Car> c = db->getCar(i);
    bool matches = true;
    for (auto f : filters)
      matches &= f->matches(c);
    if (!matches)
      continue;

    filtered.push_back(c);
  }

  int sortSelect = ui->sortSelector->currentData().toInt();
  bool sortAscending = sortSelect < 0;
  const Car::Property *sortBy = &Car::PROPERTIES[abs(sortSelect) - 1];

  std::sort(filtered.begin(), filtered.end(),
            [=](QSharedPointer<Car> a, QSharedPointer<Car> b) {
              if (a->producer == b->producer) {
                QVariant valA = a->property(sortBy->name);
                QVariant valB = b->property(sortBy->name);
                bool res = false;
                if (sortBy->step < 0) {
                  res = valA.toString() < valB.toString();
                } else {
                  res = valA.toFloat() < valB.toFloat();
                }
                res ^= sortAscending;
                return res;
              }

              return a->producer < b->producer;
            });

  ui->mainTable->setRowCount(filtered.count());
  for (qsizetype i = 0; i < filtered.count(); i++) {
    updateRow(i, filtered[i]);
  }
}

void MainWindow::updateRow(qsizetype row, QSharedPointer<Car> car) {
  for (int i = 0; i < Car::PROPERTY_COUNT; i++) {
    QVariant val = car->property(Car::PROPERTIES[i].name);
    QString valS;

    if (val.typeId() == QMetaType::Float) {
      int precision = 0;
      if (Car::PROPERTIES[i].step < 1)
        precision = 1;

      valS = QString::number(val.toFloat(), 'f', precision);
    } else {
      valS = val.toString();
    }

    ui->mainTable->setItem(row, i, new QTableWidgetItem(valS));
  }
}

void MainWindow::onAddEntry() {
  QSharedPointer<Car> car(new Car);

  CarDialog *dialog = new CarDialog(car, this);
  if (dialog->exec() != QDialog::Accepted)
    return;

  db->addCar(car);
}

void MainWindow::onEditEntry() {
  QSharedPointer<Car> carCopy(db->getCar(selectedRow)->clone());
  CarDialog *dialog = new CarDialog(carCopy, this);
  if (dialog->exec() != QDialog::Accepted)
    return;
  db->setCar(selectedRow, carCopy);
}

void MainWindow::onDeleteEntry() { db->deleteCar(selectedRow); }

void MainWindow::onSelectedRow() {
  auto selected = ui->mainTable->selectedItems();
  if (selected.count() > 0) {
    selectedRow = selected[0]->row();
  } else {
    selectedRow = -1;
  }

  ui->editEntry->setDisabled(selectedRow == -1);
  ui->deleteEntry->setDisabled(selectedRow == -1);
}

void MainWindow::onNewFile() {
  QString fileName = QFileDialog::getSaveFileName(this, "New File", "",
                                                  tr("Cars DB (*.json)"));
  if (fileName.length() == 0)
    return;

  {
    QFile f(fileName);
    if (f.exists())
      f.remove();
  }

  db->openFile(fileName);
}

void MainWindow::onOpenFile() {
  QString fileName = QFileDialog::getOpenFileName(this, "Open File", "",
                                                  tr("Cars DB (*.json)"));
  if (fileName.length() == 0)
    return;

  db->openFile(fileName);
}