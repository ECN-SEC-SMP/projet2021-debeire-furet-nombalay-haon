#ifndef __Joueur_h
#define __Joueur_h

#include <iostream>
#include <string>
using namespace std;
 
class Joueur {
  private:
  string nomJoueur;
  int fortune;
  int position;
  int nbGares;

  public:
  // accesseurs en lecture
  string getNom();
  int getFortune();
  int getPosition();

  // accesseurs en ecriture
  void setNom(string nomJoueur); 
  void setFortune(int fortune); 
  void setPosition(int position); 
 
  // constructeur
  Joueur(string nomJoueur);//initialisation de base

  bool Paiement(Joueur *recoit, int somme);//Paiement à un autre joueur
};

#endif