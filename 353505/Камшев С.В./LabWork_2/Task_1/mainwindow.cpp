#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QMenu* FileMenu = new QMenu(FilePushButton);
    QAction *openAction = new QAction("Открыть",FilePushButton);
    QAction* saveAction = new QAction("Сохранить",FilePushButton);
    QAction* closeAction = new QAction("Закрыть",FilePushButton);


    FileMenu->addAction(openAction);
    FileMenu->addAction(saveAction);
    FileMenu->addAction(closeAction);


    FilePushButton->setParent(this);
    FilePushButton->setText("Файл");
    FilePushButton->setMenu(FileMenu);
    FilePushButton->setGeometry(0,0,150,30);

    addNewDatePushButton->setParent(this);
    addNewDatePushButton->setText("Добавить дату");
    addNewDatePushButton->setGeometry(0,40,220,30);

    nextRow->setParent(this);
    nextRow->setGeometry(240, 0, 30 ,30);
    nextRow->setText(QString::fromUtf8("\u2191"));

    lastRow->setParent(this);
    lastRow->setGeometry(240, 40, 30 ,30);
    lastRow->setText(QString::fromUtf8("\u2193"));

    newDate->setParent(this);
    newDate->setGeometry(0,80,220,30);
    newDate->setInputMask(("00.00.0000;_"));

    changeSelecteRowPushButton->setParent(this);
    changeSelecteRowPushButton->setGeometry(0, 120,220,30);
    changeSelecteRowPushButton->setText("Изменть выбранное");

    changeDate->setParent(this);
    changeDate->setGeometry(0,160,220,30);
    changeDate->setInputMask(("00.00.0000;_"));

    calculateCoontDaydToBithdayPushButton->setParent(this);
    calculateCoontDaydToBithdayPushButton->setGeometry(0, 200,220,30);
    calculateCoontDaydToBithdayPushButton->setText("рассчитать количество дней");
    bithdayDate->setParent(this);
    bithdayDate->setGeometry(0,240,220,30);
    bithdayDate->setInputMask(("00.00.0000;_"));


    table->setParent(this);
    table->setGeometry(300, 0, 2100,1500);
    table->setColumnCount(8);
    table->setEditTriggers(QAbstractItemView::EditTriggers(0));
    for (int i = 0; i < 8; ++ i){
        table->setColumnWidth(i, 250);
    }



    QPushButton::connect(openAction, SIGNAL(triggered()), this, SLOT(on_openFilePushButton_clicked()));
    QPushButton::connect(saveAction, SIGNAL(triggered()), this, SLOT(on_saveFilePushButton_clicked()));
    QPushButton::connect(closeAction, SIGNAL(triggered()), this, SLOT(on_closeFilePushButton_clicked()));

    QPushButton::connect(addNewDatePushButton, SIGNAL(pressed()), this, SLOT(on_addNewDatePushButton_clicked()));
    QPushButton::connect(nextRow, SIGNAL(pressed()), this, SLOT(on_nextRow_clicked()));
    QPushButton::connect(lastRow, SIGNAL(pressed()), this, SLOT(on_lastRow_clicked()));
    QPushButton::connect(changeSelecteRowPushButton, SIGNAL(pressed()), this, SLOT(on_changeSelecteRowPushButton_clicked()));
    QPushButton::connect(calculateCoontDaydToBithdayPushButton, SIGNAL(pressed()), this, SLOT(on_calculateCoontDaydToBithdayPushButton_clicked()));

    update_timer = new QTimer(this);
    connect(update_timer, &QTimer::timeout,[=]()
            {
                SaveFileWindow->setGeometry(this->width()/2, this->height()/2, 500,500);

                table->setHorizontalHeaderLabels(colomnNames);
                if (Date::stringToDate(newDate->text()) != Date(-1,-1,-1)){
                    QPalette pal;
                    pal.setColor(QPalette::Base, Qt::white);
                    newDate->setPalette(pal);
                }
                if (Date::stringToDate(changeDate->text()) != Date(-1,-1,-1)){
                    QPalette pal;
                    pal.setColor(QPalette::Base, Qt::white);
                    changeDate->setPalette(pal);
                }

                if (Date::stringToDate(bithdayDate->text()) != Date(-1,-1,-1)){
                    QPalette pal;
                    pal.setColor(QPalette::Base, Qt::white);
                    bithdayDate->setPalette(pal);
                }

                if (fileWosOpen){
                    addNewDatePushButton->setEnabled(true);
                    addNewDatePushButton->setPalette(QPalette(Qt::white));
                    newDate->setEnabled(true);
                    nextRow->setEnabled(true);
                    nextRow->setPalette(QPalette(Qt::white));
                    lastRow->setEnabled(true);
                    lastRow->setPalette(QPalette(Qt::white));
                    changeSelecteRowPushButton->setEnabled(true);
                    changeSelecteRowPushButton->setPalette(QPalette(Qt::white));
                    changeDate->setEnabled(true);
                    calculateCoontDaydToBithdayPushButton->setEnabled(true);
                    calculateCoontDaydToBithdayPushButton->setPalette(QPalette(Qt::white));
                    bithdayDate->setEnabled(true);


                }
                else{
                    addNewDatePushButton->setEnabled(false);
                    addNewDatePushButton->setPalette(QPalette(Qt::gray));
                    newDate->setEnabled(false);
                    QPalette pal;
                    pal.setColor(QPalette::Base, Qt::gray);
                    newDate->setPalette(pal);
                    nextRow->setEnabled(false);
                    nextRow->setPalette(QPalette(Qt::gray));
                    lastRow->setEnabled(false);
                    lastRow->setPalette(QPalette(Qt::gray));
                    changeSelecteRowPushButton->setEnabled(false);
                    changeSelecteRowPushButton->setPalette(QPalette(Qt::gray));
                    changeDate->setPalette(pal);
                    changeDate->setEnabled(false);
                    calculateCoontDaydToBithdayPushButton->setEnabled(false);
                    calculateCoontDaydToBithdayPushButton->setPalette(QPalette(Qt::gray));
                    bithdayDate->setPalette(pal);
                    bithdayDate->setEnabled(false);
                }

                if (dateArr.size() > 0){
                    for (int i = 0; i < table->rowCount(); ++i){
                        for (int j = 0; j < table->columnCount(); ++j){
                            if (i == rowNumber){
                                table->item(i,j)->setBackground(Qt::green);
                            }
                            else {
                                table->item(i,j)->setBackground(Qt::white);
                            }
                        }
                    }
                }




            });
    update_timer->start(30);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showInformation()
{
    table->setRowCount(dateArr.size());
    for (int i = 0; i < table->rowCount(); ++i){
        setValues(i);
    }


}

void MainWindow::readInformation()
{

    while (!file.atEnd()){
        QString informationLine = file.readLine();
        informationLine.remove(informationLine.size()- 1, 2);
        if (Date::stringToDate(informationLine) != Date(-1,-1,-1)){
            dateArr.append(Date::stringToDate(informationLine));
            oldDateArr.append(Date::stringToDate(informationLine));
        }

    }
    showInformation();
}

void MainWindow::AddNewdate()
{
    if (Date::stringToDate(newDate->text()) != Date(-1,-1,-1)){
        table->insertRow(table->rowCount());
        file.setFileName(fileName);
        file.open(QIODevice::Append);
        if (file.isOpen()){


            dateArr.append(Date::stringToDate(newDate->text()));
            rowNumber = dateArr.size() - 1;
            setValues(rowNumber);
            setValues(rowNumber - 1);
            QTextStream out(&file);
            out << newDate->text() << '\n';
            saveWosPressed = false;
        }
    }
    else{
        QPalette pal;
        pal.setColor(QPalette::Base, Qt::red);
        newDate->setPalette(pal);
    }
}

void MainWindow::setValues(int index)
{
    QTableWidgetItem* Item = new QTableWidgetItem(dateArr[index].ToString());
    table->setItem(index,0, Item);

    Item = new QTableWidgetItem(dateArr[index].NextDay().ToString());
    table->setItem(index,1, Item);

    Item = new QTableWidgetItem(dateArr[index].PreviousDay().ToString());
    table->setItem(index,2, Item);

    Item = new QTableWidgetItem(dateArr[index].IsLeap()? "Да": "Нет");
    table->setItem(index,3, Item);

    Item = new QTableWidgetItem(QString::number(dateArr[index].WeekNumber()));
    table->setItem(index,4, Item);

    if (index != dateArr.size() - 1) Item = new QTableWidgetItem(QString::number(dateArr[index].dayToDate(dateArr[index+1])));
    else Item = new QTableWidgetItem("");
    table->setItem(index,5, Item);

    if (bithdayIsWrite) Item = new QTableWidgetItem(dateArr[index].DaysTillYourBithday(Date::stringToDate(bithdayDate->text()))==0 ? "С днем рождения": QString::number(dateArr[index].DaysTillYourBithday(Date::stringToDate(bithdayDate->text()))));
    else Item = new QTableWidgetItem("");
    table->setItem(index,6, Item);


    Item = new QTableWidgetItem(QString::number(Date::Duration(dateArr[index])));
    table->setItem(index,7, Item);
}

void MainWindow::closeEvent(QCloseEvent *event)
{

    if (!saveWosPressed){
        event->ignore();


        SaveFileWindow->show();
        SaveFileWindow->exec();

        if (SaveFileWindow->clickedButton() == yes || SaveFileWindow->clickedButton() == no){
            if (SaveFileWindow->clickedButton() == yes)
            if (SaveFileWindow->clickedButton() == no){
                file.open(QIODevice::WriteOnly);
                file.resize(0);
                QTextStream out(&file);
                for (int i = 0; i < oldDateArr.size(); ++i){
                    out << oldDateArr[i].ToString() << '\n';

                }

            }
            event->accept();

        }
    }
    else{
        QMainWindow::closeEvent(event);
        event->accept();
    }

}

void MainWindow::seveQuestion()
{
    if (!saveWosPressed){
        SaveFileWindow->show();

        SaveFileWindow->exec();
        if (SaveFileWindow->clickedButton() == yes || SaveFileWindow->clickedButton() == no){
            if(SaveFileWindow->clickedButton() == yes){};
            if (SaveFileWindow->clickedButton() == no){
                file.open(QIODevice::WriteOnly);
                file.resize(0);
                QTextStream out(&file);
                for (int i = 0; i < oldDateArr.size(); ++i){
                    out << oldDateArr[i].ToString() << '\n';

                }

            }
            table->clear();
            table->setRowCount(0);
            rowNumber = 0;
            oldDateArr.clear();
            dateArr.clear();
            saveWosPressed = true;
            bithdayIsWrite = false;
            fileWosOpen = false;
        }
    }

    else{
        table->clear();
        table->setRowCount(0);
        rowNumber = 0;
        oldDateArr.clear();
        dateArr.clear();
        saveWosPressed = true;
        bithdayIsWrite = false;
        fileWosOpen = false;
    }

}

void MainWindow::openFile()
{
    file.setFileName(fileName);
    file.open(QIODevice::ReadOnly);
    if (file.isOpen()){
        readInformation();
        fileWosOpen = true;
        file.close();

        QPalette pal;
        pal.setColor(QPalette::Base, Qt::white);
        newDate->setPalette(pal);
        changeDate->setPalette(pal);
        bithdayDate->setPalette(pal);
    }
}



void MainWindow::on_openFilePushButton_clicked()
{
    if (!fileWosOpen){
        fileName = QFileDialog::getOpenFileName(this, "Выберите файл", "/home/stepan/Labs OAIP/2/Task_1", "*.txt");
        openFile();
    }
}

void MainWindow::on_saveFilePushButton_clicked()
{
    oldDateArr = dateArr;
    saveWosPressed = true;
}

void MainWindow::on_closeFilePushButton_clicked()
{
    if (fileWosOpen){
        seveQuestion();
    }
}



void MainWindow::on_addNewDatePushButton_clicked()
{
    AddNewdate();
}

void MainWindow::on_nextRow_clicked()
{
    if (rowNumber > 0){
        rowNumber--;
    }
}

void MainWindow::on_lastRow_clicked()
{

    if (rowNumber < dateArr.size() - 1){
        rowNumber++;
    }
}

void MainWindow::on_changeSelecteRowPushButton_clicked()
{
    if (Date::stringToDate(changeDate->text()) != Date(-1,-1,-1)){
        file.setFileName(fileName);

        file.open(QIODevice::ReadWrite);
        if (file.isOpen()){

            for (int i = 0; i < rowNumber; ++i){
                QString informationLine = file.readLine();
            }

            QTextStream out(&file);
            out << changeDate->text() << '\n';

            dateArr[rowNumber] = Date::stringToDate(changeDate->text());
            setValues(rowNumber);
            if (rowNumber != 0) setValues(rowNumber - 1);
            saveWosPressed = false;

            file.close();
        }

    }
    else{
        QPalette pal;
        pal.setColor(QPalette::Base, Qt::red);
        changeDate->setPalette(pal);
    }

}

void MainWindow::on_calculateCoontDaydToBithdayPushButton_clicked()
{
    if (Date::stringToDate(bithdayDate->text()) != Date(-1,-1,-1)){
        bithdayIsWrite = true;
        for (int i = 0; i < table->rowCount(); ++i) setValues(i);
    }
    else{
        QPalette pal;
        pal.setColor(QPalette::Base, Qt::red);
        bithdayDate->setPalette(pal);
    }

}
