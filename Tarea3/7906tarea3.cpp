#include <iostream> 

using namespace std; 

int main() {
	
	locale::global(locale("spanish"));

	cout << "Programa para calcular el número de diagonales de un polígono" << endl << endl;
	int num;
	cout << "Ingresa el numero de lados del polígono: ";
	cin >> num;

	int diag;
	diag = num * (num - 3) / 2;
	cout << "El número de diagonales de tu polígono es: " << diag << endl;





	system("pause");
	return 0;

	
	

}

