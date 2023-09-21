#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

const int MAX_SERVER_WAIT_TIME_MS = 2000;
const QString SIGN_KEY = "xyloveyy1314like";
//const QString DEFAULT_HOST = "Moonkey233.top";
const QString DEFAULT_HOST = "127.0.0.1";
const QString DEFAULT_PORT = "8888";
const int HEARTBEAT_INTERVAL_TIME_MS = 5000;

enum ConnectStatus {
    CONNECT_FAIL = -1,
    CONNECT_CONNECTING = 0,
    CONNECT_SUCCESS = 1,
};

#endif // CONFIG_H
