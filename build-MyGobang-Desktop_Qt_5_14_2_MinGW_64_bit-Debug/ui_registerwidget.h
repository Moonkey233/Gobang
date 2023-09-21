/********************************************************************************
** Form generated from reading UI file 'registerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWIDGET_H
#define UI_REGISTERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWidget
{
public:
    QLabel *label_userName;
    QLineEdit *lineEdit_userName;
    QLabel *label_email;
    QLineEdit *lineEdit_email;
    QLabel *label_code;
    QLineEdit *lineEdit_code;
    QLabel *label_password;
    QLabel *label_confirm_password;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_confirm_password;
    QPushButton *btn_send;
    QPushButton *btn_return;
    QPushButton *btn_register;

    void setupUi(QWidget *RegisterWidget)
    {
        if (RegisterWidget->objectName().isEmpty())
            RegisterWidget->setObjectName(QString::fromUtf8("RegisterWidget"));
        RegisterWidget->resize(1280, 720);
        label_userName = new QLabel(RegisterWidget);
        label_userName->setObjectName(QString::fromUtf8("label_userName"));
        label_userName->setGeometry(QRect(150, 50, 141, 51));
        label_userName->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        lineEdit_userName = new QLineEdit(RegisterWidget);
        lineEdit_userName->setObjectName(QString::fromUtf8("lineEdit_userName"));
        lineEdit_userName->setGeometry(QRect(340, 60, 531, 41));
        lineEdit_userName->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        label_email = new QLabel(RegisterWidget);
        label_email->setObjectName(QString::fromUtf8("label_email"));
        label_email->setGeometry(QRect(150, 150, 141, 51));
        label_email->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        lineEdit_email = new QLineEdit(RegisterWidget);
        lineEdit_email->setObjectName(QString::fromUtf8("lineEdit_email"));
        lineEdit_email->setGeometry(QRect(340, 150, 351, 51));
        lineEdit_email->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        label_code = new QLabel(RegisterWidget);
        label_code->setObjectName(QString::fromUtf8("label_code"));
        label_code->setGeometry(QRect(130, 260, 141, 51));
        label_code->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        lineEdit_code = new QLineEdit(RegisterWidget);
        lineEdit_code->setObjectName(QString::fromUtf8("lineEdit_code"));
        lineEdit_code->setGeometry(QRect(350, 270, 531, 41));
        lineEdit_code->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        label_password = new QLabel(RegisterWidget);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(130, 350, 141, 51));
        label_password->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        label_confirm_password = new QLabel(RegisterWidget);
        label_confirm_password->setObjectName(QString::fromUtf8("label_confirm_password"));
        label_confirm_password->setGeometry(QRect(130, 440, 221, 51));
        label_confirm_password->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        lineEdit_password = new QLineEdit(RegisterWidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(360, 360, 531, 41));
        lineEdit_password->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        lineEdit_confirm_password = new QLineEdit(RegisterWidget);
        lineEdit_confirm_password->setObjectName(QString::fromUtf8("lineEdit_confirm_password"));
        lineEdit_confirm_password->setGeometry(QRect(350, 450, 531, 41));
        lineEdit_confirm_password->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        lineEdit_confirm_password->setEchoMode(QLineEdit::Password);
        btn_send = new QPushButton(RegisterWidget);
        btn_send->setObjectName(QString::fromUtf8("btn_send"));
        btn_send->setGeometry(QRect(730, 140, 141, 71));
        btn_send->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_return = new QPushButton(RegisterWidget);
        btn_return->setObjectName(QString::fromUtf8("btn_return"));
        btn_return->setGeometry(QRect(300, 570, 141, 71));
        btn_return->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_register = new QPushButton(RegisterWidget);
        btn_register->setObjectName(QString::fromUtf8("btn_register"));
        btn_register->setGeometry(QRect(640, 570, 141, 71));
        btn_register->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));

        retranslateUi(RegisterWidget);

        QMetaObject::connectSlotsByName(RegisterWidget);
    } // setupUi

    void retranslateUi(QWidget *RegisterWidget)
    {
        RegisterWidget->setWindowTitle(QCoreApplication::translate("RegisterWidget", "Form", nullptr));
        label_userName->setText(QCoreApplication::translate("RegisterWidget", "UserName:", nullptr));
        label_email->setText(QCoreApplication::translate("RegisterWidget", "Email:", nullptr));
        label_code->setText(QCoreApplication::translate("RegisterWidget", "Verify Code:", nullptr));
        label_password->setText(QCoreApplication::translate("RegisterWidget", "Password:", nullptr));
        label_confirm_password->setText(QCoreApplication::translate("RegisterWidget", "Confirm Password:", nullptr));
        btn_send->setText(QCoreApplication::translate("RegisterWidget", "Send Code", nullptr));
        btn_return->setText(QCoreApplication::translate("RegisterWidget", "Return", nullptr));
        btn_register->setText(QCoreApplication::translate("RegisterWidget", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWidget: public Ui_RegisterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWIDGET_H
