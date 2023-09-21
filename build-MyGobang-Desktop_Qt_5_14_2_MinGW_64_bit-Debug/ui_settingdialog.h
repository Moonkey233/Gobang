/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_SettingDialog
{
public:
    QPushButton *btn_default;
    QPushButton *btn_confirm;
    QLabel *label_address;
    QLineEdit *lineEdit_address;
    QLabel *label_port;
    QLineEdit *lineEdit_port;
    QRadioButton *radioButton_easy;
    QRadioButton *radioButton_amateur;
    QRadioButton *radioButton_normal;
    QRadioButton *radioButton_custom_depth;
    QRadioButton *radioButton_custom_time;
    QLabel *label_custom;
    QLineEdit *lineEdit_custom;
    QCheckBox *checkBox_forbidden;
    QLabel *label_volume;
    QSlider *slider_volume;

    void setupUi(QDialog *SettingDialog)
    {
        if (SettingDialog->objectName().isEmpty())
            SettingDialog->setObjectName(QString::fromUtf8("SettingDialog"));
        SettingDialog->resize(800, 600);
        btn_default = new QPushButton(SettingDialog);
        btn_default->setObjectName(QString::fromUtf8("btn_default"));
        btn_default->setGeometry(QRect(520, 510, 100, 50));
        btn_default->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_confirm = new QPushButton(SettingDialog);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));
        btn_confirm->setGeometry(QRect(650, 510, 100, 50));
        btn_confirm->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        label_address = new QLabel(SettingDialog);
        label_address->setObjectName(QString::fromUtf8("label_address"));
        label_address->setGeometry(QRect(30, 30, 241, 51));
        label_address->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        lineEdit_address = new QLineEdit(SettingDialog);
        lineEdit_address->setObjectName(QString::fromUtf8("lineEdit_address"));
        lineEdit_address->setGeometry(QRect(290, 30, 301, 41));
        lineEdit_address->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        label_port = new QLabel(SettingDialog);
        label_port->setObjectName(QString::fromUtf8("label_port"));
        label_port->setGeometry(QRect(30, 110, 231, 51));
        label_port->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        lineEdit_port = new QLineEdit(SettingDialog);
        lineEdit_port->setObjectName(QString::fromUtf8("lineEdit_port"));
        lineEdit_port->setGeometry(QRect(290, 110, 301, 41));
        lineEdit_port->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        radioButton_easy = new QRadioButton(SettingDialog);
        radioButton_easy->setObjectName(QString::fromUtf8("radioButton_easy"));
        radioButton_easy->setGeometry(QRect(170, 210, 151, 21));
        radioButton_easy->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        radioButton_amateur = new QRadioButton(SettingDialog);
        radioButton_amateur->setObjectName(QString::fromUtf8("radioButton_amateur"));
        radioButton_amateur->setGeometry(QRect(170, 250, 141, 21));
        radioButton_amateur->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        radioButton_normal = new QRadioButton(SettingDialog);
        radioButton_normal->setObjectName(QString::fromUtf8("radioButton_normal"));
        radioButton_normal->setGeometry(QRect(170, 290, 115, 19));
        radioButton_normal->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        radioButton_custom_depth = new QRadioButton(SettingDialog);
        radioButton_custom_depth->setObjectName(QString::fromUtf8("radioButton_custom_depth"));
        radioButton_custom_depth->setGeometry(QRect(360, 200, 151, 19));
        radioButton_custom_depth->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        radioButton_custom_time = new QRadioButton(SettingDialog);
        radioButton_custom_time->setObjectName(QString::fromUtf8("radioButton_custom_time"));
        radioButton_custom_time->setGeometry(QRect(360, 240, 181, 19));
        radioButton_custom_time->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        label_custom = new QLabel(SettingDialog);
        label_custom->setObjectName(QString::fromUtf8("label_custom"));
        label_custom->setGeometry(QRect(350, 270, 201, 51));
        label_custom->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        lineEdit_custom = new QLineEdit(SettingDialog);
        lineEdit_custom->setObjectName(QString::fromUtf8("lineEdit_custom"));
        lineEdit_custom->setGeometry(QRect(570, 280, 101, 41));
        lineEdit_custom->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        checkBox_forbidden = new QCheckBox(SettingDialog);
        checkBox_forbidden->setObjectName(QString::fromUtf8("checkBox_forbidden"));
        checkBox_forbidden->setGeometry(QRect(170, 340, 401, 31));
        checkBox_forbidden->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        label_volume = new QLabel(SettingDialog);
        label_volume->setObjectName(QString::fromUtf8("label_volume"));
        label_volume->setGeometry(QRect(90, 400, 91, 61));
        label_volume->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        slider_volume = new QSlider(SettingDialog);
        slider_volume->setObjectName(QString::fromUtf8("slider_volume"));
        slider_volume->setGeometry(QRect(200, 410, 231, 41));
        slider_volume->setOrientation(Qt::Horizontal);

        retranslateUi(SettingDialog);

        QMetaObject::connectSlotsByName(SettingDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingDialog)
    {
        SettingDialog->setWindowTitle(QCoreApplication::translate("SettingDialog", "Dialog", nullptr));
        btn_default->setText(QCoreApplication::translate("SettingDialog", "Default", nullptr));
        btn_confirm->setText(QCoreApplication::translate("SettingDialog", "Confirm", nullptr));
        label_address->setText(QCoreApplication::translate("SettingDialog", "Server Address:", nullptr));
        label_port->setText(QCoreApplication::translate("SettingDialog", "Server Port:", nullptr));
        radioButton_easy->setText(QCoreApplication::translate("SettingDialog", "Easy(4)", nullptr));
        radioButton_amateur->setText(QCoreApplication::translate("SettingDialog", "amateur(6)", nullptr));
        radioButton_normal->setText(QCoreApplication::translate("SettingDialog", "Normal(8)", nullptr));
        radioButton_custom_depth->setText(QCoreApplication::translate("SettingDialog", "Custom Depth", nullptr));
        radioButton_custom_time->setText(QCoreApplication::translate("SettingDialog", "Custom Time", nullptr));
        label_custom->setText(QCoreApplication::translate("SettingDialog", "Custom:", nullptr));
        checkBox_forbidden->setText(QCoreApplication::translate("SettingDialog", "Using the Rules of Forbidden Moves", nullptr));
        label_volume->setText(QCoreApplication::translate("SettingDialog", "Volume:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingDialog: public Ui_SettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
