#include <iostream>
#include "Case.h"
#include "Fixes.h"
using namespace std;

Fixe::Fixe(char type, string nom){
    //type = "D" pour départ, type = "A" pour aller en prison, type = "P" pour prison
    //type = "M" pour la case parking
    this->type = type;
    this->nom = nom;
}