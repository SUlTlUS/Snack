#ifndef SOUNDPLAY_H
#define SOUNDPLAY_H
#include <QSoundEffect>

enum SoundType{
    getWord,
    gameOver
};

class soundPlayer{
    public :
        soundPlayer();
        void soundPlay(SoundType);

    private :
        QSoundEffect SE;
};

#endif // SOUNDPLAY_H
