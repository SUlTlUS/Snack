#include "SnakeGame.h"

void SnakeGame::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Left:
        if (lastDirection != Qt::Key_Right)
            direction = Qt::Key_Left;
        break;
    case Qt::Key_Right:
        if (lastDirection != Qt::Key_Left)
            direction = Qt::Key_Right;
        break;
    case Qt::Key_Up:
        if (lastDirection != Qt::Key_Down)
            direction = Qt::Key_Up;
        break;
    case Qt::Key_Down:
        if (lastDirection != Qt::Key_Up)
            direction = Qt::Key_Down;
        break;
    default:
        break;
    }
}
