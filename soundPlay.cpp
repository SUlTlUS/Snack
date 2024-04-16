#include "SoundPlay.h"
#include <QSoundEffect>

soundPlayer::soundPlayer() {
    // 构造函数的实现
}

void soundPlayer::soundPlay(SoundType type){
    switch(type) {
        case getWord :
            SE.setSource(QUrl::fromLocalFile(":/res/getWord.wav"));
            SE.setLoopCount(1);
            SE.setVolume(0.6);
            break;
        case gameOver :
            SE.setSource(QUrl::fromLocalFile(":/res/gameOver.wav"));
            SE.setLoopCount(1);
            SE.setVolume(0.6);
            break;
        case backgroundMusic :
            BGM.setSource(QUrl::fromLocalFile(":/res/backgroundMusic.wav"));
            BGM.setLoopCount(-1);
            BGM.setVolume(0.4);
            BGM.play();
            break;
        case stop :
            BGM.stop();
            break;

        default :
            return;
    }
    SE.play();
}
