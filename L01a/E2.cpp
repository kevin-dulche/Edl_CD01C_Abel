/*Escribe una función en C++ que tome un arreglo que contiene 
el conjunto de todos los enteros en el rango de 1 a 52 y los revuelva 
en orden aleatorio. Usa la función rand incorporada en C++, que devuelve un 
entero pseudoaleatorio cada vez que se llama. Tu función debería generar cada 
orden posible con la misma probabilidad.*/

#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>
using namespace std;

void barajarArreglo(int arreglo[], int longitud) {
    // Semilla para la generación de números pseudoaleatorios
    srand(time(0));

    // Barajar el arreglo usando la función std::shuffle
    shuffle(arreglo, arreglo + longitud, default_random_engine(rand()));
}

int main() {
    // Crear un arreglo con los enteros en el rango de 1 a 52
    const int longitud = 52;
    int arreglo[longitud];
    for (int i = 0; i < longitud; ++i) {
        arreglo[i] = i + 1;
    }

    // Barajar el arreglo
    barajarArreglo(arreglo, longitud);

    // Imprimir el arreglo barajado
    cout << "Arreglo barajado: ";
    for (int i = 0; i < longitud; ++i) {
        cout << arreglo[i] << " ";
    }

    return EXIT_SUCCESS;
}