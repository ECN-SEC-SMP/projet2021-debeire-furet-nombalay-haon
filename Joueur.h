#pragma once
#include <iostream>
#include <string>
using namespace std;
 
class Joueur {
 private:
 string nomJoueur;
 int fortune;
 int position;
 int nbGares;
 
 public:
 // accesseurs en lecture
 string getNom() { return nomJoueur; }
 int getFortune() { return fortune; }
 int getPosition() { return position; }
 int getNbGares() { return nbGares;}
 
 // accesseurs en ecriture
 void setNom(string nomJoueur) { this->nomJoueur = nomJoueur; }
 void setFortune(int fortune) { this->fortune = fortune; }
 void setPosition(int position) { this->position = position; }
 void setNbGares(int nbGares) { this->nbGares = nbGares;}
 
 // constructeur
 Joueur(string nomJoueur, int fortune, int position, int nbGares)
 {
   this->nomJoueur = nomJoueur;
   this->fortune = fortune;
   this->position = position;
   this->nbGares = nbGares;
 }
  void initJoueur(string nomJoueur)//initialisation de base
 {
   this->nomJoueur = nomJoueur;
   this->fortune = 100000;
   this->position = 0;
   this->nbGares = 0;
 }
 
 bool Paiement(Joueur donne,Joueur recoit, int somme)//Paiement à un autre joueur
 {
   if (somme<getFortune())
   {
     int fortune_donne = (donne.getFortune()-somme);
     donne.setFortune(fortune_donne);
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
