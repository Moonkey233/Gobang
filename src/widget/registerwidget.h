#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

#include "mywidget.h"

namespace Ui {
class RegisterWidget;
}

class RegisterWidget : public MyWidget
{
    Q_OBJECT

public:
    RegisterWidget(QSharedPointer<MyTcpSocket> socket, QWidget *parent = nullptr);
    ~RegisterWidget();

private slots:
    void onSendBtnClicked();
    void onRegisterBtnClicked();
    void onReturnBtnClicked();

   void onRegisterResponse();

private:
    Ui::RegisterWidget *ui;
    bool connectSlot();

};

#endif // REGISTERWIDGET_H
