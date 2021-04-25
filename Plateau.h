#ifndef __Plateau_h_
#define __Plateau_h_

#include <vector>
#include <iostream>
using namespace std;

#include "Joueur.h"
#include "Case.h"

/*
Classe Plateau
La classe plateau permet de gérer l'ensemble des cases et des joueurs
*/

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
  void affiche();   //affiche l'entièreté des cases du plateau
  bool finDePartie(); //regarde si la fin de partie est atteinte, c'est à dire si il ne reste que un seul joueur
  void tourDeJeu();   //effectue le tour de jeu pour tous les joueurs
  void supprimeJoueur(Joueur *j);   //enlève un joueur de la partie lorsque il a perdu
  int lancerDe();   //tire au sort un numero entre 1 et 6
};

#endif
