#ifndef __Constructibles_h
#define __Constructibles_h

#include <iostream>
#include <string>


#include "Case.h"
#include "Achetables.h"

using namespace std;

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
    int calculLoyer();
};

#endif