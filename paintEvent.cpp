#include "SnakeGame.h"

void SnakeGame::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    // 绘制网格背景
    painter.setPen(Qt::lightGray); // 设置网格线的颜色
    int gridSize = 20; // 定义网格大小
    for (int x = 0; x <= width(); x += gridSize) {
        painter.drawLine(x, 0, x, height()); // 垂直线
    }
    for (int y = 0; y <= height(); y += gridSize) {
        painter.drawLine(0, y, width(), y); // 水平线
    }
    painter.setBrush(Qt::white);
    painter.drawRect(10, 10, 190, 30);
    painter.drawRect(10, 40, 150, 30);
    QFont font = painter.font();
    font.setWeight(QFont::Bold);
    font.setFamily("Extra-bold");
    painter.setFont(font);
    painter.setPen(Qt::red);
    painter.drawText(20, 30, targetchar);
    painter.drawText(20, 60, now);
    painter.drawText(20, 90, "Score: " + QString::number(currentScores));
    painter.drawText(20, 120, "Highest Score: " + QString::number(highestScores));
    for (const Letter &letter : letters) {
        painter.drawText(letter.rect, Qt::AlignCenter, QString(letter.letter));
    }
    for (const QRect &rect : snake) {
        painter.fillRect(rect, Qt::green);

    }
}
