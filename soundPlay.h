#ifndef SOUNDPLAY_H
#define SOUNDPLAY_H
#include <QSoundEffect>

enum SoundType{
    getWord,
    gameOver,
    backgroundMusic,
    stop
};

class soundPlayer{
    public :
        soundPlayer();
        void soundPlay(SoundType);

    private :
        QSoundEffect SE;
        QSoundEffect BGM;
};

#endif // SOUNDPLAY_H
