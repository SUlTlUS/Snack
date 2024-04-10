#include "SnakeGame.h"
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <random>

void getRandomWord(const QString& filename, char* randomWord) {
    QFile file(filename);
    QVector<QString> words;

    // 打开文件并读取单词
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString word = in.readLine();
            words.append(word);
        }
        file.close();

        // 生成随机数
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, words.size() - 1);
        int randomIndex = dis(gen);

        // 将随机选择的单词复制到字符数组中
        QByteArray selectedWord = words[randomIndex].toUtf8();
        qstrncpy(randomWord, selectedWord.constData(), 30);
    }
}
