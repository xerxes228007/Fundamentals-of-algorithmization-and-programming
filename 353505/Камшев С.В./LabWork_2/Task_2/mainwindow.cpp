#include "mainwindow.h"
#include "ui_mainwindow.h"
//[Камышев, Степан, Владиславович, Программист, 1, 500, 27.06.2005, //]
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    workersListPushButton->setParent(this);
    workersListPushButton->setText("Открыть файл с работниками");
    workersListPushButton->setGeometry(0,0,220,30);

    companyListPushButton->setParent(this);
    companyListPushButton->setText("Открыть файл с компаниями");
    companyListPushButton->setGeometry(0,40,220,30);

    addExperiencePushButton->setParent(this);
    addExperiencePushButton->setText("Добавить специальность");
    addExperiencePushButton->setGeometry(0, 80, 220, 30);

    newExperianceLineEdit->setParent(this);
    newExperianceLineEdit->setGeometry(0, 120, 220, 30);

    delExperiencePushButton->setParent(this);
    delExperiencePushButton->setText("удалить специальность");
    delExperiencePushButton->setGeometry(0, 160, 220, 30);

    delExperiense->setParent(this);
    delExperiense->setGeometry(0, 200, 220, 30);

    dellWorkerPushButton->setParent(this);
    dellWorkerPushButton->setText("Удалить выбранную строку");
    dellWorkerPushButton->setGeometry(0, 240, 220, 30);

    addNewWorkerPushButton->setParent(this);
    addNewWorkerPushButton->setText("Добавить строку");
    addNewWorkerPushButton->setGeometry(0, 280, 220, 30);

    sortWorkersPushButton->setParent(this);
    sortWorkersPushButton->setText("Сортировка");
    sortWorkersPushButton->setGeometry(0, 320, 220, 30);

    showOnlyPushButton->setParent(this);
    showOnlyPushButton->setText("Показать только");
    showOnlyPushButton->setGeometry(0, 360, 220, 30);

    textEdit = new QTextEdit;
    textEdit->setParent(this);
    textEdit->setGeometry(0,700, 500,500);

    tabWidget->setParent(this);
    QWidget* workersWidget = new QWidget;
    workersTable->setParent(workersWidget);
    workersTable->setGeometry(0, 0, 1900,1500);
    workersTable->setColumnCount(8);
    for (int i = 0; i < 8; ++ i){
        workersTable->setColumnWidth(i, 200);
    }
    workersTable->setHorizontalHeaderLabels(workerColomnNames);
    tabWidget->addTab(workersWidget, "Работники");

    dellCompanyPushButton->setParent(this);
    dellCompanyPushButton->setText("Удалить строку");
    dellCompanyPushButton->setGeometry(0,80,220,30);

    addNewCompanyPushButton->setParent(this);
    addNewCompanyPushButton->setText("Добавить строку");
    addNewCompanyPushButton->setGeometry(0,120,220,30);

    sortCompanyPushButton->setParent(this);
    sortCompanyPushButton->setText("Сортировка");
    sortCompanyPushButton->setGeometry(0,160,220,30);

    showOnlyCompanyPushButton->setParent(this);
    showOnlyCompanyPushButton->setText("Показать только");
    showOnlyCompanyPushButton->setGeometry(0,200,220,30);



    getWorkersPushButton->setParent(this);
    getWorkersPushButton->setText("Показать работников на каждую специальность");
    getWorkersPushButton->setGeometry(0,500,350,30);

    getwhitputWorkersPushButton->setParent(this);
    getwhitputWorkersPushButton->setText("Показать работников без работы");
    getwhitputWorkersPushButton->setGeometry(0,540,350,30);

    getWorkerswithoutJobPushButton->setParent(this);
    getWorkerswithoutJobPushButton->setText("Показать дефицитные должности");
    getWorkerswithoutJobPushButton->setGeometry(0,580,350,30);



    QPushButton::connect(workersListPushButton, SIGNAL(pressed()), this, SLOT(on_workersListPushButton_clicked()));
    QPushButton::connect(companyListPushButton, SIGNAL(pressed()), this, SLOT(on_companyListPushButton_clicked()));
    QPushButton::connect(addExperiencePushButton, SIGNAL(pressed()), this, SLOT(on_addExperiencePushButton_clicked()));
    QPushButton::connect(dellWorkerPushButton, SIGNAL(pressed()), this, SLOT(on_dellWorkerPushButton_clicked()));
    QPushButton::connect(addNewWorkerPushButton, SIGNAL(pressed()), this, SLOT(on_addNewWorkerPushButton_clicked()));
    QPushButton::connect(delExperiencePushButton, SIGNAL(pressed()), this, SLOT(on_delExperiencePushButton_clicked()));
    QPushButton::connect(sortWorkersPushButton, SIGNAL(pressed()), this, SLOT(on_sortWorkersPushButton_clicked()));
    QPushButton::connect(showOnlyPushButton, SIGNAL(pressed()), this, SLOT(on_showOnlyPushButton_clicked()));

    QPushButton::connect(dellCompanyPushButton, SIGNAL(pressed()), this, SLOT(on_dellCompanyPushButton_clicked()));
    QPushButton::connect(addNewCompanyPushButton, SIGNAL(pressed()), this, SLOT(on_addNewCompanyPushButton_clicked()));
    QPushButton::connect(sortCompanyPushButton, SIGNAL(pressed()), this, SLOT(on_sortCompanyPushButton_clicked()));
    QPushButton::connect(showOnlyCompanyPushButton, SIGNAL(pressed()), this, SLOT(on_showOnlyCompanyPushButton_clicked()));

    QPushButton::connect(getWorkersPushButton, SIGNAL(pressed()), this, SLOT(on_getWorkersPushButton_clicked()));
    QPushButton::connect(getwhitputWorkersPushButton, SIGNAL(pressed()), this, SLOT(on_getwhitputWorkersPushButton_clicked()));
    QPushButton::connect(getWorkerswithoutJobPushButton, SIGNAL(pressed()), this, SLOT(on_getWorkerswithoutJobPushButton_clicked()));

    QWidget* companysWidget = new QWidget;
    tabWidget->setGeometry(500,0, 1900, 1500);
    companysTable->setParent(companysWidget);
    companysTable->setGeometry(0, 0, 1900,1500);
    companysTable->setColumnCount(companyColomnNames.size());
    for (int i = 0; i < companyColomnNames.size(); ++ i){
        companysTable->setColumnWidth(i, 170);
    }
    companysTable->setHorizontalHeaderLabels(companyColomnNames);
    tabWidget->addTab(companysWidget, "Фирмы");


    timer = new QTimer;
    connect(timer, &QTimer::timeout, [=](){
        if (tabWidget->currentIndex() == 0){
            newExperianceLineEdit->show();
            addExperiencePushButton->show();
            dellWorkerPushButton->show();
            addNewWorkerPushButton->show();
            delExperiencePushButton->show();
            delExperiense->show();
            sortWorkersPushButton->show();
            showOnlyPushButton->show();

            dellCompanyPushButton->hide();
            addNewCompanyPushButton->hide();
            sortCompanyPushButton->hide();
        }
        else{
            newExperianceLineEdit->hide();
            addExperiencePushButton->hide();
            dellWorkerPushButton->hide();
            addNewWorkerPushButton->hide();
            delExperiencePushButton->hide();
            delExperiense->hide();
            sortWorkersPushButton->hide();
            showOnlyPushButton->hide();
            showOnlyCompanyPushButton->hide();

            dellCompanyPushButton->show();
            addNewCompanyPushButton->show();
            sortCompanyPushButton->show();
            showOnlyCompanyPushButton->show();

        }

        if (companysTable->rowCount() > 0 && workersTable->rowCount() > 0){
            getWorkersPushButton->setEnabled(true);
            getWorkersPushButton->setPalette(QPalette(Qt::white));
            getwhitputWorkersPushButton->setEnabled(true);
            getwhitputWorkersPushButton->setPalette(QPalette(Qt::white));
            getWorkerswithoutJobPushButton->setEnabled(true);
            getWorkerswithoutJobPushButton->setPalette(QPalette(Qt::white));


        }
        else{
            getWorkersPushButton->setEnabled(false);
            getWorkersPushButton->setPalette(QPalette(Qt::gray));
            getwhitputWorkersPushButton->setEnabled(false);
            getwhitputWorkersPushButton->setPalette(QPalette(Qt::gray));
            getWorkerswithoutJobPushButton->setEnabled(false);
            getWorkerswithoutJobPushButton->setPalette(QPalette(Qt::gray));
        }

        if (companysTable->rowCount() > 0){
            dellCompanyPushButton->setEnabled(true);
            dellCompanyPushButton->setPalette(QPalette(Qt::white));
            addNewCompanyPushButton->setEnabled(true);
            addNewCompanyPushButton->setPalette(QPalette(Qt::white));
            sortCompanyPushButton->setEnabled(true);
            sortCompanyPushButton->setPalette(QPalette(Qt::white));
            showOnlyCompanyPushButton->setEnabled(true);
            showOnlyCompanyPushButton->setPalette(QPalette(Qt::white));

            for (int i = 0; i < companyList.size(); ++i){
                if (minAgeSpinBoxArr[i]->value() > maxAgeSpinBoxArr[i]->value()){
                    int numb = minAgeSpinBoxArr[i]->value();
                    minAgeSpinBoxArr[i]->setValue(maxAgeSpinBoxArr[i]->value());
                    maxAgeSpinBoxArr[i]->setValue(numb);
                }
            }
        }
        else{
            dellCompanyPushButton->setEnabled(false);
            dellCompanyPushButton->setPalette(QPalette(Qt::gray));
            addNewCompanyPushButton->setEnabled(false);
            addNewCompanyPushButton->setPalette(QPalette(Qt::gray));
            sortCompanyPushButton->setEnabled(false);
            sortCompanyPushButton->setPalette(QPalette(Qt::gray));
            showOnlyCompanyPushButton->setEnabled(false);
            showOnlyCompanyPushButton->setPalette(QPalette(Qt::gray));

        }

        if (workersTable->rowCount() > 0){
            addExperiencePushButton->setEnabled(true);
            addExperiencePushButton->setPalette(QPalette(Qt::white));
            newExperianceLineEdit->setEnabled(true);
            newExperianceLineEdit->setPalette(QPalette(Qt::white));
            dellWorkerPushButton->setEnabled(true);
            dellWorkerPushButton->setPalette(QPalette(Qt::white));
            addNewWorkerPushButton->setEnabled(true);
            addNewWorkerPushButton->setPalette(QPalette(Qt::white));
            delExperiencePushButton->setEnabled(true);
            delExperiencePushButton->setPalette(QPalette(Qt::white));
            delExperiense->setEnabled(true);
            delExperiense->setPalette(QPalette(Qt::white));
            sortWorkersPushButton->setEnabled(true);
            sortWorkersPushButton->setPalette(QPalette(Qt::white));
            showOnlyPushButton->setEnabled(true);
            showOnlyPushButton->setPalette(QPalette(Qt::white));


        }
        else{
            addExperiencePushButton->setEnabled(false);
            addExperiencePushButton->setPalette(QPalette(Qt::gray));
            newExperianceLineEdit->setEnabled(false);
            newExperianceLineEdit->setPalette(QPalette(Qt::gray));
            dellWorkerPushButton->setEnabled(false);
            dellWorkerPushButton->setPalette(QPalette(Qt::gray));
            addNewWorkerPushButton->setEnabled(false);
            addNewWorkerPushButton->setPalette(QPalette(Qt::gray));
            delExperiencePushButton->setEnabled(false);
            delExperiencePushButton->setPalette(QPalette(Qt::gray));
            delExperiense->setEnabled(false);
            delExperiense->setPalette(QPalette(Qt::gray));
            sortWorkersPushButton->setEnabled(false);
            sortWorkersPushButton->setPalette(QPalette(Qt::gray));
            showOnlyPushButton->setEnabled(false);
            showOnlyPushButton->setPalette(QPalette(Qt::gray));
        }

        if (workersTable->rowCount() > 0 && workersTable->currentRow() != -1){
            delExperiense->setRange(0, workerList[workersTable->currentRow()].listOfPositions.size());

            for (int i = 0; i < workersTable->rowCount(); ++i){
                for (int j = 0; j < 8;++j){
                    if (i == workersTable->currentRow()){
                        workersTable->item(i,j)->setBackground(Qt::green);
                        QPalette pal;
                        pal.setColor(QPalette::Base, Qt::green);
                        firstNameEditArr[i]->setPalette(pal);
                        surNameEditArr[i]->setPalette(pal);
                        patronimycEditArr[i]->setPalette(pal);
                        desiredPositionEditArr[i]->setPalette(pal);
                        calendarArr[i]->setPalette(pal);
                        spinBoxArr[i]->setPalette(pal);

                    }
                    else{
                        workersTable->item(i,j)->setBackground(Qt::white);
                        QPalette pal;
                        pal.setColor(QPalette::Base, Qt::white);
                        firstNameEditArr[i]->setPalette(pal);
                        surNameEditArr[i]->setPalette(pal);
                        patronimycEditArr[i]->setPalette(pal);
                        desiredPositionEditArr[i]->setPalette(pal);
                        calendarArr[i]->setPalette(pal);
                        spinBoxArr[i]->setPalette(pal);
                    }
                }

            }
        }

        if (workerList.size() > 0 && workersTable->rowCount() > 0){
            for (int i = 0; i < workerList.size(); ++i){
                workerList[i].ageCalculating();
                workerList[i].firstName = firstNameEditArr[i]->text();
                workerList[i].surname = surNameEditArr[i]->text();
                workerList[i].patronymic = patronimycEditArr[i]->text();
                workerList[i].desiredPosition = desiredPositionEditArr[i]->text();
                workerList[i].hasRequirementsForHigherEducation = workersTable->item(i, 5)->checkState();
                workerList[i].minimumSalary = spinBoxArr[i]->value();
                workerList[i].dateOfBirth = Date::stringToDate(calendarArr[i]->text().split(' ')[0] + "." + calendarArr[i]->text().split(' ')[1] + "." + calendarArr[i]->text().split(' ')[2]);
                while(!experienceIsOk(i)){
                    workerList[i].listOfPositions.erase(workerList[i].listOfPositions.end() - 1);
                    QString str = "";
                    for (int j = 0; j < workerList[i].listOfPositions.size(); ++j){
                        str += workerList[i].listOfPositions[j].first + ':' + QString::number(workerList[i].listOfPositions[j].second) + "\n";
                    }
                    workersTable->item(i, 7)->setText(str);
                }


            }
        }

        if (companyList.size() > 0 && companysTable->rowCount() > 0){
            for (int i = 0; i < companyList.size(); ++i){
                companyList[i].nameOfCompany = companyNameEditArr[i]->text();
                companyList[i].experience = experienceBoxArr[i]->value();
                companyList[i].post = companyPostEditArr[i]->text();
                companyList[i].hasExperienceRequirements = bool(companysTable->item(i,4)->checkState());
                companyList[i].hasExperienceRequirements = bool(companysTable->item(i,5)->checkState());
                companyList[i].hasAgeRequirements = bool(companysTable->item(i,7)->checkState());
                companyList[i].minimumAge = minAgeSpinBoxArr[i]->value();
                companyList[i].maximumAge = maxAgeSpinBoxArr[i]->value();
                companyList[i].salary = salarySpinBoxArr[i]->value();
            }
        }

        if(companyList.size() > 0){
            for (int i = 0; i < companyList.size(); ++i){
                if (companysTable->item(i, 5)->checkState()) experienceBoxArr[i]->setEnabled(true);
                else experienceBoxArr[i]->setEnabled(false);

                if (companysTable->item(i, 7)->checkState()){
                    minAgeSpinBoxArr[i]->setEnabled(true);
                    maxAgeSpinBoxArr[i]->setEnabled(true);

                }
                else{
                    minAgeSpinBoxArr[i]->setEnabled(false);
                    maxAgeSpinBoxArr[i]->setEnabled(false);
                }
            }
        }

        if (companysTable->rowCount() > 0 && companysTable->currentRow() != -1){

            for (int i = 0; i < companysTable->rowCount(); ++i){
                for (int j = 0; j < 8;++j){
                    if (i == companysTable->currentRow()){
                        companysTable->item(i,j)->setBackground(Qt::green);
                        QPalette pal;
                        pal.setColor(QPalette::Base, Qt::green);
                        companyNameEditArr[i]->setPalette(pal);
                        companyPostEditArr[i]->setPalette(pal);
                        HolydaysSpinBoxArr[i]->setPalette(pal);
                        salarySpinBoxArr[i]->setPalette(pal);
                        experienceBoxArr[i]->setPalette(pal);
                        minAgeSpinBoxArr[i]->setPalette(pal);
                        maxAgeSpinBoxArr[i]->setPalette(pal);

                    }
                    else{
                        companysTable->item(i,j)->setBackground(Qt::white);
                        QPalette pal;
                        pal.setColor(QPalette::Base, Qt::white);
                        companyNameEditArr[i]->setPalette(pal);
                        companyPostEditArr[i]->setPalette(pal);
                        HolydaysSpinBoxArr[i]->setPalette(pal);
                        salarySpinBoxArr[i]->setPalette(pal);
                        experienceBoxArr[i]->setPalette(pal);
                        minAgeSpinBoxArr[i]->setPalette(pal);
                        maxAgeSpinBoxArr[i]->setPalette(pal);
                    }
                }

            }
        }
    });
    timer->start(30);

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::experienceIsOk(int index)
{
    workerList[index].ageCalculating();
    if (workerList[index].age >= workerList[index].getSumOfExperience()) return true;
    else return false;
}

void MainWindow::openWorkersFile()
{
    while (!workerFile.atEnd()){
        workerList.append(worker::stringToWorker(workerFile.readLine()));
        workersisShowedArr.append(true);

    }
    workersTable->setRowCount(workerList.size());
    workersFileWosOpen = true;
    workerFile.close();
    showWorkers();
}

void MainWindow::openCompanyFile()
{
    while (!companyFile.atEnd()){
        companyList.append(company::stringToWorker(companyFile.readLine()));
        companyShowedArr.append(true);
    }
    companysTable->setRowCount(companyList.size());
    companyFileWosOpen = true;
    companyFile.close();
    showCompanys();
}

void MainWindow::showWorkers()
{
    for (int i = 0; i < workerList.size(); ++i){
        nameValidator* val = new nameValidator;

        QTableWidgetItem* Item = new QTableWidgetItem();
        QLineEdit* surNameEdit = new QLineEdit;
        surNameEdit->setValidator(val);
        surNameEdit->setText(workerList[i].surname);
        workersTable->setItem(i,0, Item);
        surNameEditArr.append(surNameEdit);
        workersTable->setCellWidget(i, 0, surNameEdit);

        val = new nameValidator;
        Item = new QTableWidgetItem();
        QLineEdit* firstNameEdit = new QLineEdit;
        firstNameEdit->setValidator(val);
        firstNameEdit->setText(workerList[i].firstName);
        firstNameEditArr.append(firstNameEdit);
        workersTable->setItem(i,1, Item);
        workersTable->setCellWidget(i, 1, firstNameEdit);

        val = new nameValidator;
        QLineEdit* patronimycEdit = new QLineEdit;
        patronimycEdit->setValidator(val);
        patronimycEdit->setText(workerList[i].patronymic);
        patronimycEditArr.append(patronimycEdit);
        Item = new QTableWidgetItem();
        workersTable->setItem(i,2, Item);
        workersTable->setCellWidget(i, 2, patronimycEdit);

        Item = new QTableWidgetItem();
        QDateTimeEdit* calendar = new QDateTimeEdit();
        calendar->setDisplayFormat("dd MM yyyy");
        calendar->setDateRange(QDate(1950, 1, 1), QDate(2010, 1, 1));
        calendar->setDate(QDate(workerList[i].dateOfBirth.ToString().split('.')[2].toInt(), workerList[i].dateOfBirth.ToString().split('.')[1].toInt(), workerList[i].dateOfBirth.ToString().split('.')[0].toInt()));
        calendar->setCalendarPopup(true);
        calendarArr.append(calendar);
        workersTable->setItem(i,3, Item);
        workersTable->setCellWidget(i, 3, calendar);


        Item = new QTableWidgetItem();
        QSpinBox* spinbox = new QSpinBox;
        spinbox->setMinimum(500);
        spinbox->setMaximum(10000);
        spinbox->setValue(workerList[i].minimumSalary);
        spinBoxArr.append(spinbox);
        workersTable->setItem(i,4, Item);
        workersTable->setCellWidget(i, 4, spinbox);

        Item = new QTableWidgetItem();
        Item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        Item->setCheckState(workerList[i].hasRequirementsForHigherEducation? Qt::Checked:Qt::Unchecked);
        workersTable->setItem(i,5, Item);


        desiredPositionValidator* Dval = new desiredPositionValidator;
        QLineEdit* desiredPositionEdit = new QLineEdit;
        desiredPositionEdit->setValidator(Dval);
        desiredPositionEdit->setText(workerList[i].desiredPosition);
        desiredPositionEditArr.append(desiredPositionEdit);
        Item = new QTableWidgetItem();
        workersTable->setItem(i,6, Item);
        workersTable->setCellWidget(i, 6, desiredPositionEdit);



        QString str = "";
        for (int j = 0; j < workerList[i].listOfPositions.size(); ++j){
            str += workerList[i].listOfPositions[j].first + ':' + QString::number(workerList[i].listOfPositions[j].second) + "\n";
        }
        if(workersisShowedArr[i]) workersTable->setRowHeight(i, workerList[i].listOfPositions.size() > 1? 23 * workerList[i].listOfPositions.size(): 23);
        else workersTable->setRowHeight(i, 0);

        Item = new QTableWidgetItem(str);
        workersTable->setItem(i,7, Item);
        workersTable->item(i, 7)->setFlags(Item->flags() ^ Qt::ItemIsEditable);

    }
}

void MainWindow::showCompanys()
{
    for (int i = 0; i < companyList.size(); ++i){
        QTableWidgetItem* Item = new QTableWidgetItem();
        QLineEdit* nameOfCompanyEdit = new QLineEdit;
        nameOfCompanyEdit->setText(companyList[i].nameOfCompany);
        companysTable->setItem(i,0, Item);
        companyNameEditArr.append(nameOfCompanyEdit);
        companysTable->setCellWidget(i, 0, nameOfCompanyEdit);

        Item = new QTableWidgetItem();
        QLineEdit* PostEdit = new QLineEdit;
        PostEdit->setText(companyList[i].post);
        companyPostEditArr.append(PostEdit);
        companysTable->setItem(i,1, Item);
        companysTable->setCellWidget(i, 1, PostEdit);

        Item = new QTableWidgetItem();
        QSpinBox* Holspinbox = new QSpinBox;
        Holspinbox->setMinimum(14);
        Holspinbox->setMaximum(30);
        Holspinbox->setValue(companyList[i].numberOfVacationDays);
        HolydaysSpinBoxArr.append(Holspinbox);
        companysTable->setItem(i,2, Item);
        companysTable->setCellWidget(i, 2, Holspinbox);

        Item = new QTableWidgetItem();
        QSpinBox* salspinbox = new QSpinBox;
        salspinbox->setMinimum(500);
        salspinbox->setMaximum(10000);
        salspinbox->setValue(companyList[i].salary);
        salarySpinBoxArr.append(salspinbox);
        companysTable->setItem(i,3, Item);
        companysTable->setCellWidget(i, 3, salspinbox);

        Item = new QTableWidgetItem();
        Item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        Item->setCheckState(companyList[i].hasRequirementsForHigherEducation? Qt::Checked : Qt::Unchecked);
        companysTable->setItem(i,4, Item);

        Item = new QTableWidgetItem();
        Item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        Item->setCheckState(companyList[i].hasExperienceRequirements? Qt::Checked : Qt::Unchecked);
        companysTable->setItem(i,5, Item);

        Item = new QTableWidgetItem();
        QSpinBox* expspinbox = new QSpinBox;
        expspinbox->setMinimum(0);
        expspinbox->setMaximum(40);
        expspinbox->setValue(companyList[i].experience);
        experienceBoxArr.append(expspinbox);
        companysTable->setItem(i,6, Item);
        companysTable->setCellWidget(i, 6, expspinbox);


        Item = new QTableWidgetItem();
        Item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        Item->setCheckState(companyList[i].hasAgeRequirements? Qt::Checked : Qt::Unchecked);
        companysTable->setItem(i,7, Item);

        Item = new QTableWidgetItem();
        QSpinBox* minAgespinbox = new QSpinBox;
        minAgespinbox->setMinimum(0);
        minAgespinbox->setMaximum(40);
        minAgespinbox->setValue(companyList[i].minimumAge);
        minAgeSpinBoxArr.append(minAgespinbox);
        companysTable->setItem(i,8, Item);
        companysTable->setCellWidget(i, 8, minAgespinbox);

        Item = new QTableWidgetItem();
        QSpinBox* maxAgespinbox = new QSpinBox;
        maxAgespinbox->setMinimum(0);
        maxAgespinbox->setMaximum(40);
        maxAgespinbox->setValue(companyList[i].maximumAge);
        maxAgeSpinBoxArr.append(maxAgespinbox);
        companysTable->setItem(i,9, Item);
        companysTable->setCellWidget(i, 9, maxAgespinbox);

        if (companysTable->item(i, 5)->checkState()) experienceBoxArr[i]->setEnabled(true);
        else experienceBoxArr[i]->setEnabled(false);

        if (companysTable->item(i, 7)->checkState()){
            minAgeSpinBoxArr[i]->setEnabled(true);
            maxAgeSpinBoxArr[i]->setEnabled(true);

        }
        else{
            minAgeSpinBoxArr[i]->setEnabled(false);
            maxAgeSpinBoxArr[i]->setEnabled(false);
        }

        if (companyShowedArr[i] == true){
            companysTable->setRowHeight(i, 23);
        }
        else{
            companysTable->setRowHeight(i, 0);
        }
    }
}

bool MainWindow::checkNewExperianceString(QString &str)
{
    if (str.size() > 0 && str.contains(':') && str.split(':').size() == 2){
        for (int i = str.indexOf(':'); i < str.size(); ++i){
            if (str[i] == ' ') {
                str.remove(i, 1);
                i--;
            }
        }
        for (int i = 0; i < str.indexOf(':'); ++i){
            if (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == ':')) {
                str.remove(i, 1);
                i--;
            }
        }
        bool* flag = new bool;
        int newExperience = str.split(':')[1].toInt(flag);
        if (*flag == true && newExperience>0 && workerList[workersTable->currentRow()].getSumOfExperience() + newExperience <= workerList[workersTable->currentRow()].age) return true;

    }
    return false;
}

void MainWindow::workersVileSave()
{
    if (workersFileWosOpen){
        if (workerFile.isOpen()){
            workerFile.close();
        }
        workerFile.open(QIODeviceBase::WriteOnly);
        if (workerFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
            workerFile.close();
        QTextStream out(&workerFile);

        workerFile.open(QIODeviceBase::WriteOnly);
        for (int i = 0; i < workerList.size(); ++i){
            QString str = "[" + workerList[i].surname + ", " + workerList[i].firstName + ", " + workerList[i].patronymic + ", " + workerList[i].desiredPosition +  ", " + QString::number(workerList[i].hasRequirementsForHigherEducation) + ", " + QString::number(workerList[i].minimumSalary) + ", " + workerList[i].dateOfBirth.ToString();
            str += ", //";
            if (workerList[i].listOfPositions.size() > 0){
                str += "{";
                for (int j = 0; j < workerList[i].listOfPositions.size() ;++j){
                    str += workerList[i].listOfPositions[j].first + ":" + QString::number(workerList[i].listOfPositions[j].second) + "}, {";
                }
                str.erase(str.end() - 3, str.end());
            }
            str += "]\n";
            out << str;
        }
        workerFile.close();
    }
}

void MainWindow::companyFileSave()
{
    if (companyFileWosOpen){
        if (companyFile.isOpen()){
            companyFile.close();
        }
        companyFile.open(QIODeviceBase::WriteOnly);
        if (companyFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
            companyFile.close();
        QTextStream out(&companyFile);

        companyFile.open(QIODeviceBase::WriteOnly);
        for (int i = 0; i < companyList.size(); ++i){
            QString str = "[" + companyList[i].nameOfCompany + ", " + companyList[i].post + ", " + QString::number(companyList[i].salary) + ", " + QString::number(companyList[i].hasRequirementsForHigherEducation) + ", ";
            str+= QString::number(companyList[i].hasAgeRequirements) + ", " + QString::number(companyList[i].hasExperienceRequirements) + ", " + QString::number(companyList[i].numberOfVacationDays) + ", ";
            str += QString::number(companyList[i].experience) + ", " + QString::number(companyList[i].minimumAge) + ", " + QString::number(companyList[i].maximumAge) + "]\n";
            out << str;
        }
        companyFile.close();
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
    workersVileSave();
    companyFileSave();
    event->accept();
}

void MainWindow::getAns()
{
    for (int i = 0; i < workerList.size(); ++i){
        workersWithoutJobArr.append(1);
    }

    for (int i = 0; i < companyList.size(); ++i){
        defecitPostArr.append(1);
    }
    ansArr.clear();
    for (int i = 0; i < companyList.size(); ++i){
        bool flag = 0;
        for (int j = 0; j < workerList.size(); ++j){
            if (companyList[i].post.toUpper() == workerList[j].desiredPosition.toUpper() && companyList[i].salary >= workerList[j].minimumSalary){
                if (!companyList[i].hasRequirementsForHigherEducation || (companyList[i].hasRequirementsForHigherEducation && workerList[j].hasRequirementsForHigherEducation)){
                    if (!companyList[i].hasAgeRequirements || (companyList[i].hasAgeRequirements && workerList[j].age >= companyList[i].minimumAge && workerList[j].age <= companyList[i].maximumAge)){
                        if (!companyList[i].hasExperienceRequirements || (companyList[i].hasExperienceRequirements && companyList[i].experience <= workerList[j].getSumOfExperience())){
                            if (!flag){
                                QPair <company, QVector <worker>> Pair;
                                ansArr.append(Pair);
                                ansArr[i].first = companyList[i];
                                flag = true;
                            }
                            ansArr[i].second.append(workerList[j]);
                            defecitPostArr[i] = false;
                            workersWithoutJobArr[j] = false;
                        }
                    }
                }
            }

        }
    }
}

void MainWindow::showWorkersWithoutJobArr()
{
    QString str = "";
    for (int i = 0; i < workerList.size(); ++i){
        if (workersWithoutJobArr[i]){
            str += "[" + workerList[i].surname + ", " + workerList[i].firstName + ", " + workerList[i].patronymic + ", " + workerList[i].desiredPosition +  ", " + QString::number(workerList[i].hasRequirementsForHigherEducation) + ", " + QString::number(workerList[i].minimumSalary) + ", " + workerList[i].dateOfBirth.ToString();
            str += ", //";
            if (workerList[i].listOfPositions.size() > 0){
                str += "{";
                for (int j = 0; j < workerList[i].listOfPositions.size() ;++j){
                    str += workerList[i].listOfPositions[j].first + ":" + QString::number(workerList[i].listOfPositions[j].second) + "}, {";
                }
                str.erase(str.end() - 3, str.end());
            }
            str += "]\n";
        }
    }
    textEdit->setText(str);



}

void MainWindow::showDefecitPostArr()
{
    QString str ="";
    for (int i = 0; i < companyList.size(); ++i){
        if (defecitPostArr[i]){
            str += "[" + companyList[i].nameOfCompany + ", " + companyList[i].post + ", " + QString::number(companyList[i].salary) + ", " + QString::number(companyList[i].hasRequirementsForHigherEducation) + ", ";
            str+= QString::number(companyList[i].hasAgeRequirements) + ", " + QString::number(companyList[i].hasExperienceRequirements) + ", " + QString::number(companyList[i].numberOfVacationDays) + ", ";
            str += QString::number(companyList[i].experience) + ", " + QString::number(companyList[i].minimumAge) + ", " + QString::number(companyList[i].maximumAge) + "]\n";
        }
    }
    textEdit->setText(str);

}

void MainWindow::showAnsArr()
{
    QString str ="";
    for (int i = 0; i < ansArr.size(); ++i){
        str += ansArr[i].first.nameOfCompany + " " + ansArr[i].first.post + "{\n";
        for (int j = 0; j < ansArr[i].second.size(); ++j){
            str += "[" + ansArr[i].second[j].surname + " " + ansArr[i].second[j].firstName + " " + ansArr[i].second[j].patronymic + "]\n";
        }
        str +="}\n";
    }
    textEdit->setText(str);

}

void MainWindow::on_workersListPushButton_clicked()
{
    workersFileName = QFileDialog::getOpenFileName(this, "Выберите файл", "/home/stepan/Labs OAIP/2/Task_2", "*.work");
    workerFile.setFileName(workersFileName);
    workerFile.open(QIODevice::ReadOnly);
    if (workerFile.isOpen()) openWorkersFile();


}

void MainWindow::on_companyListPushButton_clicked()
{
    companyFileName = QFileDialog::getOpenFileName(this, "Выберите файл", "/home/stepan/Labs OAIP/2/Task_2", "*.comp");
    companyFile.setFileName(companyFileName);
    companyFile.open(QIODevice::ReadOnly);
    if (companyFile.isOpen()) openCompanyFile();
}

void MainWindow::on_addExperiencePushButton_clicked()
{
    if (workersTable->currentRow() != -1){
        QString str = newExperianceLineEdit->text();
        if (checkNewExperianceString(str)){
            workersTable->item(workersTable->currentRow(), 7)->setText(workersTable->item(workersTable->currentRow(), 7)->text() + str + "\n");
            QPair <QString, int> pair(str.split(':')[0], str.split(':')[1].toInt());
            workerList[workersTable->currentRow()].listOfPositions.append(pair);
            workersTable->setRowHeight(workersTable->currentRow(), 23 * workerList[workersTable->currentRow()].listOfPositions.size());
        }
    }
    else{
        QMessageBox::warning(this, "Предупреждение", "Не выбрана ячейка");
    }
}

void MainWindow::on_dellWorkerPushButton_clicked()
{
    if (workersTable->currentRow() != -1){
        workerList.erase(workerList.begin() + workersTable->currentRow());
        workersisShowedArr.clear();
        for (int i = 0; i < workerList.size(); ++i){
            workersisShowedArr.append(true);
        }
        spinBoxArr.clear();
        calendarArr.clear();
        firstNameEditArr.clear();
        surNameEditArr.clear();
        patronimycEditArr.clear();
        desiredPositionEditArr.clear();
        workersTable->setRowCount(0);
        workersTable->clear();
        workersTable->setRowCount(workerList.size());
        showWorkers();
        workersTable->setHorizontalHeaderLabels(workerColomnNames);
    }
    else{
        QMessageBox::warning(this, "Предупреждение", "Не выбрана ячейка");
    }
}

void MainWindow::on_addNewWorkerPushButton_clicked()
{
    QVector <QPair <QString, int>> vec;
    workerList.append(worker("A", "A", "A", "A", false, 500, vec, Date(01, 01, 1950)));
    workersisShowedArr.clear();
    for (int i = 0; i < workerList.size(); ++i){
        workersisShowedArr.append(true);
    }
    spinBoxArr.clear();
    calendarArr.clear();
    firstNameEditArr.clear();
    surNameEditArr.clear();
    patronimycEditArr.clear();
    desiredPositionEditArr.clear();
    workersTable->setRowCount(0);
    workersTable->clear();
    workersTable->setRowCount(workerList.size());
    workersTable->setHorizontalHeaderLabels(workerColomnNames);
    showWorkers();
}

void MainWindow::on_delExperiencePushButton_clicked()
{
    if (workersTable->currentRow() != -1){
        if (workerList[workersTable->currentRow()].listOfPositions.size() > 0){
            workerList[workersTable->currentRow()].listOfPositions.erase(workerList[workersTable->currentRow()].listOfPositions.begin() + delExperiense->value() - 1);

            workersTable->item(workersTable->currentRow(), 7)->setText("");

            QString str = "";
            for (int j = 0; j < workerList[workersTable->currentRow()].listOfPositions.size(); ++j){
                str += workerList[workersTable->currentRow()].listOfPositions[j].first + ':' + QString::number(workerList[workersTable->currentRow()].listOfPositions[j].second) + "\n";
            }
            workersTable->item(workersTable->currentRow(), 7)->setText(str);
        }
    }
    else{
        QMessageBox::warning(this, "Предупреждение", "Не выбрана ячейка");
    }
}

void MainWindow::on_sortWorkersPushButton_clicked()
{
    SortDialog = new sortDialog;
    SortDialog->exec();

    if (SortDialog->getIsChecked()){
        if (SortDialog->salryCheckBox->isChecked()){
            std::sort(workerList.begin(), workerList.end(),[](worker& a, worker& b){
                return a.minimumSalary < b.minimumSalary;
            });

        }
        else if (SortDialog->higeAducationCheckBox->isChecked()){
            std::sort(workerList.begin(), workerList.end(),[](worker& a, worker& b){
                return a.hasRequirementsForHigherEducation > b.hasRequirementsForHigherEducation;
            });
        }
        else{
            std::sort(workerList.begin(), workerList.end(),[](worker& a, worker& b){
                return a.surname < b.surname;
            });
        }

        spinBoxArr.clear();
        calendarArr.clear();
        firstNameEditArr.clear();
        surNameEditArr.clear();
        patronimycEditArr.clear();
        desiredPositionEditArr.clear();
        workersTable->setRowCount(0);
        workersTable->clear();
        workersTable->setRowCount(workerList.size());
        workersTable->setHorizontalHeaderLabels(workerColomnNames);
        showWorkers();
    }

}

void MainWindow::on_showOnlyPushButton_clicked()
{
    onlyDialog = new showOnlyWorkersDialog;
    onlyDialog->exec();
    workersisShowedArr.clear();
    for (int i = 0; i < workerList.size(); ++i){
        workersisShowedArr.append(true);
    }

    if (onlyDialog->getIsChecked()){
        if (onlyDialog->salryCheckBox->isChecked()){
            for (int i = 0; i <workerList.size(); ++i){
                if (workerList[i].minimumSalary > onlyDialog->spinBox->value()){
                    workersisShowedArr[i] = false;
                }
            }


        }
        else if (onlyDialog->higeAducationCheckBox->isChecked()){
            for (int i = 0; i <workerList.size(); ++i){
                if (!workerList[i].hasRequirementsForHigherEducation){
                    workersisShowedArr[i] = false;
                }
            }
        }
        else{
            for (int i = 0; i <workerList.size(); ++i){

                workersisShowedArr[i] = true;

            }
        }

        for (int i = 0; i < workerList.size(); ++i){
            if (workersisShowedArr[i] == false){
                workersTable->setRowHeight(i, 0);
            }
            else{
                workersTable->setRowHeight(i, 23 * workerList[i].listOfPositions.size());
            }
        }

    }
}

void MainWindow::on_dellCompanyPushButton_clicked()
{
    if (companysTable->currentRow() != -1){
        companyList.erase(companyList.begin() + companysTable->currentRow());
        companyShowedArr.clear();
        for (int i = 0; i < companyList.size(); ++i){
            companyShowedArr.append(true);
        }
        companyNameEditArr.clear();
        companyPostEditArr.clear();
        HolydaysSpinBoxArr.clear();
        salarySpinBoxArr.clear();
        experienceBoxArr.clear();
        minAgeSpinBoxArr.clear();
        maxAgeSpinBoxArr.clear();
        companysTable->setRowCount(0);
        companysTable->clear();
        companysTable->setRowCount(companyList.size());
        companysTable->setHorizontalHeaderLabels(companyColomnNames);
        showCompanys();
    }
    else{
        QMessageBox::warning(this, "Предупреждение", "Не выбрана ячейка");
    }

}

void MainWindow:: on_addNewCompanyPushButton_clicked()
{
    companyList.append(company("A1","программист", 600, 1, 0, 0, 17, 9, 11, 12));
    companyShowedArr.clear();
    for (int i = 0; i < companyList.size(); ++i){
        companyShowedArr.append(true);
    }
    companyNameEditArr.clear();
    companyPostEditArr.clear();
    HolydaysSpinBoxArr.clear();
    salarySpinBoxArr.clear();
    experienceBoxArr.clear();
    minAgeSpinBoxArr.clear();
    maxAgeSpinBoxArr.clear();
    companysTable->setRowCount(0);
    companysTable->clear();
    companysTable->setRowCount(companyList.size());
    companysTable->setHorizontalHeaderLabels(companyColomnNames);
    showCompanys();
}

void MainWindow::on_sortCompanyPushButton_clicked()
{
    SortCompanys = new sortcompanys;
    SortCompanys->exec();

    if (SortCompanys->getIsChecked()){
        if (SortCompanys->salryCheckBox->isChecked()){
            std::sort(companyList.begin(), companyList.end(),[](company& a, company& b){
                return a.salary< b.salary;
            });

        }
        else if (SortCompanys->higeAducationCheckBox->isChecked()){
            std::sort(companyList.begin(), companyList.end(),[](company& a, company& b){
                return a.hasRequirementsForHigherEducation < b.hasRequirementsForHigherEducation;
            });
        }
        else{
            std::sort(companyList.begin(), companyList.end(),[](company& a, company& b){
                return a.experience < b.experience;
            });
        }

        companyNameEditArr.clear();
        companyPostEditArr.clear();
        HolydaysSpinBoxArr.clear();
        salarySpinBoxArr.clear();
        experienceBoxArr.clear();
        minAgeSpinBoxArr.clear();
        maxAgeSpinBoxArr.clear();
        companysTable->setRowCount(0);
        companysTable->clear();
        companysTable->setRowCount(companyList.size());
        companysTable->setHorizontalHeaderLabels(companyColomnNames);
        showCompanys();
    }
}

void MainWindow::on_showOnlyCompanyPushButton_clicked()
{
    showonlycompanyDialog = new ShowOnlyCompany;
    showonlycompanyDialog->exec();

    companyShowedArr.clear();
    for (int i = 0; i < companyList.size(); ++i){
        companyShowedArr.append(true);
    }

    if (showonlycompanyDialog->getIsChecked()){
        if (showonlycompanyDialog->salryCheckBox->isChecked()){
            for (int i = 0; i <companyList.size(); ++i){
                if (companyList[i].salary < showonlycompanyDialog->spinBox->value()){
                    companyShowedArr[i] = false;
                }
            }
        }

        else if (showonlycompanyDialog->higeAducationCheckBox->isChecked()){
            for (int i = 0; i <companyList.size(); ++i){
                if (!companyList[i].hasRequirementsForHigherEducation){
                    companyShowedArr[i] = false;
                }
            }
        }
        else if(showonlycompanyDialog->expCheckBox->isChecked()){
            for (int i = 0; i <companyList.size(); ++i){
                if (companyList[i].experience < showonlycompanyDialog->expspinBox->value()){
                    companyShowedArr[i] = false;
                }
            }
        }
        else{
            for (int i = 0; i <companyList.size(); ++i){

                companyShowedArr[i] = true;

            }
        }

        for (int i = 0; i < companyList.size(); ++i){
            if (companyShowedArr[i] == false){
                companysTable->setRowHeight(i, 0);
            }
            else{
                companysTable->setRowHeight(i, 23);
            }
        }

    }
}

void MainWindow::on_getWorkersPushButton_clicked()
{
    getAns();
    showAnsArr();
}

void MainWindow::on_getwhitputWorkersPushButton_clicked()
{
    getAns();
    showWorkersWithoutJobArr();

}

void MainWindow::on_getWorkerswithoutJobPushButton_clicked()
{
    getAns();
    showDefecitPostArr();


}

