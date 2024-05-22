#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tabWidget->setTabText(2,"Другое");
    ui->saveFileButton->setDisabled(1);
    ui->saveFile2Button->setDisabled(1);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->sortByColumn(0, Qt::SortOrder::AscendingOrder);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->sortByColumn(0, Qt::SortOrder::AscendingOrder);
    ui->tableWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->pushButton_2->setDisabled(1);
    ui->salarySpinBox->setRange(1, 9999);
    ui->deleteItemButton->setDisabled(1);
    ui->editItemButton->setDisabled(1);
    ui->groupBox->setVisible(0);
    ui->groupBox_2->setVisible(0);

    ui->salaryVDoubleSpinBox->setRange(1, 9999);
    ui->groupBox_3->setVisible(0);
    ui->listWidget_2->setVisible(0);
    ui->editVocButton->setDisabled(1);
    ui->deleteVocButton->setDisabled(1);
    ui->showCandidatesButton->setDisabled(1);


    connect(ui->openFileButton, &QPushButton::clicked,this, [this](){

        ui->saveFileButton->setDisabled(0);
        openFileEmployer = new QFile (QFileDialog::getOpenFileName(this, "Выбор файла", "/home/yauheni", "text files (*.txt)"));
        openFileEmployer->open(QIODevice::ReadOnly| QIODevice::Text);
        openFileEmployer->seek(0);
        employerList.clear();
        QVector<QString> readedData;
        while (openFileEmployer->pos()<openFileEmployer->size()) {
            readedData.push_back(openFileEmployer->readLine().removeLast());
            qDebug()<<openFileEmployer->pos();
        }

        int a = readedData.size()/7;

        for(int i = 0; i<a; ++i){
            employerList.push_back(Employer(readedData[i*7], readedData[1 + i*7], readedData[2 + i*7], Widget::stringToDate(readedData[3 + i*7]), readedData[4 + i*7] == "true", readedData[5 + i*7], readedData[6 + i*7].toDouble()));
        }

        ui->saveFileButton->setDisabled(0);
        showEmployerTable();
        openFileEmployer->close();
    });

    connect(ui->saveFileButton, &QPushButton::clicked,this, [this](){

        openFileEmployer->open(QIODevice::WriteOnly| QIODevice::Text| QIODevice::Truncate);
        openFileEmployer->seek(0);
        for(int i = 0; i< employerList.size(); ++i){
            openFileEmployer->write(employerList[i].getSecondName().toUtf8()+ '\n');
            openFileEmployer->write(employerList[i].getNam().toUtf8() + '\n');
            openFileEmployer->write(employerList[i].getN().toUtf8() + '\n');
            openFileEmployer->write(Widget::dateTostring(employerList[i].getBirth()).toUtf8() + '\n');
            openFileEmployer->write(employerList[i].getGrad().toUtf8());
            openFileEmployer->write(employerList[i].getDesiredPos().toUtf8() + '\n');
            openFileEmployer->write(QString::number(employerList[i].getSalary()).toUtf8() + '\n');

        }
        openFileEmployer->close();
    });

    connect(ui->openFile1Button, &QPushButton::clicked,this, [this](){

        openFileVacancy = new QFile (QFileDialog::getOpenFileName(this, "Выбор файла", "/home/yauheni", "text files (*.txt)"));
        openFileVacancy->open(QIODevice::ReadOnly| QIODevice::Text);
        openFileVacancy->seek(0);
        vacancyList.clear();

        QVector<QString> readedData;
        while (openFileVacancy->pos()<openFileVacancy->size()) {
            readedData.push_back(openFileVacancy->readLine().removeLast());
            qDebug()<<openFileVacancy->pos();
        }

        int a = readedData.size()/8;

        for(int i = 0; i<a; ++i){
            vacancyList.push_back(Vacancy(readedData[i*8], readedData[1+ i*8], readedData[2+i*8].toDouble(), readedData[3+i*8].toInt(), readedData[4+i*8]=="Да", readedData[5+i*8].toInt(), readedData[6+i*8].toInt(), readedData[7+i*8].toInt()));
        }
        ui->saveFile2Button->setDisabled(0);
        showVacancyTable();
        openFileVacancy->close();
    });

    connect(ui->saveFile2Button, &QPushButton::clicked,this, [this](){

        openFileVacancy->open(QIODevice::WriteOnly| QIODevice::Text| QIODevice::Truncate);
        openFileVacancy->seek(0);
        for(int i = 0; i< vacancyList.size(); ++i){
            openFileVacancy->write(vacancyList[i].getFirmName().toUtf8()+ '\n');
            openFileVacancy->write(vacancyList[i].getPosition().toUtf8()+ '\n');
            openFileVacancy->write(vacancyList[i].getSalary().toUtf8()+ '\n');
            openFileVacancy->write(vacancyList[i].getVocation().toUtf8()+ '\n');
            openFileVacancy->write(vacancyList[i].getGraduation().toUtf8()+ '\n');
            openFileVacancy->write(vacancyList[i].getMinAge().toUtf8()+ '\n');
            openFileVacancy->write(vacancyList[i].getMaxAge().toUtf8()+ '\n');
            openFileVacancy->write(vacancyList[i].getStage().toUtf8()+ '\n');
        }
        openFileVacancy->close();
    });

    connect(ui->confirmButton, &QPushButton::clicked, this, [this](){
        if(ui->lineEdit->text()==""|| ui->lineEdit_2->text() ==""|| ui->lineEdit_3->text()==""|| ui->lineEdit_4->text()==""){
            ui->label_2->setText("Заполните все поля!");
        }
        else
        {
            employerList.push_back(Employer(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), ui->dateEdit->date(), ui->radioButton->isChecked(), ui->lineEdit_4->text(), ui->salarySpinBox->value()));
            showEmployerTable();
        ui->groupBox->setVisible(0);
        }
    });

    connect(ui->confirmVButton, &QPushButton::clicked, this, [this](){
        if(ui->nameFirmLineEdit->text()==""|| ui->positionVLineEdit->text() ==""|| ui->minAgeSpinBox->value() >ui->maxAgeSpinBox->value()){
            ui->label_21->setText("Неверный ввод!");
        }
        else
        {
            vacancyList.push_back(Vacancy(ui->nameFirmLineEdit->text(), ui->positionVLineEdit->text(), ui->salaryVDoubleSpinBox->value(), ui->vocationSpinBox->value(),ui->radioButton_2->isChecked(), ui->minAgeSpinBox->value(), ui->maxAgeSpinBox->value(), ui->stageSpinBox->value()));
            showVacancyTable();
            ui->groupBox_3->setVisible(0);
        }
    });

    connect(ui->addItemButton, &QPushButton::clicked, this,[this](){
        ui->groupBox->setVisible(1);
        ui->label_2->setText("Введите данные");
    });

    connect(ui->addVocButton, &QPushButton::clicked, this,[this](){
        ui->groupBox_3->setVisible(1);
        ui->label_21->setText("Введите данные");
    });

    connect(ui->editItemButton, &QPushButton::clicked, this,[this](){
        employerList.remove(ui->tableWidget->selectedItems()[0]->row());
        ui->groupBox->setVisible(1);
        ui->label_2->setText("Новые данные");
    });

    connect(ui->editVocButton, &QPushButton::clicked, this,[this](){
        vacancyList.remove(ui->tableWidget_2->selectedItems()[0]->row());
        ui->groupBox_3->setVisible(1);
        ui->label_21->setText("Новые данные");
    });

    connect(ui->deleteItemButton, &QPushButton::clicked, this,[this](){
        employerList.remove(ui->tableWidget->selectedItems()[0]->row());
        showEmployerTable();
    });

    connect(ui->deleteVocButton, &QPushButton::clicked, this,[this](){
        vacancyList.remove(ui->tableWidget_2->selectedItems()[0]->row());
        showVacancyTable();
    });

    connect(ui->showCandidatesButton, &QPushButton::clicked, this,[this](){
        showCandidates(vacancyList[ui->tableWidget_2->selectedItems()[0]->row()].possibleCandites(employerList));
        ui->listWidget_2->setVisible(1);
    });

    connect(ui->tableWidget, &QTableWidget::itemSelectionChanged, this, [this](){

        if(ui->tableWidget->selectedItems().size()==0)
        {
            ui->deleteItemButton->setDisabled(1);
            ui->editItemButton->setDisabled(1);
            ui->groupBox_2->setVisible(0);
        }
        else{
            ui->tableWidget->selectRow(ui->tableWidget->selectedItems()[0]->row());
            ui->groupBox_2->setVisible(1);
            ui->deleteItemButton->setDisabled(0);
            ui->editItemButton->setDisabled(0);
        }
    });

    connect(ui->tableWidget_2, &QTableWidget::itemSelectionChanged, this, [this](){

        if(ui->tableWidget_2->selectedItems().size()==0)
        {
            ui->deleteVocButton->setDisabled(1);
            ui->editVocButton->setDisabled(1);
            ui->showCandidatesButton->setDisabled(1);
            ui->groupBox_3->setVisible(0);
        }
        else{
            ui->tableWidget_2->selectRow(ui->tableWidget_2->selectedItems()[0]->row());
            ui->deleteVocButton->setDisabled(0);
            ui->editVocButton->setDisabled(0);
            ui->showCandidatesButton->setDisabled(0);
        }
    });

    connect(ui->listWidget, &QListWidget::itemSelectionChanged, this, [this](){
            ui->pushButton_2->setDisabled(0);
    });

    connect(ui->pushButton, &QPushButton::clicked, this, [this](){
        if(ui->lineEdit_5->text()!=""&&ui->spinBox->value()!=0){
            employerList[ui->tableWidget->selectedItems()[0]->row()].addPosition(ui->lineEdit_5->text(), ui->spinBox->value());
            showPositions(employerList[ui->tableWidget->selectedItems()[0]->row()]);
        }
    });

    connect(ui->pushButton_2, &QPushButton::clicked, this, [this](){
        employerList[ui->tableWidget->selectedItems()[0]->row()].removePosition(ui->listWidget->currentRow());
        showPositions(employerList[ui->tableWidget->selectedItems()[0]->row()]);
        ui->pushButton_2->setDisabled(1);
    });

    connect(ui->comboBox, &QComboBox::currentIndexChanged, this , [this](){
        ui->tableWidget->sortByColumn(ui->comboBox->currentIndex(), Qt::SortOrder::AscendingOrder);
    });

    connect(ui->comboBox_2, &QComboBox::currentIndexChanged, this , [this](){
       ui->tableWidget_2->sortByColumn(ui->comboBox_2->currentIndex(), Qt::SortOrder::AscendingOrder);
    });
}

void Widget::showEmployerTable(){
    ui->tableWidget->setRowCount(employerList.size());
    for(int i = 0; i<employerList.size();++i){
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(employerList[i].getName()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(employerList[i].getAge())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(employerList[i].getGraduation()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(employerList[i].getSalary())));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(employerList[i].getDesiredPos()));
    }
}

void Widget::showVacancyTable(){
    ui->tableWidget_2->setRowCount(vacancyList.size());
    for(int i = 0; i<vacancyList.size();++i){
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(vacancyList[i].getFirmName()));
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem(vacancyList[i].getPosition()));
        ui->tableWidget_2->setItem(i, 2, new QTableWidgetItem(vacancyList[i].getSalary()));
        ui->tableWidget_2->setItem(i, 3, new QTableWidgetItem(vacancyList[i].getVocation()));
        ui->tableWidget_2->setItem(i, 4, new QTableWidgetItem(vacancyList[i].getStage()));
        ui->tableWidget_2->setItem(i, 5, new QTableWidgetItem(vacancyList[i].getGraduation()));
        ui->tableWidget_2->setItem(i, 6, new QTableWidgetItem(vacancyList[i].getAge()));
    }
}

void Widget::showPositions(Employer a){
    ui->listWidget->clear();
    for(int i = 0; i<a.posSize(); ++i){
        ui->listWidget->addItem(a.getPosition(i)+"    Стаж: " + QString::number(a.getPosStage(i)));
    }
}

void Widget::showCandidates(QVector<Employer> a){
    ui->listWidget_2->clear();
    qDebug()<<a.size();
    for(int i = 0; i<a.size(); ++i){
        ui->listWidget_2->addItem(a[i].getName());
    }
}

QDate Widget::stringToDate(QString a){
    return QDate(a[0].digitValue()*1000+a[1].digitValue()*100 + a[2].digitValue()*10 + a[3].digitValue(),a[4].digitValue()*10+a[5].digitValue(),a[6].digitValue()*10 + a[7].digitValue());
};

QString Widget::dateTostring(QDate a){
    return QString::number(a.year())+QString::number(a.month())+ (a.month()<10 ? "0" : "")+QString::number(a.day())+(a.day()<10 ? "0" : "");
};

Widget::~Widget()
{
    delete ui;
}
