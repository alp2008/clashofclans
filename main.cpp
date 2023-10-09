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
    centrPic[0] = {300, 300, menuPic[0].pic, 150, 150, menuPic[0].w, menuPic[0].h, false, "обычные здания"};
    centrPic[1] = {300, 500, menuPic[1].pic, 150, 150, menuPic[1].w, menuPic[1].h, false, "обычные здания"};

    int vybor = -1;
    bool mouse_click = false;


/*int pic1_menu_x=20;
pic1_menu_y=100;
pic1_menu_w=120;
pic1_menu_h=120;
pic1_central_x=300;
pic1_central_y=300;
pic1_central_w=150;
pic1_central_h=150;
pic1_menu_visible = false;
pic1_central_visible = false;

pic2_menu_visible = false;
pic2_central_visible = false;
pic2_menu_x=20;
pic2_menu_y=300;
pic2_menu_w=120;
pic2_menu_h=120;
pic2_central_x=300;
pic2_central_y=500;
pic2_central_w=150;
pic2_central_h=150;*/

    while(!GetAsyncKeyState (VK_ESCAPE))
    {
        txBegin();
        txSetColor(TX_GREEN);
        txSetFillColor(TX_GREEN);
        txClear();

        for(int i=0; i<count_btn; i++)
        {
            btn[i].Draw();
        }

        for(int i=0; i<count_pic; i++)
        {
            menuPic[i].draw();
        }

        for(int i=0; i<count_pic; i++)
        {
            centrPic[i].draw();
        }
        for(int ib=0; ib<count_btn; ib++)
        {
            if(btn[ib].Click())
            {
                for(int ip=0; ip<count_pic; ip++)
                {
                    menuPic[ip].visible = false;
                    if(menuPic[ip].category == btn[ib].category)
                    {
                        menuPic[ip].visible = true;
                    }
                }
            }
        }

        for(int i=0; i<count_pic; i++)
        {
            if(txMouseButtons() == 1 &&
            txMouseX() >= centrPic[i].x &&
            txMouseX() <= centrPic[i].x + centrPic[i].w_scr &&
            txMouseY() >= centrPic[i].y &&
            txMouseY() <= centrPic[i].y + centrPic[i].h_scr &&
            centrPic[i].visible);
            {
                vybor = i;
                mouse_click = true;
            }
        }

        char str[10];
        sprintf(str, "индекс чёто там  = %d", vybor);
        txTextOut(50, 650, str);

        if(vybor>=0)
        {
            if (GetAsyncKeyState (VK_LEFT))
            {
                centrPic[vybor].x -= 5;
            }

            if (GetAsyncKeyState (VK_RIGHT))
            {
                centrPic[vybor].x += 5;
            }

            if (GetAsyncKeyState (VK_UP))
            {
                centrPic[vybor].y -= 5;
            }

            if (GetAsyncKeyState (VK_DOWN))
            {
                centrPic[vybor].y += 5;
            }

            if (GetAsyncKeyState (VK_OEM_PLUS) || (VK_ADD))
            {
                centrPic[vybor].w_scr = centrPic[vybor].w_scr * 1.1;
                centrPic[vybor].h_scr = centrPic[vybor].h_scr * 1.1;
            }

            if (GetAsyncKeyState (VK_OEM_MINUS) || (VK_SUBTRACT))
            {
                centrPic[vybor].w_scr = centrPic[vybor].w_scr * 0.9;
                centrPic[vybor].h_scr = centrPic[vybor].h_scr * 0.9;
            }
        }



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
