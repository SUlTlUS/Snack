#include "SnakeGame.h"
#include <QPainter>
#include <QMessageBox>

void SnakeGame::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setBrush(Qt::white);

    // 绘制next单词提示框
    painter.drawRect(10, 10, 190, 30);

    // 绘制已有单词提示框
    painter.drawRect(10, 40, 150, 30);

    // 在提示框里绘制单词now
    painter.drawText(20, 30, targetchar);

    // 绘制当前单词
    painter.drawText(20, 60, now);

    // 绘制食物
    for (const Letter &letter : letters) {
        painter.drawText(letter.rect, Qt::AlignCenter, QString(letter.letter));
    }

    // 绘制蛇身
    for (const QRect &rect : snake) {
        painter.fillRect(rect, Qt::green);
    }
}
