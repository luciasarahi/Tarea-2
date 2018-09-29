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
void modificar();
void eliminar();

void main() {
	locale::global(locale("spanish"));
	cont = 0;
	cout << "¡Hola!, estas en el menú, ¿Qué es lo que deseas hacer?" << endl << endl;
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
	cout << "1.- Introducir datos del alumno" << endl;
	cout << "2.- Introducir calificaciones." << endl;
	cout << "3.- Quiero buscar un alumno" << endl;
	cout << "4.- Quiero modificar a un alumno" << endl;
	cout << "5.- Quiero eliminar a un alumno" << endl;
	cout << "6.- Quiero que muestres los registros." << endl;
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

	case 4:
		modificar();

	case 5:
		eliminar();

	case 6:
		mostrar();

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
	while (i < cont + 1) {
		if (matri == al[i].matricula) {
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

void modificar() {
	system("cls");
	cin.ignore();

	int op;
	cout << "¿Qué matrícula buscas para modificar? " << endl;
	cin >> op;
	int i = 0;
	while (i < cont + 1) {
		if (al[i].matricula == op) {
			cout << "Encontré a: " << endl;
			cout << "Nombre y apellido: " << al[i].nombre << " " << al[i].apellido << endl;
			cout << "Matricula" << ": " << al[i].matricula << endl << endl;

			cout << "¿Qué deseas modificar?" << endl;
			cout << "1. Matrícula \n2. Nombre \n3. Apellido \n0. Nada" << endl;
			cin >> op;
			cin.ignore();
			switch (op) {
			case 1:
				cout << "Ingresa nueva mátricula: ";
				cin >> al[i].matricula;
				break;
			case 2:
				cout << "Ingresa nuevo nombre: ";
				getline(cin, al[i].nombre);
				break;
			case 3:
				cout << "Ingresa nuevo apellido: ";
				getline(cin, al[i].apellido);
				break;

			default:
				break;
			}

			if (op != 0) {
				cout << "Registro modificado: " << endl;
				cout << "Nombre y apellido: " << al[i].nombre << " " << al[i].apellido << endl;
				cout << "Matricula" << ": " << al[i].matricula << endl << endl;
			}
			else {
				cout << "No modificaste nada." << endl;
			}

			break;
		}
		i++;
	}

	system("pause > nul");
	otravez();

}

void eliminar() {
	cin.ignore();
	system("cls");
	int matri;
	int op;
	cout << "Buscador" << endl << endl;
	cout << "¿Qué matrícula buscas? " << endl;
	cin >> matri;

	int i = 0;
	while (i < cont) {
		if (al[i].matricula == matri) {
			cout << "Encontré a: " << endl;
			cout << "Nombre y apellido: " << al[i].nombre << " " << al[i].apellido << endl;
			cout << "Matrícula: " << al[i].matricula << endl << endl;

			cout << "¿Eliminar a " << al[i].matricula << "?" << endl;
			cout << "1. Sí \n2. No" << endl;
			cin >> op;

			if (op == 1 && cont != 0) {
				for (int j = i; j < cont; j++)
				{
					al[j] = al[j + 1];
				}
				cont--;
			}
			break;
		}
		if (i == cont) {
			cout << "No encontré nada" << endl;
		}
		i++;
	}

	system("pause > nul");
	otravez();

}