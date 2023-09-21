#ifndef PLAYER_H
#define PLAYER_H

#include <QDebug>
#include <QPoint>
#include <QObject>
#include "mychess.h"

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(ChessType chessType);
    void setChessType(ChessType chessType) { m_chessType = chessType; };
    ChessType getChessType() const { return m_chessType; };
    virtual bool makeMove(QPoint point) = 0;
    virtual QString getPlayerType() const = 0;

protected:
    ChessType m_chessType = CHESS_NULL;

private:

signals:
    void sigMakeMove(ChessPieceInfo piece);

};

class PlayerLocal : public Player
{
    Q_OBJECT
public:
    explicit PlayerLocal(ChessType chessType = CHESS_NULL);
    virtual bool makeMove(QPoint point) override;
    virtual QString getPlayerType() const override { return "PlayerLocal"; };

protected:

signals:

};

class PlayerRemote : public Player
{
    Q_OBJECT
public:
    explicit PlayerRemote(ChessType chessType = CHESS_NULL);
    virtual bool makeMove(QPoint point) override;
    virtual QString getPlayerType() const override { return "PlayerRemote"; };

protected:

signals:

};

class PlayerAi : public Player
{
    Q_OBJECT
public:
    explicit PlayerAi(ChessType chessType = CHESS_NULL);
    virtual bool makeMove(QPoint point) override;
    virtual QString getPlayerType() const override { return "PlayerAi"; };

protected:

signals:

};

#endif // PLAYER_H
