#include "newfilewindow.h"

newFileWindow::newFileWindow() {
    newDate->setParent(this);
    newDate->setGeometry(70,40,160, 30);
    newDate->setText("Имя файла");

    choosePathPushButton->setParent(this);
    choosePathPushButton->setText("Выбрать папку");
    choosePathPushButton->setGeometry(0,0,120,30);

    openPushButton->setParent(this);
    openPushButton->setText("Добавить файл");
    openPushButton->setGeometry(180,0,120,30);

    QPushButton::connect(choosePathPushButton, SIGNAL(pressed()), this, SLOT(on_choosePathPushButton_clicked()));
    QPushButton::connect(openPushButton, SIGNAL(pressed()), this, SLOT(on_openPushButton_clicked()));
}

void newFileWindow::on_choosePathPushButton_clicked()
{
    pathToFile = QFileDialog::ga
}
