/*Escribe una función en C++ que tome un arreglo de valores int 
y determine si hay un par de números en el arreglo cuyo producto es par.*/

#include <iostream>

bool tieneParDeProductoPar(int arreglo[], int longitud) {
    for (int i = 0; i < longitud - 1; ++i) {
        for (int j = i + 1; j < longitud; ++j) {
            int producto = arreglo[i] * arreglo[j];
            if (producto % 2 == 0) {
                // El producto es par, por lo tanto, encontramos un par de números cuyo producto es par.
                return true;
            }
        }
    }
    // No se encontró ningún par de números cuyo producto sea par.
    return false;
}

int main() {
    // Ejemplo de uso
    int arreglo[] = {1, 2, 3, 4, 5};
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]);

    if (tieneParDeProductoPar(arreglo, longitud)) {
        std::cout << "Hay un par de numeros cuyo producto es par.\n";
    } else {
        std::cout << "No hay un par de numeros cuyo producto sea par.\n";
    }

    return EXIT_SUCCESS;
}