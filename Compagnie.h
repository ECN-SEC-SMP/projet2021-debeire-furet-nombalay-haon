#ifndef __Compagnie_h
#define __Compagnie_h

#include "Case.h"
#include "Achetables.h"
#include "joueur.h"

#include <iostream>
#include <string.h>

using namespace std;

class Compagnie: public Achetables {
protected
  int loyer

public
  //Constructeur
  Compagnie(int prix; string nom)
  //Méthodes
  int nbCompagnie(joueur j);
  int calculLoyer();
}


#endif