#include "MapaInit.hh"

void situar_nivel(mapa& aux, int level) {
	int i = aux.size();
	int j = aux[i-1].size();
	int n_virus, n_ene;
	if(level == 1 or level == 4) {
		n_virus = 0;
		n_ene = 0;
	}
	if(level == 2) {
		n_virus = 3;
		n_ene = 2;
	}
	if(level == 3) {
		n_virus = 1;
		n_ene = 1;
	}
	int x, y;
	while(n_virus > 0) {
		x = rand() % i;
		y = rand() % j;
		if(aux[x][y][0] == false and not(x == 0 and y == 0)) {
			aux[x][y][0] = true;
			--n_virus;
		} 
	}
	while(n_ene > 0) {
		x = rand() % i;
		y = rand() % j;
		if(aux[x][y][1] == false and aux[x][y][0] == false and not(x == 0 and y == 0)) {
			aux[x][y][1] = true;
			--n_ene;
		} 
	}
	bool salida = false;
	while(not salida) {
		x = rand() % i;
		y = rand() % j;
		if(aux[x][y][1] == false and aux[x][y][0] == false and not(x == 0 and y == 0)) {
			aux[x][y][2] = true;
			salida = true;
		}
	}
	/*bool obj = false;
	while(not obj) {
		x = rand() % i + 1;
		y = rand() % j + 1;
		if(aux[x][y][1] == false and aux[x][y][0] == false) {
			aux[x][y][2] = true;
			obj = true;
		}
	}*/
}

void crear_mapa(mapa& aux, int level) {
	if(level == 1 or level == 4) {
		aux = vector<vector<casilla> > (2, vector<casilla> (1, vector<bool> (3, false)));
	}
	if(level == 2) {
		aux = vector<vector<casilla> > (4, vector<casilla> (4, vector<bool> (3, false)));
	}
	if(level == 3) {
		aux = vector<vector<casilla> > (1, vector<casilla> (5, vector<bool> (3, false)));
	}
	situar_nivel(aux, level);
}
