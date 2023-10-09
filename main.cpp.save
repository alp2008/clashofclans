#include "TXLib.h"
struct Button
{
    int x;
    const char* name;

    string category;

    void Draw()
    {
        txSetColor(TX_TRANSPARENT);
        txSetFillColor(TX_GREY);
        Win32::RoundRect (txDC(), x+5, 35, x+155, 75, 30, 30);
        txSetColor(TX_BLACK, 3);
        txSetFillColor(TX_WHITE);
        Win32::RoundRect (txDC(), x, 30, x+150, 70, 30, 30);
        txSetColor(TX_BLACK);
        txSelectFont("Arial", 24);
        txDrawText(x, 30, x+150, 70, name);
    }

    bool Click()
    {
        return(txMouseButtons() == 1 &&
        txMouseX()>= x && txMouseX()<=x+150 &&
        txMouseY()>= 35 && txMouseY()<=75);
    }
};

struct Picture
{
    int x;
    int y;
    HDC pic;
    int w_scr;
    int h_scr;
    int w;
    int h;
    bool visible;
    string category;

    void draw()
{
    if(visible)
    {
        Win32::TransparentBlt (txDC(),x ,y ,w_scr,h_scr,pic,0,0,w,h,TX_white);
    }
}

    bool Click()
{
    return( txMouseButtons() == 1 &&
            txMouseX() >= 20 && txMouseX() <= 100 &&
            txMouseY() >= y && txMouseY() <= y+200);
}

};

int main()
{
    txCreateWindow (1200, 700);
    //инициализация кнопок
    int count_btn=2;
    int count_pic=2;
    Button btn[count_btn];
    btn[0] = {50, "обычные здания", "обычные здания"};
    btn[1] = {250, "защитные здания", "защитные здания"};

    Picture menuPic[count_pic];
    menuPic[0] = {20, 100, txLoadImage ("pictures/build/ratusha.bmp"), 120, 120, 300, 300, false, "обычные здания"};
    menuPic[1] = {20, 300, txLoadImage ("pictures/defense/gun.bmp"), 120, 120, 300, 300, false, "обычные здания"};

    Picture centrPic[count_pic];
    centrPic[0] = {300, 300, menuPic[0].pic, 150, 150, 300, 300, false, "обычные здания"};
    centrPic[1] = {300, 500, menuPic[1].pic, 150, 150, 300, 300, false, "обычные здания"};


    /*int pic1_menu_x=20;
    int pic1_menu_y=100;
    int pic1_menu_w=120;
    int pic1_menu_h=120;
    int pic1_central_x=300;
    int pic1_central_y=300;
    int pic1_central_w=150;
    int pic1_central_h=150;
    bool pic1_menu_visible = false;
    bool pic1_central_visible = false;

    bool pic2_menu_visible = false;
    bool pic2_central_visible = false;
    int pic2_menu_x=20;
    int pic2_menu_y=300;
    int pic2_menu_w=120;
    int pic2_menu_h=120;
    int pic2_central_x=300;
    int pic2_central_y=500;
    int pic2_central_w=150;
    int pic2_central_h=150;*/

    while(!GetAsyncKeyState (VK_ESCAPE))
    {
        txBegin();
        txSetColor(TX_GREEN);
        txSetFillColor(TX_GREEN);
        txClear();

        for (int i=0; i<count_btn; i++)
        {
            btn[i].Draw();
        }

        for (int i=0;i<count_pic; i++)
        {
            menuPic[i].draw();
        }

        for (int i=0;i<count_pic; i++)
        {
            centrPic[i].draw();
        }

        for (int ib=0;ib<count_btn; ib++)
        {
            if(btn[ib].Click())
            {
                for (int ip=0;ip<count_pic; ip++)
            {
                menuPic[ip].visible= false;
                if(menuPic[ip].category == btn[ib].category)
                    {
                        menuPic[ip].visible= true;
                    }
                }
            }
        }

    if(menuPic[0].Click()&& menuPic[0].visible)
    {
        centrPic[0].visible =true;
    }

    if(menuPic[1].Click()&& menuPic[1].visible)
    {
        centrPic[1].visible =true;
    }

    if(menuPic[2].Click()&& menuPic[2].visible)
    {
        centrPic[2].visible =true;
    }

        /*if(btn[0].Click())
        {
            menuPic[0].visible = true;
            menuPic[1].visible = true;
        }

        if(menuPic[0].visible)
        {
            Draw(menuPic[0].x, menuPic[0].y, menuPic[0].w, menuPic[0].h, menuPic[0]);
        }

        if(pic2_menu_visible)
        {
            DrawPicture(pic2_menu_x, pic2_menu_y, pic2_menu_w, pic2_menu_h, pic2);
        }

        if(clickPictures(100))
        {
            pic1_central_visible = true;
        }

        if(pic1_central_visible)
        {
            DrawPicture(pic1_central_x, pic1_central_y, pic1_central_w, pic1_central_h, pic1);
        }

        if(clickPictures(250))
        {
            pic2_central_visible = true;
        }

        if(pic2_central_visible)
        {
            DrawPicture(pic2_central_x, pic2_central_y, pic2_central_w, pic2_central_h, pic2);
        }*/

        txSleep(50);
        txEnd();
    }

    for (int i=0; i<count_pic; i++)
    {
        txDeleteDC(menuPic[i].pic);
    }
    for (int i=0; i<count_pic; i++)
    {
        txDeleteDC(centrPic[i].pic);
    }

txDisableAutoPause();
txTextCursor (false);
return 0;
}
