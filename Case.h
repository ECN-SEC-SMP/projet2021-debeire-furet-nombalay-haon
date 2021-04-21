#ifndef __Case_h
#define __Case_h

#include <iostream>
#include <string>

#include "Joueur.h"

using namespace std;

class Case{ //classe abstraite
protected:
  string nom; //pas de numéro de case car on range les cases dans un tableau
  char type;

public:
  //constructeur
  Case();
  //accesseurs lecture
  char getType();
  string getNom();
  //méthodes virtuelles pour achetables
  virtual bool getAchetable();
  virtual Joueur getProprio();
  virtual void setProprio(Joueur *j);
  virtual int getPrix();
  //méthodes virtuelles pour Constructibles
  virtual int getNbMaisons();
  virtual int getNbHotels();
  virtual int calculLoyer();
  virtual void ajouterMaison(int nb);
  virtual void ajouterHotel();
};

#endif
