#include "SnakeGame.h"
#include <QDebug>

void SnakeGame::getRandomWord(const QString& filename, char* randomWord) {
    QFile file(filename);
    QVector<QString> words;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString word = in.readLine().trimmed(); // 确保没有读入空白行
            if (!word.isEmpty()) {
                words.append(word);
            }
        }
        file.close();
    } else {
        qDebug() << "Unable to open file:" << filename;
        return;
    }

    if (words.isEmpty()) {
        qDebug() << "No words found in file:" << filename;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, words.size() - 1);
    int randomIndex = dis(gen);
    QString selectedWord = words[randomIndex];
    QByteArray selectedWordUtf8 = selectedWord.toUtf8();
    qstrncpy(randomWord, selectedWordUtf8.constData(), qMin(selectedWordUtf8.size() + 1, 30));

    QFile saveFile("dowordSave.txt");
    if (saveFile.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&saveFile);
        out << "\n" << selectedWord << "\n"; // 写入文件并添加新行
        saveFile.close();
        qDebug() << "Word saved to file:" << selectedWord;
    } else {
        qDebug() << "Unable to open dowordSave.txt for writing.";
    }
}
