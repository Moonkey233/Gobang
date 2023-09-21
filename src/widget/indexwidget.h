#ifndef INDEXWIDGET_H
#define INDEXWIDGET_H

#include "mywidget.h"
#include "QProgressDialog"

namespace Ui {
class IndexWidget;
}

class IndexWidget : public MyWidget
{
    Q_OBJECT

public:
    IndexWidget(QSharedPointer<MyTcpSocket> socket, QWidget *parent = nullptr);
    ~IndexWidget();

private slots:
    void onOfflineBtnClicked();
    void onOnlineBtnClicked();
    void onSettingBtnClicked();
    void onInfoBtnClicked();
    void onExitBtnClicked();
    void showErrorMessage(QString message);

private:
    Ui::IndexWidget *ui;
    QProgressDialog *m_progressDialog;

    ConnectStatus m_connectStatus = CONNECT_CONNECTING;

    bool connectSlot();


signals:
    void setServerAddressSignal();
    void autoLoginSignal();

    void sigRecv(QString *response);
    void sigSend(const QString &message);
    void sigConnect();

};

#endif // INDEXWIDGET_H
