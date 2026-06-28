#include <iostream>
#include <windows.h>
#include "../include/headers.h"

using namespace std;
//-----------------------| P O I N T |-----------------------------//
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

//-------------------------| N L O |-----------------------------//