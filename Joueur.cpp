#include <iostream>
#include <string>

#include "Joueur.h"

using namespace std;

#define MAX_CASES 40

//initialisation d'un joueur en début de jeu
Joueur::Joueur(string nomJoueur){
  this->nomJoueur = nomJoueur;
  this->fortune = 100000;
  this->position = 1;
  this->nbGares = 0;
  this->nbCompagnies = 0;
}

//renvoie le nom du joueur
string Joueur::getNom(){
  return nomJoueur;
}

//renvoie la fortune du joueur
int Joueur::getFortune(){
  return fortune;
}

//renvoie la position du joueur
int Joueur::getPosition(){
  return position;
}

//renvoie le nombre de gares du joueur
int Joueur::getNbGares(){
  return nbGares;
}

//renvoie le nombre de compagnies du joueur
int Joueur::getNbCompagnies(){
  return nbCompagnies;
}

//renvoie faux si le joueur possède une fortune dans le négatif
bool Joueur::subFortune(int prix){
  if(fortune - prix > 0){
    fortune -= prix;
    return true;
  }
  else{
    return false;
  }
}

//renvoie vrai si le paiement est possible
//c'est à dire si le joueur ne sera pas dans le négatif après le paiement
bool Joueur::paiementPossible(int prixCase){
  if(prixCase > fortune)
    return false;
  else
    return true;
}

//paye le joueur j du loyer qu'il doit recevoir
//renvoie vrai si le paiement à bien été effectué
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

//ajoute à la fortune le nouveau prix
void Joueur::addFortune(int prix){
  fortune += prix;
}

//actualise le nombre de gares possédées par le joueur
void Joueur::setNbGares(int nb){
  nbGares = nb;
}

//actualise le nombre de compagnies possédées par le joueur
void Joueur::setNbCompagnies(int nb){
  nbCompagnies = nb;
}

//fait avancer le joueur
//le déplacement lui fait dépasser la case Départ c'est à dire la case 1, alors il revient au départ
void Joueur::avancer(int nbr){
  if(nbr + position > MAX_CASES)
    position = (position + nbr) - MAX_CASES;
  else
    position += nbr;
}
