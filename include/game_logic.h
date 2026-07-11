#pragma once
#include "headers.h"
#include <vector>

using namespace std;

void MovementNLO(NLO * nlo);

bool RocketMovement(NLO * nlo, Rocket * rocket);

void ChargeMovement(NLO * nlo, Charge * charge);

bool MeteorMovement(Meteor * meteor);

bool DarkHoleMovement(DarkHole * hole); 

void levels(LevelsWindow & window, NLO * nlo, NLO & nlo1);

void firstLevel(NLO * nlo, LevelsWindow & window, NLO & nlo1); 

void secondLevel(NLO * nlo, LevelsWindow & window, NLO & nlo1); 

void thirdLevel(NLO * nlo, LevelsWindow & window, NLO & nlo1); 

bool checkShieldCollision(NLO * nlo, ABC_Object * object);

bool checkCollision(NLO * nlo, ABC_Object * object);

void collision(NLO * nlo, vector <Rocket *> &rockets, vector <Charge *> &charges, vector <Meteor *> &meteors, vector <DarkHole *> &holes, vector <Health *> &healths, vector <Shield *> &shields);