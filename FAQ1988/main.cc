/**
 *@mainpage FINE ARTS QUEST: 1988 AUTHOR: IVAN GIL DELGADO
 * Primera versión 1 de noviembre 2020 - 4 de noviembre 2020
 * Terrassa, BCN
*/

#include "MapaInit.hh"
#include "intro.hh"

const string error = "Ahora no puedes hacer eso";

const string quehay[3] = {"Virus", "Policía", "Paso al siguiente nivel"};

const string stats[3] = {"INM", "RES", "VOL"};

bool nivel_completado = false;

int nivel = 1;

void has_perdido(Jugador& jug) {
	for(int i = 0; i < 3; ++i) {
		string stat = stats[i];
		int x = jug.consultar_stats(stat);
		if(x <= 0) {
			cout << stat << " " << x << endl;
			if(stat == "INM") cout <<"¡Has sucumbido al virus!" << endl << "Vuelves a casa a pedir hora para la PCR y cagarte en todo";
			if(stat == "RES") cout << endl << "Ya no puedes más. 'All cops are bastards' pero esos bastardos tienen coche. Que te lleven por favor, aunque sea a comisaria";
			if(stat == "VOL") cout << "A la mierda todo. Dejas el bastidor en la basura y echas CV en el Burguer King, que para acabar allí igual, mejor ir empezando";
			cout << endl;
			cualquier_tecla();
			exit(0);
		}
	}
}

void enfrentamiento(const string tipo, mapa& M, Jugador& jug, int n) {
	pair<int,int> xy = jug.dev_posicion();
	cout << endl;
	if(tipo == "Virus") {
		cout << "¡Hay una cepa de COVID-19!" << endl << "Pierdes 2 INM y 1 VOL" << endl;
		jug.modificar_stats("INM", -2);
		jug.modificar_stats("VOL", -1);
		has_perdido(jug);
		M[xy.first][xy.second][0] = false;		
	}
	if(tipo == "Policía") {
		cout << "Hay un poli que dice que estamos en cuarentena domiciliaria y te quiere multar" << endl;
		cout << "¿Qué vas a hacer?" << endl;
		cout << "HUIR - Pierdes 3 RES. El Policía seguirá ahí si vuelves" << endl << "PAGAR - Pagas la multa y pierdes 2 VOL" << endl;
		cout << "HABLAR - Te lo intentas camelar. Si tu VOL es mayor que la del Policía, te vas de rositas" << endl << "Si pierdes, pierdes tanta VOL como tuviera el Policía" << endl << "La VOL del Policía es un número aleatorio entre 2 y 5" << endl;
		string com;
		cin >> com;
		if(com == "HUIR") {
			jug.modificar_stats("RES", -3);
			has_perdido(jug);
			cout << "CORREEEE" << endl;
		}
		if(com == "PAGAR") {
			jug.modificar_stats("VOL", -2);
			has_perdido(jug);
			M[xy.first][xy.second][1] = false;
		}
		if(com == "HABLAR") {
			int voluntad_poli = rand() % 4 + 2;
			int voluntad = jug.consultar_stats("VOL");
			if(voluntad <= voluntad_poli) {
				cout << "Has perdido! v.v" << endl;
				jug.modificar_stats("VOL", -voluntad_poli);
				has_perdido(jug);
			}
			else cout << "Increible... No sabes cómo, pero te has librado" << endl;
			M[xy.first][xy.second][1] = false;
		}
	}
}

void nueva_casilla(Jugador& jug, mapa& M) {
	pair<int,int> pos_act = jug.dev_posicion();
	cout << endl << "Estás en (" << pos_act.first << ", " << pos_act.second << ")" << endl;
	cout << "En esta casilla hay: ";
	for(int i = 0; i < 3; ++i) {
		if(M[pos_act.first][pos_act.second][i]) {
			cout << quehay[i] << " ";
			enfrentamiento(quehay[i], M, jug, nivel);
		}
	}
	cout << endl;
	jug.print_stats();
}

void lector_comando(Jugador& jug, mapa& M) {
	int i = M.size();
	int j = M[i-1].size();
	pair<int,int> pos_actual;
	string comando;
	while(not nivel_completado) {
		cin >> comando;
		pos_actual = jug.dev_posicion();
		if(comando == "N") {
			if(pos_actual.first > 0) {
				jug.modificar_posicion(comando);
				nueva_casilla(jug, M);
			}
			else cout << error << endl;
		}
		if(comando == "S") {
			if(pos_actual.first < i-1) {
				jug.modificar_posicion(comando);
				nueva_casilla(jug, M);
			}
			else cout << error << endl;
		}
		if(comando == "E") {
			if(pos_actual.second < j-1) {
				jug.modificar_posicion(comando);
				nueva_casilla(jug, M);
			}
			else cout << error << endl;
		}
		if(comando == "O") {
			if(pos_actual.second > 0) {
				jug.modificar_posicion(comando);
				nueva_casilla(jug, M);
			}
			else cout << error << endl;
		}
		if(comando == "PASAR") {
			if(M[pos_actual.first][pos_actual.second][2]) {
				nivel_completado = true;
			}
			else cout << error << endl;
		}
		if(comando == "HELP") {
			intro3();
		}
		if(comando == "QUIT") exit(0);
	}
}

int main() {
	/*intro1();	//Introducción
	string n;
	cin >> n;
	intro2(n);
	string c;
	cin >> c;
	Jugador jugador(n,c);
	limpiar_pantalla();
	cout << "Tienes 1 PUNTO extra para sumar a la característica que quieras (RES/VOL/INM)" << endl;
	jugador.print_stats();
	cin >> c;
	jugador.modificar_stats(c, 1);
	cout << "Tus características finales son: ";
	jugador.print_stats();
	cualquier_tecla();
	intro3();
	cualquier_tecla();
	intro4();	//Fin introducción
	*/
	Jugador jugador("IVAN", "DIB");
	mapa M;
	//crear_mapa(M,1);
	bool terminado = false;
	while(not terminado) {
		++nivel;
		jugador.establecer_posicion(0,0);
		narrar_nivel(jugador, nivel);
		crear_mapa(M, nivel);
		nueva_casilla(jugador, M);
		lector_comando(jugador, M);
		nivel_completado = false;
	}
}
