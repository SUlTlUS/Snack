#include "SnakeGame.h"

void SnakeGame::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setBrush(Qt::white);
    painter.drawRect(10, 10, 190, 30);
    painter.drawRect(10, 40, 150, 30);
    painter.drawText(20, 30, targetchar);
    painter.drawText(20, 60, now);
    for (const Letter &letter : letters) {
        painter.drawText(letter.rect, Qt::AlignCenter, QString(letter.letter));
    }
    for (const QRect &rect : snake) {
        painter.fillRect(rect, Qt::green);
    }
}
