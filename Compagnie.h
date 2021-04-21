#ifndef __Compagnie_h
#define __Compagnie_h

#include <iostream>
#include <string>

#include "Case.h"
#include "Achetables.h"

using namespace std;

class Compagnie: public Achetables
{
protected:
  int loyer;

public:
  //Constructeur
  Compagnie(int prix, string nom);
  //Méthodes
  int calculLoyer();
};

#endif
