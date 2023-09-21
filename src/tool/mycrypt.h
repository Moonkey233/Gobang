#ifndef MYCRYPT_H
#define MYCRYPT_H

#include <QCryptographicHash>
#include <QDebug>
#include <QString>
#include <QUuid>

class MyCrypt
{
public:
    MyCrypt();
    static QString calculateMD5(const QString &text);
    static QString sign(const QString &text, const QString &key);
};

#endif // MYCRYPT_H
