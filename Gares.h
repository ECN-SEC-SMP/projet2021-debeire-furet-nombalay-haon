#ifndef __Gares_h
#define __Gares_h

#include <iostream>
#include <string>
#include "Case.h"
#include "Achetables.h"



using namespace std;

class Gare: public Achetables{
protected:
public:
  //Constructeur
  Gare(string nom, int id);
  //Méthodes
  int calculLoyer();
  // void affiche()override;
};

#endif
