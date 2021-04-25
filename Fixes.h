#ifndef __Fixe_h_
#define __Fixe_h_

#include <iostream>
#include "Case.h"
#include "Joueur.h"
using namespace std;

/*
Classe Fixe
La classe hérite de la classe Case
Cette fonction gère les cases de type Départ, Prison etc.. les cases qui ne sont pas achetables par les joueurs
Possède une méthode virtuelle estAchetable()
*/

class Fixe : public Case{
private:
public:
    //constructeur
    Fixe(string nom, int id);
    //méthode non réalisée
    void effectuerAction();//effectue l'action liée à la case, on différencie les différentes cases avec leurs noms ou leurs ID
    //méthode virtuelle
    bool estAchetable();    //renvoie faux constamment
};

#endif
