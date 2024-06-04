#ifndef CREATEORDERWINDOW_H
#define CREATEORDERWINDOW_H

#include <QMainWindow>

namespace Ui {
class CreateOrderWindow;
}

class CreateOrderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateOrderWindow(QWidget *parent = nullptr);
    ~CreateOrderWindow();

private:
    Ui::CreateOrderWindow *ui;
};

#endif // CREATEORDERWINDOW_H
