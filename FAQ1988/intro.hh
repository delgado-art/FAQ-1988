#ifdef _WIN32
#include <windows.h>
#else 
#include <unistd.h>
#endif

#include <stdlib.h>
#include <iostream>
#include "Jugador.hh"
using namespace std;

void limpiar_pantalla();

void cualquier_tecla();

void intro1();

void intro2(string n);

void intro3();

void intro4();

void narrar_nivel(Jugador& j, int nivel);
