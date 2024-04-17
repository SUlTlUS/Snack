#include "gameoverdialog.h"
#include "ui_gameoverdialog.h"
#include "SnakeGame.h"


GameOverDialog::GameOverDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GameOverDialog)
{
    ui->setupUi(this);
}

GameOverDialog::~GameOverDialog()
{
    delete ui;
}

void GameOverDialog::on_pushButton_clicked()
{
    SnakeGame *game = new SnakeGame;
    game->show();
    connect(game, &SnakeGame::destroyed, game, &QObject::deleteLater);
    close();
}


void GameOverDialog::on_pushButton_2_clicked()
{
    close();
}

