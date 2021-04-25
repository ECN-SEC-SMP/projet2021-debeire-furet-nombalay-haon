#include <iostream>
#include "Achetables.h"
#include "Joueur.h"
using namespace std;

 // constructeur
Achetables::Achetables(string nom, int id): Case(nom, id){}

bool Achetables::estAchetable(){return true;}

Joueur Achetables::getProprio() {return *proprietaire;}

int Achetables::getPrix(){return this->prix;}

int Achetables::getLoyer(){return this->loyer;}

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

void Achetables::setLoyer(int loyer){
  this->loyer = loyer;
}

bool Achetables::proprioPresent(){
  if(this->proprietaire == nullptr){return false;}
  else{return true;}
}
