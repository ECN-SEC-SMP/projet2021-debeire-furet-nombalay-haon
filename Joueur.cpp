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
  string getNom() { return nomJoueur; }
  int getFortune() { return fortune; }
  int getPosition() { return position; }

  // accesseurs en ecriture
  void setNom(string nomJoueur) { this->nomJoueur = nomJoueur; }
  void setFortune(int fortune) { this->fortune = fortune; }
  void setPosition(int position) { this->position = position; }

  // constructeur
  Joueur(string nomJoueur, int fortune, int position)
  {
    this->nomJoueur = nomJoueur;
    this->fortune = fortune;
    this->position = position;
  }
  
  void initJoueur(string nomJoueur)
  {
    this->nomJoueur = nomJoueur;
    this->fortune = 100000;
    this -> position = 0;
  }

// affichage
  /*void print() 
  {
    cout << "Le joueur" << nomJoueur << "disposant de" << fortune << "euros, est à la position" << position << endl;
  }*/
};