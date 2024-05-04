#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include <qtypes.h>

class Filter;
class Database;
class Car;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(Database *db);

private:
  void updateTable();
  void updateRow(qsizetype row, QSharedPointer<Car> car);

private slots:
  void onAddEntry();
  void onEditEntry();
  void onDeleteEntry();

  void onOpenFile();
  void onNewFile();

  void onSelectedRow();

protected:
  Ui::MainWindow *ui;
  Database *db;
  QList<QSharedPointer<Filter>> filters;

  int selectedRow;
};