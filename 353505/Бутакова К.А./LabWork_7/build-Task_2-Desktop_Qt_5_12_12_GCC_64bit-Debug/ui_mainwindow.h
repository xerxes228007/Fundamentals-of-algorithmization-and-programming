/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTreeView *treeView;
    QLineEdit *lineEdit;
    QSpinBox *spinBox;
    QPushButton *pushButton_add;
    QPushButton *pushButton_del;
    QPushButton *pushButton_find;
    QPushButton *pushButton_InOrder;
    QPushButton *pushButton_PreOrder;
    QPushButton *pushButton_PostOrder;
    QTextEdit *textEdit_ans;
    QPushButton *pushButton_eachLevel;
    QPushButton *pushButton_balanse;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(20, 20, 256, 192));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(410, 50, 321, 31));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(410, 90, 42, 25));
        spinBox->setMinimum(-999999999);
        spinBox->setMaximum(999999999);
        pushButton_add = new QPushButton(centralwidget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setGeometry(QRect(410, 140, 321, 31));
        pushButton_del = new QPushButton(centralwidget);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));
        pushButton_del->setGeometry(QRect(410, 180, 321, 31));
        pushButton_find = new QPushButton(centralwidget);
        pushButton_find->setObjectName(QString::fromUtf8("pushButton_find"));
        pushButton_find->setGeometry(QRect(410, 220, 321, 31));
        pushButton_InOrder = new QPushButton(centralwidget);
        pushButton_InOrder->setObjectName(QString::fromUtf8("pushButton_InOrder"));
        pushButton_InOrder->setGeometry(QRect(410, 260, 321, 31));
        pushButton_PreOrder = new QPushButton(centralwidget);
        pushButton_PreOrder->setObjectName(QString::fromUtf8("pushButton_PreOrder"));
        pushButton_PreOrder->setGeometry(QRect(410, 300, 321, 31));
        pushButton_PostOrder = new QPushButton(centralwidget);
        pushButton_PostOrder->setObjectName(QString::fromUtf8("pushButton_PostOrder"));
        pushButton_PostOrder->setGeometry(QRect(410, 340, 321, 31));
        textEdit_ans = new QTextEdit(centralwidget);
        textEdit_ans->setObjectName(QString::fromUtf8("textEdit_ans"));
        textEdit_ans->setGeometry(QRect(50, 240, 191, 131));
        textEdit_ans->setReadOnly(false);
        pushButton_eachLevel = new QPushButton(centralwidget);
        pushButton_eachLevel->setObjectName(QString::fromUtf8("pushButton_eachLevel"));
        pushButton_eachLevel->setGeometry(QRect(410, 380, 321, 31));
        pushButton_balanse = new QPushButton(centralwidget);
        pushButton_balanse->setObjectName(QString::fromUtf8("pushButton_balanse"));
        pushButton_balanse->setGeometry(QRect(410, 420, 321, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_add->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216", nullptr));
        pushButton_del->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \321\201 \320\267\320\260\320\264\320\260\320\275\320\275\321\213\320\274 \320\272\320\273\321\216\321\207\320\276\320\274", nullptr));
        pushButton_find->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \321\201 \320\267\320\260\320\264\320\260\320\275\320\275\321\213\320\274 \320\272\320\273\321\216\321\207\320\276\320\274", nullptr));
        pushButton_InOrder->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\320\265\321\207\320\260\321\202\320\260\321\202\321\214 \320\262 \320\277\320\276\321\200\321\217\320\264\320\272\320\265 \320\262\320\276\320\267\321\200\320\260\321\201\321\202\320\260\320\275\320\270\321\217 \320\272\320\273\321\216\321\207\320\260", nullptr));
        pushButton_PreOrder->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\320\265\321\207\320\260\321\202\320\260\321\202\321\214 \320\277\321\200\321\217\320\274\321\213\320\274 \320\276\320\261\321\205\320\276\320\264\320\276\320\274", nullptr));
        pushButton_PostOrder->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\320\265\321\207\320\260\321\202\320\260\321\202\321\214 \320\276\320\261\321\200\320\260\321\202\320\275\321\213\320\274 \320\276\320\261\321\205\320\276\320\264\320\276\320\274", nullptr));
        pushButton_eachLevel->setText(QApplication::translate("MainWindow", "\320\236\320\277\321\200\320\265\320\264\320\265\320\273\320\270\321\202\321\214 \321\207\320\270\321\201\320\273\320\276 \321\203\320\267\320\273\320\276\320\262", nullptr));
        pushButton_balanse->setText(QApplication::translate("MainWindow", "\320\241\320\261\320\260\320\273\320\260\320\275\321\201\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\262\320\265\321\202\320\272\321\203 \320\264\320\265\321\200\320\265\320\262\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
