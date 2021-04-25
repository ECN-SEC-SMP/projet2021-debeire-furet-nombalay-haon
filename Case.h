#ifndef __Case_h
#define __Case_h

#include <iostream>
#include <string>

#include "Joueur.h"

using namespace std;

class Case{
protected:
  string nom;
  int id;

public:
  //constructeur
  Case(string nom, int id);
  //accesseurs lecture
  int getID();
  string getNom();
  virtual bool estAchetable() = 0;
};

#endif
