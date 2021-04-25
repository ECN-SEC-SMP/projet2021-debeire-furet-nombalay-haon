#include <iostream>
#include "Gares.h"
#include "Achetables.h"
#include "Case.h"
using namespace std;

Gare::Gare(string nom, int id) : Achetables(nom, id){
    this->prix = 5000;
    this->loyer = 2500;
    this->proprietaire = nullptr;
}

int Gare::calculLoyer(){
    return proprietaire->getNbGares() * loyer;
}

// void Gare::affiche(){
//   cout << "Case: " << nom << " (Cout: " << prix << ") - ";
//   if(proprietaire == nullptr){
//     cout << "sans proprietaire" << endl;
//   }
//   else{
//     cout << "proprietaire: " << proprietaire->getNom() << ", loyer: " << Gare::calculLoyer() << endl;
//   }
// }
