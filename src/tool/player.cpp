#include "player.h"

Player::Player(ChessType chessType) {
    m_chessType = chessType;
}

PlayerLocal::PlayerLocal(ChessType chessType) : Player(chessType) {

}

PlayerRemote::PlayerRemote(ChessType chessType) : Player(chessType) {

}

PlayerAi::PlayerAi(ChessType chessType) : Player(chessType) {

}

bool PlayerLocal::makeMove(QPoint point) {
    emit sigMakeMove(ChessPieceInfo(point.x(), point.y(), getChessType()));
    return true;
}

bool PlayerRemote::makeMove(QPoint point) {
    emit sigMakeMove(ChessPieceInfo(point.x(), point.y(), getChessType()));
    return true;
}

bool PlayerAi::makeMove(QPoint point) {
    emit sigMakeMove(ChessPieceInfo(point.x(), point.y(), getChessType()));
    return true;
}
