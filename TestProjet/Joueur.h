#ifndef __Joueur_h_
#define __Joueur_h_

#include <iostream>
#include <string.h>
using namespace std;

/*
La classe Joueur permet de stocker les caractéristiques de chaque joueur
Un joueur est définit par un nom, sa position, sa fortune
Au cours de la partie il peut acheter des gares ou des compagnies
*/

class Joueur {
 private:
   string nomJoueur;
   int fortune;
   int position;
   int nbGares;
   int nbCompagnies;

 public:
   //constructeur
   Joueur(string nomJoueur);    //constructeur avec seulement le nom
   //méthodes
   bool paiement(Joueur *j, int somme); //le joueur paye au joueur j un loyer du montant de somme
   bool subFortune(int prix);   //soustrait une somme à la fortune, renvoie faux si la fortune devient négative
   void addFortune(int prix);   //ajoute une somme à la fortune du joueur
   bool paiementPossible(int prixCase);   //vérifie si le paiement est possible, c'est à dire si un joueur ne passe pas dans le négatif
   void avancer(int nbr);   //fait avancer le joueur de nbr cases
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
