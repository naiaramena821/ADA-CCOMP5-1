// Calculadora_puntero_a_funcion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;


float Addition(float a, float b)
{
	return a + b;
}
float Subtraction(float a, float b)
{
	return a - b;
}

float Multiplication(float a, float b)
{
	return a * b;
}

float Division(float a, float b)
{
	if (b != 0) {
		return a / b;
	}
	else {
		cout << "Error: Division by zero" << endl;
		return 0.0;
	}
}



int main()
{
	typedef float (*lpfnOperation)(float, float);
	// CVector of pointer to functions
	lpfnOperation vpf[4] = { &Addition, &Subtraction,
	&Multiplication, &Division };
	float a, b, c; 
	int opt;
	// enter the operands
	cout << "a: ";  
	cin >> a;
	cout << "b: ";  
	cin >> b;
	// enter the operation 0-Addition, 1-Subtraction, 3-Multiplication, 4-Division
	cout << "Operador: ";  
	cin >> opt;
	if (opt >= 0 && opt < 4) {
		// Perform the operation using the selected function
		c = (*vpf[opt])(a, b);
		cout << "Result: " << c << endl;
	}
	else {
		cout << "Invalid operation option" << endl;
	}
	return 0;
}
