#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include "mywidget.h"

namespace Ui {
class LoginWidget;
}

class LoginWidget : public MyWidget
{
    Q_OBJECT

public:
    LoginWidget(QSharedPointer<MyTcpSocket> socket, QWidget *parent = nullptr);
    ~LoginWidget();

private slots:
    void onForgetBtnClicked();
    void onLoginBtnClicked();
    void onRegisterBtnClicked();
    void onReturnBtnClicked();
    void onAutoLogin();
    void onCancelAutoLogin();
    void onLoginResponse(const QString &cookie, const QString &email, const QString &userName);
    void onReloginResponse();

private:
    Ui::LoginWidget *ui;
    QString m_cookie = "";
    bool m_isAutoLogin = false;
    bool connectSlot();
    bool loadSettings(); // 从文件加载设置
    bool saveSettings(); // 保存设置到文件

signals:
    void setEmailAndPreviousSignal(const QString &email, const QString &previous = "loginWidget");

};

#endif // LOGINWIDGET_H
