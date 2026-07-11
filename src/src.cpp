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

int NLO :: GetHeight() {
    return height;
}

int NLO :: GetWidth() {
    return width;
}

int NLO :: GetHealth() {
    return health;
}

bool NLO :: GetMoveable() {
    return moveable;
}

bool NLO :: GetShield() {
    return shield;
}

void NLO :: SetShield(bool NewShield) {
    shield = NewShield;
}

void NLO :: SetMoveable(bool NewMoveable) {
    moveable = NewMoveable;
}

void NLO :: SetHeight(int NewHealth) {
    health = NewHealth;
}

void NLO :: SetWidth(int NewWidth) {
    width = NewWidth;
}

void NLO :: SetHealth(int NewHealth) {
    health = NewHealth;
}

void NLO :: TurnOf() {
    int x1 = GetX() - width/4, y1 = GetY() - height/2;
    int x2 = GetX() + width/4, y2 = GetY() + height/10;

    HPEN bluePen = CreatePen(PS_SOLID, 3, RGB(0,0,255));
    HBRUSH blueBrush = CreateSolidBrush(RGB(0,0,255));
    HBRUSH lightBlueBrush = CreateSolidBrush(RGB(156,220,255));
    HPEN grayPen = CreatePen(PS_SOLID, 2, RGB(50,50,50));
    HBRUSH grayBrush = CreateSolidBrush(RGB(50,50,50));

    SelectObject(hdc, bluePen);
    SelectObject(hdc, lightBlueBrush);

    Ellipse(hdc, x1, y1, x2, y2);

    SelectObject(hdc, grayPen);
    SelectObject(hdc, grayBrush);

    x1 = GetX() - width/5;
    y1 = GetY() - height/2.5;
    x2 = GetX() + width/5;
    y2 = GetY() + height/10;

    Ellipse(hdc, x1, y1, x2, y2);

    x1 = GetX() - width/2;
    y1 = GetY() - height/12;
    x2 = GetX() + width/2;
    y2 = GetY() + height/2;


    SelectObject(hdc, blueBrush);
    SelectObject(hdc, bluePen); 

    Ellipse(hdc, x1, y1, x2, y2);

    SelectObject(hdc, grayBrush);
    SelectObject(hdc, grayPen); 

    x1 = GetX() - width/2 - width/15;
    y1 = GetY() + height/5;
    x2 = GetX() + width/2 + width/15;
    y2 = GetY() + height/5 + height/15;
    
    Ellipse(hdc, x1, y1, x2, y2);

    DeleteObject(blueBrush);
    DeleteObject(bluePen);
    DeleteObject(lightBlueBrush);
    DeleteObject(grayBrush);
    DeleteObject(grayPen); 
}

void NLO :: Show() {
    HBRUSH blackBrush = CreateSolidBrush(RGB(0,0,0));
    HPEN lightBluePen = CreatePen(PS_SOLID, 2, RGB(156,220,255));
    SelectObject(hdc, blackBrush);
    SelectObject(hdc, lightBluePen);
    int x1 = x - width/1.5, y1 = y - width/1.5;
    int x2 = x + width/1.5, y2 = y + width/1.5;
    if(GetShield()) {
        Ellipse(hdc, x1, y1, x2, y2);
    }
    DrawWindow();
    DrawCabin();
    DrawAlien();
    DeleteObject(blackBrush);
    DeleteObject(lightBluePen);
}

void NLO :: Hide() {
    
    int x1, y1, x2, y2;

    HPEN blackPen = CreatePen(PS_SOLID, 3, RGB(0,0,0));
    HBRUSH blackBrush = CreateSolidBrush(RGB(0,0,0));
    SelectObject(hdc, blackBrush);
    SelectObject(hdc, blackPen);

    if(GetShield()) {
        x1 = x - width/1.5, y1 = y - width/1.5;
        x2 = x + width/1.5, y2 = y + width/1.5;
        Ellipse(hdc, x1, y1, x2, y2);
    }
    else {
        x1 = GetX() - width/4;
        y1 = GetY() - height/2;
        x2 = GetX() + width/4;
        y2 = GetY() + height/10;
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
    }

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
    DeleteObject(whiteBrush);
    DeleteObject(whitePen);
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

    DeleteObject(whitePen);
    DeleteObject(whiteBrush);
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
    DeleteObject(whiteBrush);
    DeleteObject(whitePen);
}


//------------------------[ W I N D O W ]-----------------------//
Window :: Window(int InitX, int InitY) : Point(InitX, InitY) {}

Window :: ~Window() {}

int Window :: GetState() {
    return state;
}

void Window :: SetState(int NewState) {
    state = NewState;
}


//---------------[ L E V E L S     W I N D O W ]----------------//
LevelsWindow :: LevelsWindow(int InitX, int InitY) : Window(InitX, InitY) {}

LevelsWindow :: ~LevelsWindow() {}

void LevelsWindow :: Show() {
    HBRUSH background = CreateSolidBrush(RGB(0,0,0));
    HPEN circuit = CreatePen(PS_SOLID, 4, RGB(0,0,255));
    HPEN whitePen = CreatePen(PS_SOLID, 3, RGB(255,255,255));

    SelectObject(hdc, background);
    SelectObject(hdc, circuit);

    int x1 = GetX() - width/2;
    int y1 = GetY() - height/2;
    int x2 = GetX() + width/2;
    int y2 = GetY() + height/2;

    Rectangle(hdc, x1, y1, x2, y2);

    x1 = GetX() - width/2;
    y1 = GetY() - height/2 - height/5;
    x2 = GetX() + width/2;
    y2 = GetY() - height/2;

    Rectangle(hdc, x1, y1, x2, y2);

    SetTextColor(hdc, RGB(255, 255, 255));  
    SetBkMode(hdc, TRANSPARENT);       

    // Создание большого шрифта
    HFONT hFont = CreateFont(
        48,                     // Высота шрифта (увеличена)
        0,                      // Ширина (0 = автоматически)
        0,                      // Угол наклона
        0,                      // Направление
        FW_BOLD,                // Жирный шрифт
        FALSE,                  // Не курсив
        FALSE,                  // Не подчёркнутый
        FALSE,                  // Не зачёркнутый
        DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY,
        DEFAULT_PITCH | FF_SWISS,
        TEXT("Arial")
    );

    HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

    RECT textRect = {x1, y1, x2, y2};
    DrawText(hdc, TEXT("ZONE 51"), -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    
    SelectObject(hdc, hOldFont);
    DeleteObject(hFont);

    SelectObject(hdc, whitePen);
    if(GetState() > 0) {
        x1 = 600;
        y1 = 550;
        x2 = 625;
        y2 = 700;

        Rectangle(hdc, x1, y1, x2, y2);
    }

    if(GetState() > 1) {
        x1 = 900;
        y1 = 550;
        x2 = 925;
        y2 = 700;

        Rectangle(hdc, x1, y1, x2, y2);

        x1 = 975;
        y1 = 550;
        x2 = 1000;
        y2 = 700;

        Rectangle(hdc, x1, y1, x2, y2);
    }

    if(GetState() > 2) {
        x1 = 1225;
        y1 = 550;
        x2 = 1250;
        y2 = 700;

        Rectangle(hdc, x1, y1, x2, y2);

        x1 = 1300;
        y1 = 550;
        x2 = 1325;
        y2 = 700;

        Rectangle(hdc, x1, y1, x2, y2);

        x1 = 1375;
        y1 = 550;
        x2 = 1400;
        y2 = 700;

        Rectangle(hdc, x1, y1, x2, y2);
    }

    DeleteObject(background);
    DeleteObject(circuit);
    DeleteObject(whitePen);
} 

void LevelsWindow :: Hide() {
    HBRUSH background = CreateSolidBrush(RGB(0,0,0));
    HPEN circuit = CreatePen(PS_SOLID, 4, RGB(0,0,0));

    SelectObject(hdc, background);
    SelectObject(hdc, circuit);

    int x1 = GetX() - width/2;
    int y1 = GetY() - height/2;
    int x2 = GetX() + width/2;
    int y2 = GetY() + height/2;

    Rectangle(hdc, x1, y1, x2, y2);

    x1 = GetX() - width/2;
    y1 = GetY() - height/2 - height/5;
    x2 = GetX() + width/2;
    y2 = GetY() - height/2;

    Rectangle(hdc, x1, y1, x2, y2);

    DeleteObject(background);
    DeleteObject(circuit);
}


//--------[ F I R S T   L E V E L    W I N D O W ]--------------//
FirstLevelWindow :: FirstLevelWindow(int InitX, int InitY) : LevelsWindow(InitX, InitY) {}

FirstLevelWindow :: ~FirstLevelWindow() {}

void FirstLevelWindow :: Show() {
    HBRUSH background = CreateSolidBrush(RGB(0,0,0));
    HPEN circuit = CreatePen(PS_SOLID, 4, RGB(0,0,255));

    SelectObject(hdc, background);
    SelectObject(hdc, circuit);

    int x1 = GetX() - width/2;
    int y1 = GetY() - height/2;
    int x2 = GetX() + width/2;
    int y2 = GetY() + height/2;

    Rectangle(hdc, x1, y1, x2, y2);

    x1 = GetX() - width/2;
    y1 = GetY() - height/2 - height/5;
    x2 = GetX() + width/2;
    y2 = GetY() - height/2;

    Rectangle(hdc, x1, y1, x2, y2);

    SetTextColor(hdc, RGB(255, 255, 255)); 
    SetBkMode(hdc, TRANSPARENT);       

    HFONT hFont = CreateFont(
        48,                    
        0,                      
        0,                      
        0,                     
        FW_BOLD,                
        FALSE,                 
        FALSE,                  
        FALSE,                  
        DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY,
        DEFAULT_PITCH | FF_SWISS,
        TEXT("Arial")
    );

    HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

    RECT textRect = {x1, y1, x2-50, y2};
    DrawText(hdc, TEXT("LEVEL 1"), -1, &textRect, DT_RIGHT | DT_VCENTER | DT_SINGLELINE);

    SelectObject(hdc, hOldFont);
    DeleteObject(hFont);

    DeleteObject(background);
    DeleteObject(circuit);
} 

void FirstLevelWindow :: Hide() {
    HBRUSH background = CreateSolidBrush(RGB(0,0,0));
    HPEN circuit = CreatePen(PS_SOLID, 4, RGB(0,0,0));

    SelectObject(hdc, background);
    SelectObject(hdc, circuit);

    int x1 = GetX() - width/2;
    int y1 = GetY() - height/2;
    int x2 = GetX() + width/2;
    int y2 = GetY() + height/2;

    Rectangle(hdc, x1, y1, x2, y2);

    x1 = GetX() - width/2;
    y1 = GetY() - height/2 - height/5;
    x2 = GetX() + width/2;
    y2 = GetY() - height/2;

    Rectangle(hdc, x1, y1, x2, y2);

    DeleteObject(background);
    DeleteObject(circuit);
}


//--------[ S E C O N D   L E V E L    W I N D O W ]------------//
SecondLevelWindow :: SecondLevelWindow(int InitX, int InitY) : FirstLevelWindow(InitX, InitY) {}

SecondLevelWindow :: ~SecondLevelWindow() {}

void SecondLevelWindow :: Show() {
    HBRUSH background = CreateSolidBrush(RGB(0,0,0));
    HPEN circuit = CreatePen(PS_SOLID, 4, RGB(0,0,255));

    SelectObject(hdc, background);
    SelectObject(hdc, circuit);

    int x1 = GetX() - width/2;
    int y1 = GetY() - height/2;
    int x2 = GetX() + width/2;
    int y2 = GetY() + height/2;

    Rectangle(hdc, x1, y1, x2, y2);

    x1 = GetX() - width/2;
    y1 = GetY() - height/2 - height/5;
    x2 = GetX() + width/2;
    y2 = GetY() - height/2;

    Rectangle(hdc, x1, y1, x2, y2);

    SetTextColor(hdc, RGB(255, 255, 255)); 
    SetBkMode(hdc, TRANSPARENT);       

    HFONT hFont = CreateFont(
        48,                    
        0,                      
        0,                      
        0,                     
        FW_BOLD,                
        FALSE,                 
        FALSE,                  
        FALSE,                  
        DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY,
        DEFAULT_PITCH | FF_SWISS,
        TEXT("Arial")
    );

    HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

    RECT textRect = {x1, y1, x2-50, y2};
    DrawText(hdc, TEXT("LEVEL 2"), -1, &textRect, DT_RIGHT | DT_VCENTER | DT_SINGLELINE);

    SelectObject(hdc, hOldFont);
    DeleteObject(hFont);

    DeleteObject(background);
    DeleteObject(circuit);
} 

void SecondLevelWindow :: Hide() {
    HBRUSH background = CreateSolidBrush(RGB(0,0,0));
    HPEN circuit = CreatePen(PS_SOLID, 4, RGB(0,0,0));

    SelectObject(hdc, background);
    SelectObject(hdc, circuit);

    int x1 = GetX() - width/2;
    int y1 = GetY() - height/2;
    int x2 = GetX() + width/2;
    int y2 = GetY() + height/2;

    Rectangle(hdc, x1, y1, x2, y2);

    x1 = GetX() - width/2;
    y1 = GetY() - height/2 - height/5;
    x2 = GetX() + width/2;
    y2 = GetY() - height/2;

    Rectangle(hdc, x1, y1, x2, y2);

    DeleteObject(background);
    DeleteObject(circuit);
}


//--------[ T H I R D   L E V E L    W I N D O W ]--------------//
ThirdLevelWindow :: ThirdLevelWindow(int InitX, int InitY) : SecondLevelWindow(InitX, InitY) {}

ThirdLevelWindow :: ~ThirdLevelWindow() {}

void ThirdLevelWindow :: Show() {
    HBRUSH background = CreateSolidBrush(RGB(0,0,0));
    HPEN circuit = CreatePen(PS_SOLID, 4, RGB(0,0,255));

    SelectObject(hdc, background);
    SelectObject(hdc, circuit);

    int x1 = GetX() - width/2;
    int y1 = GetY() - height/2;
    int x2 = GetX() + width/2;
    int y2 = GetY() + height/2;

    Rectangle(hdc, x1, y1, x2, y2);

    x1 = GetX() - width/2;
    y1 = GetY() - height/2 - height/5;
    x2 = GetX() + width/2;
    y2 = GetY() - height/2;

    Rectangle(hdc, x1, y1, x2, y2);

    SetTextColor(hdc, RGB(255, 255, 255)); 
    SetBkMode(hdc, TRANSPARENT);       

    HFONT hFont = CreateFont(
        48,                    
        0,                      
        0,                      
        0,                     
        FW_BOLD,                
        FALSE,                 
        FALSE,                  
        FALSE,                  
        DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY,
        DEFAULT_PITCH | FF_SWISS,
        TEXT("Arial")
    );

    HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

    RECT textRect = {x1, y1, x2-50, y2};
    DrawText(hdc, TEXT("LEVEL 3"), -1, &textRect, DT_RIGHT | DT_VCENTER | DT_SINGLELINE);

    SelectObject(hdc, hOldFont);
    DeleteObject(hFont);

    DeleteObject(background);
    DeleteObject(circuit);
} 

void ThirdLevelWindow :: Hide() {
    HBRUSH background = CreateSolidBrush(RGB(0,0,0));
    HPEN circuit = CreatePen(PS_SOLID, 4, RGB(0,0,0));

    SelectObject(hdc, background);
    SelectObject(hdc, circuit);

    int x1 = GetX() - width/2;
    int y1 = GetY() - height/2;
    int x2 = GetX() + width/2;
    int y2 = GetY() + height/2;

    Rectangle(hdc, x1, y1, x2, y2);

    x1 = GetX() - width/2;
    y1 = GetY() - height/2 - height/5;
    x2 = GetX() + width/2;
    y2 = GetY() - height/2;

    Rectangle(hdc, x1, y1, x2, y2);

    DeleteObject(background);
    DeleteObject(circuit);
}


//---------------------[ L A S T  W I N D O W ]---------------//
LastWindow :: LastWindow(int InitX, int InitY) : Window(InitX, InitY) {}

LastWindow :: ~LastWindow() {}

void LastWindow :: Show() {
    HBRUSH background = CreateSolidBrush(RGB(0,0,0));
    HPEN circuit = CreatePen(PS_SOLID, 4, RGB(0,0,255));
    HPEN whitePen = CreatePen(PS_SOLID, 3, RGB(255,255,255));

    SelectObject(hdc, background);
    SelectObject(hdc, circuit);

    int mainX1 = GetX() - width/2;
    int mainY1 = GetY() - height/2;
    int mainX2 = GetX() + width/2;
    int mainY2 = GetY() + height/2;

    Rectangle(hdc, mainX1, mainY1, mainX2, mainY2);

    int topX1 = GetX() - width/2;
    int topY1 = GetY() - height/2 - height/5;
    int topX2 = GetX() + width/2;
    int topY2 = GetY() - height/2;

    Rectangle(hdc, topX1, topY1, topX2, topY2);

    SetTextColor(hdc, RGB(255, 255, 255));  
    SetBkMode(hdc, TRANSPARENT);       

    HFONT hFont = CreateFont(
        48,                     // Высота шрифта
        0,                      // Ширина (0 = автоматически)
        0,                      // Угол наклона
        0,                      // Направление
        FW_BOLD,                // Жирный шрифт
        FALSE,                  // Не курсив
        FALSE,                  // Не подчёркнутый
        FALSE,                  // Не зачёркнутый
        DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY,
        DEFAULT_PITCH | FF_SWISS,
        TEXT("Arial")
    );

    HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

    RECT textRect = {topX1, topY1, topX2, topY2};
    DrawText(hdc, TEXT("ZONE 51"), -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    
    RECT winRect = {mainX1, mainY1, mainX2, mainY2};
    DrawText(hdc, TEXT("YOU WIN!!!"), -1, &winRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    
    SelectObject(hdc, hOldFont);
    DeleteObject(hFont);
    
    DeleteObject(background);
    DeleteObject(circuit);
    DeleteObject(whitePen);    
}

void LastWindow :: Hide() {
    HBRUSH background = CreateSolidBrush(RGB(0,0,0));
    HPEN circuit = CreatePen(PS_SOLID, 4, RGB(0,0,0));

    SelectObject(hdc, background);
    SelectObject(hdc, circuit);

    int x1 = GetX() - width/2;
    int y1 = GetY() - height/2;
    int x2 = GetX() + width/2;
    int y2 = GetY() + height/2;

    Rectangle(hdc, x1, y1, x2, y2);

    x1 = GetX() - width/2;
    y1 = GetY() - height/2 - height/5;
    x2 = GetX() + width/2;
    y2 = GetY() - height/2;

    Rectangle(hdc, x1, y1, x2, y2);

    DeleteObject(background);
    DeleteObject(circuit);
}


//-------------------[ A B C   O B J E C T ]--------------------//
ABC_Object :: ABC_Object(int InitX, int InitY) : Point(InitX, InitY) {} 

ABC_Object :: ~ABC_Object() {}

int ABC_Object :: GetWidth() {
    return width;
}

int ABC_Object :: GetHeight() {
    return height;
}

void ABC_Object :: SetWidth(int NewWidth) {
    width = NewWidth;
}

void ABC_Object :: SetHeight(int NewHeight) {
    height = NewHeight;
}

bool ABC_Object :: isActive() {
    return active;
}


//---------------------[ R O C K E T ]--------------------------//
Rocket :: Rocket(int InitX, int InitY) : ABC_Object(InitX, InitY) {
    SetWidth(40);
    SetHeight(20);
}

Rocket :: ~Rocket() {}

int Rocket :: GetDirection() {
    return direction;
}

void Rocket :: SetDirection(int NewDirection) {
    direction = NewDirection;
}

void Rocket :: Show() {
    HBRUSH redBrush = CreateSolidBrush(RGB(255,0,0));
    HPEN blackPen = CreatePen(PS_SOLID, 3, RGB(0,0,0));
    HBRUSH yellowBrush = CreateSolidBrush(RGB(255,210,0));

    SelectObject(hdc, redBrush);
    SelectObject(hdc, blackPen);

    POINT poly[3];
    BYTE polytype[3];

    POINT polyFire[7];
    BYTE polytypeFire[7];

    if(direction == 0) {
        Rectangle(hdc, x-20, y-10, x+20, y+10);

        BeginPath(hdc);
        poly[0].x = x+20;
        poly[0].y = y+12;
        poly[1].x = x+20;
        poly[1].y = y-12;
        poly[2].x = x+40;
        poly[2].y = y;
        polytype[0] = PT_MOVETO;
        polytype[1] = PT_LINETO;
        polytype[2] = PT_LINETO;
        PolyDraw(hdc, poly, polytype, 3);
        EndPath(hdc);
        FillPath(hdc);

        SelectObject(hdc, yellowBrush);
        BeginPath(hdc);
        polyFire[0].x = x-21;
        polyFire[0].y = y-5;
        polyFire[1].x = x-21;
        polyFire[1].y = y+5;
        polyFire[2].x = x-30;
        polyFire[2].y = y+9;
        polyFire[3].x = x-24;
        polyFire[3].y = y+3;
        polyFire[4].x = x-32;
        polyFire[4].y = y;
        polyFire[5].x = x-24;
        polyFire[5].y = y-3;
        polyFire[6].x = x-30;
        polyFire[6].y = y-9;
        polytypeFire[0] = PT_MOVETO;
        polytypeFire[1] = PT_LINETO;
        polytypeFire[2] = PT_LINETO;
        polytypeFire[3] = PT_LINETO;
        polytypeFire[4] = PT_LINETO;
        polytypeFire[5] = PT_LINETO;
        polytypeFire[6] = PT_LINETO;
        PolyDraw(hdc, polyFire, polytypeFire, 7);
        EndPath(hdc);
        FillPath(hdc);
    }

    if(direction == 1) {
        Rectangle(hdc, x-20, y-10, x+20, y+10);

        BeginPath(hdc);
        poly[0].x = x-20;
        poly[0].y = y+12;
        poly[1].x = x-20;
        poly[1].y = y-12;
        poly[2].x = x-40;
        poly[2].y = y;
        polytype[0] = PT_MOVETO;
        polytype[1] = PT_LINETO;
        polytype[2] = PT_LINETO;
        PolyDraw(hdc, poly, polytype, 3);
        EndPath(hdc);
        FillPath(hdc);

        SelectObject(hdc, yellowBrush);
        BeginPath(hdc);
        polyFire[0].x = x+21;
        polyFire[0].y = y-5;
        polyFire[1].x = x+21;
        polyFire[1].y = y+5;
        polyFire[2].x = x+30;
        polyFire[2].y = y+9;
        polyFire[3].x = x+24;
        polyFire[3].y = y+3;
        polyFire[4].x = x+32;
        polyFire[4].y = y;
        polyFire[5].x = x+24;
        polyFire[5].y = y-3;
        polyFire[6].x = x+30;
        polyFire[6].y = y-9;
        polytypeFire[0] = PT_MOVETO;
        polytypeFire[1] = PT_LINETO;
        polytypeFire[2] = PT_LINETO;
        polytypeFire[3] = PT_LINETO;
        polytypeFire[4] = PT_LINETO;
        polytypeFire[5] = PT_LINETO;
        polytypeFire[6] = PT_LINETO;
        PolyDraw(hdc, polyFire, polytypeFire, 7);
        EndPath(hdc);
        FillPath(hdc);
    }

    DeleteObject(redBrush);
    DeleteObject(blackPen);
    DeleteObject(yellowBrush);
}

void Rocket :: Hide() {
    HBRUSH blackBrush = CreateSolidBrush(RGB(0,0,0));
    HPEN blackPen = CreatePen(PS_SOLID, 3, RGB(0,0,0));

    SelectObject(hdc, blackBrush);
    SelectObject(hdc, blackPen);

    POINT poly[3];
    BYTE polytype[3];

    POINT polyFire[7];
    BYTE polytypeFire[7];

    if(direction == 0) {
        Rectangle(hdc, x-20, y-10, x+20, y+10);

        BeginPath(hdc);
        poly[0].x = x+20;
        poly[0].y = y+12;
        poly[1].x = x+20;
        poly[1].y = y-12;
        poly[2].x = x+40;
        poly[2].y = y;
        polytype[0] = PT_MOVETO;
        polytype[1] = PT_LINETO;
        polytype[2] = PT_LINETO;
        PolyDraw(hdc, poly, polytype, 3);
        EndPath(hdc);
        FillPath(hdc);

        BeginPath(hdc);
        polyFire[0].x = x-21;
        polyFire[0].y = y-5;
        polyFire[1].x = x-21;
        polyFire[1].y = y+5;
        polyFire[2].x = x-30;
        polyFire[2].y = y+9;
        polyFire[3].x = x-24;
        polyFire[3].y = y+3;
        polyFire[4].x = x-32;
        polyFire[4].y = y;
        polyFire[5].x = x-24;
        polyFire[5].y = y-3;
        polyFire[6].x = x-30;
        polyFire[6].y = y-9;
        polytypeFire[0] = PT_MOVETO;
        polytypeFire[1] = PT_LINETO;
        polytypeFire[2] = PT_LINETO;
        polytypeFire[3] = PT_LINETO;
        polytypeFire[4] = PT_LINETO;
        polytypeFire[5] = PT_LINETO;
        polytypeFire[6] = PT_LINETO;
        PolyDraw(hdc, polyFire, polytypeFire, 7);
        EndPath(hdc);
        FillPath(hdc);
    }

    if(direction == 1) {
        Rectangle(hdc, x-20, y-10, x+20, y+10);

        BeginPath(hdc);
        poly[0].x = x-20;
        poly[0].y = y+12;
        poly[1].x = x-20;
        poly[1].y = y-12;
        poly[2].x = x-40;
        poly[2].y = y;
        polytype[0] = PT_MOVETO;
        polytype[1] = PT_LINETO;
        polytype[2] = PT_LINETO;
        PolyDraw(hdc, poly, polytype, 3);
        EndPath(hdc);
        FillPath(hdc);

        BeginPath(hdc);
        polyFire[0].x = x+21;
        polyFire[0].y = y-5;
        polyFire[1].x = x+21;
        polyFire[1].y = y+5;
        polyFire[2].x = x+30;
        polyFire[2].y = y+9;
        polyFire[3].x = x+24;
        polyFire[3].y = y+3;
        polyFire[4].x = x+32;
        polyFire[4].y = y;
        polyFire[5].x = x+24;
        polyFire[5].y = y-3;
        polyFire[6].x = x+30;
        polyFire[6].y = y-9;
        polytypeFire[0] = PT_MOVETO;
        polytypeFire[1] = PT_LINETO;
        polytypeFire[2] = PT_LINETO;
        polytypeFire[3] = PT_LINETO;
        polytypeFire[4] = PT_LINETO;
        polytypeFire[5] = PT_LINETO;
        polytypeFire[6] = PT_LINETO;
        PolyDraw(hdc, polyFire, polytypeFire, 7);
        EndPath(hdc);
        FillPath(hdc);
    }

    DeleteObject(blackBrush);
    DeleteObject(blackPen);
}


//------------------------[ C H A R G E ]----------------------//
Charge :: Charge(int InitX, int InitY) : Rocket(InitX, InitY) {
    SetHeight(40);
    SetWidth(40);
    SetRadius(20);
}

Charge :: ~Charge() {}

int Charge :: GetRadius() {
    return radius;
}

void Charge :: SetRadius(int NewRadius) {
    radius = NewRadius;
}

void Charge :: Show() {
    HBRUSH yellowBrush = CreateSolidBrush(RGB(255,165,0));

    SelectObject(hdc, yellowBrush);

    int x1 = x - radius; 
    int y1 = y - radius;
    int x2 = x + radius;
    int y2 = y + radius;

    Ellipse(hdc, x1, y1, x2, y2);

    DeleteObject(yellowBrush);
}

void Charge :: Hide() {
    HBRUSH blackBrush = CreateSolidBrush(RGB(0,0,0));
    HPEN blackPen = CreatePen(PS_SOLID, 2, RGB(0,0,0));

    SelectObject(hdc, blackBrush);
    SelectObject(hdc, blackPen);

    int x1 = x - radius; 
    int y1 = y - radius;
    int x2 = x + radius;
    int y2 = y + radius;

    Ellipse(hdc, x1, y1, x2, y2);

    DeleteObject(blackBrush);
    DeleteObject(blackPen);
}


//-------------------------[ M E T E O R ]--------------------//
Meteor :: Meteor(int InitX, int InitY) : Charge(InitX, InitY) {
    SetHeight(40);
    SetWidth(40);
    SetRadius(20);
}

Meteor :: ~Meteor() {}

void Meteor :: Show() {
    HBRUSH grayBrush = CreateSolidBrush(RGB(50,50,50));
    HBRUSH blackBrush = CreateSolidBrush(RGB(0,0,0));
    HPEN grayPen = CreatePen(PS_SOLID, 2, RGB(50,50,50));
    HPEN blackPen = CreatePen(PS_SOLID, 2, RGB(0,0,0));
    HBRUSH yellowBrush = CreateSolidBrush(RGB(255,200,0));
    HPEN yellowPen = CreatePen(PS_SOLID, 2, RGB(255,200,0));

    int x1 = x - radius;
    int y1 = y - radius;
    int x2 = x + radius;
    int y2 = y + radius;

    SelectObject(hdc, grayBrush);
    SelectObject(hdc, grayPen);

    Ellipse(hdc, x1, y1, x2, y2);

    SelectObject(hdc, blackBrush);
    SelectObject(hdc, blackPen);

    x1 = x - radius/3 - 13;
    y1 = y - radius/3 - 13;
    x2 = x + radius/3 - 13;
    y2 = y + radius/3 - 13;

    Ellipse(hdc, x1, y1, x2, y2);

    x1 = x - radius/4 + 12;
    y1 = y - radius/4 - 3;
    x2 = x + radius/4 + 12;
    y2 = y + radius/4 - 3;

    Ellipse(hdc, x1, y1, x2, y2);

    x1 = x - radius/6;
    y1 = y - radius/6 + 15;
    x2 = x + radius/6;
    y2 = y + radius/6 + 15;

    Ellipse(hdc, x1, y1, x2, y2);

    SelectObject(hdc, yellowBrush);
    SelectObject(hdc, yellowPen);

    POINT poly[4];
    BYTE polytype[4] = { PT_MOVETO, PT_LINETO, PT_LINETO, PT_LINETO };
    
    if(GetDirection() == 0) {
        int flameWidth = 6;
        int flameHeight = 6;

        auto DrawFlame = [&](int cx, int cy) {
            poly[0] = { cx, cy - flameHeight };
            poly[1] = { cx + flameWidth, cy };
            poly[2] = { cx, cy + flameHeight };
            poly[3] = { cx - flameWidth, cy };
            
            BeginPath(hdc);
            PolyDraw(hdc, poly, polytype, 4);
            EndPath(hdc);
            FillPath(hdc);
        };

        int diagonalOffsetX = -10;  
        int diagonalOffsetY = 10;   

        int startX = x - radius - 5;
        int startY = y + radius + 5;

        DrawFlame(startX+1, startY-5);                            
        DrawFlame(startX + diagonalOffsetX+20, startY + diagonalOffsetY+10);     
        DrawFlame(startX + diagonalOffsetX*2, startY + diagonalOffsetY*2-5); 
    }

    if(GetDirection() == 1) {
        int flameWidth = 6;
        int flameHeight = 6;

        auto DrawFlame = [&](int cx, int cy) {
            poly[0] = { cx, cy - flameHeight };
            poly[1] = { cx + flameWidth, cy };
            poly[2] = { cx, cy + flameHeight };
            poly[3] = { cx - flameWidth, cy };
            
            BeginPath(hdc);
            PolyDraw(hdc, poly, polytype, 4);
            EndPath(hdc);
            FillPath(hdc);
        };

        int diagonalOffsetX = 10;   
        int diagonalOffsetY = -10;

        int startX = x + radius + 15;   
        int startY = y - radius - 15;   

        DrawFlame(startX-10, startY+5);                                          
        DrawFlame(startX + diagonalOffsetX + 16, startY + diagonalOffsetY+20);      
        DrawFlame(startX + diagonalOffsetX*2, startY + diagonalOffsetY*2);  
    }


    DeleteObject(grayBrush);
    DeleteObject(blackBrush);
    DeleteObject(blackPen);
    DeleteObject(grayPen);
    DeleteObject(yellowPen);
    DeleteObject(yellowBrush);
}

void Meteor :: Hide() {
    HBRUSH blackBrush = CreateSolidBrush(RGB(0,0,0));
    HPEN blackPen = CreatePen(PS_SOLID, 2, RGB(0,0,0));

    SelectObject(hdc, blackBrush);
    SelectObject(hdc, blackPen);

    int x1 = x - radius;
    int y1 = y - radius;
    int x2 = x + radius;
    int y2 = y + radius;

    Ellipse(hdc, x1, y1, x2, y2);

    x1 = x - radius/3 - 13;
    y1 = y - radius/3 - 13;
    x2 = x + radius/3 - 13;
    y2 = y + radius/3 - 13;

    Ellipse(hdc, x1, y1, x2, y2);

    x1 = x - radius/4 + 12;
    y1 = y - radius/4 - 3;
    x2 = x + radius/4 + 12;
    y2 = y + radius/4 - 3;

    Ellipse(hdc, x1, y1, x2, y2);

    x1 = x - radius/6;
    y1 = y - radius/6 + 15;
    x2 = x + radius/6;
    y2 = y + radius/6 + 15;

    Ellipse(hdc, x1, y1, x2, y2);

    POINT poly[4];
    BYTE polytype[4] = { PT_MOVETO, PT_LINETO, PT_LINETO, PT_LINETO };
    
    if(GetDirection() == 0) {
        int flameWidth = 6;
        int flameHeight = 6;

        auto DrawFlame = [&](int cx, int cy) {
            poly[0] = { cx, cy - flameHeight };
            poly[1] = { cx + flameWidth, cy };
            poly[2] = { cx, cy + flameHeight };
            poly[3] = { cx - flameWidth, cy };
            
            BeginPath(hdc);
            PolyDraw(hdc, poly, polytype, 4);
            EndPath(hdc);
            FillPath(hdc);
        };

        int diagonalOffsetX = -10;  
        int diagonalOffsetY = 10;   

        int startX = x - radius - 5;
        int startY = y + radius + 5;

        DrawFlame(startX+1, startY-5);                            
        DrawFlame(startX + diagonalOffsetX+20, startY + diagonalOffsetY+10);     
        DrawFlame(startX + diagonalOffsetX*2, startY + diagonalOffsetY*2-5); 
    }

    if(GetDirection() == 1) {
        int flameWidth = 6;
        int flameHeight = 6;

        auto DrawFlame = [&](int cx, int cy) {
            poly[0] = { cx, cy - flameHeight };
            poly[1] = { cx + flameWidth, cy };
            poly[2] = { cx, cy + flameHeight };
            poly[3] = { cx - flameWidth, cy };
            
            BeginPath(hdc);
            PolyDraw(hdc, poly, polytype, 4);
            EndPath(hdc);
            FillPath(hdc);
        };

        int diagonalOffsetX = 10;   
        int diagonalOffsetY = -10;

        int startX = x + radius + 15;   
        int startY = y - radius - 15;   

        DrawFlame(startX-10, startY+5);                                          
        DrawFlame(startX + diagonalOffsetX + 16, startY + diagonalOffsetY+20);      
        DrawFlame(startX + diagonalOffsetX*2, startY + diagonalOffsetY*2);  
    }
    
    DeleteObject(blackBrush);
    DeleteObject(blackPen);
}


//-------------------[ D A R K   H O L E ]--------------------//
DarkHole :: DarkHole(int InitX, int InitY) : Meteor(InitX, InitY) {
    SetHeight(40);
    SetWidth(40);
    SetRadius(20);
}

DarkHole :: ~DarkHole() {}

void DarkHole :: Show() {
    HBRUSH blackBrush = CreateSolidBrush(RGB(0,0,0));
    HBRUSH whiteBrush = CreateSolidBrush(RGB(255,250,200));
    HPEN whitePen = CreatePen(PS_SOLID, 2, RGB(255,250,200));

    SelectObject(hdc, blackBrush);
    SelectObject(hdc, whitePen);

    Ellipse(hdc, x-radius*3, y-radius*3, x+radius*3, y+radius*3);

    Ellipse(hdc, x-radius, y-radius, x+radius, y+radius);

    SelectObject(hdc, whiteBrush);

    Ellipse(hdc, x-radius-radius/5, y-radius/5, x+radius + radius/5,  y+radius/5);

    DeleteObject(blackBrush);
    DeleteObject(whiteBrush);
    DeleteObject(whitePen);
}

void DarkHole :: Hide() {
    HBRUSH blackBrush = CreateSolidBrush(RGB(0,0,0));
    HPEN blackPen = CreatePen(PS_SOLID, 2, RGB(0,0,0));

    SelectObject(hdc, blackBrush);
    SelectObject(hdc, blackPen);

    Ellipse(hdc, x-radius*3, y-radius*3, x+radius*3, y+radius*3);

    DeleteObject(blackBrush);
    DeleteObject(blackPen);
}


//-----------------------[ H E A R T ]------------------------//
Heart :: Heart(int InitX, int InitY) : ABC_Object(InitX, InitY) {}

Heart :: ~Heart() {}

void Heart :: Show() {
    HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
    HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
    
    SelectObject(hdc, redBrush);
    SelectObject(hdc, redPen);
    
    int halfSize = 50 / 2;
    
    BeginPath(hdc);
    POINT triangle[3] = {
        { x - halfSize, y+3 },         
        { x + halfSize, y+3 },         
        { x, y + halfSize }            
    };
    BYTE polytype[3] = { PT_MOVETO, PT_LINETO, PT_LINETO};

    PolyDraw(hdc, triangle, polytype, 3);
    
    EndPath(hdc);
    FillPath(hdc);
    
    Ellipse(hdc, x - halfSize, y - halfSize/2, x, y + halfSize/2);
    
    Ellipse(hdc, x, y - halfSize/2, x + halfSize, y + halfSize/2);
    
    DeleteObject(redBrush);
    DeleteObject(redPen);
}

void Heart :: Hide() {
    HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0));
    HPEN blackPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    
    SelectObject(hdc, blackBrush);
    SelectObject(hdc, blackPen);
    
    int halfSize = 50 / 2;
    
    BeginPath(hdc);
    POINT triangle[3] = {
        { x - halfSize, y+3 },         
        { x + halfSize, y+3 },         
        { x, y + halfSize }            
    };
    BYTE polytype[3] = { PT_MOVETO, PT_LINETO, PT_LINETO};

    PolyDraw(hdc, triangle, polytype, 3);
    
    EndPath(hdc);
    FillPath(hdc);
    
    Ellipse(hdc, x - halfSize, y - halfSize/2, x, y + halfSize/2);
    
    Ellipse(hdc, x, y - halfSize/2, x + halfSize, y + halfSize/2);
    
    DeleteObject(blackBrush);
    DeleteObject(blackPen);
}


//----------------------[ H E A L T H ]-----------------------//
Health :: Health(int InitX, int InitY) : Heart(InitX, InitY) {
    SetWidth(50);
    SetHeight(50);
}

Health :: ~Health() {}

void Health :: Show() {
    HBRUSH greenBrush = CreateSolidBrush(RGB(0,255,0));
    HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0,255,0));

    
    SelectObject(hdc, greenBrush);
    SelectObject(hdc, greenPen);
    
    
    Rectangle(hdc, x - 25, y - 5, x + 25, y + 5);
    
    Rectangle(hdc, x - 5, y - 25, x + 5, y + 25);
    
    DeleteObject(greenBrush);
    DeleteObject(greenPen);
}

void Health :: Hide() {
    HBRUSH blackBrush = CreateSolidBrush(RGB(0,0,0));
    HPEN blackPen = CreatePen(PS_SOLID, 2, RGB(0,0,0));

    
    SelectObject(hdc, blackBrush);
    SelectObject(hdc, blackPen);
    
    
    Rectangle(hdc, x - 25, y - 5, x + 25, y + 5);
    
    Rectangle(hdc, x - 5, y - 25, x + 5, y + 25);
    
    DeleteObject(blackBrush);
    DeleteObject(blackPen);
}


//-----------------------[ S H I E L D ]----------------------//
Shield :: Shield(int InitX, int InitY) : Health(InitX, InitY) {
    SetWidth(40);
    SetHeight(60);
}

Shield :: ~Shield() {}

void Shield :: Show() {
    HBRUSH grayBrush = CreateSolidBrush(RGB(192,192,192));
    HBRUSH whiteBrush = CreateSolidBrush(RGB(255,255,255));
    HPEN grayPen = CreatePen(PS_SOLID, 2, RGB(192,192,192));
    HPEN whitePen = CreatePen(PS_SOLID, 2, RGB(255,255,255));

    SelectObject(hdc, grayBrush);
    SelectObject(hdc, grayPen);

    Rectangle(hdc, x-15, y-20, x+15, y+18);

    Rectangle(hdc, x-20, y-30, x+20, y-20);

    BeginPath(hdc);
    POINT triangle[3] =
    {
        {x-20, y+16},
        {x+20, y+16},
        {x, y+30}
    };
    BYTE triangleType[3] = {PT_MOVETO, PT_LINETO, PT_LINETO};
    PolyDraw(hdc, triangle, triangleType, 3);
    EndPath(hdc);
    FillPath(hdc);

    SelectObject(hdc, whiteBrush);
    SelectObject(hdc, whitePen);

    Rectangle(hdc, x-10, y-12, x+10, y+10);

    Rectangle(hdc, x-12, y-17, x+13, y-12);

    BeginPath(hdc);
    POINT triangle1[3] =
    {
        {x-12, y+8},
        {x+12, y+8},
        {x, y+15}
    };
    BYTE triangleType1[3] = {PT_MOVETO, PT_LINETO, PT_LINETO};
    PolyDraw(hdc, triangle1, triangleType1, 3);
    EndPath(hdc);
    FillPath(hdc);

    DeleteObject(grayBrush);
    DeleteObject(whiteBrush);
    DeleteObject(grayPen);
    DeleteObject(whitePen);
}

void Shield :: Hide() {
    HBRUSH blackBrush = CreateSolidBrush(RGB(0,0,0));
    HPEN blackPen = CreatePen(PS_SOLID, 2, RGB(0,0,0));

    SelectObject(hdc, blackBrush);
    SelectObject(hdc, blackPen);

    Rectangle(hdc, x-15, y-20, x+15, y+18);

    Rectangle(hdc, x-20, y-30, x+20, y-20);

    BeginPath(hdc);
    POINT triangle[3] =
    {
        {x-20, y+16},
        {x+20, y+16},
        {x, y+28}
    };
    BYTE triangleType[3] = {PT_MOVETO, PT_LINETO, PT_LINETO};
    PolyDraw(hdc, triangle, triangleType, 3);
    EndPath(hdc);
    FillPath(hdc);

    DeleteObject(blackBrush);
    DeleteObject(blackPen);
}