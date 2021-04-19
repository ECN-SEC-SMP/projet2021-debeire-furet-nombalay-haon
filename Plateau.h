#ifndef __Plateau_h_
#define __Plateau_h_

#include <vector>
#include <iostream>
using namespace std;

#include "Joueur.h"
#include "Case.h"

class Plateau{
private:
  int nbCases;
  int nbJoueurDepart;
  int nbJoueurEnJeu;
  vector<Joueur> listeJoueurs;
  Case tabCases[];

public:
  //constructeur
  Plateau();
  //méthodes
  void initPlateau(); //initialise le plateau et demande les caractéristiques des joueurs
  void affiche();
  int nbGares(Joueur j);
  Case avance(Case c, int d);
  bool finDePartie();
  void tourDeJeu();
  //accesseurs en lecture
  int getNbJoueurEnJeu() const;
  int getNbJoueurDepart() const;
};

#endif
