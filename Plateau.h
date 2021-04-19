#ifndef __Plateau_h
#define __Plateau_h

#define <vector>
using namespace std;

#include "Joueur.h"
#include "Case.h"

class Plateau{
private:
  int nbCases;
  int nbJoueursDeparts;
  int nbJoueursEnJeu;
  vector <Joueur*> listeJoueurs;
  vector <Case*> listeCases;
public:
  Plateau(int nbJoueurDeparts);//initialisation
  int getNbJoueursEnJeu() const;
  int getNbJoueursDepart() const;
};

#endif