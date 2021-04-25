#include <iostream>
#include "Case.h"
#include "Achetables.h"
#include "Constructibles.h"
using namespace std;

//constructeur
Constructibles::Constructibles(string nom, int id, int prix, int loyer) : Achetables(nom, id){
    this->prix = prix;
    this->loyer = loyer;
    this->proprietaire = nullptr;
    this->nbMaisons = 0;
    this->nbHotels = 0;
}

//ajoute de 1 à 4 maisons à la case
//la vérification du nombre de maisons pour ne pas dépasser 4 est fait avant cette méthode
void Constructibles::ajouterMaison(int nb){
    nbMaisons += nb;
}

//ajoute 1 hotel à la case
//vérification si l'ajout d'un hotel est possible avant l'appel à cette méthode
void Constructibles::ajouterHotel(){
    if (nbHotels != 1)
        nbHotels ++;
}

//calcule le loyer
//si le joueur ne possède aucune maison ni aucun hotel alors le loyer est de 60% le prix de base
//si le joueur possède 1 ou plusieurs maisons le loyer est de 60% le prix de base + 10% du prix de base par maison
//si le joueur possède un hotel le loyer est de 150% le prix de base
int Constructibles::calculLoyer(){
  if(nbMaisons == 0 && nbHotels == 0)
    return prix * 0.6;
  else if(nbMaisons != 0 && nbHotels == 0){
    return prix * (0.6 + 0.1 * nbMaisons);
  }
  else if(nbMaisons == 0 && nbHotels == 1)
    return (prix + prix * 0.5);
}
