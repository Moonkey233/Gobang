#include "registerwidget.h"
#include "ui_registerwidget.h"

RegisterWidget::RegisterWidget(QSharedPointer<MyTcpSocket> socket, QWidget *parent) :
    MyWidget(socket, parent),
    ui(new Ui::RegisterWidget)
{
    ui->setupUi(this);
    connectSlot();
}

RegisterWidget::~RegisterWidget()
{
    delete ui;
}

bool RegisterWidget::connectSlot() {
    connect(ui->btn_send, SIGNAL(clicked()), this, SLOT(onSendBtnClicked()));
    connect(ui->btn_register, SIGNAL(clicked()), this, SLOT(onRegisterBtnClicked()));
    connect(ui->btn_return, SIGNAL(clicked()), this, SLOT(onReturnBtnClicked()));
    connect(m_socket.data(), &MyTcpSocket::sigRegisterResponse, this, &RegisterWidget::onRegisterResponse);

    return true;
}

void RegisterWidget::onRegisterResponse() {
    QMessageBox::information(this, tr("Success"), tr("Register successfully, please login."));
    emit changeWidgetSignal("loginWidget");
}

void RegisterWidget::onSendBtnClicked() {
    QString email = ui->lineEdit_email->text();

    QRegularExpression emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    if (!emailRegex.match(email).hasMatch() || email == "") {
        qDebug() << "email error";
        return;
    }
    m_socket->sendToServer(m_socket->sign("SENDCODE", email, SIGN_KEY));
}

void RegisterWidget::onRegisterBtnClicked() {
    QString email = ui->lineEdit_email->text();
    QString userName = ui->lineEdit_userName->text();
    QString password = ui->lineEdit_password->text();
    QString confirmPassword = ui->lineEdit_confirm_password->text();
    QString verifyCode = ui->lineEdit_code->text();

    if(userName == ""){
        qDebug() << "empty";
        return;
    } else if (userName.length() > 32) {
        qDebug() << "username too long";
    }
    if(email == ""){
        qDebug() << "empty";
        return;
    } else if (email.length() > 32) {
        qDebug() << "email too long";
    }
    if(password == ""){
        qDebug() << "empty";
        return;
    }
    if(verifyCode == ""){
        qDebug() << "empty";
        return;
    }

    if(password.length() < 6 || password.contains('&') || password.contains('=') || password.contains(' ')){
        qDebug() << "password error";
        return;
    }
    if(userName[0] >= '0' && userName[0] <= '9') {
        qDebug() << "name error";
        return;
    }
    QRegularExpression emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    if (!emailRegex.match(email).hasMatch()) {
        qDebug() << "mail error";
        return;
    }

    if (password == confirmPassword) {
        QString message = "email=" + email + "&username=" + userName + "&password=" + password + "&verifycode=" + verifyCode;
        m_socket->sendToServer(m_socket->sign("REGISTER", message, SIGN_KEY));
    } else {
        qDebug() << "confrimPassword error";
    }
}

void RegisterWidget::onReturnBtnClicked() {
    emit changeWidgetSignal("loginWidget");
}
