#include "gamewidget.h"
#include "ui_gamewidget.h"

GameWidget::GameWidget(QSharedPointer<MyTcpSocket> socket, QWidget *parent) :
    MyWidget(socket, parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);
    m_boardWidget = new BoardWidget(this);
}

GameWidget::~GameWidget()
{
    delete ui;
    delete m_player1;
    delete m_player2;

}

bool GameWidget::connectSlot() {
    connect(m_boardWidget, &BoardWidget::sigMouseRelease, this, &GameWidget::onMouseRelease);
    connect(m_player1, &Player::sigMakeMove, this, &GameWidget::onMakeMove);
    connect(m_player2, &Player::sigMakeMove, this, &GameWidget::onMakeMove);
    connect(m_socket.data(), &MyTcpSocket::sigSetpieceResponse, this, &GameWidget::onSetpieceResponse);

    return true;
}

void GameWidget::resizeEvent(QResizeEvent *event)
{
    QSize newSize = event->size();
    int newBoardSize = newSize.width() > newSize.height() ? newSize.height() : newSize.width();
    m_boardWidget->resize(newBoardSize * 640 / 720, newBoardSize * 640 / 720.0);
    m_boardWidget->move(newBoardSize * 40 / 720.0, newBoardSize * 40 / 720.0);
}

void GameWidget::onMouseRelease(QPoint point) {
    if(m_currentPlayer->getPlayerType() == "PlayerLocal") {
        m_currentPlayer->makeMove(point);
    } else {
        qDebug() << "Not your turn.";
    }
}

void GameWidget::onMakeMove(ChessPieceInfo piece) {
    if (m_boardWidget->isValid(piece)) {
        m_boardWidget->makeMove(piece);
        if (m_gameType == GAME_ONLINE && m_currentPlayer == m_player1) {
            QString row = QString::number(piece.row);
            QString col = QString::number(piece.col);
            QString type = piece.type == CHESS_BLACK ? "BLACK" : "WHITE";
            m_socket->sendToServer(m_socket->sign("SETPIECE", "row=" + row + "&col=" + col + "&type=" + type + "&roomid=" + m_roomId, SIGN_KEY));
        }
        switchPlayer();
    } else {
        qDebug() << "Invalid Move.";
    }
}

void GameWidget::onInitGame(Player *player1, Player *player2, GameType gameType, const QString &roomId, const QString &roomName, const QString &rivalName) {
    m_player1= player1;
    m_player2 = player2;
    m_roomId = roomId;
    m_roomName = roomName;
    m_rivalName = rivalName != "null" ? rivalName : tr("Waiting to join...");
    m_currentPlayer = m_player1->getChessType() == CHESS_BLACK ? m_player1 : m_player2;
    m_gameType = gameType;
    connectSlot();
}

void GameWidget::onSetpieceResponse(ChessPieceInfo piece) {
    if (m_currentPlayer->getPlayerType() == "PlayerRemote" && m_currentPlayer->getChessType() == piece.type) {
        m_currentPlayer->makeMove(QPoint(piece.row, piece.col));
    }
}

bool GameWidget::switchPlayer() {
    m_currentPlayer = m_currentPlayer == m_player1 ? m_player2 : m_player1;
    return true;
}

