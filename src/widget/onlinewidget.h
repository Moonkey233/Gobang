#ifndef ONLINEWIDGET_H
#define ONLINEWIDGET_H

#include "mywidget.h"
#include "../tool/player.h"
#include "../tool/config.h"
#include "../tool/mychess.h"
#include "../dialog/createroomdialog.h"
#include "../dialog/joinroomdialog.h"

namespace Ui {
class OnlineWidget;
}

class OnlineWidget : public MyWidget
{
    Q_OBJECT

public:
    OnlineWidget(QSharedPointer<MyTcpSocket> socket, QWidget *parent = nullptr);
    ~OnlineWidget();

private slots:
    void onMatchBtnClicked();
    void onRankBtnClicked();
    void onCreateBtnClicked();
    void onJoinBtnClicked();
    void onHistoryBtnClicked();
    void onSettingBtnClicked();
    void onChangeBtnClicked();
    void onLogoutBtnClicked();
    void onExitBtnClicked();

    void onJoinResponse(const QString &roomId, const QString &roomName, const QString &rival, const ChessType &chessType);

private:
    Ui::OnlineWidget *ui;
    CreateRoomDialog *m_createRoomDialog = nullptr;
    JoinRoomDialog *m_joinRoomDialog = nullptr;
//    QString m_userName = "";
//    QString m_email = "";
    bool connectSlot();

signals:
    void setEmailAndPreviousSignal(const QString &email, const QString &previous = "loginWidget");
    void cancelAutoLoginSignal();
    void sigInitGame(Player *player1, Player *player2, GameType gameType, const QString &roomId, const QString &roomName, const QString &rivalName);

};

#endif // ONLINEWIDGET_H
