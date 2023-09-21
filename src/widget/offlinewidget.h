#ifndef OFFLINEWIDGET_H
#define OFFLINEWIDGET_H

#include "mywidget.h"
#include "../tool/player.h"

namespace Ui {
class OfflineWidget;
}

class OfflineWidget : public MyWidget
{
    Q_OBJECT

public:
    OfflineWidget(QSharedPointer<MyTcpSocket> socket, QWidget *parent = nullptr);
    ~OfflineWidget();

private slots:
    void onAiFirstBtnClicked();
    void onHumanFirstBtnClicked();
    void onHotseatBtnClicked();
    void onReturnBtnClicked();

private:
    Ui::OfflineWidget *ui;
    bool connectSlot();

Q_SIGNALS:
    void sigInitGame(Player *player1, Player *player2, GameType gameType, const QString &roomId, const QString &roomName, const QString &rivalName);

};

#endif // OFFLINEWIDGET_H
