#include <iostream>
#include <windows.h>
#include "../include/headers.h"

using namespace std;
//-----------------------[ P O I N T ]-----------------------------//
Point :: Point(int InitX, int InitY) {
    x = InitX;
    y = InitY;   
}

Point :: ~Point() {}

int Point :: GetX() {
    return x;
}

int Point :: GetY() {
    return y;
}

bool Point :: GetVisible() {
    return visible;
}

void Point :: SetX(int NewX) {
    x = NewX;
}

void Point :: SetY(int NewY) {
    y = NewY;
}

void Point :: SetVisible(bool NewVisible) {
    visible = NewVisible;
}

void Point :: Show() {
    SetPixel(hdc, GetX(), GetY(), (255,255,255));
}

void Point :: Hide() {    
    SetPixel(hdc, GetX(), GetY(), (0,0,0));
}

void Point :: MoveTo(int NewX, int NewY) {
    Hide();
    SetX(NewX);
    SetY(NewY);
    Show();
}

//-------------------------[ N L O ]------------------------------//
NLO :: NLO(int InitX, int InitY) : Point(InitX, InitY) {}

NLO :: ~NLO() {}

void NLO :: Show() {
    DrawWindow();
    DrawCabin();
    DrawAlien();
}

void NLO :: Hide() {
    int x1 = GetX() - width/4, y1 = GetY() - height/2;
    int x2 = GetX() + width/4, y2 = GetY() + height/10;

    HPEN blackPen = CreatePen(PS_SOLID, 3, RGB(0,0,0));
    HBRUSH blackBrush = CreateSolidBrush(RGB(0,0,0));

    SelectObject(hdc, blackBrush);
    SelectObject(hdc, blackPen);

    Ellipse(hdc, x1, y1, x2, y2);

    x1 = GetX() - width/2;
    y1 = GetY() - height/12;
    x2 = GetX() + width/2;
    y2 = GetY() + height/2;

    Ellipse(hdc, x1, y1, x2, y2);

    x1 = GetX() - width/2 - width/15;
    y1 = GetY() + height/5;
    x2 = GetX() + width/2 + width/15;
    y2 = GetY() + height/5 + height/15;
    
    Ellipse(hdc, x1, y1, x2, y2);

    DeleteObject(blackBrush);
    DeleteObject(blackPen);
}

void NLO :: DrawWindow() {
    int x1 = GetX() - width/4, y1 = GetY() - height/2;
    int x2 = GetX() + width/4, y2 = GetY() + height/10;

    HPEN bluePen = CreatePen(PS_SOLID, 3, RGB(0,0,255));
    HBRUSH lightBlueBrush = CreateSolidBrush(RGB(156,220,255));
    HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0,200,0));
    HBRUSH greenBrush = CreateSolidBrush(RGB(0,200,0));

    SelectObject(hdc, bluePen);
    SelectObject(hdc, lightBlueBrush);

    Ellipse(hdc, x1, y1, x2, y2);

    SelectObject(hdc, greenPen);
    SelectObject(hdc, greenBrush);

    x1 = GetX() - width/5;
    y1 = GetY() - height/2.5;
    x2 = GetX() + width/5;
    y2 = GetY() + height/10;

    Ellipse(hdc, x1, y1, x2, y2);

    DeleteObject(bluePen);
    DeleteObject(lightBlueBrush);
    DeleteObject(greenBrush);
    DeleteObject(greenPen);    
}

void NLO :: DrawCabin() {
    int x1 = GetX() - width/2, y1 = GetY() - height/12;
    int x2 = GetX() + width/2, y2 = GetY() + height/2;

    HPEN bluePen = CreatePen(PS_SOLID, 3, RGB(0,0,255));
    HBRUSH blueBrush = CreateSolidBrush(RGB(0,0,255));
    HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0,200,0));
    HBRUSH greenBrush = CreateSolidBrush(RGB(0,200,0));

    SelectObject(hdc, blueBrush);
    SelectObject(hdc, bluePen); 

    Ellipse(hdc, x1, y1, x2, y2);

    SelectObject(hdc, greenBrush);
    SelectObject(hdc, greenPen); 

    x1 = GetX() - width/2 - width/15;
    y1 = GetY() + height/5;
    x2 = GetX() + width/2 + width/15;
    y2 = GetY() + height/5 + height/15;
    
    Ellipse(hdc, x1, y1, x2, y2);

    DeleteObject(blueBrush);
    DeleteObject(bluePen);
    DeleteObject(greenBrush);
    DeleteObject(greenPen);
}

void NLO :: DrawAlien() {
    int x1 = GetX() - width/14, y1 = GetY() - height/3;
    int x2 = GetX() + width/14, y2 = GetY() - height/15;

    HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0,100,0));
    HBRUSH greenBrush = CreateSolidBrush(RGB(0,100,0));
    HPEN whitePen = CreatePen(PS_SOLID, 2, RGB(255,255,255));
    HBRUSH whiteBrush = CreateSolidBrush(RGB(255,255,255));

    SelectObject(hdc, greenBrush);
    SelectObject(hdc, greenPen);

    Ellipse(hdc, x1, y1, x2, y2);

    SelectObject(hdc, whiteBrush);
    SelectObject(hdc, whitePen);

    x1 = GetX() - width/17;
    y1 = GetY() - height/4.5;
    x2 = GetX() - width/60;
    y2 = GetY() - height/5;

    Ellipse(hdc, x1, y1, x2, y2);

    x1 = GetX() + width/60;
    y1 = GetY() - height/4.5;
    x2 = GetX() + width/17;
    y2 = GetY() - height/5;

    Ellipse(hdc, x1, y1, x2, y2);

    DeleteObject(greenBrush);
    DeleteObject(greenPen);
}

//-------------------[ Y E L L O W    N L O ]---------------------//
YellowNLO :: YellowNLO(int InitX, int InitY) : NLO(InitX, InitY) {}

YellowNLO :: ~YellowNLO() {}

void YellowNLO :: DrawWindow() {
    int x1 = GetX() - width/4, y1 = GetY() - height/2;
    int x2 = GetX() + width/4, y2 = GetY() + height/10;

    HPEN bluePen = CreatePen(PS_SOLID, 3, RGB(0,0,255));
    HBRUSH lightBlueBrush = CreateSolidBrush(RGB(156,220,255));
    HPEN yellowPen = CreatePen(PS_SOLID, 2, RGB(255,255,0));
    HBRUSH yellowBrush = CreateSolidBrush(RGB(255,255,0));

    SelectObject(hdc, bluePen);
    SelectObject(hdc, lightBlueBrush);

    Ellipse(hdc, x1, y1, x2, y2);

    SelectObject(hdc, yellowPen);
    SelectObject(hdc, yellowBrush);

    x1 = GetX() - width/5;
    y1 = GetY() - height/2.5;
    x2 = GetX() + width/5;
    y2 = GetY() + height/10;

    Ellipse(hdc, x1, y1, x2, y2);

    DeleteObject(bluePen);
    DeleteObject(lightBlueBrush);
    DeleteObject(yellowBrush);
    DeleteObject(yellowPen); 
}

void YellowNLO :: DrawAlien() {
    int x1 = GetX() - width/14, y1 = GetY() - height/3;
    int x2 = GetX() + width/14, y2 = GetY() - height/15;

    HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0,100,0));
    HBRUSH greenBrush = CreateSolidBrush(RGB(0,100,0));
    HPEN whitePen = CreatePen(PS_SOLID, 2, RGB(255,255,255));
    HBRUSH whiteBrush = CreateSolidBrush(RGB(255,255,255));

    SelectObject(hdc, greenBrush);
    SelectObject(hdc, greenPen);

    Ellipse(hdc, x1, y1, x2, y2);

    SelectObject(hdc, whiteBrush);
    SelectObject(hdc, whitePen);

    x1 = GetX() - width/17;
    y1 = GetY() - height/3.5;
    x2 = GetX() - width/60;
    y2 = GetY() - height/5;

    Ellipse(hdc, x1, y1, x2, y2);

    x1 = GetX() + width/60;
    y1 = GetY() - height/3.5;
    x2 = GetX() + width/17;
    y2 = GetY() - height/5;

    Ellipse(hdc, x1, y1, x2, y2);

    DeleteObject(greenBrush);
    DeleteObject(greenPen);
}

void YellowNLO :: DrawCabin() {
    int x1 = GetX() - width/2, y1 = GetY() - height/12;
    int x2 = GetX() + width/2, y2 = GetY() + height/2;

    HPEN bluePen = CreatePen(PS_SOLID, 3, RGB(0,0,255));
    HBRUSH blueBrush = CreateSolidBrush(RGB(0,0,255));
    HPEN yellowPen = CreatePen(PS_SOLID, 2, RGB(255,255,0));
    HBRUSH yellowBrush = CreateSolidBrush(RGB(255,255,0));

    SelectObject(hdc, blueBrush);
    SelectObject(hdc, bluePen); 

    Ellipse(hdc, x1, y1, x2, y2);

    SelectObject(hdc, yellowBrush);
    SelectObject(hdc, yellowPen); 

    x1 = GetX() - width/2 - width/15;
    y1 = GetY() + height/5;
    x2 = GetX() + width/2 + width/15;
    y2 = GetY() + height/5 + height/15;
    
    Ellipse(hdc, x1, y1, x2, y2);

    DeleteObject(blueBrush);
    DeleteObject(bluePen);
    DeleteObject(yellowBrush);
    DeleteObject(yellowPen);
}

//-----------------------[ R E D   N L O ]-----------------------//
RedNLO :: RedNLO(int InitX, int InitY) : NLO(InitX, InitY) {}

RedNLO :: ~RedNLO() {}

void RedNLO :: DrawWindow() {
    int x1 = GetX() - width/4, y1 = GetY() - height/2;
    int x2 = GetX() + width/4, y2 = GetY() + height/10;

    HPEN bluePen = CreatePen(PS_SOLID, 3, RGB(0,0,255));
    HBRUSH lightBlueBrush = CreateSolidBrush(RGB(156,220,255));
    HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255,0,0));
    HBRUSH redBrush = CreateSolidBrush(RGB(255,0,0));

    SelectObject(hdc, bluePen);
    SelectObject(hdc, lightBlueBrush);

    Ellipse(hdc, x1, y1, x2, y2);

    SelectObject(hdc, redPen);
    SelectObject(hdc, redBrush);

    x1 = GetX() - width/5;
    y1 = GetY() - height/2.5;
    x2 = GetX() + width/5;
    y2 = GetY() + height/10;

    Ellipse(hdc, x1, y1, x2, y2);

    DeleteObject(bluePen);
    DeleteObject(lightBlueBrush);
    DeleteObject(redBrush);
    DeleteObject(redPen);    
}

void RedNLO :: DrawCabin() {
    int x1 = GetX() - width/2, y1 = GetY() - height/12;
    int x2 = GetX() + width/2, y2 = GetY() + height/2;

    HPEN bluePen = CreatePen(PS_SOLID, 3, RGB(0,0,255));
    HBRUSH blueBrush = CreateSolidBrush(RGB(0,0,255));
    HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255,0,0));
    HBRUSH redBrush = CreateSolidBrush(RGB(255,0,0));

    SelectObject(hdc, blueBrush);
    SelectObject(hdc, bluePen); 

    Ellipse(hdc, x1, y1, x2, y2);

    SelectObject(hdc, redBrush);
    SelectObject(hdc, redPen); 

    x1 = GetX() - width/2 - width/15;
    y1 = GetY() + height/5;
    x2 = GetX() + width/2 + width/15;
    y2 = GetY() + height/5 + height/15;
    
    Ellipse(hdc, x1, y1, x2, y2);

    DeleteObject(blueBrush);
    DeleteObject(bluePen);
    DeleteObject(redBrush);
    DeleteObject(redPen);
}

void RedNLO :: DrawAlien() {
    int x1 = GetX() - width/14, y1 = GetY() - height/3;
    int x2 = GetX() + width/14, y2 = GetY() - height/15;

    HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0,100,0));
    HBRUSH greenBrush = CreateSolidBrush(RGB(0,100,0));
    HPEN whitePen = CreatePen(PS_SOLID, 2, RGB(255,255,255));
    HBRUSH whiteBrush = CreateSolidBrush(RGB(255,255,255));
    HPEN blackPen = CreatePen(PS_SOLID, 2, RGB(0,0,0));
    HBRUSH blackBrush = CreateSolidBrush(RGB(0,0,0));

    SelectObject(hdc, greenBrush);
    SelectObject(hdc, greenPen);

    Ellipse(hdc, x1, y1, x2, y2);

    SelectObject(hdc, whiteBrush);
    SelectObject(hdc, whitePen);

    x1 = GetX() - width/17;
    y1 = GetY() - height/3.5;
    x2 = GetX() - width/60;
    y2 = GetY() - height/5;

    Ellipse(hdc, x1, y1, x2, y2);

    x1 = GetX() + width/60;
    y1 = GetY() - height/3.5;
    x2 = GetX() + width/17;
    y2 = GetY() - height/5;

    Ellipse(hdc, x1, y1, x2, y2);

    SelectObject(hdc, blackBrush);
    SelectObject(hdc, blackPen);

    x1 = GetX() + width/60;
    y1 = GetY() - height/6;
    x2 = GetX() - width/60;
    y2 = GetY() - height/8;

    Ellipse(hdc, x1, y1, x2, y2);

    DeleteObject(greenBrush);
    DeleteObject(greenPen);
    DeleteObject(blackPen);
    DeleteObject(blackBrush);
}
