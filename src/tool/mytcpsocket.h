#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H
#include <QObject>
#include <QTcpSocket>
#include <QtNetwork>
#include <QThread>
#include <QtConcurrent>
#include "mycrypt.h"
#include "config.h"
#include "mychess.h"

class MyTcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    MyTcpSocket();
    ~MyTcpSocket();
    bool connectToServer();
    bool sendToServer(const QString &message);
    bool recvFromServer(QString *response);
    bool closeSocket();
    bool setServerAddress(const QString &serverAddr, const QString &serverPort);
    QString sign(const QString &cmd, const QString &data, const QString &key = SIGN_KEY);

    void setCookie(const QString &cookie) { m_cookie = cookie; }
    void setUserName(const QString &userName) { m_userName = userName; }
    void setEmail(const QString &email) { m_email = email; }

    QString getCookie() const { return m_cookie; }
    QString getUserName() const { return m_userName; }
    QString getEmail() const { return m_email; }

private:
    QString m_serverAddr = "";
    QString m_serverPort = "";
    QString m_cookie = "";
    QString m_userName = "";
    QString m_email = "";

    QTimer *m_timer = nullptr;
    QString getValue(const QString &message, const QString &key);

private slots:
    void onReadyRead();
    void onParseResponse(const QString &response);

signals:
    void sigReturnConnectStatus(ConnectStatus connectStatus);
    void sigParseResponse(const QString &response);

    void sigErrorResponse(const QString &error);
    void sigLoginResponse(const QString &cookie, const QString &email, const QString &userName);
    void sigPasswordResponse();
    void sigReloginResponse();
    void sigSendcodeResponse();
    void sigRegisterResponse();
    void sigSetpieceResponse(ChessPieceInfo piece);
    void sigJoinResponse(const QString &roomId, const QString &roomName, const QString &rival, const ChessType &chessType);
};

#endif // MYTCPSOCKET_H
