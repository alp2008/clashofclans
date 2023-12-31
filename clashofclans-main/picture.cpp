#include "TXLib.h"
struct Picture
{
    int x;
    int y;
    HDC pic;
    string adress;
    int w_scr;
    int h_scr;
    int w;
    int h;
    bool visible;
    string category;

    void Draw()
{
    if(visible)
    {
        Win32::TransparentBlt (txDC(),x ,y ,w_scr,h_scr,pic,0,0,w,h,TX_BLACK);
    }
}

    bool Click()
{
    return( txMouseButtons() == 1 &&
            txMouseX() >= x && txMouseX() <= x+w_scr &&
            txMouseY() >= y && txMouseY() <= y+h_scr);
}

};

