#include "SnakeGame.h"

void SnakeGame::getRandomWord(const QString& filename, char* randomWord) {
    QFile file(filename);
    QVector<QString> words;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString word = in.readLine();
            words.append(word);
        }
        file.close();
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, words.size() - 1);
        int randomIndex = dis(gen);
        QByteArray selectedWord = words[randomIndex].toUtf8();
        qstrncpy(randomWord, selectedWord.constData(), 30);
    }
}
