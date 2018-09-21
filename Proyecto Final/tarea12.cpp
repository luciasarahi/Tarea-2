#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;


/*Como tal el programa funciona, pero lo deje muy basico ya que comenze a batallar por que me salian errores y al tener tantos datos me estaba
haciendo bolas con todo, asi que elimine mucho de lo que originalmente habia hecho.
Se que no esta completo y si es posible espero y pueda haber una retroalimentacion del tema otra vez. En mi caso especifico es mas que nada como
llamar a los datos de las estructuras o mas bien como darles un dato. Segun yo habia entendido pero al intentar hacer esto sola me di cuenta
que no. Por si las dudas, soy la chica de la esquina que nunca habla (?)-Lucia Ramos*/


void regisalum();
//void calif();
void mostrar();
int elec;
int cont;

struct alumnos {
	string nombre;
	string apellido;
	int matricula;
};

alumnos estud[100];



void main() {
	system("cls");
	cont = 0;
	locale::global(locale("spanish"));
	cout << "Hola, estas aqui para registar un alumno" << endl;
	regisalum();

		system("pause>nul");

}

void regisalum() {
	system("cls");
	cout << "Estas en el registro para alumnos" << endl;
	cout << "Ingresa el nombre: ";
	cin >> estud[cont].nombre;
	//getline(cin, estud[cont].nombre); Si me permite usarlas pero despues de ingresar como la primera vez, despues este dato el nombre se salta
	                                    //Ya a partir del siguiente solo puedo ingresar apellido y matricula.
	cout << "Ingresa el apellido: ";
	cin >> estud[cont].apellido;
	//getline(cin, estud[cont].apellido);
	cout << "Ingresa la matricula: ";
	cin >> estud[cont].matricula;

		cout << "Se ha guardado un alumno"<<endl;

		cout << "¿Quieres registrar otro?"<<endl;
		cout << "1.-Si    2.-No";
			cin >> elec;
			if (elec == 1) {
				cont++;
				regisalum();
			}
			else
				if (elec == 2) {
					cout << "¿Quieres volver o quieres que te muestre lo que has guaradado?" << endl;
					cout << "1.-Volver   2.-Mostrar";
					cin >> elec;
					switch (elec) {
					case 1:
						main();
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

void mostrar() {
	system("cls");
	for (int i = 0; i < cont; i++) {
		cout << "Todos" << endl;
		for (int i = 0; i < cont+1; i++) {
			cout << "Nombre y apellido: " << estud[i].nombre << " " << estud[i].apellido << endl;
			cout << "Matricula: " << estud[i].matricula << endl;
		}

		system("pause > nul");
	}

	system("pause>nul");
}