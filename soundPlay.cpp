#include "SoundPlay.h"
#include <QSoundEffect>

soundPlayer::soundPlayer() {
    // 构造函数的实现
}

void soundPlayer::soundPlay(SoundType type){
    switch(type) {
        case getWord :
            SE.setSource(QUrl::fromLocalFile(":/res/getWord.wav"));
            SE.setVolume(1);
            break;
        case gameOver :
            SE.setSource(QUrl::fromLocalFile(":/res/gameOver.wav"));
            SE.setVolume(0.6);
            break;
        default :
            return;
    }
    SE.play();
}
