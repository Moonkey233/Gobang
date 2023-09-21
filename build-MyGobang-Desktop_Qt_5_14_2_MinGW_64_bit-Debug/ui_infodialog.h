/********************************************************************************
** Form generated from reading UI file 'infodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFODIALOG_H
#define UI_INFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_InfoDialog
{
public:
    QPushButton *btn_confirm;
    QLabel *label_info;
    QLabel *label_bilibili;
    QLabel *label_github;
    QLabel *label_gitee;

    void setupUi(QDialog *InfoDialog)
    {
        if (InfoDialog->objectName().isEmpty())
            InfoDialog->setObjectName(QString::fromUtf8("InfoDialog"));
        InfoDialog->resize(800, 600);
        btn_confirm = new QPushButton(InfoDialog);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));
        btn_confirm->setGeometry(QRect(230, 490, 331, 61));
        btn_confirm->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        label_info = new QLabel(InfoDialog);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setGeometry(QRect(130, 10, 511, 181));
        label_info->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        label_info->setAlignment(Qt::AlignCenter);
        label_bilibili = new QLabel(InfoDialog);
        label_bilibili->setObjectName(QString::fromUtf8("label_bilibili"));
        label_bilibili->setGeometry(QRect(230, 180, 341, 71));
        label_bilibili->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        label_bilibili->setAlignment(Qt::AlignCenter);
        label_bilibili->setOpenExternalLinks(true);
        label_github = new QLabel(InfoDialog);
        label_github->setObjectName(QString::fromUtf8("label_github"));
        label_github->setGeometry(QRect(230, 280, 341, 61));
        label_github->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        label_github->setAlignment(Qt::AlignCenter);
        label_github->setOpenExternalLinks(true);
        label_gitee = new QLabel(InfoDialog);
        label_gitee->setObjectName(QString::fromUtf8("label_gitee"));
        label_gitee->setGeometry(QRect(220, 380, 341, 51));
        label_gitee->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        label_gitee->setAlignment(Qt::AlignCenter);
        label_gitee->setOpenExternalLinks(true);

        retranslateUi(InfoDialog);

        QMetaObject::connectSlotsByName(InfoDialog);
    } // setupUi

    void retranslateUi(QDialog *InfoDialog)
    {
        InfoDialog->setWindowTitle(QCoreApplication::translate("InfoDialog", "Dialog", nullptr));
        btn_confirm->setText(QCoreApplication::translate("InfoDialog", "Confirm", nullptr));
        label_info->setText(QCoreApplication::translate("InfoDialog", "Gobang\n"
"\346\234\254\346\270\270\346\210\217\346\230\257\344\270\200\346\254\276\344\272\224\345\255\220\346\243\213\346\270\270\346\210\217\357\274\214\346\224\257\346\214\201\345\215\225\346\234\272\346\250\241\345\274\217\345\222\214\350\201\224\346\234\272\345\257\271\346\210\230\343\200\202", nullptr));
        label_bilibili->setText(QCoreApplication::translate("InfoDialog", "Open in <a href=\"https://space.bilibili.com/215177187\">Bilibili</a>", nullptr));
        label_github->setText(QCoreApplication::translate("InfoDialog", "Open in <a href=\"https://github.com/Moonkey233/Gobang\">Github</a>", nullptr));
        label_gitee->setText(QCoreApplication::translate("InfoDialog", "Open in <a href=\"https://gitee.com/Moonkey233/Gobang\">Gitee</a>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoDialog: public Ui_InfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFODIALOG_H
