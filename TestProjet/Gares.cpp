#include <iostream>
#include "Gares.h"
#include "Achetables.h"
#include "Case.h"
using namespace std;

//constructeur
Gare::Gare(string nom, int id) : Achetables(nom, id){
    this->prix = 5000;
    this->loyer = 2500;
    this->proprietaire = nullptr;
}

//calcule le loyer
//le loyer est du nombre de gares possédé par le joueur multiplié par le loyer de base
int Gare::calculLoyer(){
    return proprietaire->getNbGares() * loyer;
}
