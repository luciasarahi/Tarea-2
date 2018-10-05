#include<iostream>
#include <stdlib.h>
#include<string>
using namespace std;

int cont;

struct alumnos {
	string nombre;
	string apellido;
	int matricula;
	string n;
	string tel;
	string correo;
	string colonia;
	string calle;
	double cal1, cal2, cal3, calfinal;
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
	cout << "¡Hola!, bienvenido al menú principal";
	system("pause>null");
	otravez();
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
	cout << "Ingresa su número de contacto: ";
	cin >> al[cont].tel;
	cout << "Ingresa su correo electronico: ";
	cin >> al[cont].correo;
	cout << "Ingresa su dirección, colonia: ";
	cin >> al[cont].colonia;
	cout << "Calle: ";
	cin >> al[cont].calle;
	cout << "Número de casa: ";
	cin >> al[cont].n;
	cout << "Ingresa sus tres calificaciones, calificacion 1: ";
	cin >> al[cont].cal1;
	cout << "Calificación 2: ";
	cin >> al[cont].cal2;
	cout << "Calificación 3: ";
	cin >> al[cont].cal3;

	al[cont].calfinal = (al[cont].cal1 * 30) + (al[cont].cal2 * 45) + (al[cont].cal3 * 25);

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
	cout << "¿Que quieres hacer?" << endl << endl;
	cout << "1.- Introducir datos del alumno" << endl;
	cout << "2.- Introducir calificaciones." << endl;
	cout << "3.- Quiero buscar un alumno" << endl;
	cout << "4.- Quiero modificar a un alumno" << endl;
	cout << "5.- Quiero eliminar a un alumno" << endl;
	cout << "6.- Quiero que muestres los registros." << endl;
	cout << "7.- Quiero salir." << endl;
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
		break;

	case 4:
		modificar();
		break;

	case 5:
		eliminar();
		break;

	case 6:
		mostrar();
		break;

	case 7:
		cout << "Adios";
		system("pause>nul");
		break;

	default:
		cout << "La opcion que has elegido no es valida, vuelve a intentarlo" << endl;
		system("pause>nul");
		otravez();
		break;
	}


}

void mostrar() {
	system("cls");
	cout << "Aquí se muestran todos los alumnos y su información respectiva que se ha guardado." << endl << endl;
	for (int i = 0; i < cont + 1; i++) {
		cout << "Nombre y apellido: " << al[i].nombre << " " << al[i].apellido << endl;
		cout << "Matrícula: " << al[i].matricula << endl;
		cout << "Correo electronico: " << al[i].correo << endl;
		cout << "Numero de contacto: " << al[i].tel << endl;
		cout << "Dirección: Colonia " << al[i].colonia << " ,Calle " << al[i].calle << " ,Numero " << al[i].n << endl;
		cout << "Calificación: " << al[cont].calfinal << endl;
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
			cout << "Correo electronico: " << al[i].correo << endl;
			cout << "Numero de contacto: " << al[i].tel << endl;
			cout << "Dirección: Colonia " << al[i].colonia << " ,Calle " << al[i].calle << " ,Numero " << al[i].n << endl;
			cout << "Calificación: " << al[cont].calfinal << endl;

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
			cout << "Correo electronico: " << al[i].correo << endl;
			cout << "Numero de contacto: " << al[i].tel << endl;
			cout << "Dirección: Colonia " << al[i].colonia << " ,Calle " << al[i].calle << " ,Numero " << al[i].n << endl;
			cout << "Calificación: " << al[cont].calfinal << endl;

			cout << "¿Qué deseas modificar?" << endl;
			cout << "1. Matrícula \n2. Nombre \n3. Apellido \n4. Correo Electronico\n5. Telefono \n6. Colonia \n7. Calle\n8. Numero de casa \n0. Nada" << endl;
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
			case 4:
				cout << "Ingresa el nuevo correo: ";
				getline(cin, al[i].correo);
				break;
			case 5:
				cout << "Ingresa el nuevo telefono: ";
				getline(cin, al[i].tel);
				break;
			case 6:
				cout << "Ingresa la nueva colonia: ";
				getline(cin, al[i].colonia);
				break;
			case 7:
				cout << "Ingresa la nueva calle: ";
				getline(cin, al[i].calle);
				break;
			case 8:
				cout << "Ingresa el nuevo numero de casa: ";
				getline(cin, al[i].n);
				break;

			default:
				break;
			}

			if (op != 0) {
				cout << "Registro modificado: " << endl;
				cout << "Nombre y apellido: " << al[i].nombre << " " << al[i].apellido << endl;
				cout << "Matricula" << ": " << al[i].matricula << endl << endl;
				cout << "Correo electronico: " << al[i].correo << endl;
				cout << "Numero de contacto: " << al[i].tel << endl;
				cout << "Dirección: Colonia " << al[i].colonia << " ,Calle " << al[i].calle << " ,Numero " << al[i].n << endl;
				cout << "Calificación: " << al[cont].calfinal << endl;
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
			cout << "Correo electronico: " << al[i].correo << endl;
			cout << "Numero de contacto: " << al[i].tel << endl;
			cout << "Dirección: Colonia " << al[i].colonia << " ,Calle " << al[i].calle << " ,Numero " << al[i].n << endl;
			cout << "Calificación: " << al[cont].calfinal << endl;

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