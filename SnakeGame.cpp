#include "SnakeGame.h"

SnakeGame::SnakeGame(QWidget *parent) : QWidget(parent) {
    readHighestScoresFromFile();
    setFixedSize(1300, 800);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SnakeGame::moveSnake);
    timer->start(180);
    snake.append(QRect(100, 100, 20, 20));
    for (int i = 0; i < 20; i++) now[i] = '\0';
    getRandomWord(":/res/youxiaoword.txt", targetchar);
    generateFood();
    Bplayer.soundPlay(backgroundMusic);
}

SnakeGame::~SnakeGame() {
    delete timer;
}
