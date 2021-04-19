#ifndef __Achetable_h
#define __Achetable_h

#include "Case.h"
#include "Joueur.h"

#include <string>

using namespace std;

class Achetables: public Case{ //classe fille
protected:
  int prix; //prix de la case
  Joueur *proprietaire;
  bool achetable; //si case déjà achetée ou pas

public:
  Achetables();
  void acheter(achetable, Joueur);
};

#endif