#ifndef MYCHESS_H
#define MYCHESS_H

enum ChessType {
    CHESS_BLACK = -1,
    CHESS_NULL = 0,
    CHESS_WHITE = 1
};

enum StatusType {
    STATUS_CONTINUE = -2,
    STATUS_LOSE = -1,
    STATUS_DRAW = 0,
    STATUS_WIN = 1
};

enum GameType {
    GAME_AI_FIRST = -2,
    GAME_HUMAN_FIRST = -1,
    GAME_HOTSEAT = 0,
    GAME_ONLINE = 1
};

const int ROWS = 15;

struct ChessPieceInfo {
    ChessPieceInfo(int r, int c, ChessType t) : row(r), col(c), type(t) {};
    int row;
    int col;
    ChessType type;
};

#endif // MYCHESS_H
