#include "Joueur.h"
#include <iostream>
#include <string>
using namespace std;
 
// constructeur
Joueur::Joueur(string nomJoueur)//initialisation de base
{
  this->nomJoueur = nomJoueur;
  this->fortune = 100000;
  this->position = 0;
}

 // accesseurs en lecture
 string Joueur::getNom() { return nomJoueur; }
 int Joueur::getFortune() { return fortune; }
 int Joueur::getPosition() { return position; }
 
 // accesseurs en ecriture
 void Joueur::setNom(string nomJoueur) { this->nomJoueur = nomJoueur; }
 void Joueur::setFortune(int fortune) { this->fortune = fortune; }
 void Joueur::setPosition(int position) { this->position = position; }
 
 bool Joueur::Paiement(Joueur *recoit, int somme)//Paiement à un autre joueur
 {
   if (somme<this->getFortune())
   {
     this->setFortune(this->getFortune()-somme);
     recoit->setFortune(recoit->getFortune()+somme);
     return true;
   }
   else
   {
     return false;
   }
 };
