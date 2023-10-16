#include "TXLib.h"
#include "button.cpp"
#include "picture.cpp"

int main()
{
    txCreateWindow (1200, 700);
    //������������� ������
    int count_btn=2;
    int count_pic=2;
    Button btn[count_btn];
    btn[0] = {50, "������� ������", "������� ������"};
    btn[1] = {250, "�������� ������", "�������� ������"};

    Picture menuPic[count_pic];
    menuPic[0] = {20, 100, txLoadImage ("pictures/build/ratusha.bmp"), 120, 120, 225, 225, false, "������� ������"};
    menuPic[1] = {20, 300, txLoadImage ("pictures/defense/gun.bmp"), 120, 120, 225, 225, false, "������� ������"};

    Picture centrPic[100];

    int vybor = -1;
    bool mouse_click = false;
    int nCentrPic = 0;
    int npic = 0;

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
            menuPic[i].Draw();
        }

        for(int i=0; i<count_pic; i++)
        {
            centrPic[i].Draw();
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
            if(menuPic[i].Click() && menuPic[i].visible)
            {
                while(txMouseButtons() == 1)
                {
                    txSleep(10);
                }
                centrPic[nCentrPic]  = {500,
                                        100,
                                        menuPic[npic].pic,
                                        menuPic[npic].w,
                                        menuPic[npic].h,
                                        menuPic[npic].w,
                                        menuPic[npic].h,
                                        menuPic[npic].visible,
                                        menuPic[npic].category};

                nCentrPic ++;
            }
        }


        for(int i=0; i<count_pic; i++)
        {
            if(centrPic[i].Click() && centrPic[i].visible)
            {
                vybor = i;
                mouse_click = false;
            }
        }


        char str[10];
        sprintf(str, "������ ���� ���  = %d", vybor);
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

            if (GetAsyncKeyState (VK_OEM_PLUS) || GetAsyncKeyState(VK_ADD))
            {
                centrPic[vybor].w_scr = centrPic[vybor].w_scr * 1.1;
                centrPic[vybor].h_scr = centrPic[vybor].h_scr * 1.1;
            }

            if (GetAsyncKeyState (VK_OEM_MINUS) || GetAsyncKeyState(VK_SUBTRACT))
            {
                centrPic[vybor].w_scr = centrPic[vybor].w_scr * 0.9;
                centrPic[vybor].h_scr = centrPic[vybor].h_scr * 0.9;
            }
        }

        if(vybor>=0)
        {
            if(txMouseButtons() == 1 && !mouse_click)
            {
                centrPic[vybor].x = txMouseX() - centrPic[vybor].w_scr/2;
                centrPic[vybor].y = txMouseY() - centrPic[vybor].h_scr/2;
            }
            else
            {
                if(txMouseButtons() !=1)
                {
                    mouse_click = true;
                }
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
