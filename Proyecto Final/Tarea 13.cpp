#include<iostream>
#include <stdlib.h>
#include<string>
using namespace std;

int cont;

struct alumnos {
	string nombre;
	string apellido;
	int matricula;
};

alumnos al[100];


int elec;
int op;
void otravez();
void alumno();
void cal();
void mostrar();
void buscarma();

void main() {
	locale::global(locale("spanish"));
	cont = 0;
	cout << "Hola!, estas en el menu, ¿Que es lo que deseas hacer?" << endl << endl;
	cout << "1. - Introducir datos del alumno." << endl;
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
	cin.ignore();
	cout << "Estas en el area para introducir los datos del estudiante" << endl << endl;
	cout << "Ingresa el nombre: ";
	getline(cin, al[cont].nombre); 
	cout << "Ingresa el apellido: ";
	getline(cin, al[cont].apellido);
	cout << "Ingresa la matrícula: ";
	cin >> al[cont].matricula;

	cout << "Se ha guardado un alumno" << endl << endl;

	cout << "¿Quieres registrar otro?" << endl;
	cout << "1.-Si    2.-No" << endl;
	cin >> elec;
	if (elec == 1) {
		cont++;
		alumno();
	}
	else
		if (elec == 2) {
			cout << "¿Quieres volver o quieres que te muestre lo que has guaradado?" << endl;
			cout << "1.-Volver   2.-Mostrar";
			cin >> elec;
			switch (elec) {
			case 1:
				otravez();
				break;
			case 2:
				mostrar();
				break;

			default:
				break;

			}
		}


	system("pause>nul");

}

void cal() {
	system("cls");

	cout << "Estas en el area para introducir las calificaciones" << endl;
	system("pause>nul");
	otravez();
}

void otravez() {
	system("cls");
	cout << "volviste al menú. ¿Ahora que quieres hacer?" << endl << endl;
	cout << "1. - Introducir datos del alumno" << endl;
	cout << "2.- Introducir calificaciones." << endl;
	cout << "3.- Quiero buscar un alumno" << endl;
	cin >> elec;

	switch (elec) {

	case 1:
		alumno();
		break;

	case 2:
		cal();
		break;

	case 3:
		buscarma();

	default:
		break;
	}


}

void mostrar() {
	system("cls");
	cout << "Aquí se muestran todos los alumnos y su información respectiva que se ha guardado." << endl << endl;
		for (int i = 0; i < cont + 1; i++) {
			cout << "Nombre y apellido: " << al[i].nombre << " " << al[i].apellido << endl;
			cout << "Matrícula: " << al[i].matricula << endl;
		}

		system("pause > nul");

		otravez();
}


void buscarma() {
	system("cls");
	int matri;
	cout << "Estas en el buscador" << endl << endl;
	cout << "Ingresa la matrícula de la persona que buscas: ";
	cin >> matri;
	bool encontrado = false;

	int i = 0;
	while (i < cont+1) {
		if (matri==al[i].matricula) {
			cout << "¡Lo encontré!" << endl << endl;
			cout << "Nombre y apellido: " << al[i].nombre << " " << al[i].apellido << endl;
			cout << "Matrícula: " << al[i].matricula << endl;

			encontrado = true;
			break;
		}
		i++;

	}


	if (!encontrado) {
		cout << "No existe un registro con esa matrícula." << endl;
	}

	i++;


	system("pause>nul");
	otravez();
}