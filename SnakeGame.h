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

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    void moveSnake();
    void generateFood();
    void getRandomWord(const QString& filename, char* randomWord);

private:
    struct Letter {
        QRect rect;
        QChar letter;
    };

    QList<QRect> snake;
    QList<Letter> letters;
    QTimer *timer;
    int direction = Qt::Key_Right;
    int lastDirection = Qt::Key_Right;
    char now[20], targetchar[20];
    int kkk = 0;
    int course = 0;
    int lifecnt = 3;
    soundPlayer Splayer;
};

#endif // SNAKEGAME_H
