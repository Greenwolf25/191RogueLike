#include "Menus.h"


Menus::Menus()
{

    //ctor

    inMenu = true;
    menuName = "landing page";
    mainTexture = new TextureLoader();
}



void Menus::helpMenuInit(char* fileName)
{
    helpTexture->LoadTexture(fileName);
}

void Menus::mainMenuInit(char* fileName)
{
    mainTexture->LoadTexture(fileName);
}

void Menus::landingMenuInit(char* fileName)
{
    landTexture->LoadTexture(fileName);
}

void Menus::pauseMenuInit(char* fileName)
{
    pauseTexture->LoadTexture(fileName);
}


void Menus::drawMenus(float width, float height)
{
    if(menuName != "pause menu")
    {

        if(menuName == "landing page")
        {
            landTexture->binder();
        }
        else if(menuName == "main menu")
        {
            mainTexture->binder();
        }
        else if(menuName == "help menu")
        {
            helpTexture->binder();
        }
        glPushMatrix();
        glScaled(3.33,3.33,1.0);
        glBegin(GL_QUADS);

        glTexCoord2f(0.0,1.0);
        glVertex3f(-width/height, -1.0, -8.0);

        glTexCoord2f(1.0,1.0);
        glVertex3f(width/height, -1.0, -8.0);

        glTexCoord2f(1.0,0.0);
        glVertex3f(width/height, 1.0, -8.0);

        glTexCoord2f(0.0,0.0);
        glVertex3f(-width/height, 1.0, -8.0);

        glEnd();
        glPopMatrix();
    }

    else
    {
        pauseTexture->binder();
        glPushMatrix();
        glScaled(3.33,3.33,1.0);
        glBegin(GL_QUADS);

        glTexCoord2f(0.0,1.0);
        glVertex3f(-width/height, -1.0, -8.0);

        glTexCoord2f(1.0,1.0);
        glVertex3f(width/height, -1.0, -8.0);

        glTexCoord2f(1.0,0.0);
        glVertex3f(width/height, 1.0, -8.0);

        glTexCoord2f(0.0,0.0);
        glVertex3f(-width/height, 1.0, -8.0);

        glEnd();
        glPopMatrix();
    }
}

void Menus::drawButtons()
{

}


void Menus::menuInputs(Inputs *KbMs, bool* exitGame)
{
    if(menuName == "landing page")
    {
        if(KbMs->isKeyPressed(VK_RETURN))
        {
            menuName = "main menu";
        }
        else if(KbMs->isKeyPressed(0x45))
        {
            *exitGame = true;
        }

    }
    else if(menuName == "main menu")
    {
        if(KbMs->isKeyPressed(0x4E))
        {
            inMenu = false;
            Timer::unpause();
            menuName = "in game";
        }
        else if(KbMs->isKeyPressed(0x48))
        {
            menuName = "help menu";
        }
        else if(KbMs->isKeyPressed(0x45))
        {
            *exitGame = true;
        }
    }
    else if(menuName == "help menu" && KbMs->isKeyPressed(VK_ESCAPE))
    {
        menuName = "main menu";
    }
    else if(menuName == "pause menu")
    {
        if(KbMs->isKeyPressed(VK_RETURN))
        {
            Timer::unpause();
            inMenu = false;
            menuName = "in game";
        }
        else if(KbMs->isKeyPressed(0x45))
        {
            *exitGame = true;
        }
    }
    else if(inMenu == false)
    {
        if(KbMs->isKeyPressed(VK_ESCAPE))
        {
            Timer::pause();
            menuName = "pause menu";
            inMenu = true;
        }
    }

}


Menus::~Menus()
{
    //dtor
}
