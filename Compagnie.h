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
public:
  //Constructeur
  Compagnie(string nom, int id);
  //Méthodes
  int calculLoyer();
  // void affiche()override;
};

#endif
