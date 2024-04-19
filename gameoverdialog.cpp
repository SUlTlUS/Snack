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

    QFile file("dowordSave.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QStringList lines;
        while (!in.atEnd()) {
            QString line = in.readLine();
            lines << line;
        }
        file.close();

        if (!lines.isEmpty()) {
            lines.removeLast();
        }
        QString contentWithoutLastLine = lines.join("\n");
        file.close();

        ui->textBrowser->setText(contentWithoutLastLine);
    } else {
        ui->textBrowser->setText("Unable to open dowordSave.txt.");
    }
}

GameOverDialog::~GameOverDialog()
{
    delete ui;
}

void GameOverDialog::on_pushButton_clicked()
{
    SnakeGame::cleardowordSave();
    SnakeGame *game = new SnakeGame;
    game->show();
    connect(game, &SnakeGame::destroyed, game, &QObject::deleteLater);

    close();
}


void GameOverDialog::on_pushButton_2_clicked()
{
    close();
    exit(0);
}

