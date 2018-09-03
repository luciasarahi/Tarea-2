#include<iostream>
#include <stdlib.h>
using namespace std;


int elec;
int op;
void otravez();
void alumno();
void cal();

void main() {
	locale::global(locale("spanish"));
	cout << "Hola!, estas en el menu, ¿Que es lo que deseeas hacer?" << endl << endl;
	cout << "1. - Introducir datos del alumno" << endl;
	cout << "2.- Introducir calificaciones." << endl;
	cin >> elec;

	switch (elec) {

	case 1:
		alumno();
		break;

	case 2:
		cal();
		break;

	default:
		break;
	}


	system("pause>null");
}

void alumno() {
	system("cls");

	cout << "Estas en el area para introducir los datos del estudiante" << endl;
	cout << "¿Que mas quieres hacer?" << endl;
		cout << "1.- Volver al menu" << endl;
		cout << "2.- Introducir las calificaciones" << endl;
		cin >> op;

		if (op == 1) {
			otravez();
		}
		if (op == 2) {
			cal();
		}
}

void cal() {
	system("cls");

	cout << "Estas en el area para introducir las calificaciones" << endl;
	cout << "¿Que mas quieres hacer?" << endl;
	cout << "1.- Volver al menu" << endl;
	cout << "2.- Introducir datos del alumno" << endl;
	cin >> op;

	if (op == 1) {
		otravez();
	}
	if (op == 2) {
		alumno();
	}
}

void otravez() {
	system("cls");
	cout << "volviste al menu. ¿Ahoraa que quieres hacer?" << endl << endl;
	cout << "1. - Introducir datos del alumno" << endl;
	cout << "2.- Introducir calificaciones." << endl;
	cout << "3.- Deseo salir" << endl;
	cin >> elec;

	switch (elec) {

	case 1:
		alumno();
		break;

	case 2:
		cal();
		break;

	case 3:
		cout << "Adios" << endl;

	default:
		break;
	}


	system("pause>null");


}