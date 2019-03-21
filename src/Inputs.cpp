#include "Inputs.h"
#include <iostream>

Inputs::Inputs()
{
    //ctor

    prev_mouse_X = 0;
    prev_mouse_Y = 0;
    mouse_Translate = false;
    mouse_Rotate = false;
    keys = new bool[221];

}

Inputs::~Inputs()
{
    //dtor
}

void Inputs::keyPressed()
{
    cout << wParam << "true" << endl;
    if(wParam < 221) keys[wParam] = true;

    /*switch(wParam){
        case VK_LEFT:
            Mdl->RotateX -= 1.0;
            break;
        case VK_RIGHT:
            Mdl->RotateX += 1.0;
            break;
        case VK_UP:
            Mdl->RotateY -= 1.0;
            break;
        case VK_DOWN:
            Mdl->RotateY += 1.0;
            break;
        case 0x41:
            Mdl->Zoom += 1.0;
            break;
        case 0x44:
            Mdl->Zoom -= 1.0;
            break;
    }*/
}

void Inputs::keyUp()
{
    cout << wParam << "false" << endl;
    if(wParam < 221) keys[wParam] = false;
}

void Inputs::mouseEventDown(double x, double y)
{
    prev_mouse_X = x;
    prev_mouse_Y = y;

    switch(wParam)
    {
        case MK_LBUTTON:
            mouse_Rotate = true;
            break;
        case MK_RBUTTON:
            mouse_Translate = true;
            break;
        default: break;

    }
}

void Inputs::mouseEventUp()
{
    switch(wParam)
    {
        case MK_LBUTTON: // reset values
            mouse_Rotate = false;
            break;
        case MK_RBUTTON:
            mouse_Translate = false;
            break;
        default: break;
    }
}

void Inputs::mouseEventWheel(Model* Mdl, double delta)
{
    Mdl->Zoom += delta/100.0;
}

void Inputs::mouseEventMove(Model* Mdl, double x, double y)
{
        if(mouse_Translate){
            Mdl->xPos += (x-prev_mouse_X)/100;
            Mdl->yPos -= (y-prev_mouse_Y)/100;

            prev_mouse_X = x;
            prev_mouse_Y = y;
        }
        if(mouse_Rotate){
            Mdl->RotateX += (x-prev_mouse_X)/3;
            Mdl->RotateY -= (y-prev_mouse_Y)/3;

            prev_mouse_X = x;
            prev_mouse_Y = y;
        }
}

void Inputs::keyEnv(Parallax* Plx, float speed)
{
    switch(wParam){
        case VK_LEFT:
            Plx->scroll("left",speed);
            break;
        case VK_RIGHT:
            Plx->scroll("right",speed);
            break;
        case VK_UP:
            Plx->scroll("up",speed);
            break;
        case VK_DOWN:
            Plx->scroll("down",speed);
            break;
    }
}


bool Inputs::isKeyPressed(int keyCode)
{
    return keys[keyCode];
}

