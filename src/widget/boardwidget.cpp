#include "boardwidget.h"
#include "ui_boardwidget.h"

BoardWidget::BoardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BoardWidget)
{
    ui->setupUi(this);

    m_chessPieces = new ChessType *[ROWS];
    for(int row = 0; row < ROWS; row++) {
        m_chessPieces[row] = new ChessType [ROWS];
    }

    m_imgLabel = new QLabel(this);
    m_black.load(":/res/black.png");
    m_white.load(":/res/white.png");

    if (m_black.isNull()) {
        qDebug() << "Error: black image is null";
        return;
    }

    init();
    update();
}

BoardWidget::~BoardWidget()
{
    delete ui;

    for(int i = 0; i < ROWS; i++) {
        delete[] m_chessPieces[i];
        m_chessPieces[i] = nullptr;
    }
    delete[] m_chessPieces;
    m_chessPieces = nullptr;
}

int BoardWidget::checkWin(int row, int col) {

    if (m_numPieces == ROWS * ROWS) {
        return STATUS_DRAW;
    }
    //判定最后一步棋是否达成胜利条件
    int chessType = m_chessPieces[row][col];

    //8个方向向量
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0){
                continue;
            } else {
                int sum = 0;
                for(int k = -4; k <= 4; k++) {
                    if(((row + (i * k)) < 0 ||
                    (row + (i * k)) >= ROWS ||
                    (col + (j * k)) < 0 ||
                    (col + (j * k)) >= ROWS ) ||
                    (sum == 0 && (
                    (row + (i * (k + 4))) >= ROWS ||
                    (row + (i * (k + 4))) < 0 ||
                    (col + (j * (k + 4))) >= ROWS ||
                    (col + (j * (k + 4))) < 0))) {
                        continue;
                    } else {
                        if(m_chessPieces[(row + (i * k))][(col + (j * k))] == chessType) {
                            sum++;
                        } else {
                            sum = 0;
                            continue;
                        } if(sum == 5) {
                            return STATUS_WIN;
                        }
                    }
                }
            }
        }
    }
    return STATUS_CONTINUE;
}

bool BoardWidget::isValid(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < ROWS && m_chessPieces[row][col] == CHESS_NULL);
}

bool BoardWidget::isValid(ChessPieceInfo piece) {
    return isValid(piece.row, piece.col);
}

bool BoardWidget::init() {
    m_numPieces = 0;
    m_lastPiece = { 0, 0, CHESS_NULL };
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < ROWS; ++col) {
            m_chessPieces[row][col] = CHESS_NULL;
        }
    }

    return true;
}

bool BoardWidget::init(ChessType pieces[ROWS][ROWS], ChessPieceInfo lastPiece) {
    m_numPieces = 0;
    m_lastPiece = lastPiece;
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < ROWS; ++col) {
            m_chessPieces[row][col] = pieces[row][col];
            if (m_chessPieces[row][col] != CHESS_NULL)
                m_numPieces++;
        }
    }
    flush();
    return true;
}

QPoint BoardWidget::posToRowCol(QPoint point) {
    int xRound = int((point.x() - m_startX - m_boardWidth + m_gridWidth / 2) / m_gridWidth);
    int yRound = int((point.y() - m_startY - m_boardWidth + m_gridWidth / 2) / m_gridWidth);
    xRound = xRound >= 0 ? xRound : 0;
    yRound = yRound >= 0 ? yRound : 0;
    xRound = xRound <= 14 ? xRound : 14;
    yRound = yRound <= 14 ? yRound : 14;
    return QPoint(xRound, yRound);
}

// 重载 QWidget 的 resizeEvent() 方法
void BoardWidget::resizeEvent(QResizeEvent *event)
{
    // 调用 QWidget 的 resizeEvent() 方法
    QWidget::resizeEvent(event);
    m_size = size().width();
    m_imgLabel->resize(m_size, m_size);
    m_boardWidth = m_size / 80;
    m_startX = m_size / 16 - m_boardWidth;
    m_startY = m_size / 16 - m_boardWidth;
    m_gridWidth = m_size / 16;
    m_pointRadius = m_size / 160;
    m_fontSize = m_size / 64;
    m_cursorSize = m_size / 40;
    m_pieceRadius = m_size / 20;
    m_penSize = m_size / 160;

    flush();
}

void BoardWidget::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    m_currentPos = event->pos();
    update();
}

void BoardWidget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    m_pressPos = posToRowCol(event->pos());
}

void BoardWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    QPoint endPos = posToRowCol(event->pos());
    if (endPos == m_pressPos) {
        if (isValid(endPos.x(), endPos.y())) {
            qDebug() << endPos;
            emit sigMouseRelease(endPos);
        }
    }
}

void BoardWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    m_displayPixmap.fill(Qt::transparent);
    QPainter painter(&m_displayPixmap);
    painter.drawPixmap(0, 0, m_displayWithoutCursorPixmap);

    if (m_currentPos.x() > 0 && m_currentPos.y() > 0 && m_currentPos.x() < m_size && m_currentPos.y() < m_size) {
        QPoint point = posToRowCol(m_currentPos);
        int xRound = point.x();
        int yRound = point.y();
        if (m_chessPieces[xRound][yRound] == CHESS_NULL) {
            painter.drawPixmap(
                xRound * m_gridWidth + m_startX + m_boardWidth - m_cursorSize / 2,
                yRound * m_gridWidth + m_startY + m_boardWidth - m_cursorSize / 2,
                m_cursorPixmap
            );
        }
    }
    painter.end();
    m_imgLabel->setPixmap(m_displayPixmap);
}

void BoardWidget::enterEvent(QEvent *event)
{
    QWidget::enterEvent(event);
    m_imgLabel->setMouseTracking(true);
    setMouseTracking(true);
    update();
}

void BoardWidget::leaveEvent(QEvent *event)
{
    QWidget::leaveEvent(event);
    m_imgLabel->setMouseTracking(false);
    setMouseTracking(false);
    m_currentPos = QPoint(-1, -1);
    update();
}

bool BoardWidget::flush() {

    m_boardPixmap = QPixmap(m_size, m_size);
    m_chessPixmap = QPixmap(m_size, m_size);
    m_cursorPixmap = QPixmap(m_cursorSize, m_cursorSize);
    m_displayPixmap = QPixmap(m_size, m_size);
    m_displayWithoutCursorPixmap = QPixmap(m_size, m_size);
    m_boardPixmap.fill(Qt::transparent);
    m_chessPixmap.fill(Qt::transparent);
    m_cursorPixmap.fill(Qt::transparent);
    m_displayPixmap.fill(Qt::transparent);
    m_displayWithoutCursorPixmap.fill(Qt::transparent);

    drawChessboard();
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < ROWS; col++) {
            if(row != m_lastPiece.row || col != m_lastPiece.col){
                drawPiece(row, col, ChessType(m_chessPieces[row][col]), false);
            } else {
                drawPiece(row, col, ChessType(m_chessPieces[row][col]), true);
            }
        }
    }

    QPainter painter(&m_displayWithoutCursorPixmap);
    painter.drawPixmap(0, 0, m_boardPixmap);
    painter.drawPixmap(0, 0, m_chessPixmap);
    painter.end();
    drawCursor();

    update();
    return true;
}

bool BoardWidget::fillBackgroundColor() {
    m_boardPixmap.fill(m_bgColor);

    return true;
}

bool BoardWidget::drawChessboard() {
    fillBackgroundColor();

    QPainter painter(&m_boardPixmap);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::TextAntialiasing, true);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine));

    QFont font;
    font.setPointSize(m_fontSize);
    font.setBold(true);
    painter.setFont(font);

    int left = m_startX + m_boardWidth;
    int right = left + m_gridWidth * (ROWS - 1);
    int top = m_startY + m_boardWidth;
    int bottom = top + m_gridWidth * (ROWS - 1);

    for (int i = 0; i < ROWS; ++i) {
        // Horizontal lines
        painter.drawLine(left, top + m_gridWidth * i, right, top + m_gridWidth * i);
        // vertical lines
        painter.drawLine(left + m_gridWidth * i, top, left + m_gridWidth * i, bottom);

        // top & bottom  text (A, B, C, ... , O)
        painter.drawText(QPoint(left + m_gridWidth * i - m_fontSize / 2, m_startY * 2 / 3), QString('A' + i));
        painter.drawText(QPoint(left + m_gridWidth * i - m_fontSize / 2, bottom + m_boardWidth + m_startY / 2), QString('A' + i));

        // left & right  text (1, 2, 3, ... , 15)
        if (i < 9) {
            painter.drawText(QPoint(m_startX / 3, top + m_gridWidth * i + m_fontSize / 2), QString::number(1 + i));
            painter.drawText(QPoint(right + m_boardWidth + m_startX / 3, top + m_gridWidth * i + m_fontSize / 2), QString::number(1 + i));
        } else {
            painter.drawText(QPoint(m_startX / 3 - m_fontSize / 2, top + m_gridWidth * i + m_fontSize / 2), QString::number(1 + i));
            painter.drawText(QPoint(right + m_boardWidth + m_startX / 3 - m_fontSize / 2, top + m_gridWidth * i + m_fontSize / 2), QString::number(1 + i));
        }
    }

    // board internal lines
    left = m_startX;
    top = m_startY;
    right = left + m_boardWidth * 2 + m_gridWidth * (ROWS - 1);
    bottom = top + m_boardWidth * 2 + m_gridWidth * (ROWS - 1);
    painter.drawLine(left, top, right, top);
    painter.drawLine(right, top, right, bottom);
    painter.drawLine(left, bottom, right, bottom);
    painter.drawLine(left, top, left, bottom);

    // five control points
    painter.setPen(QColor(Qt::black));
    painter.setBrush(QBrush(Qt::black));
    int centerX = m_startX + m_boardWidth + (ROWS / 2) * m_gridWidth;
    int centerY = m_startY + m_boardWidth + (ROWS / 2) * m_gridWidth;
    painter.drawEllipse(QPoint(centerX, centerY), int(m_pointRadius), int(m_pointRadius));
    painter.drawEllipse(QPoint(centerX - 4 * m_gridWidth, centerY - 4 * m_gridWidth), int(m_pointRadius), int(m_pointRadius));
    painter.drawEllipse(QPoint(centerX + 4 * m_gridWidth, centerY - 4 * m_gridWidth), int(m_pointRadius), int(m_pointRadius));
    painter.drawEllipse(QPoint(centerX - 4 * m_gridWidth, centerY + 4 * m_gridWidth), int(m_pointRadius), int(m_pointRadius));
    painter.drawEllipse(QPoint(centerX + 4 * m_gridWidth, centerY + 4 * m_gridWidth), int(m_pointRadius), int(m_pointRadius));

    painter.end();
    return true;
}

bool BoardWidget::drawPiece(int row, int col, ChessType type, bool highlight) {
    if (type == CHESS_NULL)
        return false;

    int x = m_startX + m_boardWidth + m_gridWidth * row;
    int y = m_startY + m_boardWidth + m_gridWidth * col;

    QPainter painter(&m_chessPixmap);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPixmap piecePixmap = type == CHESS_BLACK ? m_black : m_white;
    piecePixmap.scaled(m_pieceRadius, m_pieceRadius, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(QRect(x - m_pieceRadius / 2, y - m_pieceRadius / 2, m_pieceRadius, m_pieceRadius), piecePixmap);

    if (highlight) {
        QPen pen;
        pen.setWidth(m_penSize);
        pen.setColor(type == CHESS_BLACK ? Qt::yellow : Qt::blue);
        painter.setPen(pen);
        painter.drawLine(x + m_penSize / 2 - 0.5, y - 0.5, x + m_penSize * 1.5 - 0.5, y - 0.5);
        painter.drawLine(x - m_penSize / 2 - 0.5, y - 0.5, x - m_penSize * 1.5 - 0.5, y - 0.5);
        painter.drawLine(x - 0.5, y + m_penSize / 2 - 0.5, x - 0.5, y + m_penSize * 1.5 - 0.5);
        painter.drawLine(x - 0.5, y - m_penSize / 2 - 0.5, x - 0.5, y - m_penSize * 1.5 - 0.5);
        m_numPieces++;
    }

    painter.end();
    return true;
}

// Place a piece
bool BoardWidget::setPiece(ChessPieceInfo chessPiece) {
    int row = chessPiece.row;
    int col = chessPiece.col;
    ChessType type = chessPiece.type;
    m_chessPieces[row][col] = type;

    qDebug() << row << col << type;

    drawPiece(m_lastPiece.row, m_lastPiece.col, m_lastPiece.type, false);
    drawPiece(row, col, type, true);

    m_lastPiece = { row, col, type };

    if (type != CHESS_NULL) {
        int status = checkWin(row, col);
        if (status == STATUS_WIN) {
            emit winSignal(type);
            m_isWin = true;
            qDebug() << "WIN";
        }
        else if (status == STATUS_DRAW) {
            emit drawSignal();
            qDebug() << "DRAW";
        }

        return true;
    } else {
        return false;
    }
}

bool BoardWidget::drawCursor() {
    QPainter painter(&m_cursorPixmap);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::TextAntialiasing, true);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine));
    painter.setBrush(QBrush(Qt::red));
    painter.drawRect(0, 0, int(m_cursorSize), int(m_cursorSize));
    painter.end();
    return true;
}

bool BoardWidget::ignoreMouseEvent(bool isIgnore) {
    setAttribute(Qt::WA_TransparentForMouseEvents, isIgnore);
    return true;
}

bool BoardWidget::makeMove(ChessPieceInfo piece) {
    setPiece(piece);
    m_displayWithoutCursorPixmap.fill(Qt::transparent);
    QPainter painter(&m_displayWithoutCursorPixmap);
    painter.drawPixmap(0, 0, m_boardPixmap);
    painter.drawPixmap(0, 0, m_chessPixmap);
    painter.end();
    update();

    return true;
}
