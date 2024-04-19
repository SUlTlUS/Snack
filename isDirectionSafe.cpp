#include "SnakeGame.h"

bool SnakeGame::isDirectionSafe(Qt::Key dir) {
    QRect nextHead = snake.first();

    switch (dir) {
    case Qt::Key_Left:
        nextHead.translate(-20, 0);
        break;
    case Qt::Key_Right:
        nextHead.translate(20, 0);
        break;
    case Qt::Key_Up:
        nextHead.translate(0, -20);
        break;
    case Qt::Key_Down:
        nextHead.translate(0, 20);
        break;
    default :
        break;
    }

    // 是否撞到墙壁
    if (nextHead.left() < 0 || nextHead.right() >= this->width() ||
        nextHead.top() < 0 || nextHead.bottom() >= this->height()) {
        return false;
    }

    // 是否与自己的身体碰撞
    for (int i = 1; i < snake.length(); ++i) {
        if (nextHead == snake[i]) {
            return false;
        }
    }

    // 是否会遇到错误的字母
    for (const Letter &letter : letters) {
        if (nextHead.intersects(letter.rect) && letter.letter.toLatin1() != targetchar[kkk]) {
            return false;
        }
    }

    return true;
}
