#include <iostream>
#include "Case.h"
#include "Achetables.h"
#include "Constructibles.h"
using namespace std;

Constructibles::Constructibles(string nom, int id, int prix, int loyer) : Achetables(nom, id){
    this->prix = prix;
    this->loyer = loyer;
    this->proprietaire = nullptr;
    this->nbMaisons = 0;
    this->nbHotels = 0;
}

//vérification du nombre de maisons possible à ajouter avant l'appel à cette méthode
void Constructibles::ajouterMaison(int nb){
    nbMaisons += nb;
}

//vérification si l'ajout d'un hotel est possible avant l'appel à cette méthode
void Constructibles::ajouterHotel(){
    if (nbHotels != 1)
        nbHotels ++;
}

int Constructibles::calculLoyer(){
  if(nbMaisons == 0 && nbHotels == 0)
    return prix * 0.6;
  else if(nbMaisons != 0 && nbHotels == 0){
    return prix * (0.6 + 0.1 * nbMaisons);
  }
  else if(nbMaisons == 0 && nbHotels == 1)
    return (prix + prix * 0.5);
}

// void Constructibles::affiche(){
//   cout << "Case: " << nom << " (Cout: " << prix << ") - ";
//   if(proprietaire != nullptr)
//     cout << "proprietaire: " << proprietaire->getNom() << ", " << nbMaisons << " maisons, loyer = " << Constructibles::calculLoyer() << endl;
//   else
//     cout << "sans proprietaire" << endl;
// }
