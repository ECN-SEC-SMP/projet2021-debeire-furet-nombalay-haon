#ifndef __Fixe_h_
#define __Fixe_h_

#include <iostream>
#include "Case.h"
#include "Joueur.h"
using namespace std;

class Fixe : public Case{
private:
public:
    //constructeur
    Fixe(char type, string nom);
    virtual bool getAchetable();
    virtual Joueur getProprio();

    virtual int getNbMaisons();
    virtual int getNbHotels();
    virtual int calculLoyer();
    virtual void ajouterMaison(int nb);
    virtual void ajouterHotel();
    virtual void setProprio(Joueur *j);
    virtual int getPrix();
};

#endif
