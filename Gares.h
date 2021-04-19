#ifndef __Gares_h
#define __Gares_h

#include <iostream>
#include <string>
#include "Case.h"
#include "Achetables.h"



using namespace std;

class Gare: public Achetables{
protected:
  int loyer;

public:
  //Constructeur
  Gare(int prix, string nom);
  //Méthodes
  int calculLoyer(int nbGares);
};

#endif