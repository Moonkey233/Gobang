#include "settingdialog.h"
#include "ui_settingdialog.h"

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    connect(ui->btn_confirm, SIGNAL(clicked()), this, SLOT(onConfirmBtnClicked()));
    connect(ui->btn_default, SIGNAL(clicked()), this, SLOT(onDefaultBtnClicked()));
    connect(ui->radioButton_custom_depth, SIGNAL(toggled(bool)), this, SLOT(onCustomDepthBtnToggled(bool)));
    connect(ui->radioButton_custom_time, SIGNAL(toggled(bool)), this, SLOT(onCustomTimeBtnToggled(bool)));

    loadSettings();
}

SettingDialog::~SettingDialog()
{
    delete ui;
}

void SettingDialog::onDefaultBtnClicked() {
    ui->lineEdit_address->setText(DEFAULT_HOST);
    ui->lineEdit_port->setText(DEFAULT_PORT);
    ui->radioButton_normal->setChecked(true);
    ui->checkBox_forbidden->setChecked(false);
    ui->slider_volume->setValue(50);
    ui->lineEdit_custom->setText("10");
}

void SettingDialog::onConfirmBtnClicked() {
    QString serverAddress = ui->lineEdit_address->text();
    QString serverPort = ui->lineEdit_port->text();
    bool isEasy = ui->radioButton_easy->isChecked();
    bool isAmateur = ui->radioButton_amateur->isChecked();
    bool isNormal = ui->radioButton_normal->isChecked();
    bool isDepth = ui->radioButton_custom_depth->isChecked();
    bool isTime = ui->radioButton_custom_time->isChecked();
    QString custom = ui->lineEdit_custom->text();

    if(serverAddress == "" ||
            serverPort == "" ||
            (!isEasy && !isAmateur && !isNormal && !isDepth && !isTime) ||
            ((isDepth || isTime) && custom == "")) {
        qDebug() << "empty";
        return;
    }

    if (!isValidAddress(serverAddress) && serverAddress.toLower() != "localhost") {
        qDebug() << "InvalidAddress";
        return;
    }

    bool ok;
    int intValue = serverPort.toInt(&ok);
    if (!ok || QString::number(intValue) != serverPort) {
        qDebug() << "port must number";
        return;
    }

    if(isDepth || isTime) {
        intValue = custom.toInt(&ok);
        if (!ok || QString::number(intValue) != custom) {
            qDebug() << "depth or time must number";
            return;
        } else if ((isDepth && (intValue % 2 != 0 || intValue > 100 || intValue < 2)) || (isTime && intValue < 5)) {
            qDebug() << "depth must even and smaller than 100 bigger than 2, time must bigger than 5";
            return;
        }
    }

    saveSettings();
    this->close();
}

const QString SettingDialog::getServerAddress() {
    return ui->lineEdit_address->text();
}

const QString SettingDialog::getServerPort() {
    return ui->lineEdit_port->text();
}

void SettingDialog::onCustomDepthBtnToggled(bool isChecked)
{
    if (isChecked) {
        ui->label_custom->setText("Depth Limit(layer):");
        ui->label_custom->setEnabled(true);
        ui->lineEdit_custom->setEnabled(true);
    } else {
        ui->label_custom->setEnabled(ui->radioButton_custom_time->isChecked());
        ui->lineEdit_custom->setEnabled(ui->radioButton_custom_time->isChecked());
    }
}

void SettingDialog::onCustomTimeBtnToggled(bool isChecked)
{
    if (isChecked) {
        ui->label_custom->setText("Time Limit(sec):");
        ui->label_custom->setEnabled(true);
        ui->lineEdit_custom->setEnabled(true);
    } else {
        ui->label_custom->setEnabled(ui->radioButton_custom_depth->isChecked());
        ui->lineEdit_custom->setEnabled(ui->radioButton_custom_depth->isChecked());
    }
}

bool SettingDialog::loadSettings() {
    QDir dir;
    if (!dir.exists("data")) {
        dir.mkdir("data");
    }
    QFile file("data/settings.json");
    if (file.open(QIODevice::ReadOnly))
    {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll());
        QJsonObject jsonObj = jsonDoc.object();

        // 从 JSON 对象中读取设置值
        if (jsonObj.contains("serverAddress")) {
            ui->lineEdit_address->setText(jsonObj["serverAddress"].toString());
        } else {
            ui->lineEdit_address->setText("Moonkey233.top");
        }

        if (jsonObj.contains("serverPort")) {
            ui->lineEdit_port->setText(jsonObj["serverPort"].toString());
        } else {
            ui->lineEdit_port->setText(DEFAULT_PORT);
        }

        if (jsonObj.contains("isForbidden")) {
            if(jsonObj["isForbidden"].toString() == "true") {
                ui->checkBox_forbidden->setChecked(true);
            } else {
                ui->checkBox_forbidden->setChecked(false);
            }
        } else {
            ui->checkBox_forbidden->setChecked(false);
        }

        if (jsonObj.contains("volume")) {
            ui->slider_volume->setValue(jsonObj["volume"].toInt());
        } else {
            ui->slider_volume->setRange(0, 100);
            ui->slider_volume->setValue(50);
        }

        ui->lineEdit_custom->setText("10");
        if (jsonObj.contains("difficulty")) {
            if(jsonObj["difficulty"].toInt() == 1) {
                ui->radioButton_easy->setChecked(true);
            } else if(jsonObj["difficulty"].toInt() == 2) {
                ui->radioButton_amateur->setChecked(true);
            } else if(jsonObj["difficulty"].toInt() == 3) {
                ui->radioButton_normal->setChecked(true);
            } else if(jsonObj["difficulty"].toInt() > 3 && jsonObj["difficulty"].toInt() < 500) {
                ui->radioButton_custom_depth->setChecked(true);
                int depth = jsonObj["difficulty"].toInt() % 100;
                ui->lineEdit_custom->setText(QString::number(depth));
            } else if(jsonObj["difficulty"].toInt() > 500) {
                ui->radioButton_custom_time->setChecked(true);
                int time = jsonObj["difficulty"].toInt() - 500;
                ui->lineEdit_custom->setText(QString::number(time));
            }
        } else {
            ui->radioButton_normal->setChecked(true);
        }

        file.close();
        return true;
    } else {
        ui->lineEdit_address->setText(DEFAULT_HOST);
        ui->lineEdit_port->setText(DEFAULT_PORT);
        ui->radioButton_normal->setChecked(true);
        ui->checkBox_forbidden->setChecked(false);
        ui->slider_volume->setValue(50);
        ui->lineEdit_custom->setText("10");
        return false;
    }
}

bool SettingDialog::saveSettings() {
    QDir dir;
    if (!dir.exists("data")) {
        dir.mkdir("data");
    }
    QFile file("data/settings.json");
    if (file.open(QIODevice::ReadWrite))
    {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll());
        QJsonObject jsonObj = jsonDoc.object();
        jsonObj.insert("serverAddress", ui->lineEdit_address->text());
        jsonObj.insert("serverPort", ui->lineEdit_port->text());
        jsonObj.insert("isForbidden", ui->checkBox_forbidden->isChecked());
        jsonObj.insert("volume", ui->slider_volume->value());
        if (ui->radioButton_easy->isChecked()) {
            jsonObj.insert("difficulty", 1);
        } else if (ui->radioButton_amateur->isChecked()) {
            jsonObj.insert("difficulty", 2);
        } else if (ui->radioButton_normal->isChecked()) {
            jsonObj.insert("difficulty", 3);
        } else if (ui->radioButton_custom_depth->isChecked()) {
            jsonObj.insert("difficulty", 400 + ui->lineEdit_custom->text().toInt());
        } else if (ui->radioButton_custom_time->isChecked()) {
            jsonObj.insert("difficulty", 500 + ui->lineEdit_custom->text().toInt());
        }

        jsonDoc.setObject(jsonObj);
        file.resize(0);
        file.write(jsonDoc.toJson());
        file.close();
        return true;
    } else {
        return false;
    }
}

bool SettingDialog::isValidAddress(const QString &address) {
    QHostAddress serverAddress(address);
    QRegularExpression regex("^[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    QRegularExpressionMatch match = regex.match(address);
    return (match.hasMatch() || serverAddress.protocol() != QAbstractSocket::UnknownNetworkLayerProtocol);
}
