#include "Achetables.h"
#include "Joueur.h"

 // constructeur
Achetables::Achetables(){}

bool Achetables::getAchetable(){return achetable;}

Joueur Achetables::getProprio() {return *proprietaire;}

int Achetables::getPrix(){return prix;}

void Achetables::setProprio(Joueur *j){
  this->proprietaire = j;
}

int Achetables::getNbMaisons(){}

int Achetables::getNbHotels(){}

int Achetables::calculLoyer(){}

void Achetables::ajouterMaison(int nb){}

void Achetables::ajouterHotel(){}
