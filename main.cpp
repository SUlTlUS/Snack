#include <QApplication>
#include "SnakeGame.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    SnakeGame game;
    game.show();
    return app.exec();
}
