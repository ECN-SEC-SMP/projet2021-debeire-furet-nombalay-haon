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
    Fixe(string nom, int id);
    void effectuerAction();
    //méthode virtuelle
    bool estAchetable();
};

#endif
