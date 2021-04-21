#include "Case.h"
#include "Achetables.h"
#include "Joueur.h"

#include <iostream>
#include <string.h>

using namespace std;

 // constructeur
  Achetables::Achetables() {}
  Achetables::Achetables(int prix, Joueur NomJoueur, bool achetable) {}


/*void acheter(bool caseAchetable, Joueur j){
  if(caseAchetable == 1)
  {
    // il faut une fonction pour acheter la case ou 
    caseAchetable = false;
  }
}*/

ostream& operator<<(ostream& flux, Achetables const& a)
{
  flux << typeid(a).name() << " : "; //A finir
  return flux;
} 