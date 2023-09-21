#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QDebug>
#include <QPoint>
#include <QMouseEvent>
#include "../tool/mychess.h"

namespace Ui {
class BoardWidget;
}

class BoardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BoardWidget(QWidget *parent = nullptr);
    ~BoardWidget();
//    void setChessType(const ChessType &chessType) { m_chessType = chessType; }
//    void setGameType(const GameType &gameType) { m_gameType = gameType; }
//    ChessType getYourChessType() const { return m_chessType; }
//    GameType getGameType() const { return m_gameType; }
    bool setPiece(ChessPieceInfo chessPiece);
    ChessType **getChessBoard() const { return m_chessPieces; }
    bool isWin() const { return m_isWin; };
    bool makeMove(ChessPieceInfo piece);
    bool isValid(int row, int col);
    bool isValid(ChessPieceInfo piece);

private:
    bool m_isWin = false;

    ChessType **m_chessPieces = nullptr;
    int m_numPieces = 0;
    double m_size = 640;
    double m_gridWidth = m_size / 16;
    double m_pieceRadius = m_size / 20;
    double m_startX = m_size / 20;
    double m_startY = m_size / 20;
    double m_cursorSize = m_size / 40;
    double m_fontSize = m_size / 64;
    double m_boardWidth = m_size / 80;
    double m_pointRadius = m_size / 160;
    double m_penSize = m_size / 160;

    Ui::BoardWidget *ui;
    QLabel *m_imgLabel = nullptr;
    QPixmap m_displayPixmap = QPixmap();
    QPixmap m_displayWithoutCursorPixmap = QPixmap();
    QPixmap m_boardPixmap = QPixmap();
    QPixmap m_chessPixmap = QPixmap();
    QPixmap m_cursorPixmap = QPixmap();
    QColor m_bgColor = qRgb(200, 150, 100);
    ChessPieceInfo m_lastPiece = {0, 0, CHESS_NULL};
//    ChessType m_currentType = CHESS_BLACK;
//    ChessType m_chessType = CHESS_NULL;
//    GameType m_gameType = GAME_HOTSEAT;
    QPoint m_currentPos;
    QPoint m_pressPos;
    QPixmap m_black = QPixmap();
    QPixmap m_white = QPixmap();

private:
    bool flush();
    bool init();
    bool init(ChessType pieces[ROWS][ROWS], ChessPieceInfo lastPiece);
    bool ignoreMouseEvent(bool isIgnore);
    bool drawChessboard();
    bool drawPiece(int row, int col, ChessType type, bool highlight);
    bool drawCursor();
    bool fillBackgroundColor();
    int checkWin(int row, int col);
    QPoint posToRowCol(QPoint point);

protected:
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;
    virtual void enterEvent(QEvent *event) override;
    virtual void leaveEvent(QEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;

public slots:

signals:
    void winSignal(ChessType type);
    void drawSignal();
    void sigMouseRelease(QPoint point);

};

#endif // BOARDWIDGET_H
