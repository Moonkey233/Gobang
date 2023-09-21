#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QSocketNotifier>
#include "mywidget.h"
#include "boardwidget.h"
#include "../tool/player.h"

namespace Ui {
class GameWidget;
}

class GameWidget : public MyWidget
{
    Q_OBJECT

public:
    GameWidget(QSharedPointer<MyTcpSocket> socket, QWidget *parent = nullptr);
    ~GameWidget();

protected:
    virtual bool connectSlot() override;
    virtual void resizeEvent(QResizeEvent *event) override;
    bool switchPlayer();

private:
    Ui::GameWidget *ui;
    BoardWidget *m_boardWidget = nullptr;
    Player *m_player1 = nullptr;
    Player *m_player2 = nullptr;
    Player *m_currentPlayer = nullptr;
    GameType m_gameType = GAME_HOTSEAT;
    QString m_roomId;
    QString m_roomName;
    QString m_rivalName;

public slots:
    void onMouseRelease(QPoint point);
    void onMakeMove(ChessPieceInfo piece);
    void onSetpieceResponse(ChessPieceInfo piece);
    void onInitGame(Player *player1, Player *player2, GameType gameType, const QString &roomId, const QString &roomName, const QString &rivalName);

signals:

};

#endif // GAMEWIDGET_H
