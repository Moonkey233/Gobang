#include "indexwidget.h"
#include "ui_indexwidget.h"

IndexWidget::IndexWidget(QSharedPointer<MyTcpSocket> socket, QWidget *parent) :
    MyWidget(socket, parent),
    ui(new Ui::IndexWidget)
{
    ui->setupUi(this);
    connectSlot();
}

IndexWidget::~IndexWidget()
{
    delete ui;
}

bool IndexWidget::connectSlot() {
    connect(ui->btn_offline, SIGNAL(clicked()), this, SLOT(onOfflineBtnClicked()));
    connect(ui->btn_online, SIGNAL(clicked()), this, SLOT(onOnlineBtnClicked()));
    connect(ui->btn_setting, SIGNAL(clicked()), this, SLOT(onSettingBtnClicked()));
    connect(ui->btn_info, SIGNAL(clicked()), this, SLOT(onInfoBtnClicked()));
    connect(ui->btn_exit, SIGNAL(clicked()), this, SLOT(onExitBtnClicked()));

    connect(this, &IndexWidget::sigRecv, m_socket.data(), &MyTcpSocket::recvFromServer);
    connect(this, &IndexWidget::sigSend, m_socket.data(), &MyTcpSocket::sendToServer);
    connect(this, &IndexWidget::sigConnect, m_socket.data(), &MyTcpSocket::connectToServer);

    connect(m_socket.data(), &MyTcpSocket::sigReturnConnectStatus, this, [this](ConnectStatus connectStatus){
        m_connectStatus = connectStatus;
    });

    return true;
}

void IndexWidget::onOfflineBtnClicked() {
    emit changeWidgetSignal("offlineWidget");
}

void IndexWidget::onOnlineBtnClicked() {
    m_progressDialog = new QProgressDialog("请等待...", "取消", 0, 100, this);
    m_progressDialog->setWindowModality(Qt::WindowModal);
    m_progressDialog->show();
    m_connectStatus = CONNECT_CONNECTING;
    m_socket->closeSocket();
    emit setServerAddressSignal();
    emit sigConnect();

    QtConcurrent::run([this](){
        while(m_connectStatus == CONNECT_CONNECTING);
        if(m_connectStatus == CONNECT_SUCCESS){
            emit changeWidgetSignal("loginWidget");
            emit autoLoginSignal();
        } else if (m_connectStatus == CONNECT_FAIL) {
            QMetaObject::invokeMethod(this, "showErrorMessage", Qt::QueuedConnection, Q_ARG(QString, "服务器连接错误, 请确保服务器地址端口正确并已开启监听"));
        }
        QMetaObject::invokeMethod(m_progressDialog, "close", Qt::QueuedConnection);
        qDebug() << "Quit connect";
    });
}

void IndexWidget::showErrorMessage(QString message) {
    QMessageBox::critical(this, tr("Error"), message);
}

void IndexWidget::onSettingBtnClicked() {
    emit changeWidgetSignal("settingDialog");
}

void IndexWidget::onInfoBtnClicked() {
    emit changeWidgetSignal("infoDialog");
}

void IndexWidget::onExitBtnClicked() {
    QApplication::quit();
}
