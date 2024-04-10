#include "SnakeGame.h"
#include <QMessageBox>

void SnakeGame::moveSnake() {
    QRect head = snake.first();
    QRect newHead = head;

    switch (direction) {
    case Qt::Key_Left:
        newHead.translate(-20, 0);
        break;
    case Qt::Key_Right:
        newHead.translate(20, 0);
        break;
    case Qt::Key_Up:
        newHead.translate(0, -20);
        break;
    case Qt::Key_Down:
        newHead.translate(0, 20);
        break;
    default:
        break;
    }

    // 检查是否触碰到窗口边界
    if (newHead.left() < 0 || newHead.right() >= width() || newHead.top() < 0 || newHead.bottom() >= height()) {
        timer->stop();
        QMessageBox::information(this, "Game Over", "Game Over");
        return;
    }

    // 检查是否触碰到食物字母
    bool ateFood = false;
    for (int i = 0; i < letters.size(); ++i) {
        if (newHead == letters.at(i).rect) {
            snake.prepend(letters.at(i).rect);
            now[kkk] = letters.at(i).letter.toLatin1();
            if (targetchar[kkk] != now[kkk]) {
                timer->stop();
                QMessageBox::information(this, "Game Over", "Game Over");
                return;
            }
            letters.removeAt(i);
            generateFood();
            ateFood = true;
            break;
        }
    }

    if (ateFood) {
        if (strlen(targetchar) == strlen(now)) {
            course++;
            getRandomWord("Users/notRikka/Downloads/youxiaoword.txt", targetchar);
            kkk = 0;
            for (int i = 0; i < 20; i++) now[i] = '\0';
        } else {
            kkk++;
        }
    }

    if (!ateFood) {
        snake.removeLast();
        snake.prepend(newHead);
    }

    for (int i = 1; i < snake.size(); ++i) {
        if (newHead.intersects(snake.at(i))) {
            timer->stop();
            QMessageBox::information(this, "Game Over", "Game Over");
            return;
        }
    }

    lastDirection = direction;
    update();
}
