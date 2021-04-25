#ifndef __Gares_h
#define __Gares_h

#include <iostream>
#include <string>
#include "Case.h"
#include "Achetables.h"

using namespace std;

/*
Classe Gare
Cette classe hérite de Achetables
Elle définit les cases de type Gare
Elle n'a pas d'attributs et une seule méthode servant à calculer le loyer
*/

class Gare: public Achetables{
protected:
public:
  //Constructeur
  Gare(string nom, int id);
  //Méthodes
  int calculLoyer();  //renvoie le loyer à chaque fois qu'il est demandé mais n'est stocké nulle part
                      //elle renvoie le loyer en fonction du nombre de gares que possède le joueur
};

#endif
