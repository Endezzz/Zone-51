/**********************************************************************
 *                           œ–¿ “» ¿                                 *
 *--------------------------------------------------------------------*
 * Project Type  : Win64 Console Application                          *
 * Project Name  : Zone 51                                            *
 * File Name     : main.cpp                                           *
 * Programmer(s) : ﬂˆÂ‚ ≈.¬., Ã3Œ-209¡¬-24                           *
 * Modifyed By   :                                                    *
 * Created       : 25/06/2026                                         *
 * Last Revision : 24/07/2026                                         *
 * Comment(s)    :                                                    *
 *********************************************************************/

#include <windows.h>
#include <iostream>
#include "../include/headers.h"
#include "../include/game_logic.h"


using namespace std;

HDC hdc = NULL;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

int main() {
    HWND hwnd = GetConsoleWindow();
    if(!hwnd) {
        cout << "Console Window Descriptor NOT FOUND!\n";
        return 1;
    }
    
    ShowWindow(hwnd, SW_MAXIMIZE);
    Sleep(200);

    hdc = GetWindowDC(hwnd);
    if(!hdc) {
        cout << "Handle Device Context NOT FOUND!\n";
        return 2;
    }
    
    LevelsWindow window(950,600);
    window.Show();

    GreenNLO nlo1(950, 600);
    NLO * nlo = &nlo1;
    levels(window, nlo, nlo1);
    ReleaseDC(hwnd, hdc);
    return 0;
}