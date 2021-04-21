/*#include "Plateau.h"
#include "Joueur.h"
#include "Case.h"

#include <random>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <map>

using namespace std;

Plateau::Plateau(int nbJoueurDeparts)
{
  string s ="";
  for (int i = 0; i==nbJoueurDeparts; i++){
    cin >> s;    
    this->listeJoueurs.push_back(new Joueur(s));
  }
}

Case* Plateau::avance(Case* Case,int d)
{
  int p = Joueur::getPosition();
  Joueur::setPosition(p + rand()%6);
}

Plateau::finDePartie()
{
  if(getNbJoueursEnJeu() == 1) {return 1;}
  else {return 0;}
}

void Plateau::tourDeJeu()
{
  int de = round(rand()*6);
  Plateau::avance(Case, de);
  cout << "Le joueur " << Joueur << " se trouve sur la case " << Case << endl;

  if(Case)
}
*/