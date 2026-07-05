#include <iostream>
#include <windows.h>
#include <random>
#include <vector>
#include "../include/game_logic.h"
#include "../include/headers.h"

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

using namespace std;

void levels(LevelsWindow &window, NLO * nlo, NLO & nlo1) {
    while(!KEY_DOWN(VK_ESCAPE)) {
        if(KEY_DOWN('1') && window.GetState() >= 1)
            firstLevel(nlo, window, nlo1);
        if(KEY_DOWN('2') && window.GetState() >= 2)
            secondLevel(nlo, window);
        if(KEY_DOWN('3') && window.GetState() >= 3)
            thirdLevel(nlo, window);   
    }
}


void firstLevel(NLO * nlo, LevelsWindow & window, NLO & nlo1) {
    FirstLevelWindow window1(950, 600);
    window1.Show();
    nlo->Show();
    YellowNLO nlo2(100,100);
    nlo2.Show();
    RedNLO nlo3(100, 500);

    int state = 0;

    Heart firstHeart(420, 175);
    firstHeart.Show();
    Heart secondHeart(500, 175);
    secondHeart.Show();
    Heart thirdHeart(580, 175);
    thirdHeart.Show();
    
    DWORD startTime = GetTickCount();
    DWORD lastSpawnTime = startTime;
    DWORD lastMoveTime = startTime;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(275, 925);
    int random_number = 0;
    int side;
    
    vector <Rocket*> rockets;
    vector <Charge *> charges;
    vector <Meteor *> meteors;
    vector <DarkHole *> holes;
    vector <Health *> healths;
    vector <Shield *> shields;
    
    while(true) { 
        MovementNLO(nlo);
        DWORD currentTime = GetTickCount();
        DWORD elapsedTime = currentTime - startTime;

        if(currentTime - lastSpawnTime >= 7000 || random_number == 0) {
            random_number = distr(gen);
            if(random_number % 2 == 0)
                side = 1450;
            else
                side = 450;
            rockets.push_back(new Rocket(side, random_number));
            lastSpawnTime = currentTime;
        }
        
        if(currentTime - lastMoveTime >= 1) {
            for(size_t j = 0; j < rockets.size(); j++) {
                RocketMovement(nlo, rockets[j]);
            }
            lastMoveTime = currentTime;
            nlo->Show();
        }

        collision(nlo, rockets, charges, meteors, holes, healths, shields);

        if(nlo->GetHealth() == 3) {
            nlo1.SetX(nlo->GetX());
            nlo1.SetY(nlo->GetY());
            nlo1.SetHealth(3);
            nlo = &nlo1;
            firstHeart.Show();
            secondHeart.Show();
            thirdHeart.Show();
        }
        else if(nlo->GetHealth() == 2) {
            nlo2.SetX(nlo->GetX());
            nlo2.SetY(nlo->GetY());
            nlo2.SetHealth(2);
            nlo = &nlo2;
            firstHeart.Show();
            secondHeart.Show();
            thirdHeart.Hide();
        }
        else if(nlo->GetHealth() == 1) {
            nlo3.SetX(nlo->GetX());
            nlo3.SetY(nlo->GetY());
            nlo3.SetHealth(1);
            nlo = &nlo3;
            firstHeart.Show();
            secondHeart.Hide();
            thirdHeart.Hide();
        }
        else {
            state = 1;
            break;
        }

        if (elapsedTime >= 30000) { 
            break;
        }
    }
    
    for(Rocket* rocket : rockets) {
        delete rocket;
    }
    rockets.clear();

    for(Charge* charge : charges) {
        delete charge;
    }
    charges.clear();

    for(Meteor* meteor : meteors) {
        delete meteor;
    }
    meteors.clear();

    for(DarkHole* hole : holes) {
        delete hole;
    }
    holes.clear();

    for(Health* health : healths) {
        delete health;
    }
    healths.clear();

    for(Shield* shield : shields) {
        delete shield;
    }
    shields.clear();

    if(window.GetState() < 2 && state == 0) window.SetState(2);
    nlo1.SetX(nlo->GetX());
    nlo1.SetY(nlo->GetY());
    nlo1.SetHealth(3);
    nlo = &nlo1;
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
    if (currentTime%5 == 0){
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


void RocketMovement(NLO * nlo, Rocket * rocket) {
    if(rocket->GetX() < nlo->GetX())
    {
        rocket->Hide();
        rocket->SetDirection(0);
        if(rocket->GetY() < nlo->GetY())
            rocket->MoveTo(rocket->GetX()+1, rocket->GetY()+1);
        else 
            rocket->MoveTo(rocket->GetX()+1, rocket->GetY()-1);
    }
    else 
    {
        rocket->Hide();
        rocket->SetDirection(1);
        if(rocket->GetY() < nlo->GetY())
            rocket->MoveTo(rocket->GetX()-1, rocket->GetY()+1);
        else 
            rocket->MoveTo(rocket->GetX()-1, rocket->GetY()-1);
    }
}


bool checkCollision(NLO * nlo, ABC_Object * object) {
    int nloLeft = nlo->GetX() - nlo->GetWidth()/2;
    int nloRight = nlo->GetX() + nlo->GetWidth()/2;
    int nloTop = nlo->GetY() - nlo->GetHeight()/2;
    int nloBottom = nlo->GetY() + nlo->GetHeight()/2;
    
    int objLeft = object->GetX() - object->GetWidth()/2;
    int objRight = object->GetX() + object->GetWidth()/2;
    int objTop = object->GetY() - object->GetHeight()/2;
    int objBottom = object->GetY() + object->GetHeight()/2;
    
    bool collisionX = nloRight > objLeft && nloLeft < objRight;
    bool collisionY = nloBottom > objTop && nloTop < objBottom;
    
    return collisionX && collisionY;
}   


void collision(NLO * nlo, vector <Rocket *> &rockets, vector <Charge *> &charges, vector <Meteor *> &meteors, vector <DarkHole *> &holes, vector <Health *> &healths, vector <Shield *> &shields) {
    for(int i = 0; i < rockets.size(); i++) {
        if(checkCollision(nlo, rockets[i])) {
            nlo->SetHealth(nlo->GetHealth()-1);
            rockets[i]->Hide();
            rockets.erase(rockets.begin() + i);
        }
    }
    for(int i = 0; i < charges.size(); i++) {
        if(checkCollision(nlo, charges[i])) {
            nlo->SetHealth(nlo->GetHealth()-1);
            charges[i]->Hide();
            charges.erase(charges.begin() + i);
        }
    }
    for(int i = 0; i < meteors.size(); i++) {
        if(checkCollision(nlo, meteors[i])) {
            nlo->SetHealth(nlo->GetHealth()-1);
            meteors[i]->Hide();
            meteors.erase(meteors.begin() + i);
        }
    }
    for(int i = 0; i < holes.size(); i++) {
        if(checkCollision(nlo, holes[i])) {
            nlo->SetHealth(nlo->GetHealth()-3);
            holes[i]->Hide();
            holes.erase(holes.begin() + i);
        }
    }
    for(int i = 0; i < healths.size(); i++) {
        if(checkCollision(nlo, healths[i])) {
            nlo->SetHealth(nlo->GetHealth()+1);
            healths[i]->Hide();
            healths.erase(healths.begin() + i);
        }
    }
    for(int i = 0; i < shields.size(); i++) {
        if(checkCollision(nlo, shields[i])) {
            shields[i]->Hide();
            shields.erase(shields.begin() + i);
        }
    }
}