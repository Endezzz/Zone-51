#include <iostream>
#include <windows.h>
#include "../include/game_logic.h"
#include "../include/headers.h"

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

using namespace std;

void levels(LevelsWindow &window, NLO * nlo) {
    while(!KEY_DOWN(VK_ESCAPE)) {
        if(KEY_DOWN('1') && window.GetState() >= 1)
            firstLevel(nlo, window);
        if(KEY_DOWN('2') && window.GetState() >= 2)
            secondLevel(nlo, window);
        if(KEY_DOWN('3') && window.GetState() >= 3)
            thirdLevel(nlo, window);   
    }
}

void firstLevel(NLO * nlo, LevelsWindow & window) {
    FirstLevelWindow window1(950, 600);
    window1.Show();
    nlo->Show();
    DWORD startTime = GetTickCount();
    while(true) { 
        MovementNLO(nlo);
        DWORD currentTime = GetTickCount();
        DWORD elapsedTime = currentTime - startTime;

        if (elapsedTime >= 30000) { 
            break;
        }
    }
    if(window.GetState() < 2) window.SetState(2);
    window.Show();
}

void secondLevel(NLO * nlo, LevelsWindow &window) {
    SecondLevelWindow window2(950, 600);
    window2.Show();
    nlo->Show();
    DWORD startTime = GetTickCount();
    while(true) { 
        MovementNLO(nlo);
        DWORD currentTime = GetTickCount();
        DWORD elapsedTime = currentTime - startTime;

        if (elapsedTime >= 60000) { 
            break;
        }
    }
    if(window.GetState() < 3) window.SetState(3);
    window.Show();
}

void thirdLevel(NLO * nlo, LevelsWindow &window) {
    ThirdLevelWindow window3(950, 600);
    window3.Show();
    nlo->Show();
    DWORD startTime = GetTickCount();
    while(true) { 
        MovementNLO(nlo);
        DWORD currentTime = GetTickCount();
        DWORD elapsedTime = currentTime - startTime;

        if (elapsedTime >= 90000) { 
            break;
        }
    }
    window.Show();
}

void MovementNLO(NLO * nlo) {
    int speed = 1;
    DWORD currentTime = GetTickCount();
    if (currentTime%10 == 0){
        if(KEY_DOWN('W'))
        {
            if(nlo->GetY()-speed > 250 + nlo->GetHeight()/2+5)
                nlo->MoveTo(nlo->GetX(), nlo->GetY()-speed);
        }
        if(KEY_DOWN('S'))
        {
            if(nlo->GetY()+speed < 950 - nlo->GetHeight()/2-5)
                nlo->MoveTo(nlo->GetX(), nlo->GetY()+speed);
        }
        if(KEY_DOWN('A'))
        {
            if(nlo->GetX()-speed > 350 + nlo->GetWidth()/2+15)
                nlo->MoveTo(nlo->GetX()-speed, nlo->GetY());
        }
        if(KEY_DOWN('D'))
        {
            if(nlo->GetX()+speed < 1550 - nlo->GetWidth()/2-15)
                nlo->MoveTo(nlo->GetX()+speed, nlo->GetY());
        }
    }
}