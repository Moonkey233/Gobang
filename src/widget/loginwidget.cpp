#include "loginwidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget(QSharedPointer<MyTcpSocket> socket, QWidget *parent) :
    MyWidget(socket, parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
    connectSlot();
    loadSettings();
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::onLoginResponse(const QString &cookie, const QString &email, const QString &userName) {
    m_cookie = cookie;
    saveSettings();
    m_socket->setCookie(m_cookie);
    m_socket->setUserName(userName);
    m_socket->setEmail(email);
    emit changeWidgetSignal("onlineWidget");
}

void LoginWidget::onReloginResponse() {
    QMessageBox::information(this, tr("Relogin"), tr("Cookie auto login is out of date, please relogin."));
}

bool LoginWidget::connectSlot() {
    connect(ui->btn_forget, SIGNAL(clicked()), this, SLOT(onForgetBtnClicked()));
    connect(ui->btn_login, SIGNAL(clicked()), this, SLOT(onLoginBtnClicked()));
    connect(ui->btn_register, SIGNAL(clicked()), this, SLOT(onRegisterBtnClicked()));
    connect(ui->btn_return, SIGNAL(clicked()), this, SLOT(onReturnBtnClicked()));

    connect(m_socket.data(), &MyTcpSocket::sigLoginResponse, this, &LoginWidget::onLoginResponse);
    connect(m_socket.data(), &MyTcpSocket::sigReloginResponse, this, &LoginWidget::onReloginResponse);

    return true;
}

void LoginWidget::onForgetBtnClicked() {
    emit setEmailAndPreviousSignal(ui->lineEdit_userName->text(), "loginWidget");
    emit changeWidgetSignal("forgetWidget");
}

void LoginWidget::onLoginBtnClicked() {
    QString userName = ui->lineEdit_userName->text();
    QString password = ui->lineEdit_password->text();
    if(userName == "" || password == ""){
        qDebug() << "empty";
        return;
    }

    QString message = "username=" + userName + "&password=" + password;
    m_socket->sendToServer(m_socket->sign("LOGIN", message, SIGN_KEY));
}

void LoginWidget::onRegisterBtnClicked() {
    emit changeWidgetSignal("registerWidget");
}

void LoginWidget::onReturnBtnClicked() {
    m_socket->closeSocket();
    emit changeWidgetSignal("indexWidget");
}

void LoginWidget::onAutoLogin() {
    if (m_isAutoLogin){
        m_socket->sendToServer(m_socket->sign("AUTOLOGIN", "cookie=" + m_cookie, SIGN_KEY));
    }
}

bool LoginWidget::loadSettings() {
    QDir dir;
    if (!dir.exists("data")) {
        dir.mkdir("data");
    }
    QFile file("data/settings.json");
    if (file.open(QIODevice::ReadOnly))
    {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll());
        QJsonObject jsonObj = jsonDoc.object();

        if (jsonObj.contains("cookie")) {
            m_cookie = jsonObj["cookie"].toString();
            // 从 JSON 对象中读取设置值
            if (jsonObj.contains("isAutoLogin")) {
                if(jsonObj["isAutoLogin"].toBool()) {
                    ui->checkBox_autoLogin->setChecked(true);
                    m_isAutoLogin = true;
                }
            }
        }
        file.close();
    } else {
        return false;
    }
    return true;
}

bool LoginWidget::saveSettings() {
    QDir dir;
    if (!dir.exists("data")) {
        dir.mkdir("data");
    }
    QFile file("data/settings.json");
    if (file.open(QIODevice::ReadWrite))
    {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll());
        QJsonObject jsonObj = jsonDoc.object();

        jsonObj.insert("cookie", m_cookie);
        jsonObj.insert("isAutoLogin", ui->checkBox_autoLogin->isChecked());

        jsonDoc.setObject(jsonObj);
        file.resize(0);
        file.write(jsonDoc.toJson());
        file.close();
    } else {
        return false;
    }
    return true;
}

void LoginWidget::onCancelAutoLogin() {
    m_cookie = "";
    m_isAutoLogin = false;
    m_socket->setCookie("");
    ui->checkBox_autoLogin->setChecked(false);
    saveSettings();
}
