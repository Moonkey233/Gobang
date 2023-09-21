#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <QHostAddress>
#include <QRegularExpression>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDir>
#include "../tool/config.h"

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = nullptr);
    ~SettingDialog();
    const QString getServerAddress();
    const QString getServerPort();

private:
    Ui::SettingDialog *ui;
    bool loadSettings(); // 从文件加载设置
    bool saveSettings(); // 保存设置到文件
    bool isValidAddress(const QString &address);

private slots:
    void onCustomDepthBtnToggled(bool isChecked);
    void onCustomTimeBtnToggled(bool isChecked);
    void onDefaultBtnClicked();
    void onConfirmBtnClicked();

};

#endif // SETTINGDIALOG_H
