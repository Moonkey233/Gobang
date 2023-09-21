#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QMessageBox>
#include "widget/indexwidget.h"
#include "widget/offlinewidget.h"
#include "widget/loginwidget.h"
#include "widget/registerwidget.h"
#include "widget/forgetwidget.h"
#include "widget/onlinewidget.h"
#include "dialog/settingdialog.h"
#include "widget/gamewidget.h"
#include "dialog/infodialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSharedPointer<MyTcpSocket> m_socket = nullptr;
    QStackedWidget *m_stackedWidget = nullptr;
    IndexWidget *m_indexWidget = nullptr;
    OfflineWidget *m_offlineWidget = nullptr;
    LoginWidget *m_loginWidget = nullptr;
    RegisterWidget *m_registerWidget = nullptr;
    ForgetWidget *m_forgetWidget = nullptr;
    OnlineWidget *m_onlineWidget = nullptr;
    SettingDialog *m_settingDialog = nullptr;
    GameWidget *m_gameWidget = nullptr;
    InfoDialog *m_infoDialog = nullptr;
    bool connectSlot();

private slots:
    void onChangeWidget(const QString &widgetName);
    void onSetServerAddress();

};
#endif // MAINWINDOW_H
