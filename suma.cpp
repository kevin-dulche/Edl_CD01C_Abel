#include <iostream>
using namespace std;

// ESte programa recibe dos numeros x y y, y regresa su suma
int main(int argc, char const *argv[]){
    int x, y , suma;

    cout << "Por favor ingresa dos numeros: ";
    cin >> x >> y;
    suma = x + y;
    cout << "Su suma es " << suma << endl;
    return EXIT_SUCCESS;
}