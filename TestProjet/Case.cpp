#include <iostream>
#include "Case.h"

//constructeur
Case::Case(string nom, int id){
  this->nom = nom;
  this->id = id;
}

//renvoie l'id de la case
int Case::getID(){return id;}

//renvoie le nom de la case
string Case::getNom() {return nom;};
