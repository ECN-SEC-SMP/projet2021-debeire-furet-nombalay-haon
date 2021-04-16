#ifndef __Case_h
#define __Case_h

#include "case.h"
#include "Joueur.h"
#include "string.h"

using namespace std;

class Achetables{ //classe fille
protected:
  int prix; //prix de la case
  Joueur propriétaire;
  bool achetable; //si case déjà achetée ou pas

public:
  Achetables();
  void acheter(Joueur);
};

#endif