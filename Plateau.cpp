#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "Plateau.h"
#include "Joueur.h"
#include "Case.h"
#include "Achetables.h"
#include "Constructibles.h"
#include "Gares.h"
#include "Compagnie.h"
#include "Fixes.h"

using namespace std;

#define MAX_CASES 40


//technique pour savoir si un object appartient à une classe
//renvoie vrai si l'objet appartient bien à l'objet, sinon renvoie faux
//technique trouvée sur internet
//équivalent de isinstance(object, class) en python
//équivalent de instanceof() en java
template<typename Base, typename T>
inline bool instanceof(const T*){
  return std::is_base_of<Base, T>::value;
}

Plateau::Plateau(){
  this->nbJoueurDepart = 0;
}

void Plateau::initPlateau(){
  //initialisation des joueurs
  cout << "**************INITIALISATION DES JOUEURS**************\n" << endl;
  cout << "Entrez le nombre de participants:\t";
  cin >> this->nbJoueurDepart;

	if(this->nbJoueurDepart < 2){
    cout << "Nombre de joueurs requis insuffisants" << endl;
    exit(-1);
  }
	else if(this->nbJoueurDepart > 6){
    cout << "Nombre de joueurs trop élevé" << endl;
    exit(-1);
  }

  for(int i = 0; i < this->nbJoueurDepart; i++){
    cout << "Nom du joueur " << i + 1 << ":  ";
    string name;
    cin >> name;
    Joueur *j = new Joueur(name);
    this->listeJoueurs.push_back(j);
  }

  //initialisation des cases
  int id = 1;
  cases.push_back(new Fixe("Depart", id++));
  cases.push_back(new Constructibles("Boulevard de Belleville", id++, 3000, 600));
  cases.push_back(new Fixe("Caisse de communaute", id++));
  cases.push_back(new Constructibles("Rue Lecourbe", id++, 3000, 600));
  cases.push_back(new Fixe("Impot sur le revenu", id++));
  cases.push_back(new Gare("Gare Montparnasse", id++));
  cases.push_back(new Constructibles("Rue de Vaugirard", id++, 4000, 800));
  cases.push_back(new Fixe("Chance", id++));
  cases.push_back(new Constructibles("Rue de Courcelles", id++, 4000, 800));
  cases.push_back(new Constructibles("Avenue de la Republique", id++, 4000, 800));    //case 10
  cases.push_back(new Fixe("Prison", id++));
  cases.push_back(new Constructibles("Boulevard de la Villette", id++, 6000, 1200));
  cases.push_back(new Compagnie("Distribution electricite", id++));
  cases.push_back(new Constructibles("Avenue de Neuilly", id++, 6000, 1200));
  cases.push_back(new Constructibles("Rue de Paradis", id++, 6000, 1200));
  cases.push_back(new Gare("Gare de Lyon", id++));
  cases.push_back(new Constructibles("Avenue de Mozart", id++, 8000, 1600));
  cases.push_back(new Fixe("Caisse de communaute", id++));
  cases.push_back(new Constructibles("Boulevard St-Michel", id++, 8000, 1600));
  cases.push_back(new Constructibles("Place Pigalle", id++, 8000, 1600));
  cases.push_back(new Fixe("Parc Gratuit", id++));
  cases.push_back(new Constructibles("Avenue Matignon", id++, 11000, 2200));
  cases.push_back(new Fixe("Chance", id++));
  cases.push_back(new Constructibles("Boulevard Malesherbes", id++, 11000, 2200));
  cases.push_back(new Constructibles("Avenue Henri-Martin", id++, 11000, 2200));
  cases.push_back(new Gare("Gare du Nord", id++));
  cases.push_back(new Constructibles("Faubourg Saint-Honore", id++, 13000, 2600));
  cases.push_back(new Constructibles("Place de la Bourse", id++, 13000, 2600));
  cases.push_back(new Compagnie("Distribution d'eau", id++));
  cases.push_back(new Constructibles("Rue Lafayette", id++, 13000, 2600));
  cases.push_back(new Fixe("Allez en prison", id++));
  cases.push_back(new Constructibles("Avenue de Breteuil", id++, 18000, 3600));
  cases.push_back(new Constructibles("Avenue Foch", id++, 18000, 3600));
  cases.push_back(new Fixe("Caisse de communaute", id++));
  cases.push_back(new Constructibles("Boulevard des Capucines", id++, 18000, 3600));
  cases.push_back(new Gare("Gare Saint-Lazare", id++));
  cases.push_back(new Fixe("Chance", id++));
  cases.push_back(new Constructibles("Avenue des Champs-Elysees", id++, 20000, 5000));
  cases.push_back(new Fixe("Taxe de luxe", id++));
  cases.push_back(new Constructibles("Rue de la Paix", id++, 20000, 5000));
}

bool Plateau::finDePartie()
{
  if(this->listeJoueurs.size() == 1)
	{
		cout << "Le gagnant est : " << endl;
    this->listeJoueurs[0];
		return true;
  }
  else return false;
}

int Plateau::lancerDe(){
  return (rand() % 6) + 1;    //entre 1 et 6
}

void Plateau::supprimeJoueur(Joueur *j){

}

void Plateau::tourDeJeu()
{
  srand(time(NULL));
  for(int i = 0; i<listeJoueurs.size(); i++){
    //fait avancer le joueur
    cout << "Tour du joueur: " << listeJoueurs[i]->getNom() << endl;
    int de = Plateau::lancerDe();
    cout << "Valeur du de: " << de << endl;
    cout << "Ancienne position du joueur: " <<listeJoueurs[i]->getPosition();
    listeJoueurs[i]->avancer(de);
    int posJoueur = listeJoueurs[i]->getPosition();
    cout << "\tNouvelle position du joueur: " << listeJoueurs[i]->getPosition() << endl;

    if(!instanceof<Achetables>(cases[posJoueur])){    //nouvelle position sur une case achetable
      cout <<"test1"<<endl;
      Achetables * caseAchetable = (Achetables *) cases[posJoueur];
      Joueur j = caseAchetable->getProprio();
      cout <<"test2"<<endl;
      Joueur * proprioCase = &j;
      cout <<"test3"<<endl;
      //si la case de possède pas de proprietaire
      if(proprioCase == nullptr){
        cout << "Case: " << caseAchetable->getNom() << " - sans proprietaire" << endl;
        //si l'achat de la case par le joueur est possible et que le résultat du dé est impair alors le joueur achète la case
        if(listeJoueurs[i]->paiementPossible(caseAchetable->getPrix()) && de%2 == 1){
          cout << "Achat de la case car le resultat du de est impair et le joueur possede suffisamment de moyens" << endl;
          //vérifie si l'achat s'est bien passé
          if(caseAchetable->acheter(listeJoueurs[i])){
            cout << "Achat de la case " << caseAchetable->getNom() << " effectue" << endl;
          }
        }
      }
      //si la case possède un proprietaire
      else if(proprioCase != nullptr && proprioCase != listeJoueurs[i]){
        cout << "La case possede un proprietaire qui est le joueur: " << caseAchetable->getProprio().getNom() << endl;
        int loyer = caseAchetable->calculLoyer();
        bool resPaiement = listeJoueurs[i]->paiement(proprioCase, loyer);
        if(!resPaiement){   //si le joueur ne pouvait pas payer le loyer il est supprimer de la liste des joueurs
          Plateau::supprimeJoueur(listeJoueurs[i]);
          cout << "Joueur " << listeJoueurs[i]->getNom() << " elimine car moyens insuffisants" << endl;
        }
      }
    }
    else{                                   //nouvelle position sur une case non achetable

    }
  }
}
