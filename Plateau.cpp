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

#define MAX_CASES 29

Plateau::Plateau()
{
  this->nbCases = MAX_CASES;
  this->nbJoueurDepart = 0;
  this->nbJoueurEnJeu = 0;
}

void Plateau::initPlateau(){
  //initialisation des joueurs
  cout << "**************INITIALISATION DES JOUEURS**************\n" << endl;
  cout << "Entrez le nombre de participants:\t";
  cin >> this->nbJoueurDepart;
  this->nbJoueurEnJeu = this->nbJoueurDepart;

  for(int i = 0; i < this->nbJoueurDepart; i++){
    cout << "Nom du joueur " << i + 1 << "\t";
    string name;
    cin >> name;
    Joueur *j = new Joueur(name);
    this->listeJoueurs.push_back(j);
    cout << endl;
  }

  //initialisation des cases
  tabCases[0] = new Fixe('D', "Depart");  //case départ
  tabCases[1] = new Constructibles(3000, 600, "Rue Lecourbe");
  tabCases[2] = new Constructibles(3000, 600, "Boulevard de Belleville");
  tabCases[3] = new Gare(20000, "Gare du Nord");
  tabCases[4] = new Constructibles(4000, 800, "Avenue de la Republique");
  tabCases[5] = new Constructibles(4000, 800, "Rue de Courcelles");
  tabCases[6] = new Constructibles(4000, 800, "Rue de Vaugirard");
  tabCases[7] = new Constructibles(6000, 1200, "Boulevard de la Villette");
  tabCases[8] = new Compagnie(10000, "Distribution de l'electricite");
  tabCases[9] = new Constructibles(6000, 1200, "Avenue de Neuilly");
  tabCases[10] = new Constructibles(6000, 1200, "Rue de Paradis");
  tabCases[11] = new Gare(20000, "Gare Montparnasse");
  tabCases[12] = new Constructibles(8000, 1600, "Avenue de Mozart");
  tabCases[13] = new Constructibles(8000, 1600, "Boulevard St-Michel");
  tabCases[14] = new Constructibles(8000, 1600, "Place Pigalle");
  tabCases[15] = new Constructibles(11000, 2200, "Avenue Matignon");
  tabCases[16] = new Constructibles(11000, 2200, "Boulevard Malesherbes");
  tabCases[17] = new Constructibles(11000, 2200, "Avenue Henri-Martin");
  tabCases[18] = new Gare(20000, "Gare Saint-Lazare");
  tabCases[19] = new Constructibles(13000, 2600, "Faubourg Saint-Honore");
  tabCases[20] = new Constructibles(13000, 2600, "Place de la Bourse");
  tabCases[21] = new Compagnie(10000, "Distribution de l'eau");
  tabCases[22] = new Constructibles(13000, 2600, "Rue Lafayette");
  tabCases[23] = new Constructibles(18000, 3600, "Avenue de Breteuil");
  tabCases[24] = new Constructibles(18000, 3600, "Avenue Foch");
  tabCases[25] = new Constructibles(18000, 3600, "Boulevard des Capucines");
  tabCases[26] = new Gare(20000, "Gare de Lyon");
  tabCases[27] = new Constructibles(20000, 5000, "Avenue des Champs-Elysees");
  tabCases[28] = new Constructibles(20000, 5000, "Rue de la Paix");
}

int Plateau::nbGares(Joueur j){
  int nb = 0;
  for(int i = 0; i<MAX_CASES; i++){
    if(this->tabCases[i]->getType() == 'G'){
      if(!(this->tabCases[i]->getAchetable()) && this->tabCases[i]->getProprio() == j)
        nb ++;
    }
  }
  return nb;
}

bool Plateau::finDePartie()
{
  if(this->nbJoueurEnJeu == 1)
    return true;
  else
    return false;
}

int Plateau::lancerDe(){
  srand(time(NULL));
  return (rand() % 6);    //entre 1 et 6
}

//todo: ajouter de l'affichage sur les grosses actions du jeu
void Plateau::tourDeJeu()
{
  for(int it = 0; it < this->listeJoueurs.size(); it++){
    int de = Plateau::lancerDe();
    listeJoueurs[it]->avancer(de);    //fait avancer le joueur
    Case *cons = tabCases[listeJoueurs[it]->getPosition()];   //récupère la case sur laquelle le joueur se situe
    if(cons->getType() == 'R'){         //case de type rue
      if(cons->getAchetable() && de%2 == 1){    //si elle est achetable et le résultat du dé est impair
        if(listeJoueurs[it]->achatPossible(cons->getPrix())){   //vérifie que le joueur a les moyens de payer la case
          cons->setProprio(listeJoueurs[it]);   //change le proprietaire
          listeJoueurs[it]->subFortune(cons->getPrix());    //soustrait le prix de la case à la fortune du joueur
        }//fin if achat possible
      }//fin if achetable
      else if(cons->getAchetable() == false){   //si la case est déjà achetée
        Joueur proprio = cons->getProprio();
        if(&proprio != listeJoueurs[it]){   //si le joueur sur la case n'est pas l'heureux propriétaire de cette case
          int loyer = cons->calculLoyer();  //calcul du loyer
          listeJoueurs[it]->paiement(&proprio, loyer);  //effectue le paiement
        }
        else if(&proprio == listeJoueurs[it]){  //si le joueur présent sur la case est le proprietaire alors il peut acheter des maisons ou un hotel
          cout << "Vous possedez une fortune de " << listeJoueurs[it]->getFortune() << "." << endl;
          if(cons->getNbHotels() == 1)  //le proprietaire possede deja un hotel sur la case il ne peut donc plus acheter quoi que ce soit
            cout << "Vous possedez deja un hotel sur la case " << cons->getNom() << " et vous ne pouvez pas construire d'avantage." << endl;
          else if(cons->getNbHotels() == 0 && cons->getNbMaisons() != 4){   //le proprietaire peut encore acheter une ou plusieurs maisons
            cout << "Vous ne possedez pas d'hotel et vous possedez " << cons->getNbMaisons() << " maisons, voulez vous construire ? [o:oui/n:non]";
            char reponse;
            cin >> reponse;
            cout << endl;
            if(reponse == 'o' || reponse == 'O'){ //le joueur veut acheter une ou plusieurs maisons
              cout << "Vous ne pouvez construire que " << 4 - cons->getNbMaisons() << "." << endl;
              cout << "Combien de maisons voulez-vous construire pour le prix de 5000 chacune ??  ";
              int nb;
              cin >> nb;
              cout << endl;
              while(cons->getNbMaisons() + nb > 4){ //il ne peut avoir que 4 maisons max par case ou 1 hotel
                cout << "Vous ne pouvez avoir que 4 maisons maximum avant d'acheter un hotel la prochaine fois que vous tomberez sur la case " << cons->getNom() << endl;
                cout << "Combien de maisons voulez-vous construire pour le prix de 5000 chacune ? (4 maximum par case)  ";
                cin >> nb;
                cout << endl;
              }
              cout << "Vous achetez " << nb << " maisons sur la case " << cons->getNom() << endl;
              cons->ajouterMaison(nb);    //on ajoute les maisons a la case
              listeJoueurs[it]->subFortune(5000*nb);  //on enleve le prix des maisons au joueur
            }
          }
          else{   //le proprietaire peut acheter un hotel car il possede 4 maisons
            cout << "Vous possedez 4 maisons, voulez-vous acheter un hotel sur la case " << cons->getNom() << " ? [o:oui:n:non]";
            char reponse;
            cin >> reponse;
            cout << endl;
            if(reponse == 'o' || reponse == 'O'){
              cout << "Vous achetez un hotel sur la case " << cons->getNom() << " pour la somme de 10 000." << endl;
              cons->ajouterHotel();
              listeJoueurs[it]->subFortune(10000);
            }
          }
        }
      }
    }//fin if cons
    else if(cons->getType() == 'G'){
      
    }
  }//fin for
}
