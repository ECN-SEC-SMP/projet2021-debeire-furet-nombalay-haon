#ifndef __Constructibles_h
#define __Constructibles_h

#include <iostream>
using namespace std;

#include "Achetables.h"
#include "Joueur.h"

class Constructibles : public Achetables{
private:
    int loyerBrut;
    int nbMaisons;
    int nbHotels;

public:
    //constructeur
    Constructibles(int prix, int loyerBase, string nom);
    //méthodes
    void ajouterMaison(int nb);
    void ajouterHotel();
    int getNbMaisons();
    int getNbHotels();
    int calculLoyer();
};

#endif
