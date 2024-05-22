#include "CarDialog.h"
#include "Car.h"
#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <qdialog.h>
#include <qformlayout.h>
#include <qicon.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qspinbox.h>

CarDialog::CarDialog(QSharedPointer<Car> car, QWidget *parent)
    : QDialog(parent) {

  QVBoxLayout *vbox = new QVBoxLayout();
  setLayout(vbox);

  QFormLayout *form = new QFormLayout();
  vbox->addLayout(form);

  for (int i = 0; i < Car::PROPERTY_COUNT; i++) {
    const Car::Property *prop = &Car::PROPERTIES[i];

    QWidget *input = nullptr;
    if (prop->step <= 0) {
      QLineEdit *inp = new QLineEdit();
      inp->setText(car->property(prop->name).toString());
      connect(inp, &QLineEdit::textChanged, [prop, car](const QString &val) {
        car->setProperty(prop->name, val);
      });

      input = inp;
    } else {
      QDoubleSpinBox *inp = new QDoubleSpinBox();

      inp->setMaximum(prop->max);
      inp->setMinimum(prop->min);
      inp->setSingleStep(prop->step);

      inp->setValue(car->property(prop->name).toDouble());

      connect(inp, &QDoubleSpinBox::valueChanged,
              [prop, car](double val) { car->setProperty(prop->name, val); });

      input = inp;
    }

    form->addRow(prop->displayName, input);
  }

  QDialogButtonBox *buttonBox = new QDialogButtonBox(
      QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);

  vbox->addWidget(buttonBox);

  connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
  connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}
