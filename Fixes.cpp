#include <iostream>
#include "Case.h"
#include "Fixes.h"
#include "Joueur.h"
using namespace std;

Fixe::Fixe(string nom, int id) : Case(nom, id){}

void Fixe::effectuerAction(){
  cout << "action effectuee" << endl;
}

bool Fixe::estAchetable(){return false;}
