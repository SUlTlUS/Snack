#include "SnakeGame.h"

SnakeGame::SnakeGame(QWidget *parent) : QWidget(parent) {
    setFixedSize(1300, 800);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SnakeGame::moveSnake);
    timer->start(160);
    snake.append(QRect(100, 100, 20, 20));
    for (int i = 0; i < 20; i++) now[i] = '\0';
    getRandomWord("/Users/duxiaodong/Qt/youxiaoword.txt", targetchar);
    generateFood();
}

SnakeGame::~SnakeGame() {
    delete timer;
}
