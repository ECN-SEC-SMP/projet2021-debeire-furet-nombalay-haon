#include "Joueur.h"
#include "Case.h"
#include "Achetables.h"
#include "Gares.h"
#include <gtest/gtest.h>

using namespace std;

// Test des fichiers Joueurs.h/cpp

// Création de deux joueurs
Joueur *j1 = new Joueur("Michel");
Joueur *j2 = new Joueur("Philippe");

// Test pour vérifier si les joueurs sont bien créés
TEST(Test_Joueur, CreationPerso)
{
	EXPECT_EQ("Michel",j1->getNom());
	EXPECT_EQ(100000,j1->getFortune());
	EXPECT_EQ(1,j1->getPosition());

	EXPECT_EQ("Philippe",j2->getNom());
	EXPECT_EQ(100000,j2->getFortune());
	EXPECT_EQ(1,j2->getPosition());
}

// Test de la fonction de soustraction de fortune
TEST(Test_Joueur, SubFortune)
{
	j1->subFortune(40000); // Michel paie un impot de 40 000
	EXPECT_EQ(60000,j1->getFortune()); // Sa fortune doit être à 60 000 (100 000 - 40 000)
}

// Test de la fonction d'addition de fortune
TEST(Test_Joueur, AddFortune)
{
	j1->addFortune(20000); // Michel reçois une somme de 20 000
	EXPECT_EQ(80000,j1->getFortune()); // Sa fortune doit être à 80 000 (60 000 + 20 000)
}

// Test de la fonction d'avancement des joueurs
TEST(Test_Joueur, Position)
{
	j1->avancer(6); // Avance Michel de 6 cases (1 -> 7)
	EXPECT_EQ(7,j1->getPosition());

	j1->avancer(3); // Avance Michel de 4 cases (7 -> 10)
	EXPECT_EQ(10,j1->getPosition());

	j1->avancer(35); // Avance Michel de 35 cases (10 -> 5)
	EXPECT_EQ(5,j1->getPosition());
}

// Test de la fonction de transaction
TEST(Test_Joueur, Paiement)
{
	j1->paiement(j2, 20000); // Michel paie à Philippe 20 000
	EXPECT_EQ(60000,j1->getFortune()); // Michel donne 20 000, il passe de 80 000 à 60 000
	EXPECT_EQ(120000,j2->getFortune()); // Philippe reçoit 20 000, il passe de 100 000 à 120 000
}

// Test de la fonction de test d'achat
TEST(Test_Joueur, Acheter)
{
	EXPECT_EQ(true,j1->paiementPossible(30000)); // Michel peut payer un terrain à 30 000 avec 60 000 sur son compte
	EXPECT_EQ(false,j1->paiementPossible(70000)); // Michel NE peut PAS payer un terrain à 70 000 avec 60 000 sur son compte
} 


// Test des fichiers Gares.h/cpp

// Création de deux joueurs
Gare *g1 = new Gare("Gare de Toulouse Matabiau",1);
Gare *g2 = new Gare("Gare de Nantes",2);

// Test pour vérifier si les gares sont bien créées
TEST(Test_Gare, CreationGare)
{
	EXPECT_EQ("Gare de Toulouse Matabiau",g1->getNom());
	EXPECT_EQ(1,g1->getID());
	EXPECT_EQ(5000,g1->getPrix());
	EXPECT_EQ(2500,g1->getLoyer());
	EXPECT_EQ(1,g2->estAchetable());

	EXPECT_EQ("Gare de Nantes",g2->getNom());
	EXPECT_EQ(2,g2->getID());
	EXPECT_EQ(5000,g2->getPrix());
	EXPECT_EQ(2500,g2->getLoyer());
	EXPECT_EQ(1,g2->estAchetable());
} 
