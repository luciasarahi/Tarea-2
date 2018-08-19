#include <iostream>
#include <math.h>
using namespace std;

void main() {
	locale::global(locale("spanish"));

	float x;
	float y;
	float angulo;
	float radio;

	cout << "Programa que calcula las coordenadas (x,y) de un punto dados el radio y su ángulo sexadecimal" << endl<<endl;
	cout << "Proporcioname el radio: ";
		cin >> radio;
	cout << "Proporcioname el ángulo: ";
	cin >> angulo;

	x = round(radio * cos(angulo));
	y = round(radio * sin(angulo));

	cout << "Las coordenadas son: (" << x << "," << y << ")" << endl;


	system("pause");

}