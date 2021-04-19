#include "Joueur.h"
#include <iostream>
#include <string>
using namespace std;
 
 // accesseurs en lecture
 string Joueur::getNom() { return nomJoueur; }
 int Joueur::getFortune() { return fortune; }
 int Joueur::getPosition() { return position; }
 
 // accesseurs en ecriture
 void Joueur::setNom(string nomJoueur) { this->nomJoueur = nomJoueur; }
 void Joueur::setFortune(int fortune) { this->fortune = fortune; }
 void Joueur::setPosition(int position) { this->position = position; }
 
 // constructeur
  Joueur::Joueur(string nomJoueur)//initialisation de base
  {
   this->nomJoueur = nomJoueur;
   this->fortune = 100000;
   this->position = 0;
  }
 
 bool Joueur::Paiement(Joueur recoit, int somme)//Paiement à un autre joueur
 {
   if (somme<this->getFortune())
   {
     int fortune_donne = (this->getFortune()-somme);
     this->setFortune(fortune_donne);
     int fortune_recoit = (recoit.getFortune()+somme);
     recoit.setFortune(fortune_recoit);
     return true;
   }
   else
   {
     return false;
   }
 }
};
