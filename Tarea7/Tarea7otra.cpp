#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int otravez;
int compu;
int elec;
void juego();

void main() {
	locale::global(locale("spanish"));
	cout << "Juego de piedra, papel o tijeras." << endl << endl;
	cout << "Es un juego cotidiano asi que asumire que sabes la forma de jugar. Ahora, enfrentaras al oponente mas duro de todos, ¡la computadora!" << endl;

	system("pause");
	juego();
}

void juego() {
	system("cls");
	srand(time(NULL));
	compu = rand() % 3 + 1;
	//cout << "La computadora eligio: " << compu << endl;
	cout << "Elije tu ataque: " << endl;
	cout << "1.- Piedra   2.- Papel   3.- Tijeras" << endl;
	cin >> elec;

	switch (elec) {

	case 1:

		if (compu == 1) {
			cout << "Tu rival ha elegido piedra tambien, ¡Han empatado!.";
		} 
		if (compu == 2) {
			cout << "Tu rival ha elegido papel, ¡Has perdido loser >:)";
		}
		if (compu == 3) {
			cout << "Tu rival ha elegido Tijera, ¡Has ganado! Felicidades <3";
		}

		break;


	case 2:

		if (compu == 1) {
			cout << "Tu rival ha elegido piedra, ¡Has ganado! Felicidades <3";
		}
		if (compu == 2) {
			cout << "Tu rival ha elegido papel tambien, ¡Han empatado!.";
		}
		if (compu == 3) {
			cout << "Tu rival ha elegido Tijera, ¡Has perdido loser >:)";
		}

		break;


	case 3:

		if (compu == 1) {
			cout << "Tu rival ha elegido piedra, ¡Has perdido loser >:)";
		}
		if (compu == 2) {
			cout << "Tu rival ha elegido papel, ¡Has ganado! Felicidades <3";
		}
		if (compu == 3) {
			cout << "Tu rival ha elegido Tijera tambien, ¡Han empatado!.";
		}

		break;

	default:
		break;



	}  

	system("pause");
	cout << "¿Quieres jugar otra vez?" << endl;
	cout << "1.-Si    2.-No" << endl;
		cin >> otravez;
		if (otravez == 1) {
			juego();
		}

		else
			system("pause");
}