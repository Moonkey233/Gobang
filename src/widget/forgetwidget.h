#ifndef FORGETWIDGET_H
#define FORGETWIDGET_H

#include "mywidget.h"

namespace Ui {
class ForgetWidget;
}

class ForgetWidget : public MyWidget
{
    Q_OBJECT

public:
    ForgetWidget(QSharedPointer<MyTcpSocket> socket, QWidget *parent = nullptr);
    ~ForgetWidget();

private slots:
    void onSendBtnClicked();
    void onChangeBtnClicked();
    void onReturnBtnClicked();
    void onSetEmailAndPrevious(const QString &email, const QString &previous);
    void onPasswordResponse();

private:
    Ui::ForgetWidget *ui;
    QString m_previous = "loginWidget";
    bool connectSlot();

signals:
    void cancelAutoLoginSignal();

};

#endif // FORGETWIDGET_H
