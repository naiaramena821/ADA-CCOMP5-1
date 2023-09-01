#include <iostream>
using namespace std;
#include <cmath>

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


int  main()
{
    int op;
    float a, b;
    cout << "1. Suma " << endl;
    cout << "2. Resta " << endl;
    cout << "3. Multiplicacion " << endl;
    cout << "4. Division " << endl;
    cin >> op;
    cout << "numero 1: " << endl;
    cin >> a;
    cout << "numero 2: " << endl;
    cin >> b;
    switch (op)
    {
        case 1:
            cout << "suma: " << Addition(a, b) << endl;
            break;
        case 2:
            cout << "resta: " << Subtraction(a, b) << endl;
            break;
        case 3:
            cout << "multiplicacion: " << Multiplication(a, b) << endl;
            break;
        case 4:
            cout << "division: " << Division(a, b) << endl;
            break;
    }
}
