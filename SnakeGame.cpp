#include "SnakeGame.h"
#include "soundPlay.h"

SnakeGame::SnakeGame(QWidget *parent) : QWidget(parent) {
    setFixedSize(1300, 800);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SnakeGame::moveSnake);
    timer->start(160);
    snake.append(QRect(100, 100, 20, 20));
    for (int i = 0; i < 20; i++) now[i] = '\0';
    getRandomWord("C:/Users/notRikka/Documents/qtProject/snaketestv02/res/youxiaoword.txt", targetchar);
    generateFood();
}

SnakeGame::~SnakeGame() {
    delete timer;
}
