#include "onlinewidget.h"
#include "ui_onlinewidget.h"

OnlineWidget::OnlineWidget(QSharedPointer<MyTcpSocket> socket, QWidget *parent) :
    MyWidget(socket, parent),
    ui(new Ui::OnlineWidget)
{
    ui->setupUi(this);
    connectSlot();
}

OnlineWidget::~OnlineWidget()
{
    delete ui;
}

bool OnlineWidget::connectSlot() {
    connect(ui->btn_match, SIGNAL(clicked()), this, SLOT(onMatchBtnClicked()));
    connect(ui->btn_rank, SIGNAL(clicked()), this, SLOT(onRankBtnClicked()));
    connect(ui->btn_history, SIGNAL(clicked()), this, SLOT(onHistoryBtnClicked()));
    connect(ui->btn_create, SIGNAL(clicked()), this, SLOT(onCreateBtnClicked()));
    connect(ui->btn_join, SIGNAL(clicked()), this, SLOT(onJoinBtnClicked()));
    connect(ui->btn_change, SIGNAL(clicked()), this, SLOT(onChangeBtnClicked()));
    connect(ui->btn_setting, SIGNAL(clicked()), this, SLOT(onSettingBtnClicked()));
    connect(ui->btn_logout, SIGNAL(clicked()), this, SLOT(onLogoutBtnClicked()));
    connect(ui->btn_exit, SIGNAL(clicked()), this, SLOT(onExitBtnClicked()));

    connect(m_socket.data(), &MyTcpSocket::sigJoinResponse, this, &OnlineWidget::onJoinResponse);

    return true;
}

void OnlineWidget::onJoinResponse(const QString &roomId, const QString &roomName, const QString &rival, const ChessType &chessType) {
    PlayerLocal *player1 = new PlayerLocal(chessType);
    PlayerRemote *player2 = new PlayerRemote(chessType == CHESS_BLACK ? CHESS_WHITE : CHESS_BLACK);
    emit sigInitGame(player1, player2, GAME_ONLINE, roomId, roomName, rival);

    emit changeWidgetSignal("gameWidget");
}

void OnlineWidget::onMatchBtnClicked(){
    qDebug() << "match";

    PlayerLocal *player1 = new PlayerLocal(CHESS_BLACK);
    PlayerRemote *player2 = new PlayerRemote(CHESS_WHITE);
    emit sigInitGame(player1, player2, GAME_ONLINE, "online", "online", "online"); //1111111111111111111111111111111111111111

    emit changeWidgetSignal("gameWidget");
}

void OnlineWidget::onRankBtnClicked(){
    qDebug() << "rank";
}

void OnlineWidget::onCreateBtnClicked(){
    m_createRoomDialog = new CreateRoomDialog(m_socket->getUserName(), this);
    connect(m_createRoomDialog, &CreateRoomDialog::sigCreateRoom, this, [this](const QString &roomName, const QString &chessType, const QString &isPublic){
        m_socket->sendToServer(m_socket->sign("CREATE", "roomname=" + roomName + "&chesstype=" + chessType + "&public=" + isPublic, SIGN_KEY));
        disconnect(m_createRoomDialog, &CreateRoomDialog::sigCreateRoom, this, nullptr);
    });
    m_createRoomDialog->exec();
}

void OnlineWidget::onJoinBtnClicked(){
    m_joinRoomDialog = new JoinRoomDialog(this);
    connect(m_joinRoomDialog, &JoinRoomDialog::sigJoinRoom, this, [this](const QString &roomId){
        m_socket->sendToServer(m_socket->sign("JOIN", "roomid=" + roomId + "&username=" + m_socket->getUserName(), SIGN_KEY));
        disconnect(m_joinRoomDialog, &JoinRoomDialog::sigJoinRoom, this, nullptr);
    });
    m_joinRoomDialog->exec();
}

void OnlineWidget::onHistoryBtnClicked(){
    qDebug() << "history";
}

void OnlineWidget::onSettingBtnClicked(){
    emit changeWidgetSignal("settingDialog");
}

void OnlineWidget::onChangeBtnClicked(){
    emit setEmailAndPreviousSignal(m_socket->getEmail(), "onlineWidget");
    emit changeWidgetSignal("forgetWidget");
}

void OnlineWidget::onLogoutBtnClicked(){
    emit cancelAutoLoginSignal();
    emit changeWidgetSignal("loginWidget");
}

void OnlineWidget::onExitBtnClicked(){
    QApplication::quit();
}
