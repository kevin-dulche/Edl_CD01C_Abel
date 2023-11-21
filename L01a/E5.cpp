/*
El máximo común divisor, o MCD, de dos enteros 
positivos n y m es el número más grande j, de modo 
que n y m son ambos múltiplos de j. 
Euclides propuso un algoritmo simple para calcular 
MCD(n, m), donde n > m, que se basa en un concepto 
conocido como el teorema chino del resto. La idea 
principal del algoritmo es realizar repetidamente 
cálculos de módulo de pares consecutivos de la secuencia 
que comienza (n, m, ...), hasta llegar a cero. 
El último número distinto de cero en esta secuencia 
es el MCD de n y m.  
Por ejemplo, para n = 80,844 y m = 25,320, 
la secuencia es la siguiente:

80,844 mod 25,320 = 4,884
25,320 mod 4,884 = 900
4,884 mod 900 = 384
900 mod 384 = 132
384 mod 132 = 120
132 mod 120 = 12
120 mod 12 = 0

Entonces, el MCD de 80,844 y 25,320 es 12. 
Escribe una función en C++ para calcular MCD(n, m) 
para dos enteros n y m.*/

#include <iostream>
using namespace std;

int n1, n2;

void MCD(int mayor, int menor){
    int aux = mayor % menor;
    cout << mayor << " mod " << menor << " = " << aux << endl;
    if (aux != 0){
        MCD(menor, aux);
    } else {
        cout << "El MCD de " << n1 << " y " << n2 << " es: " << menor << endl;
    }
    
}

int main(int argc, char const *argv[]){
    cout << "Programa para obtener el MCD de dos numeros" << endl;
    cout << "Ingresa el numero 1: ";
    cin >> n1;
    cout << "Ingresa el numero 2: ";
    cin >> n2;
    if (n1 > n2){
        MCD(n1, n2);
    } else {
        MCD(n2, n1);
    }
    return EXIT_SUCCESS;
}