#ifndef __Case_h
#define __Case_h

#pragma once
#include <string>

using namespace std;

class Case{ //classe abstraite
protected:
  string nom; //pas de numéro de case car on range les cases dans un tableau
  char type;

public:
  Case();

};

#endif