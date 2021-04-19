#include "Case.h"
#include "Fixes.h"
#include "Gares.h"
#include "Joueur.h"
#include "Plateau.h"
#include "Achetables.h"
#include "Constructibles.h"
#include "Compagnie.h"


int main()
{

  //Test joueur
  Joueur Joueur1 = Joueur("Joueur1");
  Joueur Joueur2 = Joueur("Joueur2");
  cout << "Fortune Joueur 1" << Joueur1.getFortune() << endl;
  cout << "Fortune Joueur 2" << Joueur1.getFortune() << endl;
  bool paie_ok = Joueur1.Paiement(Joueur2,2000);
  if(paie_ok)
  {
    cout <<"Paiement possible" << endl;
  }
  else
  {
    cout <<"Paiement impossible" << endl;
  }
  cout << "Fortune Joueur 1" << Joueur1.getFortune() << endl;
  cout << "Fortune Joueur 2" << Joueur1.getFortune() << endl;
}