#include<iostream>
#include <stdlib.h>
#include<string>
#include <fstream>
using namespace std;

int cont, medida, medidac, o;
bool bien = false;
bool bcal1 = false, bcal2 = false, bcal3 = false;

struct alumnos {
	string nombre;
	string apellido;
	int matricula;
	string n;
	string tel;
	string correo;
	string colonia;
	string calle;
	float cal1 = 0, cal2 = 0, cal3 = 0;
	float calfinal;

};
alumnos al[100];


int elec;
int op;
void otravez();
void alumno();
void guardar();
void mostrar();
void buscarma();
void modificar();
void eliminar();
void guardarARCH();
void manual();

void main() {
	locale::global(locale("spanish"));
	cont = 0;

	// Crear objeto de lectura
	ifstream archivo("Datos de Alumnos.data", ios::binary);

	// Leer el archivo
	archivo.read((char*)&al, sizeof(al));
	if (archivo.is_open()) {

		while (!archivo.eof()) {
			archivo.read((char*)&al, sizeof(al));
		}
	}
	else {
		cout << "El archivo no existe o hay problemas para abrirlo." << endl;
		system("pause>nul");
	}

	// Cerrar el archivo
	archivo.close();

	for (int i = 0; i < 100; i++)
	{
		if (al[i].matricula != 0) {
			cont++;
		}
	}

	system("cls");
	cout << "�Hola!, bienvenido al men� principal.";
	system("pause>null");
	otravez();
}

void alumno() {

	system("cls");
	cin.ignore();
	cout << "Estas en el area para introducir los datos del estudiante." << endl << endl;

	cout << "Ingresa el(los) nombre(s): ";
	getline(cin, al[cont].nombre);
	cout << "Ingresa el(los) apellido(s): ";
	getline(cin, al[cont].apellido);
	cout << "Ingresa la matr�cula: ";
	cin >> al[cont].matricula;
	cin.ignore();
	cout << "Ingresa su numero de contacto: ";
	getline(cin, al[cont].tel);

	medida = al[cont].tel.size();
	while (medida < 8 || medida > 12) {

		cout << "El tel�fono debe tener al menos 8 digitos y ser menor a 12. Ingresa de nuevo el numero de contacto: " << endl;
		getline(cin, al[cont].tel);
		medida = al[cont].tel.size();
	}

	cin.ignore();
	cout << "Ingresa su correo electronico: ";
	getline(cin, al[cont].correo);

	medidac = al[cont].correo.size();
	int countAr = 0, countCOM = 0;
	for (int i = 1; i <= medidac; i++) {

		if (al[cont].correo[i] == 64) {
			countAr = 1;
		}

		if (al[cont].correo[medidac - 4] == 46 && al[cont].correo[medidac - 3] == 99 && al[cont].correo[medidac - 2] == 111 && al[cont].correo[medidac - 1] == 109) {
			countCOM = 1;
		}
		
	}
	if (countAr == 1 && countCOM == 1) {
		bien = true;
	}


	while (bien = false) {
		cout << "Te falta alguno de los elementos: @ o .com. Por favor vuelve a introducir el correo electronico: ";
		getline(cin, al[cont].correo);
		medidac = al[cont].correo.size();
		countAr = 0;
		countCOM = 0;
		for (int i = 1; i <= medidac; i++) {

			if (al[cont].correo[i] == 64) {
				countAr = 1;
			}

			if (al[cont].correo[medidac - 4] == 46 && al[cont].correo[medidac - 3] == 99 && al[cont].correo[medidac - 2] == 111 && al[cont].correo[medidac - 1] == 109) {
				countCOM = 1;
			}

		}
		if (countAr == 1 && countCOM == 1) {
			bien = true;
		}

	}

	cin.ignore();
	cout << "Ingresa su direcci�n, colonia: ";
	getline(cin, al[cont].colonia);
	cout << "Calle: ";
	getline(cin, al[cont].calle);
	cout << "Numero de casa: ";
	getline(cin, al[cont].n);

	cout << "Ingresa sus tres calificaciones, calificaci�n 1: ";
	cin >> al[cont].cal1;

	cout << "Calificaci�n 2: ";
	cin >> al[cont].cal2;

	
	cout << "Calificaci�n 3: ";
	cin >> al[cont].cal3;


	if (al[cont].cal1 == 0 || al[cont].cal2 == 0 || al[cont].cal3 == 0) {

		al[cont].calfinal = 0;
	}

	else {

		al[cont].calfinal = (al[cont].cal1 * 30) / 100 + (al[cont].cal2 * 45) / 100 + (al[cont].cal3 * 25) / 100;
	}
	cout << "Promedio: " << al[cont].calfinal;

	cont++;
	guardar();

	cout << "�Quieres registrar otro?" << endl;
	cout << "1.-Si    2.-No" << endl;
	cin >> elec;
	if (elec == 1) {
		alumno();
	}
	else
		if (elec == 2) {
				otravez();
		}


	system("pause>nul");

}



void otravez() {
	system("cls");
	cout << "�Que es lo que desea hacer?" << endl << endl;
	cout << "1.- Introducir datos del alumno" << endl;
	cout << "2.- Quiero buscar un alumno" << endl;
	cout << "3.- Quiero modificar a un alumno" << endl;
	cout << "4.- Quiero eliminar a un alumno" << endl;
	cout << "5.- Quiero que muestres los registros." << endl;
	cout << "6.- Quiero guardar." << endl;
	cout << "7.- Quiero consultar el manual." << endl;
	cout << "8.- Quiero salir." << endl;
	cin >> elec;

	switch (elec) {

	case 1:
		alumno();
		break;

	case 2:
		buscarma();
		break;

	case 3:
		modificar();
		break;

	case 4:
		eliminar();
		break;

	case 5:
		mostrar();
		break;

	case 6:
		guardarARCH();
		break;

	case 7:
		manual();

	case 8:
		guardar();
		cout << "Adios. Que tenga un excelente dia.";
		system("pause>nul");
		break;

	default:
		cout << "La opcion que has elegido no es valida, por favor vuelve a intentarlo." << endl;
		system("pause>nul");
		otravez();
		break;
	}


}

void mostrar() {
	system("cls");
	cout << "Aqui se muestran todos los alumnos y su informaci�n respectiva que se ha guardado." << endl << endl;
	for (int i = 0; i < cont; i++) {
		cout << "Nombre y apellido: " << al[i].nombre << " " << al[i].apellido << endl;
		cout << "Matr�cula: " << al[i].matricula << endl;
		cout << "Correo electronico: " << al[i].correo << endl;
		cout << "Numero de contacto: " << al[i].tel << endl;
		cout << "Direcci�n: Colonia " << al[i].colonia << " ,Calle " << al[i].calle << " ,Numero " << al[i].n << endl;
		cout << "Calificaciones: " << al[i].cal1 << ", " << al[i].cal2 << ", " << al[i].cal3 << endl;
		cout << "Promedio: " << al[i].calfinal << endl;
	}

	system("pause > nul");

	otravez();
}


void buscarma() {
	system("cls");
	int matri;
	cout << "Estas en el buscador" << endl << endl;
	cout << "Ingresa la matr�cula de la persona que buscas: ";
	cin >> matri;
	bool encontrado = false;

	int i = 0;
	while (i < cont) {
		if (matri == al[i].matricula) {
			cout << "Lo encontr�" << endl << endl;
			cout << "Nombre y apellido: " << al[i].nombre << " " << al[i].apellido << endl;
			cout << "Matr�cula: " << al[i].matricula << endl;
			cout << "Correo electronico: " << al[i].correo << endl;
			cout << "Numero de contacto: " << al[i].tel << endl;
			cout << "Direcci�n: Colonia " << al[i].colonia << " ,Calle " << al[i].calle << " ,Numero " << al[i].n << endl;
			cout << "Calificaciones: " << al[i].cal1 << ", " << al[i].cal2 << ", " << al[i].cal3 << endl;
			cout << "Promedio: " << al[i].calfinal << endl;

			encontrado = true;
			break;
		}
		i++;

	}


	if (!encontrado) {
		cout << "No existe un registro con esa matr�cula." << endl;
	}

	i++;


	system("pause>nul");
	otravez();
}

void modificar() {
	system("cls");
	cin.ignore();

	int op, o;
	cout << "Estas en el area para realizar una modificaci�n. " << endl << endl;
	cout << "�Que matr�cula buscas? " << endl;
	cin >> op;
	int i = 0;
	while (i < cont) {
		if (al[i].matricula == op) {
			cout << "Encontre a: " << endl;
			cout << "Nombre y apellido: " << al[i].nombre << " " << al[i].apellido << endl;
			cout << "Matr�cula" << ": " << al[i].matricula << endl << endl;
			cout << "Correo electronico: " << al[i].correo << endl;
			cout << "Numero de contacto: " << al[i].tel << endl;
			cout << "Direcci�n: Colonia " << al[i].colonia << " ,Calle " << al[i].calle << " ,Numero " << al[i].n << endl;
			cout << "Calificaciones: " << al[i].cal1 << ", " << al[i].cal2 << ", " << al[i].cal3 << endl;
			cout << "Promedio: " << al[i].calfinal << endl;

			cout << "�Que deseas modificar?" << endl;
			cout << "1. Matr�cula \n2. Nombre \n3. Apellido \n4. Correo Electronico\n5. Telefono \n6. Direcci�n \n7. Calificaciones \n0. Nada" << endl;
			cin >> op;
			cin.ignore();
			switch (op) {
			case 1:
				cout << "Ingresa nueva matr�cula: ";
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
				cout << "Ingresa el nuevo correo electronico: ";
				getline(cin, al[cont].correo);
				break;
			case 5:
				cout << "Ingresa el nuevo telefono: ";
				getline(cin, al[i].tel);
				break;
			case 6:
				cout << "�Cual de los tres campos de la direcci�n quieres modificar? " << endl;
				cout << "1. Colonia \n2.Calle \n3.Numero ";
				cin >> o;
				switch (o) {
				case 1:
					cin.ignore();
					cout << "Ingresa la nueva colonia : ";
					getline(cin, al[i].colonia);
					break;
				case 2:
					cin.ignore();
					cout << "Ingresa la nueva calle: ";
					getline(cin, al[i].calle);
					break;
				case 3:
					cin.ignore();
					cout << "Ingresa el nuevo n�mero de casa: ";
					getline(cin, al[i].n);
					break;
				default:
					break;
				}
				break;
			case 7:
				cout << "�Cual de las tres calificaciones quiere modificar? " << endl;
				cout << "1. Calificaci�n 1 \n2.Calificaci�n 2 \n3.Calificaci�n 3 ";
				cin >> o;
				switch (o) {
				case 1:
					cin.ignore();
					cout << "Ingresa la nueva Calificaci�n 1 : ";
					cin >> al[i].cal1;
					al[i].calfinal = ((al[i].cal1 * .30) + (al[i].cal2 * .45) + (al[i].cal3 * .25) / 3);
					break;
				case 2:
					cin.ignore();
					cout << "Ingresa la nueva Calificaci�n 2: ";
					cin >> al[cont].cal2;
					al[i].calfinal = ((al[i].cal1 * .30) + (al[i].cal2 * .45) + (al[i].cal3 * .25) / 3);
					break;
				case 3:
					cin.ignore();
					cout << "Ingresa la nueva Calificaci�n 3: ";
					cin >> al[i].cal3;
					al[i].calfinal = ((al[i].cal1 * .30) + (al[i].cal2 * .45) + (al[i].cal3 * .25) / 3);
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}

			if (op != 0) {
				cout << "Registro modificado: " << endl;
				cout << "Nombre y apellido: " << al[i].nombre << " " << al[i].apellido << endl;
				cout << "Matr�cula" << ": " << al[i].matricula << endl << endl;
				cout << "Correo electronico: " << al[i].correo << endl;
				cout << "Numero de contacto: " << al[i].tel << endl;
				cout << "Direcci�n: Colonia " << al[i].colonia << " ,Calle " << al[i].calle << " ,N�mero " << al[i].n << endl;
				cout << "Calificaciones: " << al[i].cal1 << ", " << al[i].cal2 << ", " << al[i].cal3 << endl;
				cout << "Promedio: " << al[i].calfinal << endl;
			}
			else {
				cout << "No se realiz� ninguna modificaci�n." << endl;
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
	cout << "Se encuentra en el area para eliminar un registro." << endl << endl;
	cout << "�Qu� matr�cula desea encontrar? " << endl;
	cin >> matri;

	int i = 0;
	while (i < cont) {
		if (al[i].matricula == matri) {

			cout << "Se encontr� a: " << endl;
			cout << "Nombre y apellido: " << al[i].nombre << " " << al[i].apellido << endl;
			cout << "Matr�cula: " << al[i].matricula << endl << endl;
			cout << "Correo electronico: " << al[i].correo << endl;
			cout << "Numero de contacto: " << al[i].tel << endl;
			cout << "Direcci�n: Colonia " << al[i].colonia << " ,Calle " << al[i].calle << " ,Numero " << al[i].n << endl;
			cout << "Calificaciones: " << al[i].cal1 << ", " << al[i].cal2 << ", " << al[i].cal3 << endl;
			cout << "Promedio: " << al[i].calfinal << endl;

			cout << "�Seguro que desea eliminar a " << al[i].matricula << "?" << endl;
			cout << "1. Si \n2. No" << endl;
			cin >> op;

			if (op == 1 && cont != 0) {
				for (int j = i; j < cont; j++)
				{
					al[j] = al[j + 1];
				}
				cont--;
			}
			break;

			if (op == 2) {
				cout << "El registro sigue intacto. " << endl;
				system("pause");
				otravez();
			}
		}
		if (i == cont) {
			cout << "No se encontro a nadie con esa matr�cula." << endl << endl;
		}
		i++;
	}

	system("pause > nul");
	otravez();

}

void guardar() {
	cout << "�Deseas guardar?" << endl;
	cout << "1.- S� \n2. No." << endl;

	cin >> o;

	if (o == 1)
	{
		// Se crea objeto de escritura
		ofstream archivo;

		archivo.open("Datos de Alumnos.data", ios::binary);

		archivo.write((char*)&al, sizeof(al));

		archivo.close();
	}
}

void guardarARCH() {
	ofstream archivo;

	
	archivo.open("Datos de Alumnos.txt");

	for (int i = 0; i < cont; i++) { 
		archivo << to_string(al[i].matricula) << ",";
		archivo << al[i].nombre << ",";
		archivo << al[i].apellido << ",";
		archivo << al[i].correo << ",";
		archivo << al[i].tel << ",";
		archivo << al[i].colonia << ",";
		archivo << al[i].calle << ",";
		archivo << al[i].n << ",";
		archivo << al[i].calfinal << ",";
	}

	// Al terminar se cierra
	archivo.close();

}

void manual() {
	ifstream read;
	string line;

	read.open("readme.md");
	if (read.is_open()) {

		while (!read.eof()) {

			getline(read, line);
			cout << line << endl;
		}
	}
	else {
		cout << "Archivo inexistente o problemas para abrirlo." << endl;

	}

	system("pause>nul");

	read.close();
	otravez();
}