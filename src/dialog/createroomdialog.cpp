#include "createroomdialog.h"
#include "ui_createroomdialog.h"

CreateRoomDialog::CreateRoomDialog(const QString &userName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateRoomDialog)
{
    ui->setupUi(this);
    ui->lineEdit_name->setText(userName);
    ui->radioButton_black->setChecked(true);
    ui->checkBox_public->setChecked(true);

    connect(ui->btn_create, &QPushButton::clicked, this, &CreateRoomDialog::onCreateBtnClicked);
    connect(ui->btn_cancel, &QPushButton::clicked, this, &CreateRoomDialog::onCancelBtnClicked);
}

CreateRoomDialog::~CreateRoomDialog()
{
    delete ui;
}

void CreateRoomDialog::onCreateBtnClicked() {
    QString type = ui->radioButton_black->isChecked() ? "black" : "white";
    QString isPublic = ui->checkBox_public->isChecked() ? "true" : "false";
    emit sigCreateRoom(ui->lineEdit_name->text().replace(" ", "_").replace("&","_").replace("=", "_"), type, isPublic);
    this->close();
}

void CreateRoomDialog::onCancelBtnClicked() {
    this->close();
}
