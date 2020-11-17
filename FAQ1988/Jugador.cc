#include "Jugador.hh"

Jugador::Jugador(string n, string c) {
	name = n;
	stats = vector<int>(3,5);
	//invent = vector<int>(4,0);
	if (c == "DIB") {
		clase = 0;
		stats[2] = stats[2] + 2;
		stats[1] = stats[1] - 2;
	}
	if (c == "PIN") {
		clase = 1;
		stats[0] = stats[0] + 2;
		stats[2] = stats[2] - 2;
	}
	if (c == "ESC") {
		clase = 2;
		stats[1] = stats[1] + 2;
		stats[0] = stats[0] - 2;
	}
	posicion.first = 0;
	posicion.second = 0;
}

Jugador::~Jugador() {}

string Jugador::dev_nombre() {
	return name;
}

string Jugador::dev_clase() {
	string c;
	if(clase == 0) c = "DIB";
	if(clase == 1) c = "PIN";
	if(clase == 2) c = "ESC";
	return c;
}

int Jugador::consultar_stats(string c) {
	if(c == "DIB") return stats[0];
	if(c == "PIN") return stats[1];
	if(c == "ESC") return stats[2];
}

/*int Jugador::consultar_invent(int i) {
	return invent[i];
}*/

void Jugador::print_stats() {
	cout << "RES " << stats[0];
	cout << " VOL " << stats[1];
	cout << " INM " << stats[2] << endl;
}

/*void Jugador::print_invent() {
	if(invent[0] > 0) cout << "Material: " << invent[0] << endl;
	if(invent[1] > 0) cout << "Mascarilla: " << invent[0] << endl;
	if(invent[2] > 0) cout << "Oro: " << invent[0] << endl;
	if(invent[3] > 0) cout << "Limpiagafas: " << invent[0] << endl;
}*/

pair<int,int> Jugador::dev_posicion() {
	return posicion;
}

void Jugador::modificar_stats(string c, int x) {
	if(c == "RES") {
		stats[0] = stats[0] + x;
	}
	if(c == "VOL") {
		stats[1] = stats[1] + x;
	}
	if(c == "INM") {
		stats[2] = stats[2] + x;
	}
}

/*void Jugador::modificar_invent(int i, int x) {
	invent[i] = invent[i] + x;
}*/

void Jugador::modificar_posicion(string comando) {
	if(comando == "N") --posicion.first;
	if(comando == "S") ++posicion.first;
	if(comando == "E") ++posicion.second;
	if(comando == "O") --posicion.second;
}

void Jugador::establecer_posicion(int x, int y) {
	posicion.first = x;
	posicion.second = y;
}
