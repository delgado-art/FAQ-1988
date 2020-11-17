/*
 @class Jugador
 @brief La clase Jugador alberga los stats e inventario del jugador
*/

#ifndef JUGADOR_HH
#define JUGADOR_HH

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Jugador {

private:
	string name;
	int clase; //0=DIB, 1=PIN, 2=ESC
	//Stats
	vector<int> stats; // [0]=RES, [1]=VOL, [2]=INM
	//Inventario
	//vector<int> invent; // [0]=material,[1]=mascarilla,[2]=oro,[3]=toalla
	pair<int,int> posicion;

public:
	//Constructora
	/** @brief Crea un jugador
	   \pre Los datos del jugador se han dado
	   \post Se crea un jugador con los datos dados
	*/
	Jugador(string n, string c);

	//Destructora
	~Jugador();

	//Consultoras

	string dev_nombre(); //Devuelve el nombre

	string dev_clase(); //devuelve la clase

	int consultar_stats(string c); //Devuelve el valor del stat

	//int consultar_invent(int i); //Devuleve el valor de invent[i]

	void print_stats(); //Imprime el valor actual de los stats

	//void print_invent(); //Imprime los objetos y cantidad

	pair<int,int> dev_posicion();

	//Modificadoras
	
	void modificar_stats(string c, int x); //Modifica el stat[c] = [c] + x

	//void modificar_invent(int i, int x); //Modifica el invent[i] = [i] + x

	void modificar_posicion(string comando);

	void establecer_posicion(int x, int y);
};
#endif
