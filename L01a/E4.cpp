/*Escribe una función eficiente en C++ que 
tome cualquier valor entero i y devuelva 2^i, 
como un valor long. Tu función no debe multiplicar 
2 por sí mismo i veces. Hay formas mucho más rápidas de calcular 2^i.*/

#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[]){
    int n;
    cout << "Dame un numero para hacer la potencia de 2: ";
    cin >> n;
    int res = pow(2, n);
    cout << "2 elevado a la " << n << " es " << res << endl;
    return EXIT_SUCCESS;
}