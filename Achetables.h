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
  bool achetable; //si case déjà achetée ou pas

public:
  //constructeur
  Achetables();
  //méthodes
  void acheter(Joueur j);
  //accesseurs en lecture
  Joueur getProprio();
  bool getAchetable();
  int getPrix();
  void setProprio(Joueur *j);
  virtual int getNbMaisons();
  virtual int getNbHotels();
  virtual int calculLoyer();
  virtual void ajouterMaison(int nb);
  virtual void ajouterHotel();
};

#endif
