/********************************************************************************
** Form generated from reading UI file 'createdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEDIALOG_H
#define UI_CREATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_CreateDialog
{
public:
    QPushButton *btn_cancel;
    QCheckBox *checkBox_public;
    QRadioButton *radioButton_black;
    QPushButton *btn_create;
    QRadioButton *radioButton_white;
    QLabel *label_chess;
    QLabel *label_name;
    QLineEdit *lineEdit_name;

    void setupUi(QDialog *CreateDialog)
    {
        if (CreateDialog->objectName().isEmpty())
            CreateDialog->setObjectName(QString::fromUtf8("CreateDialog"));
        CreateDialog->resize(400, 300);
        btn_cancel = new QPushButton(CreateDialog);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        btn_cancel->setGeometry(QRect(180, 250, 81, 41));
        btn_cancel->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        checkBox_public = new QCheckBox(CreateDialog);
        checkBox_public->setObjectName(QString::fromUtf8("checkBox_public"));
        checkBox_public->setGeometry(QRect(40, 190, 171, 41));
        checkBox_public->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        radioButton_black = new QRadioButton(CreateDialog);
        radioButton_black->setObjectName(QString::fromUtf8("radioButton_black"));
        radioButton_black->setGeometry(QRect(170, 140, 81, 41));
        radioButton_black->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_create = new QPushButton(CreateDialog);
        btn_create->setObjectName(QString::fromUtf8("btn_create"));
        btn_create->setGeometry(QRect(280, 250, 81, 41));
        btn_create->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        radioButton_white = new QRadioButton(CreateDialog);
        radioButton_white->setObjectName(QString::fromUtf8("radioButton_white"));
        radioButton_white->setGeometry(QRect(260, 140, 81, 41));
        radioButton_white->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        label_chess = new QLabel(CreateDialog);
        label_chess->setObjectName(QString::fromUtf8("label_chess"));
        label_chess->setGeometry(QRect(40, 130, 111, 51));
        label_chess->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        label_name = new QLabel(CreateDialog);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(40, 50, 131, 51));
        label_name->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        lineEdit_name = new QLineEdit(CreateDialog);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(170, 60, 181, 41));
        lineEdit_name->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));

        retranslateUi(CreateDialog);

        QMetaObject::connectSlotsByName(CreateDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateDialog)
    {
        CreateDialog->setWindowTitle(QCoreApplication::translate("CreateDialog", "Dialog", nullptr));
        btn_cancel->setText(QCoreApplication::translate("CreateDialog", "Cancel", nullptr));
        checkBox_public->setText(QCoreApplication::translate("CreateDialog", "Public Room", nullptr));
        radioButton_black->setText(QCoreApplication::translate("CreateDialog", "Black", nullptr));
        btn_create->setText(QCoreApplication::translate("CreateDialog", "Create", nullptr));
        radioButton_white->setText(QCoreApplication::translate("CreateDialog", "White", nullptr));
        label_chess->setText(QCoreApplication::translate("CreateDialog", "Your Chess:", nullptr));
        label_name->setText(QCoreApplication::translate("CreateDialog", "Room Name:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateDialog: public Ui_CreateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEDIALOG_H
