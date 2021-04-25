#ifndef __Plateau_h_
#define __Plateau_h_

#define MAX_CASES 40

#include <vector>
#include <iostream>
using namespace std;

#include "Joueur.h"
#include "Case.h"

class Plateau{
private:
  int nbJoueurDepart;
  vector<Joueur *> listeJoueurs;
  vector<Case *> cases;

public:
  //constructeur
  Plateau();
  //méthodes
  void initPlateau(); //initialise le plateau et demande les caractéristiques des joueurs
  void affiche();
  bool finDePartie();
  void tourDeJeu();
  void supprimeJoueur(Joueur *j);
  int lancerDe();
};

#endif
