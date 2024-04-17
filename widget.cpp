#include "widget.h"
#include "ui_widget.h"
#include "SnakeGame.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::snakeGame)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_clicked()
{
    SnakeGame *game = new SnakeGame;
    game->show();
    connect(game, &SnakeGame::destroyed, game, &QObject::deleteLater);
    close();
}

void Widget::on_exitButton_clicked()
{
    close();
}
