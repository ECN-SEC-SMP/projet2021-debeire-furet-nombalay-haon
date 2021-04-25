#include <iostream>
#include "Achetables.h"
#include "Joueur.h"
using namespace std;

 // constructeur
Achetables::Achetables(string nom, int id): Case(nom, id){}

//renvoie vrai constamment
bool Achetables::estAchetable(){return true;}

//renvoie un pointeur sur le proprietaire qui est un objet de type Joueur
Joueur Achetables::getProprio() {return *proprietaire;}

//renvoie le prix
int Achetables::getPrix(){return prix;}

//renvoie le loyer de base de la case
int Achetables::getLoyer(){return loyer;}

//le joueur qui achète devient proprietaire de la case
//il doit également payer le prix de cette case
//renvoie vrai si l'achat s'est bien déroulé
bool Achetables::acheter(Joueur *acheteur){
  if(this->proprietaire != nullptr){
    if(acheteur->getFortune() >= this->prix){
      if(acheteur->subFortune(this->prix)){
        acheteur->subFortune(this->prix);
        this->proprietaire = acheteur;
        return true;
      }
      else
        return false;
    }
  }
  return false;
}
