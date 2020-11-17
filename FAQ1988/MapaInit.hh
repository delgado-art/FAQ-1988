#ifndef MAPAINIT_HH
#define MAPAINIT_HH

#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<bool> casilla; //[0]=virus,[1]=enemigo,[2]=objetivo
typedef vector<vector<casilla> > mapa;

void situar_nivel(mapa& aux, int level);

void crear_mapa(mapa& aux, int level);

#endif
