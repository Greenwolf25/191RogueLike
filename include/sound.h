#ifndef SOUND_H
#define SOUND_H
#include <SNDS/irrKlang.h>
#include <iostream>

#pragma comment(lib, "irrKlang.lib")

using namespace irrklang;
using namespace std;

class sound
{
    public:
        sound();
        virtual ~sound();
        //bgm & sfx
        void playSound(char *);
        void playMusic(char *);
        void cease();
        int  initSounds();

        ISoundEngine* engine = createIrrKlangDevice();//creates engine

    protected:

    private:

};

#endif // SOUND_H
