#ifndef DIALOGSQUARE_H
#define DIALOGSQUARE_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class DialogSquare;
}

class DialogSquare : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSquare(QWidget *parent = nullptr);
    ~DialogSquare();

    int getNewSide();

    void setValue(qreal side);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogSquare *ui;
    int newSide;

signals:
    void setNewSide();
};

#endif // DIALOGSQUARE_H
