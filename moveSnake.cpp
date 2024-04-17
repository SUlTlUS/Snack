#include "SnakeGame.h"
#include "soundPlay.h"
#include "gameoverdialog.h"

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
    if (newHead.left() < 0 || newHead.right() >= width() || newHead.top() < 0 || newHead.bottom() >= height()) {
        timer->stop();
        Splayer.soundPlay(gameOver);
        Bplayer.soundPlay(stop);
        if (currentScores > highestScores) {
            highestScores = currentScores;
            writeHighestScoresToFile(currentScores);
        }
        // 在moveSnake函数的游戏结束部分替换代码
        close();
        GameOverDialog dialog(this);
        dialog.exec();
        return;
    }
    bool ateFood = false;
    for (int i = 0; i < letters.size(); ++i) {
        if (newHead == letters.at(i).rect) {
            snake.prepend(letters.at(i).rect);
            now[kkk] = letters.at(i).letter.toLatin1();
            if (targetchar[kkk] != now[kkk]) {
                Splayer.soundPlay(gameOver);
                Bplayer.soundPlay(stop);
                if (currentScores > highestScores) {
                    highestScores = currentScores;
                    writeHighestScoresToFile(currentScores);
                }
                timer->stop();
                // 在moveSnake函数的游戏结束部分替换代码
                close();
                GameOverDialog dialog(this);
                dialog.exec();

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
            Splayer.soundPlay(getWord);
            getRandomWord(":/res/youxiaoword.txt", targetchar);
            kkk = 0;
            currentScores += 20;
            if(moveDelay > 60) {
                moveDelay -= 20;
                timer->start(moveDelay);
            }
            if (currentScores > highestScores) {
                highestScores = currentScores;
                writeHighestScoresToFile(currentScores);
            }
            for (int i = 0; i < 20; i++) now[i] = '\0';
        } else {
            Splayer.soundPlay(getWord);
            kkk++;
            currentScores += 3;
            if (currentScores > highestScores) {
                highestScores = currentScores;
                writeHighestScoresToFile(currentScores);
            }
        }
    }
    if (!ateFood) {
        snake.removeLast();
        snake.prepend(newHead);
    }

    for (int i = 1; i < snake.size(); ++i) {
        if (newHead.intersects(snake.at(i))) {
            Splayer.soundPlay(gameOver);
            Bplayer.soundPlay(stop);
            if (currentScores > highestScores) {
                highestScores = currentScores;
                writeHighestScoresToFile(currentScores);
            }
            timer->stop();
            // 在moveSnake函数的游戏结束部分替换代码
            close();
            GameOverDialog dialog(this);
            dialog.exec();

            return;
        }
    }

    lastDirection = direction;
    update();
}
