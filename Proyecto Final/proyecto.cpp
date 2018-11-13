#include<iostream>
#include <stdlib.h>
#include<string>
#include <fstream>
using namespace std;

int cont, medida, o;

struct alumnos {
	string nombre;
	string apellido;
	int matricula;
	string n;
	string tel;
	char correo[50];
	string colonia;
	string calle;
	double cal1 = 0, cal2 = 0, cal3 = 0, calfinal;

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
	cout << "Ingresa la matricula: ";
	cin >> al[cont].matricula;
	cin.ignore();
	cout << "Ingresa su numero de contacto: ";
	getline(cin, al[cont].tel);

	medida = al[cont].tel.size();
	while (medida < 8 || medida > 12) {

		cout << "El teléfono debe tener al menos 8 digitos y ser menor a 12." << endl;
		getline(cin, al[cont].tel);
		medida = al[cont].tel.size();
	}

	cin.ignore();
	cout << "Ingresa su correo electronico: ";
	cin >> al[cont].correo;

	int countAt = 0, countDot = 0;
	for (int i = 0; al[cont].correo[i] != NULL; i++) {

		if (al[cont].correo[i] == '@') {
			countAt++;
		}
		if (al[cont].correo[i] == '.') {
			countDot++;
		}
		if (al[cont].correo[i] == 'c') {
			countDot++;
		}
		if (al[cont].correo[i] == 'o') {
			countDot++;
		}
		if (al[cont].correo[i] == 'm') {
			countDot++;
		}
	}
	if (countAt == 0) {
		cout << "No pusiste @. Por favor vuelve a ingresar el correo electronico. " << endl;
		cin >> al[cont].correo;
	}
	if (countDot < 4) {
		cout << "Falta uno de los elementos del .com. Por favor vuelve a escribir el correo electronico. " << endl;
		cin >> al[cont].correo;
	}


	cin.ignore();
	cout << "Ingresa su direccion, colonia: ";
	getline(cin, al[cont].colonia);
	cout << "Calle: ";
	getline(cin, al[cont].calle);
	cout << "Numero de casa: ";
	getline(cin, al[cont].n);
	cout << "Ingresa sus tres calificaciones, calificacion 1: ";
	cin >> al[cont].cal1;
	cout << "Calificacion 2: ";
	cin >> al[cont].cal2;
	cout << "Calificacion 3: ";
	cin >> al[cont].cal3;

	al[cont].calfinal = ((al[cont].cal1 * .30) + (al[cont].cal2 * .45) + (al[cont].cal3 * .25)) / 3;

	cout << "Se ha guardado un alumno" << endl << endl;
	cont++;
	guardar();

	cout << "¿Quieres registrar otro?" << endl;
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
	cout << "¿Que es lo que desea hacer?" << endl << endl;
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
	cout << "Aqui se muestran todos los alumnos y su información respectiva que se ha guardado." << endl << endl;
	for (int i = 0; i < cont; i++) {
		cout << "Nombre y apellido: " << al[i].nombre << " " << al[i].apellido << endl;
		cout << "Matricula: " << al[i].matricula << endl;
		cout << "Correo electronico: " << al[i].correo << endl;
		cout << "Numero de contacto: " << al[i].tel << endl;
		cout << "Direccion: Colonia " << al[i].colonia << " ,Calle " << al[i].calle << " ,Numero " << al[i].n << endl;
		cout << "Calificacion: " << al[cont].calfinal << endl;
	}

	system("pause > nul");

	otravez();
}


void buscarma() {
	system("cls");
	int matri;
	cout << "Estas en el buscador" << endl << endl;
	cout << "Ingresa la matricula de la persona que buscas: ";
	cin >> matri;
	bool encontrado = false;

	int i = 0;
	while (i < cont) {
		if (matri == al[i].matricula) {
			cout << "Lo encontre" << endl << endl;
			cout << "Nombre y apellido: " << al[i].nombre << " " << al[i].apellido << endl;
			cout << "Matricula: " << al[i].matricula << endl;
			cout << "Correo electronico: " << al[i].correo << endl;
			cout << "Numero de contacto: " << al[i].tel << endl;
			cout << "Direccion: Colonia " << al[i].colonia << " ,Calle " << al[i].calle << " ,Numero " << al[i].n << endl;
			cout << "Calificacion: " << al[cont].calfinal << endl;

			encontrado = true;
			break;
		}
		i++;

	}


	if (!encontrado) {
		cout << "No existe un registro con esa matricula." << endl;
	}

	i++;


	system("pause>nul");
	otravez();
}

void modificar() {
	system("cls");
	cin.ignore();

	int op, o;
	cout << "¿Que matricula buscas para modificar? " << endl;
	cin >> op;
	int i = 0;
	while (i < cont) {
		if (al[i].matricula == op) {
			cout << "Encontre a: " << endl;
			cout << "Nombre y apellido: " << al[i].nombre << " " << al[i].apellido << endl;
			cout << "Matricula" << ": " << al[i].matricula << endl << endl;
			cout << "Correo electronico: " << al[i].correo << endl;
			cout << "Numero de contacto: " << al[i].tel << endl;
			cout << "Direccion: Colonia " << al[i].colonia << " ,Calle " << al[i].calle << " ,Numero " << al[i].n << endl;
			cout << "Calificacion: " << al[cont].calfinal << endl;

			cout << "¿Que deseas modificar?" << endl;
			cout << "1. Matrícula \n2. Nombre \n3. Apellido \n4. Correo Electronico\n5. Telefono \n6. Dirección \n7. Calificaciones \n0. Nada" << endl;
			cin >> op;
			cin.ignore();
			switch (op) {
			case 1:
				cout << "Ingresa nueva matrícula: ";
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
				cin >> al[i].correo;
				break;
			case 5:
				cout << "Ingresa el nuevo telefono: ";
				getline(cin, al[i].tel);
				break;
			case 6:
				cout << "¿Cual de los tres campos de la direccion quieres modificar? " << endl;
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
					cout << "Ingresa el nuevo numero de casa: ";
					getline(cin, al[i].n);
					break;
				default:
					break;
				}
				break;
			case 7:
				cout << "¿Cual de las tres calificaciones quiere modificar? " << endl;
				cout << "1. Calificación 1 \n2.Calificación 2 \n3.Calificación 3 ";
				cin >> o;
				switch (o) {
				case 1:
					cin.ignore();
					cout << "Ingresa la nueva Calificación 1 : ";
					cin >> al[cont].cal1;
					al[cont].calfinal = ((al[cont].cal1 * .30) + (al[cont].cal2 * .45) + (al[cont].cal3 * .25) / 3);
					break;
				case 2:
					cin.ignore();
					cout << "Ingresa la nueva Calificación 3: ";
					cin >> al[cont].cal2;
					al[cont].calfinal = ((al[cont].cal1 * .30) + (al[cont].cal2 * .45) + (al[cont].cal3 * .25) / 3);
					break;
				case 3:
					cin.ignore();
					cout << "Ingresa la nueva Calificación 3: ";
					cin >> al[cont].cal3;
					al[cont].calfinal = ((al[cont].cal1 * .30) + (al[cont].cal2 * .45) + (al[cont].cal3 * .25) / 3);
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
				cout << "Matricula" << ": " << al[i].matricula << endl << endl;
				cout << "Correo electronico: " << al[i].correo << endl;
				cout << "Numero de contacto: " << al[i].tel << endl;
				cout << "Direccion: Colonia " << al[i].colonia << " ,Calle " << al[i].calle << " ,Numero " << al[i].n << endl;
				cout << "Calificacion: " << al[cont].calfinal << endl;
			}
			else {
				cout << "No se realizó ninguna modificación." << endl;
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
	cout << "¿Qué matrícula desea encontrar? " << endl;
	cin >> matri;

	int i = 0;
	while (i < cont) {
		if (al[i].matricula == matri) {

			cout << "Se encontro a: " << endl;
			cout << "Nombre y apellido: " << al[i].nombre << " " << al[i].apellido << endl;
			cout << "Matrícula: " << al[i].matricula << endl << endl;
			cout << "Correo electronico: " << al[i].correo << endl;
			cout << "Numero de contacto: " << al[i].tel << endl;
			cout << "Direccion: Colonia " << al[i].colonia << " ,Calle " << al[i].calle << " ,Numero " << al[i].n << endl;
			cout << "Calificacion: " << al[cont].calfinal << endl;

			cout << "¿Seguro que desea eliminar a " << al[i].matricula << "?" << endl;
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
		}
		if (i == cont) {
			cout << "No se encontro a nadie con esa matrícula." << endl << endl;
		}
		i++;
	}

	system("pause > nul");
	otravez();

}

void guardar() {
	cout << "¿Deseas guardar?" << endl;
	cout << "1.- Sí \n2. No." << endl;

	cin >> o;

	if (o == 1)
	{
		// Se crea objeto de escritura
		ofstream archivo;

		// Se guarda como binario
		archivo.open("Datos de Alumnos.data", ios::binary);

		// Se escribe el arreglo entero en el archivo
		archivo.write((char*)&al, sizeof(al));

		// Al terminar se cierra el archivo
		archivo.close();
	}
}

void guardarARCH() {
	// Se crea objeto de escritura
	ofstream archivo;

	// Se guarda como binario
	archivo.open("Datos de Alumnos.csv");

	for (int i = 0; i < cont; i++) { // Itera entre todos los registrados
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

	// Al terminar se cierra (esto guarda el contenido)
	archivo.close();
}

void manual() {
	cout << "AUN NADA";
}