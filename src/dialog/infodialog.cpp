#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
    connect(ui->btn_confirm, SIGNAL(clicked()), this, SLOT(onConfirmBtnClicked()));
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::onConfirmBtnClicked() {
    this->close();
}
