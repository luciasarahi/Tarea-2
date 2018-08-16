#include <iostream>
using namespace std;

int main() {


	cout << "Nombre: " << endl;
	char nombre[20];
	cin >> nombre;

	cout << "Apellido: " << endl;
	char apellido[20];
	cin >> apellido;

	cout << "Edad: " << endl;
	int edad;
	cin >> edad;

	cout << "Telefono: " << endl;
	char tel[20];
	cin >> tel;


	cout << endl;
	cout << "Nombre: " << apellido << ", " << nombre << "." << endl;
	cout << endl;
	cout << "Edad: " << edad << " anios." << endl;
	cout << "Telefono: +52" << tel << endl;



	system("pause");


	return 0;
}