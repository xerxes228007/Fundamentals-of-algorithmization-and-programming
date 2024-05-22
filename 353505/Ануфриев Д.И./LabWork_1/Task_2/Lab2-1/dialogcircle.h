#ifndef DIALOGCIRCLE_H
#define DIALOGCIRCLE_H

#include <QDialog>
#include <QAbstractButton>
#include <QMessageBox>

namespace Ui {
class DialogCircle;
}

class DialogCircle : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCircle(QWidget *parent = nullptr);

    void setValue(qreal radius);

    ~DialogCircle();

    int getNewRadius();
private slots:

    void on_buttonBox_accepted();

private:
    Ui::DialogCircle *ui;
    int newRadius = 0;

signals:
    void setNewRadius();
};

#endif // DIALOGCIRCLE_H
