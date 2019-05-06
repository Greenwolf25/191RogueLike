#include "sound.h"

sound::sound()
{
    //ctor

}

sound::~sound()
{
    //dtor
    engine->drop();
}
void sound::playSound(char* fileName)
{
    engine->play2D(fileName, false, false); //other false is to make it not reopeat
}

void sound::playMusic(char* fileName) //plays the sound we want
{
    engine->play2D(fileName, true);
}

void sound::cease()
{

}

int sound::initSounds()
{
 if(!engine)
    {
        cout << "could not start engine\n";
        return 0;// only if u want to quit the game
    }
    return 1;
}
