#include <windows.h>
#include <iostream>
#include "../include/headers.h"

using namespace std;

HDC hdc = NULL;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

int main() {
    HWND hwnd = GetConsoleWindow();
    if(!hwnd) {
        cout << "Console Window Descriptor NOT FOUND!\n";
        return 1;
    }
    
    hdc = GetWindowDC(hwnd);
    if(!hdc) {
        cout << "Handle Device Context NOT FOUND!\n";
        return 2;
    }
    
    Point point(100, 100);
    point.Show(); 
    NLO nlo(500, 500);
    nlo.Show();
    YellowNLO nlo1(300, 300);
    nlo1.Show();
    RedNLO nlo2(600, 300);
    nlo2.Show();
    while(!KEY_DOWN(VK_ESCAPE)) {}
    
    ReleaseDC(hwnd, hdc);
    return 0;
}