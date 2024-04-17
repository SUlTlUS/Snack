#include "SnakeGame.h"

void SnakeGame::generateFood() {
    int xx[100000], yy[100000], xyk = 0;
    letters.clear();
    for (int i = 0; i < 30; ++i) {
        int x = 0, y = 0;
        while (x <= 195 && y <= 130) {
            x = QRandomGenerator::global()->bounded(width() / 20) * 20;
            y = QRandomGenerator::global()->bounded(height() / 20) * 20;
        }
        int ss = 0;
        for (int j = 0; j <= 100000; j++) {
            if (xx[j] == x && yy[j] == y) ss = 1;
        }
        if (ss) continue;
        xx[xyk] = x, yy[xyk++] = y;
        QRect rect(x, y, 20, 20);
        Letter letter;
        letter.rect = rect;
        letter.letter = QChar('a' + i % 26);
        letters.append(letter);
    }
}
