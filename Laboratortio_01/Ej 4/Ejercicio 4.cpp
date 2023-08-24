// Ejercicio 4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

class CVector
{
private:
    int* m_pVect, // Pointer to the buffer
        m_nCount, // Control how many elements are actually used
        m_nMax, // Control how many are allocated as maximum
        m_nDelta; // To control the growing
    void Init(int delta); // Init our private variables, etc
    void Resize(); // Resize the vector when occurs an overflow
    
public:
    CVector(int delta = 10); // Constructor
    void Insert(int elem); // Insert a new element
    void Print();
    ~CVector();
};

CVector::CVector(int delta) {
    Init(delta);
}

CVector::~CVector() {
    delete[] m_pVect;
}

void CVector::Init(int delta){
    m_pVect = new int[delta];
    m_nCount = 0;
    m_nMax = delta;
    m_nDelta = delta;
}

void CVector::Insert(int elem)
{
    if (m_nCount == m_nMax) // Verify the overflow
        Resize(); // Resize the vector before inserting elem
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}

void CVector::Resize()
{
    const int delta = 10;                      // Used to increase the vector size
    int* pTemp = new int[m_nMax + delta];       // Allocate a new vector
    for (int i = 0; i < m_nCount; i++)          // Transfer the elements
        pTemp[i] = m_pVect[i];
    delete[] m_pVect;                           // Delete the old vector
    m_pVect = pTemp;                            // Update the pointer
    m_nMax += delta;
}

void CVector::Print() {
    for (int j = 0; j < m_nCount; j++) {
        cout << m_pVect[j] << " ";
    }
}

int main()
{
    CVector vector;

    for (int i = 0; i < 25; i++) {
        vector.Insert(i);
    }

    vector.Print();
    
}

