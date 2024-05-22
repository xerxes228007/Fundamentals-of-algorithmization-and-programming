#include "mainwindow.h"
#include "Database.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Database db;
    MainWindow w(&db);
    w.show();
    return a.exec();
}