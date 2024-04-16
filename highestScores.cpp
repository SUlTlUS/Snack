#include "SnakeGame.h"
#include <QTextStream>
#include <QFile>
#include <QCoreApplication>

void SnakeGame::writeHighestScoresToFile(int currentScores) {
    QString filePath = QCoreApplication::applicationDirPath() + "/highestScores.txt";
    QFile file(filePath); // Check if this path is correct
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << currentScores;
        file.close();
        qDebug() << "Scores written successfully.";
    } else {
        qDebug() << "Error writing to file:" << file.errorString();
    }
}

void SnakeGame::readHighestScoresFromFile() {
    highestScores = 0;
    QString filePath = QCoreApplication::applicationDirPath() + "/highestScores.txt";
    QFile file(filePath); // 将文件保存到文件系统中
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString HSstr = in.readAll();
        file.close();
        highestScores = HSstr.toInt();
    }
}
