#include "Case.h"
#include "Achetables.h"
#include "Compagnie.h"

#include <iostream>
#include <string.h>

using namespace std;

Compagnie::Compagnie(int prix, string nom) {
  this->prix = prix;
  this->nom = nom;
}
