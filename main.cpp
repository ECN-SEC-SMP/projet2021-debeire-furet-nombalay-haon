#include <iostream>
#include <bits/stdc++.h>
#include <ctype.h>
#include "Plateau.h"
using namespace std;

int main(int argc, char const *argv[]) {
  Plateau *plateau = new Plateau();
  system("cls");
  plateau->initPlateau();
  plateau->tourDeJeu();
  return 0;
}
