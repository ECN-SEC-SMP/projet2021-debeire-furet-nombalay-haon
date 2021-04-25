#ifndef __Constructibles_h
#define __Constructibles_h

#include <iostream>
using namespace std;

#include "Achetables.h"

/*
Classe Constructibles
Elle hérite de la classe Achetables
La classe constructibles est définit par le nombre de maisons et d'hotels sur la case
Un joueur peut posséder au maximum 4 maisons et 0 hotels ou 1 hotel et 0 maisons
*/

class Constructibles : public Achetables{
private:
    int nbMaisons;
    int nbHotels;

public:
    //constructeur
    Constructibles(string nom, int id, int prix, int loyer);
    //méthodes
    int calculLoyer();    //calcule le loyer à chaque fois que quelqu'un tombe sur la case en question
    void ajouterMaison(int nb); //ajoute un nombre nb de maisons (max 4)
    void ajouterHotel();    //ajoute un hotel (max 1)
    // void affiche()override;
};

#endif
