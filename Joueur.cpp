#include <iostream>
#include <string>

#include "Joueur.h"

using namespace std;

#define MAX_CASES 40

Joueur::Joueur(string nomJoueur){
  this->nomJoueur = nomJoueur;
  this->fortune = 100000;
  this->position = 1;
  this->nbGares = 0;
  this->nbCompagnies = 0;
}

string Joueur::getNom(){
  return nomJoueur;
}

int Joueur::getFortune(){
  return fortune;
}

int Joueur::getPosition(){
  return position;
}

int Joueur::getNbGares(){
  return nbGares;
}

int Joueur::getNbCompagnies(){
  return nbCompagnies;
}

bool Joueur::subFortune(int prix){
  if(fortune - prix > 0){
    fortune -= prix;
    return true;
  }
  else{
    return false;
  }
}

bool Joueur::paiementPossible(int prixCase){
  if(prixCase > fortune)
    return false;
  else
    return true;
}

bool Joueur::paiement(Joueur *j, int somme){
  cout << "Le joueur " << nomJoueur << " paye au joueur " << j->getNom() << "un loyer d'une somme de " << somme << endl;
  j->addFortune(somme);
  if(Joueur::paiementPossible(somme)){
    Joueur::subFortune(somme);
    return true;
  }
  else
    return false;
}

void Joueur::addFortune(int prix){
  fortune += prix;
}

void Joueur::setNbGares(int nb){
  nbGares = nb;
}

void Joueur::setNbCompagnies(int nb){
  nbCompagnies = nb;
}

void Joueur::avancer(int nbr){
  if(nbr + position > MAX_CASES)
    position = (position + nbr) - MAX_CASES;
  else
    position += nbr;
}
