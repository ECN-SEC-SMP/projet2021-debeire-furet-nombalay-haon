#ifndef __Case_h
#define __Case_h

#include <iostream>
#include <string>

#include "Joueur.h"

using namespace std;
/*
La classe Case est une classe abstraite
De cette classe découlent deux autres classes, Achetables et Fixe
La méthode virtuelle estAchetable sera redéfinie dans ces deux classes
*/
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
