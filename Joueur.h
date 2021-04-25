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
   int nbGares;
   int nbCompagnies;

 public:
   //constructeur
   Joueur(string nomJoueur);
   //méthodes
   bool paiement(Joueur *j, int somme); //le joueur paye au joueur j un loyer du montant de somme
   bool subFortune(int prix);
   void addFortune(int prix);
   bool paiementPossible(int prixCase);
   void avancer(int nbr);
   // accesseurs en lecture
   string getNom();
   int getFortune();
   int getPosition();
   int getNbGares();
   int getNbCompagnies();
   // accesseurs en écriture
   void setNbGares(int nb);
   void setNbCompagnies(int nb);
};

#endif
