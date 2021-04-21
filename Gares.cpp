#include <iostream>
#include "Gares.h"
#include "Achetables.h"
#include "Case.h"
using namespace std;

Gare::Gare(int prix, string nom){
    this->prix = prix;
    this->nom = nom;
    this->loyer = 2500;
    this->achetable = true;
    this->type = 'G';
}

int Gare::calculLoyer(int nbGares){
    return nbGares * loyer;
}
