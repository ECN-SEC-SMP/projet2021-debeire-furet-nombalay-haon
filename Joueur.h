#ifndef __Joueur_h_
#define __Joueur_h_

#include <iostream>
#include <string.h>
using namespace std;

class Joueur {
 private:
   string nomJoueur;
   int fortune;
   int position;

 public:
   // accesseurs en lecture
   string getNom();
   int getFortune();
   int getPosition();
   //constructeur
   Joueur(string nomJoueur);
   //méthodes
   void avancer(int nbCasesSup);
   bool paiement(Joueur *j, int somme); //le joueur paye au joueur j un loyer du montant de somme
   void subFortune(int prix);
   void addFortune(int prix);
   bool achatPossible(int prixCase);
};

bool operator==(Joueur const& j1, Joueur const& j2);

#endif
