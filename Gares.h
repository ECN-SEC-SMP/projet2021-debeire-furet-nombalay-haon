#ifndef __Gare_h
#define __Gare_h

#pragma once
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