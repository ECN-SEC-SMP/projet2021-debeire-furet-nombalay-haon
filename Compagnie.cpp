#include "Case.h"
#include "Achetables.h"
#include "Compagnie.h"

#include <iostream>
#include <string.h>

using namespace std;

Compagnie::Compagnie(string nom, int id) : Achetables(nom, id){
  this->proprietaire = nullptr;
  this->prix = 5000;
  this->loyer = 0;
}

int Compagnie::calculLoyer(){
  if(proprietaire != nullptr){
    if(proprietaire->getNbCompagnies() == 1)
      return prix * 0.4;
    else if(proprietaire->getNbCompagnies() == 2)
      return prix * 0.6;
  }
  return 0;
}

// void Compagnie::affiche(){
//   cout << "Case: " << nom << " (Cout: " << prix << ") - ";
//   if(proprietaire == nullptr){
//     cout << "sans proprietaire" << endl;
//   }
//   else{
//     cout << "proprietaire: " << proprietaire->getNom() << ", loyer: " << Compagnie::calculLoyer() << endl;
//   }
// }
