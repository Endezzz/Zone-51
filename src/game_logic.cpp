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
            secondLevel(nlo, window, nlo1);
        if(KEY_DOWN('3') && window.GetState() >= 3)
            thirdLevel(nlo, window, nlo1);   
    }
}


void firstLevel(NLO * nlo, LevelsWindow & window, NLO & nlo1) {
    FirstLevelWindow window1(950, 600);
    nlo->SetX(950);
    nlo->SetY(600);
    window1.Show();
    nlo->Show();
    YellowNLO nlo2(100,100);
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

        if(currentTime - lastSpawnTime >= 1000 || random_number == 0) {
            random_number = distr(gen);
            if(random_number % 2 == 0)
                side = 400;
            else
                side = 1500;
            rockets.push_back(new Rocket(side, nlo->GetY()));
            rockets[rockets.size() - 1]->SetDirection(random_number%2);
            lastSpawnTime = currentTime;
        }
        
        if(currentTime - lastMoveTime >= 1) {
            for(size_t j = 0; j < rockets.size(); j++) {
                if(!RocketMovement(nlo, rockets[j])) {
                    rockets[j]->Hide();
                    delete rockets[j];
                    rockets.erase(rockets.begin() + j);
                }
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
    nlo1.SetMoveable(true);
    nlo = &nlo1;
    window.Show();
}


void secondLevel(NLO * nlo, LevelsWindow &window, NLO & nlo1) {
    SecondLevelWindow window2(950, 600);
    nlo->SetX(950);
    nlo->SetY(600);
    window2.Show();
    nlo->Show();
    YellowNLO nlo2(100,100);
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
    DWORD lastSpawnTimeCharges = startTime;
    DWORD lastSpawnTimeMeteors = startTime;
    DWORD lastSpawnTimeHealth = startTime;
    DWORD lastSpawnTimeShield = startTime;
    DWORD lastIncreseTime = startTime;
    DWORD lastMoveTime = startTime;
    DWORD freezTime = startTime;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(275, 925);
    uniform_int_distribution<> distr1(450, 1450);

    int random_number = 0;
    int side;
    bool shield = false;
    
    vector <Rocket*> rockets;
    vector <Charge *> charges;
    vector <Meteor *> meteors;
    vector <DarkHole *> holes;
    vector <Health *> healths;
    vector <Shield *> shields;

    while(true) { 
        DWORD currentTime = GetTickCount();
        DWORD elapsedTime = currentTime - startTime;
        if(nlo->GetMoveable()) {
            MovementNLO(nlo);
            freezTime = GetTickCount();
        }
        else {
            if(currentTime - freezTime >= 2000) {
                nlo->SetMoveable(true);
            }
        }

        if(currentTime - lastSpawnTime >= 1000 || random_number == 0) {
            random_number = distr(gen);
            if(random_number % 2 == 0)
                side = 400;
            else
                side = 1500;
            rockets.push_back(new Rocket(side, nlo->GetY()));
            rockets[rockets.size() - 1]->SetDirection(random_number%2);
            lastSpawnTime = currentTime;
        }

        if(currentTime - lastSpawnTimeCharges >= 7000) {
            random_number = distr(gen);
            if(random_number % 2 == 0) {
                side = 1450;
            }
            else {
                side = 450;
            }
            for(size_t j = 0; j < charges.size(); j++) {
                charges[j]->Hide();
                delete charges[j];
            }
            charges.clear();
            charges.push_back(new Charge(side, nlo->GetY()));
            lastSpawnTimeCharges = currentTime;
        }

        if(currentTime - lastSpawnTimeHealth >= 12000) {
            random_number = distr(gen);
            side = distr1(gen);
            for(size_t j = 0; j < healths.size(); j++) {
                healths[j]->Hide();
                delete healths[j];
            }
            healths.clear();
            healths.push_back(new Health(side, random_number));
            healths[healths.size() - 1]->Show();
            lastSpawnTimeHealth = currentTime;
        }

        if(currentTime - lastSpawnTimeMeteors >= 5000) {
            random_number = distr1(gen);
            if(random_number % 2 == 0) {
                side = 860;
            }
            else {
                side = 330;
            }
            meteors.push_back(new Meteor(random_number, side));
            meteors[meteors.size()-1]->SetDirection(random_number%2);
            meteors[meteors.size()-1]->SetRadius(30);
            lastSpawnTimeMeteors = currentTime;
        }
        
        if(currentTime - lastSpawnTimeShield >= 20000) {
            uniform_int_distribution<> distr2(400, 600);
            random_number = distr2(gen);
            uniform_int_distribution<> distr3(600, 1200);
            side = distr3(gen);
            for(size_t j = 0; j < shields.size(); j++) {
                shields[j]->Hide();
                delete shields[j];
            }
            shields.clear();
            shields.push_back(new Shield(side, random_number));
            shields[shields.size() - 1]->Show();
            lastSpawnTimeShield = currentTime;
        }

        if(currentTime - lastMoveTime >= 1) {
            for(size_t j = 0; j < rockets.size(); j++) {
                if(!RocketMovement(nlo, rockets[j])) {
                    rockets[j]->Hide();
                    delete rockets[j];
                    rockets.erase(rockets.begin() + j);
                }
            }
            for(size_t j = 0; j < charges.size(); j++) {
                ChargeMovement(nlo, charges[j]);
            }
            for(size_t j = 0; j < meteors.size(); j++) {
                if(!MeteorMovement(meteors[j])) {
                    meteors[j]->Hide();
                    delete meteors[j];
                    meteors.erase(meteors.begin() + j);
                }
            }
            for(size_t j = 0; j < healths.size(); j++) {
                healths[j]->Show();
            }
            for(size_t j = 0; j < shields.size(); j++) {
                shields[j]->Show();
            }
            lastMoveTime = currentTime;
            if(nlo->GetMoveable())
                nlo->Show();
        }

        if(currentTime - lastIncreseTime >= 350) {
            for(size_t j = 0; j < charges.size(); j++) {
                charges[j]->SetRadius(charges[j]->GetRadius()+1);
                charges[j]->SetWidth(charges[j]->GetWidth()+1);
                charges[j]->SetHeight(charges[j]->GetHeight()+1);
            }
            lastIncreseTime = currentTime;
        }
        collision(nlo, rockets, charges, meteors, holes, healths, shields);

        if(nlo->GetHealth() == 3) {
            if(nlo->GetShield()) nlo1.SetShield(true);
            nlo1.SetX(nlo->GetX());
            nlo1.SetY(nlo->GetY());
            nlo1.SetHealth(3);
            nlo = &nlo1;
            firstHeart.Show();
            secondHeart.Show();
            thirdHeart.Show();
        }
        else if(nlo->GetHealth() == 2) {
            if(nlo->GetShield()) nlo2.SetShield(true);
            nlo2.SetX(nlo->GetX());
            nlo2.SetY(nlo->GetY());
            nlo2.SetHealth(2);
            nlo = &nlo2;
            firstHeart.Show();
            secondHeart.Show();
            thirdHeart.Hide();
        }
        else if(nlo->GetHealth() == 1) {
            if(nlo->GetShield()) nlo3.SetShield(true);
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

        if (elapsedTime >= 45000) { 
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

    if(window.GetState() < 3 && state == 0) window.SetState(3);
    nlo1.SetX(nlo->GetX());
    nlo1.SetY(nlo->GetY());
    nlo1.SetHealth(3);
    nlo1.SetMoveable(true);
    nlo = &nlo1;
    window.Show();
}


void thirdLevel(NLO * nlo, LevelsWindow &window, NLO & nlo1) {
    ThirdLevelWindow window2(950, 600);
    nlo->SetX(950);
    nlo->SetY(600);
    window2.Show();
    nlo->Show();
    YellowNLO nlo2(100,100);
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
    DWORD lastSpawnTimeCharges = startTime;
    DWORD lastSpawnTimeMeteors = startTime;
    DWORD lastSpawnTimeHoles = startTime;
    DWORD lastSpawnTimeHealth = startTime;
    DWORD lastSpawnTimeShield = startTime;
    DWORD lastIncreseTime = startTime;
    DWORD lastMoveTime = startTime;
    DWORD freezTime = startTime;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(275, 925);
    uniform_int_distribution<> distr1(450, 1450);

    int random_number = 0;
    int side;
    
    vector <Rocket*> rockets;
    vector <Charge *> charges;
    vector <Meteor *> meteors;
    vector <DarkHole *> holes;
    vector <Health *> healths;
    vector <Shield *> shields;

    while(true) { 
        DWORD currentTime = GetTickCount();
        DWORD elapsedTime = currentTime - startTime;
        if(nlo->GetMoveable()) {
            MovementNLO(nlo);
            freezTime = GetTickCount();
        }
        else {
            if(currentTime - freezTime >= 2000) {
                nlo->SetMoveable(true);
            }
        }

        if(currentTime - lastSpawnTime >= 1000 || random_number == 0) {
            random_number = distr(gen);
            if(random_number % 2 == 0)
                side = 400;
            else
                side = 1500;
            rockets.push_back(new Rocket(side, nlo->GetY()));
            rockets[rockets.size() - 1]->SetDirection(random_number%2);
            lastSpawnTime = currentTime;
        }

        if(currentTime - lastSpawnTimeCharges >= 7000) {
            random_number = distr(gen);
            if(random_number % 2 == 0) {
                side = 1450;
            }
            else {
                side = 450;
            }
            for(size_t j = 0; j < charges.size(); j++) {
                charges[j]->Hide();
                delete charges[j];
            }
            charges.clear();
            charges.push_back(new Charge(side, nlo->GetY()));
            lastSpawnTimeCharges = currentTime;
        }

        if(currentTime - lastSpawnTimeHoles >= 10000) {
            random_number = distr1(gen);
            if(random_number % 2 == 0) {
                side = 850;
            }
            else {
                side = 350;
            }
            holes.push_back(new DarkHole(random_number, side));
            holes[holes.size()-1]->SetDirection(random_number%2);
            holes[holes.size()-1]->SetRadius(30);
            lastSpawnTimeHoles = currentTime;
        }

        if(currentTime - lastSpawnTimeMeteors >= 5000) {
            random_number = distr1(gen);
            if(random_number % 2 == 0) {
                side = 860;
            }
            else {
                side = 330;
            }
            meteors.push_back(new Meteor(random_number, side));
            meteors[meteors.size()-1]->SetDirection(random_number%2);
            meteors[meteors.size()-1]->SetRadius(30);
            lastSpawnTimeMeteors = currentTime;
        }
        
        if(currentTime - lastSpawnTimeHealth >= 12000) {
            random_number = distr(gen);
            side = distr1(gen);
            for(size_t j = 0; j < healths.size(); j++) {
                healths[j]->Hide();
                delete healths[j];
            }
            healths.clear();
            healths.push_back(new Health(side, random_number));
            healths[healths.size() - 1]->Show();
            lastSpawnTimeHealth = currentTime;
        }
        
        if(currentTime - lastSpawnTimeShield >= 15000) {
            uniform_int_distribution<> distr2(400, 600);
            random_number = distr2(gen);
            uniform_int_distribution<> distr3(600, 1200);
            side = distr3(gen);
            for(size_t j = 0; j < shields.size(); j++) {
                shields[j]->Hide();
                delete shields[j];
            }
            shields.clear();
            shields.push_back(new Shield(side, random_number));
            shields[shields.size() - 1]->Show();
            lastSpawnTimeShield = currentTime;
        }

        if(currentTime - lastMoveTime >= 1) {
            for(size_t j = 0; j < rockets.size(); j++) {
                if(!RocketMovement(nlo, rockets[j])) {
                    rockets[j]->Hide();
                    delete rockets[j];
                    rockets.erase(rockets.begin() + j);
                }
            }
            for(size_t j = 0; j < charges.size(); j++) {
                ChargeMovement(nlo, charges[j]);
            }
            for(size_t j = 0; j < meteors.size(); j++) {
                if(!MeteorMovement(meteors[j])) {
                    meteors[j]->Hide();
                    delete meteors[j];
                    meteors.erase(meteors.begin() + j);
                }
            }
            for(size_t j = 0; j < holes.size(); j++) {
                if(!DarkHoleMovement(holes[j])) {
                    holes[j]->Hide();
                    delete holes[j];
                    holes.erase(holes.begin() + j);
                }
            }
            for(size_t j = 0; j < healths.size(); j++) {
                healths[j]->Show();
            }
            for(size_t j = 0; j < shields.size(); j++) {
                shields[j]->Show();
            }
            lastMoveTime = currentTime;
            if(nlo->GetMoveable())
                nlo->Show();
        }

        if(currentTime - lastIncreseTime >= 350) {
            for(size_t j = 0; j < charges.size(); j++) {
                charges[j]->SetRadius(charges[j]->GetRadius()+1);
                charges[j]->SetWidth(charges[j]->GetWidth()+1);
                charges[j]->SetHeight(charges[j]->GetHeight()+1);
            }
            lastIncreseTime = currentTime;
        }
        
        collision(nlo, rockets, charges, meteors, holes, healths, shields);

        if(nlo->GetHealth() == 3) {
            if(nlo->GetShield()) nlo1.SetShield(true);
            nlo1.SetX(nlo->GetX());
            nlo1.SetY(nlo->GetY());
            nlo1.SetHealth(3);
            nlo = &nlo1;
            firstHeart.Show();
            secondHeart.Show();
            thirdHeart.Show();
        }
        else if(nlo->GetHealth() == 2) {
            if(nlo->GetShield()) nlo2.SetShield(true);
            nlo2.SetX(nlo->GetX());
            nlo2.SetY(nlo->GetY());
            nlo2.SetHealth(2);
            nlo = &nlo2;
            firstHeart.Show();
            secondHeart.Show();
            thirdHeart.Hide();
        }
        else if(nlo->GetHealth() == 1) {
            if(nlo->GetShield()) nlo3.SetShield(true);
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

        if (elapsedTime >= 45000) { 
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

    nlo1.SetX(nlo->GetX());
    nlo1.SetY(nlo->GetY());
    nlo1.SetMoveable(true);
    nlo1.SetHealth(3);
    nlo = &nlo1;
    window.Show();
}


void MovementNLO(NLO * nlo) {
    int speed = 1;
    DWORD currentTime = GetTickCount();
    if (currentTime%5 == 0){
        if(KEY_DOWN('W'))
        {   if(nlo->GetShield()) {
                if(nlo->GetY()-speed > 250 + nlo->GetWidth()/1.5+5)
                    nlo->MoveTo(nlo->GetX(), nlo->GetY()-speed);
            }
            else {
                if(nlo->GetY()-speed > 250 + nlo->GetHeight()/2+5)
                    nlo->MoveTo(nlo->GetX(), nlo->GetY()-speed);
            }
        }
        if(KEY_DOWN('S'))
        {
            if(nlo->GetShield()) {
                if(nlo->GetY()+speed < 950 - nlo->GetWidth()/1.5-5)
                    nlo->MoveTo(nlo->GetX(), nlo->GetY()+speed);
            }
            else {
                if(nlo->GetY()+speed < 950 - nlo->GetHeight()/2-5)
                    nlo->MoveTo(nlo->GetX(), nlo->GetY()+speed);
            }
        }
        if(KEY_DOWN('A'))
        {
            if(nlo->GetShield()) {
                if(nlo->GetX()-speed > 350 + nlo->GetWidth()/1.5+15)
                    nlo->MoveTo(nlo->GetX()-speed, nlo->GetY());
            }
            else {
                if(nlo->GetX()-speed > 350 + nlo->GetWidth()/2+15)
                    nlo->MoveTo(nlo->GetX()-speed, nlo->GetY());
            }
        }
        if(KEY_DOWN('D'))
        {
            if(nlo->GetShield()) {
                if(nlo->GetX()+speed < 1550 - nlo->GetWidth()/1.5-15)
                    nlo->MoveTo(nlo->GetX()+speed, nlo->GetY());
            }
            else {
                if(nlo->GetX()+speed < 1550 - nlo->GetWidth()/2-15)
                    nlo->MoveTo(nlo->GetX()+speed, nlo->GetY());
            }
        }
    }
}


bool RocketMovement(NLO * nlo, Rocket * rocket) {
    if(rocket->GetDirection() == 0) {
        if(rocket->GetX() + 3 < 1540 - rocket->GetWidth()) {
            rocket->MoveTo(rocket->GetX()+3, rocket->GetY());
        }
        else
            return false;
    }

    if(rocket->GetDirection() == 1) {
        if(rocket->GetX() - 3 > 360 + rocket->GetWidth())
            rocket->MoveTo(rocket->GetX()-3, rocket->GetY());
        else 
            return false;
    }

    return true;
}


void ChargeMovement(NLO * nlo, Charge * charge) {
    if(nlo->GetX() > charge->GetX()) {
        if(nlo->GetY() > charge->GetY()) {
            charge->MoveTo(charge->GetX()+1, charge->GetY()+1);
        }
        else {
            charge->MoveTo(charge->GetX()+1, charge->GetY()-1);
        }
    }
    else {
        if(nlo->GetY() > charge->GetY()) {
            charge->MoveTo(charge->GetX()-1, charge->GetY()+1);
        }
        else {
            charge->MoveTo(charge->GetX()-1, charge->GetY()-1);
        }
    }
}


bool MeteorMovement(Meteor * meteor) {
    if(meteor->GetDirection() == 0) {
        if(meteor->GetX()+2 < 1540 - meteor->GetRadius() && meteor->GetY()-2 > 260 + meteor->GetRadius()) {
            meteor->MoveTo(meteor->GetX()+2, meteor->GetY()-2);
        }
        else return false;
    }
    else {
        if(meteor->GetX()-2 > 360 + meteor->GetRadius() && meteor->GetY()+2 < 940 - meteor->GetRadius()) {
            meteor->MoveTo(meteor->GetX()-2, meteor->GetY()+2);
        }
        else return false;
    }
    return true;
}


bool DarkHoleMovement(DarkHole * holes) {
    if(holes->GetDirection() == 0) {
        if(holes->GetY() - 1 > 300 + holes->GetRadius()*3) {
            holes->MoveTo(holes->GetX(), holes->GetY()-1);
        }
        else return false;
    }
    else {
        if(holes->GetY() + 1 < 930 - holes->GetRadius()*3) {
            holes->MoveTo(holes->GetX(), holes->GetY()+1);
        }
        else return false;
    }
    return true;
}


bool checkShieldCollision(NLO* nlo, ABC_Object* object) {
    float shieldWidth = nlo->GetWidth() * 1.5f;
    float shieldHeight = nlo->GetWidth() * 1.5f;
    
    int shieldLeft = nlo->GetX() - shieldWidth/2;
    int shieldRight = nlo->GetX() + shieldWidth/2;
    int shieldTop = nlo->GetY() - shieldHeight/2;
    int shieldBottom = nlo->GetY() + shieldHeight/2;
    
    int objLeft = object->GetX() - object->GetWidth()/2;
    int objRight = object->GetX() + object->GetWidth()/2;
    int objTop = object->GetY() - object->GetHeight()/2;
    int objBottom = object->GetY() + object->GetHeight()/2;
    
    return (shieldRight > objLeft && shieldLeft < objRight &&
            shieldBottom > objTop && shieldTop < objBottom);
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
        if(nlo->GetShield()) {
            if(checkShieldCollision(nlo, rockets[i])) {
                nlo->Hide();
                nlo->SetShield(false);
                rockets[i]->Hide();
                delete rockets[i];
                rockets.erase(rockets.begin() + i);
            }
        }
        else if(checkCollision(nlo, rockets[i])) {
            nlo->SetHealth(nlo->GetHealth()-1);
            nlo->SetMoveable(true);
            rockets[i]->Hide();
            delete rockets[i];
            rockets.erase(rockets.begin() + i);
        }
    }
    for(int i = 0; i < charges.size(); i++) {
        if(nlo->GetShield()) {
            if(checkShieldCollision(nlo, charges[i])) {
                nlo->Hide();
                nlo->SetShield(false);
                charges[i]->Hide();
                delete charges[i];
                charges.erase(charges.begin() + i);
            }
        }
        else if(checkCollision(nlo, charges[i])) {
            nlo->SetMoveable(false);
            nlo->TurnOf();
            charges[i]->Hide();
            delete charges[i];
            charges.erase(charges.begin() + i);
        }
    }
    for(int i = 0; i < meteors.size(); i++) {
        if(nlo->GetShield()) {
            if(checkShieldCollision(nlo, meteors[i])) {
                nlo->Hide();
                nlo->SetShield(false);
                meteors[i]->Hide();
                delete meteors[i];
                meteors.erase(meteors.begin() + i);
            }
        }
        else if(checkCollision(nlo, meteors[i])) {
            nlo->SetHealth(nlo->GetHealth()-2);
            nlo->SetMoveable(true);
            meteors[i]->Hide();
            delete meteors[i];
            meteors.erase(meteors.begin() + i);
        }
    }
    for(int i = 0; i < holes.size(); i++) {
        if(checkCollision(nlo, holes[i])) {
            nlo->SetHealth(nlo->GetHealth()-3);
            holes[i]->Hide();
            delete holes[i];
            holes.erase(holes.begin() + i);
        }
    }
    for(int i = 0; i < healths.size(); i++) {
        if(checkCollision(nlo, healths[i])) {
            if(nlo->GetHealth() != 3)
                nlo->SetHealth(nlo->GetHealth()+1);
            healths[i]->Hide();
            delete healths[i];
            healths.erase(healths.begin() + i);
        }
    }
    for(int i = 0; i < shields.size(); i++) {
        if(checkCollision(nlo, shields[i])) {
            nlo->SetShield(true);
            shields[i]->Hide();
            delete shields[i];
            shields.erase(shields.begin() + i);
        }
    }
}