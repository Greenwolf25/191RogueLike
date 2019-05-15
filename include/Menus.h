#ifndef MENUS_H
#define MENUS_H
#include <TextureLoader.h>
#include <Inputs.h>
#include <Timer.h>


class Menus
{
    public:
        Menus();
        virtual ~Menus();

        void mainMenuInit(char*);
        void landingMenuInit(char*);
        void pauseMenuInit(char*);
        void helpMenuInit(char*);
        void creditMenuInit(char*);
        void gameOverMenuInit(char*);
        void victoryMenuInit(char*);
        void drawMenus(float, float);
        void drawButtons();
        void menuInputs(Inputs*, bool*);

        TextureLoader *butTexture = new TextureLoader();
        TextureLoader *pauseTexture = new TextureLoader();
        TextureLoader *landTexture = new TextureLoader();
        TextureLoader *helpTexture = new TextureLoader();
        TextureLoader *creditTexture = new TextureLoader();
        TextureLoader *gameOverTexture = new TextureLoader();
        TextureLoader *victoryTexture = new TextureLoader();

        bool inMenu;
        string menuName;

    protected:

    private:
        TextureLoader *mainTexture;
};

#endif // MENUS_H
