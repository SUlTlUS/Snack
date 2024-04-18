#include "SnakeGame.h"

void SnakeGame::cleardowordSave() {
    // 清空dowordSave.txt文件
    QFile file("dowordSave.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        file.close();
        qDebug() << "dowordSave.txt has been cleared.";
    } else {
        qDebug() << "Unable to clear dowordSave.txt.";
    }
}
