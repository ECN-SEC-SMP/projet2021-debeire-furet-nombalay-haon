#include <iostream>
#include "Case.h"
#include "Fixes.h"
#include "Joueur.h"
using namespace std;

//constructeur
Fixe::Fixe(string nom, int id) : Case(nom, id){}

//todo
//effectue une action
void Fixe::effectuerAction(){
  cout << "action effectuee" << endl;
}

//renvoie faux constamment
bool Fixe::estAchetable(){return false;}
