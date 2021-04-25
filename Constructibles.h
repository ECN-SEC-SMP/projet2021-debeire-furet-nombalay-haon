#ifndef __Constructibles_h
#define __Constructibles_h

#include <iostream>
using namespace std;

#include "Achetables.h"

class Constructibles : public Achetables{
private:
    int nbMaisons;
    int nbHotels;

public:
    //constructeur
    Constructibles(string nom, int id, int prix, int loyer);
    //méthodes
    int calculLoyer();
    void ajouterMaison(int nb);
    void ajouterHotel();
    // void affiche()override;
};

#endif
