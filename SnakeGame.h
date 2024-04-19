#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <QRandomGenerator>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include "soundPlay.h"

class SnakeGame : public QWidget {
    Q_OBJECT

public:
    explicit SnakeGame(QWidget *parent = nullptr);
    ~SnakeGame();
    static void cleardowordSave();
    bool autoPlayEnabled = false;


protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    void moveSnake();
    void generateFood();
    void getRandomWord(const QString& filename, char* randomWord);
    void writeHighestScoresToFile(int);
    void readHighestScoresFromFile();

private:
    struct Letter {
        QRect rect;
        QChar letter;
    };

    QList<QRect> snake;
    QList<Letter> letters;
    QTimer *timer;
    soundPlayer Splayer;
    soundPlayer Bplayer;
    int direction = Qt::Key_Right;
    int lastDirection = Qt::Key_Right;
    char now[20], targetchar[20];
    int kkk = 0;
    int course = 0;
    int lifecnt = 3;
    int currentScores = 0;
    int highestScores = 0;
    int moveDelay = 160;

    void autoPlay();
    bool isDirectionSafe(Qt::Key direction);
};

#endif // SNAKEGAME_H
