#include "SnakeGame.h"
#include <QtMath>

void SnakeGame::autoPlay() {
    QRect head = snake.first();
    Letter closestFood;
    int minDistance = std::numeric_limits<int>::max();

    // 寻找最近的正确字母
    for (const Letter &letter : letters) {
        if (letter.letter.toLatin1() == targetchar[kkk]) {
            int distance = qAbs(head.x() - letter.rect.x()) + qAbs(head.y() - letter.rect.y());
            if (distance < minDistance) {
                minDistance = distance;
                closestFood = letter;
            }
        }
    }

    // 确定最近食物的方向
    int dx = closestFood.rect.x() - head.x();
    int dy = closestFood.rect.y() - head.y();
    QVector<Qt::Key> preferredDirections;

    // 选择优先的方向
    if (qAbs(dx) > qAbs(dy)) {
        preferredDirections.append(dx > 0 ? Qt::Key_Right : Qt::Key_Left);
        preferredDirections.append(dy > 0 ? Qt::Key_Down : Qt::Key_Up);
    } else {
        preferredDirections.append(dy > 0 ? Qt::Key_Down : Qt::Key_Up);
        preferredDirections.append(dx > 0 ? Qt::Key_Right : Qt::Key_Left);
    }

    // 不安全则检查另外方向
    foreach (Qt::Key dir, preferredDirections) {
        if (isDirectionSafe(dir)) {
            direction = dir;
            break;
        }
    }
}
