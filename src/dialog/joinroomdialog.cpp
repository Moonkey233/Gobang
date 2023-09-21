#include "joinroomdialog.h"
#include "ui_joinroomdialog.h"

JoinRoomDialog::JoinRoomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JoinRoomDialog)
{
    ui->setupUi(this);

    connect(ui->btn_join, &QPushButton::clicked, this, &JoinRoomDialog::onJoinBtnClicked);
    connect(ui->btn_cancel, &QPushButton::clicked, this, &JoinRoomDialog::onCancelBtnClicked);
}

JoinRoomDialog::~JoinRoomDialog()
{
    delete ui;
}

void JoinRoomDialog::onJoinBtnClicked() {
    emit sigJoinRoom(ui->lineEdit_roomId->text().replace(" ", "_").replace("&","_").replace("=", "_"));
    this->close();
}

void JoinRoomDialog::onCancelBtnClicked() {
    this->close();
}
