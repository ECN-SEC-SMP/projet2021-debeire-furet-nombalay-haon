#include <iostream>
#include "Case.h"

Case::Case(string nom, int id){
  this->nom = nom;
  this->id = id;
}

int Case::getID(){return id;}

string Case::getNom() {return nom;};
