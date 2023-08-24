// Ejercicio 2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

int* gpVect = NULL; // Dynamic buffer to save the elements
int gnCount = 0;    // Counter to know the number of used elements
int gnMax = 9;      // Variable containing the size of the allocated memory

void Resize()
{
    const int delta = 10;                      // Used to increase the vector size
    int* pTemp = new int[gnMax + delta];       // Allocate a new vector
    for (int i = 0; i < gnCount; i++)          // Transfer the elements
        pTemp[i] = gpVect[i];
    delete[] gpVect;                           // Delete the old vector
    gpVect = pTemp;                            // Update the pointer
    gnMax += delta;                            // Update the maximum size
}

void Insert(int elem)
{
    if (gnCount == gnMax)                      // There is no space at this moment for elem
        Resize();                               // Resize the vector before inserting elem
    gpVect[gnCount] = elem;                     // Insert the element at the end of the sequence
    gnCount++;                                  // Increment the count after insertion
}

int main()
{
    int tam = 14;
    gpVect = new int[gnMax];
    for (int i = 0; i < tam; i++) {
        Insert(i);
        cout << gpVect[i] << " ";
    }
    delete[] gpVect;

    return 0;

}
