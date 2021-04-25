#ifndef __Achetables_h
#define __Achetables_h

#include <iostream>
#include <string>
#include "Case.h"
#include "Joueur.h"

using namespace std;

/*
La classe Achetables
Elle est classe fille de la classe Case
C'est une méthode qui possède également 3 classes fille, Constructibles, Gare et Compagnie
La classe est caractérisée par un prix, un proprietaire et un loyer de base
*/

class Achetables: public Case { //classe fille
protected:
  int prix; //prix de la case
  Joueur *proprietaire;
  int loyer;

public:
  //constructeur
  Achetables(string nom, int id);
  //méthodes
  bool estAchetable();  //méthode virtuelle héritée de la classe Case, renvoie vrai si l'objet est bien de classe Achetables
  bool acheter(Joueur *acheteur);   //achète la case en s'occupant du paiement pour le joueur et définit le proprietaire
                                    //le loyer est calculé à chaque paiement et n'est jamais actualisé dans l'attribut loyer
  virtual int calculLoyer() = 0;    //méthode virtuelle servant à calculer le loyer
  //accesseurs en lecture
  Joueur getProprio();
  int getPrix();
  int getLoyer();
};

#endif
