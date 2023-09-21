#include "offlinewidget.h"
#include "ui_offlinewidget.h"

OfflineWidget::OfflineWidget(QSharedPointer<MyTcpSocket> socket, QWidget *parent) :
    MyWidget(socket, parent),
    ui(new Ui::OfflineWidget)
{
    ui->setupUi(this);
    connectSlot();
}

OfflineWidget::~OfflineWidget()
{
    delete ui;
}

bool OfflineWidget::connectSlot() {
    connect(ui->btn_ai_first, SIGNAL(clicked()), this, SLOT(onAiFirstBtnClicked()));
    connect(ui->btn_human_first, SIGNAL(clicked()), this, SLOT(onHumanFirstBtnClicked()));
    connect(ui->btn_hotseat, SIGNAL(clicked()), this, SLOT(onHotseatBtnClicked()));
    connect(ui->btn_return, SIGNAL(clicked()), this, SLOT(onReturnBtnClicked()));

    return true;
}

void OfflineWidget::onAiFirstBtnClicked() {
    qDebug() << "onAiFirstBtnClicked";
}

void OfflineWidget::onHumanFirstBtnClicked() {
    qDebug() << "onHumanFirstBtnClicked";
}

void OfflineWidget::onHotseatBtnClicked() {
    PlayerLocal *player1 = new PlayerLocal(CHESS_BLACK);
    PlayerLocal *player2 = new PlayerLocal(CHESS_WHITE);
    emit sigInitGame(player1, player2, GAME_HOTSEAT, "-1", tr("Hotseat Room"), "Hotseat");

    emit changeWidgetSignal("gameWidget");
}

void OfflineWidget::onReturnBtnClicked() {
    emit changeWidgetSignal("indexWidget");
}
