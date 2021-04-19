#ifndef __Gare_h
#define __Gare_h

#include "Case.h"
#include "Achetables.h"

#include <iostream>
#include <string.h>

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