#include "gameoverdialog.h"
#include "ui_gameoverdialog.h"
#include "SnakeGame.h"


GameOverDialog::GameOverDialog(int score,int hscore, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GameOverDialog)
    , currentScores(score)
    , highestScores(hscore)
{
    ui->setupUi(this);
    ui->ScoreLabel->setText(QString::number(currentScores));
    ui->HScoreLabel->setText(QString::number(highestScores));
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

