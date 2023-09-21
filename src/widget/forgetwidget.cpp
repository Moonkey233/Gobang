#include "forgetwidget.h"
#include "ui_forgetwidget.h"

ForgetWidget::ForgetWidget(QSharedPointer<MyTcpSocket> socket, QWidget *parent) :
    MyWidget(socket, parent),
    ui(new Ui::ForgetWidget)
{
    ui->setupUi(this);
    connectSlot();
}

void ForgetWidget::onSetEmailAndPrevious(const QString &email, const QString &previous) {
    ui->lineEdit_userName->setText(email);
    m_previous = previous;
}

ForgetWidget::~ForgetWidget()
{
    delete ui;
}

void ForgetWidget::onPasswordResponse() {
    QMessageBox::information(this, tr("Success"), tr("Password was changed, please relogin."));
    emit cancelAutoLoginSignal();
    emit changeWidgetSignal("loginWidget");
}

bool ForgetWidget::connectSlot() {
    connect(ui->btn_send, SIGNAL(clicked()), this, SLOT(onSendBtnClicked()));
    connect(ui->btn_change, SIGNAL(clicked()), this, SLOT(onChangeBtnClicked()));
    connect(ui->btn_return, SIGNAL(clicked()), this, SLOT(onReturnBtnClicked()));
    connect(m_socket.data(), &MyTcpSocket::sigPasswordResponse, this, &ForgetWidget::onPasswordResponse);

    return true;
}

void ForgetWidget::onSendBtnClicked() {
    QString email = ui->lineEdit_userName->text();

    QRegularExpression emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    if (!emailRegex.match(email).hasMatch() || email == "") {
        qDebug() << "email error";
        return;
    }

    m_socket->sendToServer(m_socket->sign("SENDCODE", email, SIGN_KEY));
}

void ForgetWidget::onChangeBtnClicked() {
    QString email = ui->lineEdit_userName->text();
    QString password = ui->lineEdit_password->text();
    QString confirmPassword = ui->lineEdit_confirm_password->text();
    QString verifyCode = ui->lineEdit_code->text();

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
    QRegularExpression emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    if (!emailRegex.match(email).hasMatch()) {
        qDebug() << "mail error";
        return;
    }

    if (password != confirmPassword) {
        qDebug() << "confirmPassword error";
        return;
    }

    QString message = "email=" + email + "&password=" + password + "&verifycode=" + verifyCode;
    m_socket->sendToServer(m_socket->sign("PASSWORD", message, SIGN_KEY));
}

void ForgetWidget::onReturnBtnClicked() {
    emit changeWidgetSignal(m_previous);
}
