#ifndef DIALOGSTAR5_H
#define DIALOGSTAR5_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class DialogStar5;
}

class DialogStar5 : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStar5(QWidget *parent = nullptr);
    ~DialogStar5();

    qreal getNewExternalRadius();
    qreal getNewInternalRadius();

    void setValues(qreal intrad, qreal extrad);

private slots:
    void on_buttonBox_accepted();

private:
    int newInternalRadius, newExternalRadius;
    Ui::DialogStar5 *ui;

signals:
    void setNewRadiuses();
};

#endif // DIALOGSTAR5_H
