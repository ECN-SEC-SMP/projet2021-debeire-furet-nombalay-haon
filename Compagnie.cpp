#include "Case.h"
#include "Achetables.h"
#include "Compagnie.h"

#include <iostream>
#include <string.h>

using namespace std;

//constructeur
Compagnie::Compagnie(string nom, int id) : Achetables(nom, id){
  this->proprietaire = nullptr;
  this->prix = 5000;
  this->loyer = 0;
}

//calcule le loyer en fonction du nombre de compagnies possédé par le joueur et du loyer de base
//si le joueur possède 1 compagnie alors le loyer est de 40% le prix de base
//si le joueur possède 2 compagnie alors le loyer est de 60% le prix de base
int Compagnie::calculLoyer(){
  if(proprietaire != nullptr){
    if(proprietaire->getNbCompagnies() == 1)
      return prix * 0.4;
    else if(proprietaire->getNbCompagnies() == 2)
      return prix * 0.6;
  }
  return 0;
}
