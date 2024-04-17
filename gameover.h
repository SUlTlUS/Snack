#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>

namespace Ui {
class gameOver;
}

class gameOver : public QWidget
{
    Q_OBJECT

public:
    explicit gameOver(QWidget *parent = nullptr);
    ~gameOver();

private:
    Ui::gameOver *ui;
};

#endif // GAMEOVER_H
