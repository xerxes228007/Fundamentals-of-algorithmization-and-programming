#pragma once
#include "Car.h"
#include "Filter.h"
#include <QListWidget>
#include <QSet>
#include <QCheckBox>
#include <qnamespace.h>
#include <qtclasshelpermacros.h>

class Database;

class SelectFilter : public QObject, public Filter {
  Q_OBJECT

public:
  SelectFilter(const Car::Property *prop, Database *db);

  virtual void setupUI(QBoxLayout *);
  virtual bool matches(QSharedPointer<Car> c);

private:
  void updateItems(QSet<QString> newItems);
  void updateSelectAll();

private slots:
  void selectionChanged(QListWidgetItem *item);
  void syncItems();
  void onSelectAll();

signals:
  void changed();

private:
  const Car::Property *prop;
  Database *db;

  QListWidget *selector;
  QCheckBox *selectAll;

  QSet<QString> unselected;
  int selectedCount;
};