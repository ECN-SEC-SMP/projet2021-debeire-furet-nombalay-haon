#include <iostream>
#include <string>

#include "Joueur.h"

using namespace std;

#define MAX_CASES 29

Joueur::Joueur(string nomJoueur){
  this->nomJoueur = nomJoueur;
  this->fortune = 100000;
  this->position = 0;
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

void Joueur::subFortune(int prix){
  fortune -= prix;
}

void Joueur::avancer(int nbCasesSup){
  if((position + nbCasesSup) >= MAX_CASES)
    position = (position + nbCasesSup) - MAX_CASES;
  else
    position += nbCasesSup;
}

bool operator==(Joueur j1, Joueur j2){
  if(j1.getNom() == j2.getNom() && j1.getFortune() == j2.getFortune() && j1.getPosition() == j2.getPosition())
    return true;
  else
    return false;
}

bool Joueur::achatPossible(int prixCase){
  if(prixCase > fortune)
    return true;
  else
    return false;
}

bool Joueur::paiement(Joueur *j, int somme){
  cout << "Le joueur " << nomJoueur << " paye au joueur " << j->getNom() << "un loyer d'une somme de " << somme << endl;
  Joueur::subFortune(somme);
  j->addFortune(somme);
}

void Joueur::addFortune(int prix){
  fortune += prix;
}
