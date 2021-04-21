#include <iostream>
#include "Case.h"
#include "Fixes.h"
#include "Joueur.h"
using namespace std;

Fixe::Fixe(char type, string nom){
    //type = "D" pour départ
    //type = "M" pour la case parking
    this->type = type;
    this->nom = nom;
}

bool Fixe::getAchetable(){}

Joueur Fixe::getProprio(){}

int Fixe::getNbMaisons(){}

int Fixe::getNbHotels(){}

int Fixe::calculLoyer(){}

void Fixe::ajouterMaison(int nb){}

void Fixe::ajouterHotel(){}

void Fixe::setProprio(Joueur *j){}

int Fixe::getPrix(){}
