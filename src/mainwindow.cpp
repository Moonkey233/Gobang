#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);;
    m_stackedWidget = new QStackedWidget(this);
    setCentralWidget(m_stackedWidget);

    m_socket = QSharedPointer<MyTcpSocket> (new MyTcpSocket());

    m_offlineWidget = new OfflineWidget(m_socket, m_stackedWidget);
    m_stackedWidget->addWidget(m_offlineWidget);

    m_loginWidget = new LoginWidget(m_socket, m_stackedWidget);
    m_stackedWidget->addWidget(m_loginWidget);

    m_registerWidget = new RegisterWidget(m_socket, m_stackedWidget);
    m_stackedWidget->addWidget(m_registerWidget);

    m_forgetWidget = new ForgetWidget(m_socket, m_stackedWidget);
    m_stackedWidget->addWidget(m_forgetWidget);

    m_onlineWidget = new OnlineWidget(m_socket, m_stackedWidget);
    m_stackedWidget->addWidget(m_onlineWidget);

    m_settingDialog = new SettingDialog(this);

    m_gameWidget = new GameWidget(m_socket, m_stackedWidget);
    m_stackedWidget->addWidget(m_gameWidget);

    m_indexWidget = new IndexWidget(m_socket, m_stackedWidget);
    m_stackedWidget->addWidget(m_indexWidget);

    m_infoDialog = new InfoDialog(this);
    connectSlot();

    m_stackedWidget->setCurrentWidget(m_indexWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
    m_socket.clear();
}

bool MainWindow::connectSlot() {
    connect(m_indexWidget, SIGNAL(changeWidgetSignal(const QString &)), this, SLOT(onChangeWidget(const QString &)));
    connect(m_offlineWidget, SIGNAL(changeWidgetSignal(const QString &)), this, SLOT(onChangeWidget(const QString &)));
    connect(m_loginWidget, SIGNAL(changeWidgetSignal(const QString &)), this, SLOT(onChangeWidget(const QString &)));
    connect(m_registerWidget, SIGNAL(changeWidgetSignal(const QString &)), this, SLOT(onChangeWidget(const QString &)));
    connect(m_forgetWidget, SIGNAL(changeWidgetSignal(const QString &)), this, SLOT(onChangeWidget(const QString &)));
    connect(m_onlineWidget, SIGNAL(changeWidgetSignal(const QString &)), this, SLOT(onChangeWidget(const QString &)));
    connect(m_onlineWidget, SIGNAL(setEmailAndPreviousSignal(const QString &, const QString &)),
            m_forgetWidget, SLOT(onSetEmailAndPrevious(const QString &, const QString &)));
    connect(m_loginWidget, SIGNAL(setEmailAndPreviousSignal(const QString &, const QString &)),
            m_forgetWidget, SLOT(onSetEmailAndPrevious(const QString &, const QString &)));
    connect(m_indexWidget, SIGNAL(setServerAddressSignal()), this, SLOT(onSetServerAddress()));
    connect(m_indexWidget, SIGNAL(autoLoginSignal()), m_loginWidget, SLOT(onAutoLogin()));
    connect(m_forgetWidget, SIGNAL(cancelAutoLoginSignal()), m_loginWidget, SLOT(onCancelAutoLogin()));
    connect(m_onlineWidget, SIGNAL(cancelAutoLoginSignal()), m_loginWidget, SLOT(onCancelAutoLogin()));
    connect(m_gameWidget, SIGNAL(changeWidgetSignal(const QString &)), this, SLOT(onChangeWidget(const QString &)));

    connect(m_onlineWidget, &OnlineWidget::sigInitGame, m_gameWidget, &GameWidget::onInitGame);
    connect(m_offlineWidget, &OfflineWidget::sigInitGame, m_gameWidget, &GameWidget::onInitGame);
//    connect(m_onlineWidget, &OnlineWidget::sigJoinRoom, m_gameWidget, &GameWidget::onJoinRoom);

    connect(m_socket.data(), &MyTcpSocket::sigErrorResponse, this, [this](const QString &error){
        QMessageBox::critical(this, tr("Error"), error);
    });
    connect(m_socket.data(), &MyTcpSocket::sigSendcodeResponse, this, [this](){
        QMessageBox::information(this, tr("Verification"), tr("Verification code has been sent, it's valid for three minutes."));
    });

    return true;
}

void MainWindow::onChangeWidget(const QString &widgetName) {
    if (widgetName == "offlineWidget") {
        m_stackedWidget->setCurrentWidget(m_offlineWidget);
    } else if (widgetName == "onlineWidget") {
        m_stackedWidget->setCurrentWidget(m_onlineWidget);
    } else if (widgetName == "indexWidget") {
        m_stackedWidget->setCurrentWidget(m_indexWidget);
    } else if (widgetName == "loginWidget") {
        m_stackedWidget->setCurrentWidget(m_loginWidget);
    } else if (widgetName == "registerWidget") {
        m_stackedWidget->setCurrentWidget(m_registerWidget);
    } else if (widgetName == "forgetWidget") {
        m_stackedWidget->setCurrentWidget(m_forgetWidget);
    } else if (widgetName == "settingDialog") {
        m_settingDialog->exec();
    } else if (widgetName == "gameWidget") {

        m_stackedWidget->setCurrentWidget(m_gameWidget);
    } else if (widgetName == "infoDialog") {
        m_infoDialog->show();
    }

    else {
        qDebug() << "Widget Not Found";
    }
}

void MainWindow::onSetServerAddress() {
    m_socket->setServerAddress(m_settingDialog->getServerAddress(), m_settingDialog->getServerPort());
}
