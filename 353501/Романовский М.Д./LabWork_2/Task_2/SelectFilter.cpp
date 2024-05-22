#include "SelectFilter.h"
#include "Car.h"
#include "Database.h"
#include <qboxlayout.h>
#include <qcheckbox.h>
#include <qitemselectionmodel.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qlistwidget.h>
#include <qnamespace.h>
#include <qspinbox.h>

SelectFilter::SelectFilter(const Car::Property *_prop, Database *_db)
    : prop(_prop), db(_db) {
  selector = new QListWidget();
  selector->setSelectionMode(QListWidget::NoSelection);

  connect(selector, &QListWidget::itemChanged, this,
          &SelectFilter::selectionChanged);

  selectAll = new QCheckBox("Select all");
  connect(selectAll, &QCheckBox::clicked, this, &SelectFilter::onSelectAll);

  connect(db, &Database::updated, this, &SelectFilter::syncItems);

  syncItems();
}

void SelectFilter::setupUI(QBoxLayout *layout) {
  QHBoxLayout *top = new QHBoxLayout();

  top->addWidget(new QLabel(QString("<b>%0</b>").arg(prop->displayName)));
  top->addWidget(selectAll);

  layout->addLayout(top);
  layout->addWidget(selector);
}

bool SelectFilter::matches(QSharedPointer<Car> c) {
  QString val = c->property(prop->name).toString();
  return !unselected.contains(val);
}

void SelectFilter::selectionChanged(QListWidgetItem *item) {
  if (item->checkState() == Qt::Unchecked) {
    unselected.insert(item->text());
    selectedCount--;
  } else {
    unselected.remove(item->text());
    selectedCount++;
  }

  updateSelectAll();
  emit changed();
}

void SelectFilter::updateItems(QSet<QString> newItems) {
  selector->clear();
  selectedCount = 0;

  for (auto entry : newItems) {
    QListWidgetItem *item = new QListWidgetItem(entry);
    item->setFlags(item->flags() & ~Qt::ItemIsSelectable |
                   Qt::ItemIsUserCheckable); // set checkable flag

    bool unselect = unselected.contains(entry);
    if (!unselect)
      selectedCount++;

    item->setCheckState(unselect ? Qt::Unchecked : Qt::Checked);
    selector->addItem(item);
  }

  updateSelectAll();
}

void SelectFilter::syncItems() {
  QSet<QString> options = db->getUniqOptions(prop->name);
  updateItems(options);
}

void SelectFilter::updateSelectAll() {
  if (selectedCount == 0)
    selectAll->setCheckState(Qt::Unchecked);
  else if (unselected.empty())
    selectAll->setCheckState(Qt::Checked);
  else
    selectAll->setCheckState(Qt::PartiallyChecked);
}

void SelectFilter::onSelectAll() {
  Qt::CheckState nextState = Qt::Checked;
  if (unselected.empty())
    nextState = Qt::Unchecked;

  for (int i = 0; i < selector->count(); i++) {
    selector->item(i)->setCheckState(nextState);
  }

  updateSelectAll();
}