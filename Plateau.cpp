#include "Plateau.h"
#include "Joueur.h"

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