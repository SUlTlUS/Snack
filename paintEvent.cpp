#include "SnakeGame.h"

void SnakeGame::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    // 绘制网格背景
    painter.setPen(Qt::lightGray);
    int gridSize = 20;
    for (int x = 0; x <= width(); x += gridSize) {
        painter.drawLine(x, 0, x, height());
    }
    for (int y = 0; y <= height(); y += gridSize) {
        painter.drawLine(0, y, width(), y);
    }

    // 绘制目标字母和得分
    painter.setBrush(Qt::white);
    painter.drawRect(10, 10, 190, 30);
    painter.drawRect(10, 40, 150, 30);
    QFont font = painter.font();
    font.setWeight(QFont::Bold);
    font.setFamily("Extra-bold");
    painter.setFont(font);
    painter.setPen(Qt::black);
    painter.drawText(20, 30, targetchar);
    painter.drawText(20, 60, now);
    painter.drawText(20, 95, "Score: " + QString::number(currentScores));
    painter.drawText(20, 115, "Highest Score: " + QString::number(highestScores));

    // 绘制食物
    QChar nextChar = kkk < strlen(targetchar) ? targetchar[kkk] : '\0';
    for (const Letter &letter : letters) {
        if (letter.letter == nextChar) {
            painter.setPen(Qt::red);
        } else {
            painter.setPen(Qt::black);
        }
        painter.drawText(letter.rect, Qt::AlignCenter, QString(letter.letter));
    }

    // 绘制蛇
    for (const QRect &rect : snake) {
        painter.fillRect(rect, Qt::green);
    }
}
