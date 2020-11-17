#include "intro.hh"

void limpiar_pantalla() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void cualquier_tecla() {
	cout << endl << endl << endl;
	cout << "Presiona enter para continuar" << endl;
	#ifdef _WIN32
		system("pause>nul");
	#else
		system("read n 1");
	#endif
	limpiar_pantalla();
}

void intro1() {
	limpiar_pantalla();
	cout << "FINE ARTS QUEST: 1988" << endl;
	sleep(2);
	cout << "v0.1 BETA - 3/11/2020" << endl;
	sleep(2);
	cout << "Diseño y código: IVAN GIL" << endl;
	sleep(1);
	cualquier_tecla();
	sleep(1);
	cout << "Bienvenid@ artista!" << endl; sleep(1);
	cout << "Soy el Narrador, y voy a guiarte en tu aventura" << endl;
	cout << "Por favor, dime tu nombre" << endl;
}

void intro2(string n) {
	limpiar_pantalla();
	cout << "Hola " << n << ", deja que te explique algunas cosas" << endl; sleep(1);
	cout << "Tu aventura consiste en llegar de tu CASA a la FACULTAD" << endl; sleep(1);
	cout << "Por el camino, te enfrentarás a algunos peligros:" << endl;
	cout << "	El VIRUS, que se combate con la característica INMunidad" << endl;
	cout << "	Otras PERSONAS, de las que puedes huir con la característica RESistencia" << endl;
	cout << "	TÚ mism@, que dependes de tu VOLuntad" << endl; sleep(2);
	cout << endl << "Si alguna de tus características llega a 0, habrás PERDIDO" << endl;
	cout << "Si llegas a la facultad, habrás GANADO" << endl;
	cout << "¡Así que gestiona tus características con cuidado!" << endl << endl << endl;
	cualquier_tecla();
	cout << "Tus características tienen una puntación base de 5, y se modifican según tu CLASE" << endl << sleep(1);
	cout << "Ahora escoge tu CLASE:" << endl; sleep(1);
	cout << "	DIBujante:" << endl <<"+2 INM El virus resbala sobre la pátina permanente de carboncillo en tus manos" << endl;
	cout << "-2 VOL Cualquiera con lápiz y libreta puede dibujar... ¿Qué tienes tú de especial? Estás llen@ de dudas" << endl; sleep(1);
	cout << "	PINtor/a:" << endl << "+2 RES A base de palos, has desarrolado la capacidad de ir por ahí con tres 50 Figura, 47 pinceles y 28 botes de pintura" << endl;
	cout << "-2 INM Tanto respirar disolvente te ha dejado los pulmones para el arrastre" << endl; sleep(1);
	cout << "	ESCultor/a:" << endl << "+2 VOL No le diste suficiente disgusto a tu madre cuando le dijiste que querías hacer Bellas Artes, así que decidiste meterte a escultura. Una voluntad férrea sin duda" << endl;
	cout << "-2 RES Estás en estado de fatiga permanente de arrastar 20kg de barro" << endl; sleep(1);
	cout << "¿Qué clase escoges? (DIB/PIN/ESC)" << endl;
}

void intro3() {
	cout << "Aquí tienes una lista de los comandos disponibles:" << endl;
	cout << "N - ir al norte" << endl;
	cout << "S - ir al sur" << endl;
	cout << "E - ir al este" << endl;
	cout << "O - ir al oeste" << endl; 
	cout << "PASAR - ve al siguiente nivel" << endl; 
	//cout << "INVENT - muestra el inventario" << endl; 
	cout << "HELP - muestra esta lista" << endl; 
	cout << "QUIT - termina el juego" << endl;
}

void intro4() {
	cout << "Tu aventura está a punto de empezar..." << endl;
	sleep(3);
	limpiar_pantalla();
}

void narrar_nivel(Jugador& j, int nivel) {
	limpiar_pantalla();
	if(nivel == 1) {
		cout << "Estás en CASA" << endl; sleep(2);
		cout << "Hoy tienes clase de " << j.dev_clase() << ". Ve al sur para salir" << endl;
	}
	if(nivel == 2) {
		cout << "Has salido a la CALLE" << endl; sleep(2);
		cout << "La CALLE es una matriz de 4x4. Encuentra el paso al siguiente nivel para llegar al METRO" << endl; sleep(2);
		cout << "¡Cuidado! Hay 3 casillas con VIRUS y 2 con POLICÍA. Si caes en ellas, tendrás problemas" << endl;
	}
}
