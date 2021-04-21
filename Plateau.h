#ifndef __Plateau_h_
#define __Plateau_h_

#define MAX_CASES 29

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
  vector<Joueur *> listeJoueurs;
  Case *tabCases[MAX_CASES];

public:
  //constructeur
  Plateau();
  //méthodes
  void initPlateau(); //initialise le plateau et demande les caractéristiques des joueurs
  void affiche();
  int nbGares(Joueur j);
  bool finDePartie();
  void tourDeJeu();
  void supprimeJoueur(Joueur j);
  int lancerDe();
  //accesseurs en lecture
  int getNbJoueurEnJeu() const;
  int getNbJoueurDepart() const;
};

#endif
