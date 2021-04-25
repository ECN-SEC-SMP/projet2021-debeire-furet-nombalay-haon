#ifndef __Achetables_h
#define __Achetables_h

#include <iostream>
#include <string>
#include "Case.h"
#include "Joueur.h"

using namespace std;

class Achetables: public Case { //classe fille
protected:
  int prix; //prix de la case
  Joueur *proprietaire;
  int loyer;

public:
  //constructeur
  Achetables(string nom, int id);
  //méthodes
  bool estAchetable();
  bool acheter(Joueur *acheteur);
  virtual int calculLoyer() = 0;
  bool proprioPresent();
  // virtual void affiche();
  //accesseurs en lecture
  Joueur getProprio();
  int getPrix();
  int getLoyer();
  //accesseur écriture
  void setLoyer(int loyer);
};

#endif
