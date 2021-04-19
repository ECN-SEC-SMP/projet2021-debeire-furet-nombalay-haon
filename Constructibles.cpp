#include <iostream>
#include "Case.h"
#include "Achetables.h"
#include "Constructibles.h"
using namespace std;

Constructibles::Constructibles(int prix, int loyerBase, string nom){
    this->prix = prix;
    this->loyerBrut = loyerBase;
    this->nom = nom;
    this->type = 'R';       //R = rue
    this->achetable = true;
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
    //formule pour les maisons: loyer = nbMaisons * loyerBrut
    if (nbMaisons != 0 && nbHotels == 0){
        return nbMaisons * loyerBrut;
    }
    //si pas de maison ni hotel on retourne le loyer brut de base
    else if(nbMaisons == 0 && nbHotels == 0){
        return loyerBrut;
    }
    //si un hotel on retourne le loyer brut * 6
    else if (nbMaisons == 0 && nbHotels == 1){
        return loyerBrut * 6;
    }
}