#ifndef __Compagnie_h
#define __Compagnie_h

#include <iostream>
#include <string>

#include "Case.h"
#include "Achetables.h"

using namespace std;

/*
Classe Compagnie
Cette classe hérite de Achetables
Elle ne possède pas d'attributs et une méthode virtuelle héritée de Achetables
*/

class Compagnie: public Achetables
{
protected:
public:
  //Constructeur
  Compagnie(string nom, int id);
  //Méthodes
  int calculLoyer();    //renvoie le loyer à chaque fois qu'il est demandé mais n'est stocké nulle part
                        //calcule le loyer en fonction du nombre de compagnies possédées par le joueur
};

#endif
