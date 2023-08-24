// Ejercicio 3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstdlib>

using namespace std;

struct Vector
{
    int* m_pVect; // Pointer to the buffer
    int m_nCount; // Control how many elements are actually used
    int m_nMax;   // Control how many are allocated as maximum
    int m_nDelta; // To control the growing
};

void Insert(Vector* pThis, int elem);
void Resize(Vector* pThis);

void Insert(Vector* pThis, int elem)
{
    if (pThis->m_nCount == pThis->m_nMax) // Verify the overflow
        Resize(pThis); // Resize the vector before inserting elem
    // Insert the element at the end of the sequence
    pThis->m_pVect[pThis->m_nCount++] = elem;
}

void Resize(Vector* pThis)
{
    pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));

    // The Max has to be increased by delta
    pThis->m_nMax += pThis->m_nDelta;
}

int main()
{
    Vector myVector;
    myVector.m_nCount = 0;
    myVector.m_nMax = 19;
    myVector.m_nDelta = 10;
    myVector.m_pVect = (int*)malloc(sizeof(int) * myVector.m_nMax);

    for (int i = 0; i < myVector.m_nMax; i++)
    {
        Insert(&myVector, i);
        cout << myVector.m_pVect[i] << " ";
    }

    free(myVector.m_pVect); // Deallocate the memory

    return 0;
}

