#include <iostream>
using namespace std;

// Muestra el funcionamiento de los apuntadores
int main(int argc, char const *argv[]){
    char ch = 'Q';
    char *p = &ch; // p contine la direccion de ch
    cout << *p << endl; // muestra el caracter 'Q'
    ch = 'Z'; // ch ahora contiene el caracter 'Z'
    cout << *p << endl; //muestra el caracter 'Z'
    *p = 'X'; //ch ahora contiene 'X'
    cout << ch << endl; // muestra el caracter 'X'
    return EXIT_SUCCESS;
}