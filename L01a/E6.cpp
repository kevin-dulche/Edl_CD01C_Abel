/*
Un castigo común para los niños de primaria es 
escribir la misma oración varias veces. Escribe 
un programa en C++ que muestre la siguiente oración 
cien veces: "Siempre usaré un diseño orientado a objetos". 
Tu programa debe numerar cada una de las oraciones y, 
"accidentalmente", debe cometer ocho errores ortográficos 
diferentes de forma aleatoria en varios puntos de la lista, 
para que parezca que un humano lo ha escrito todo a mano.*/

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int generarNumeroAleatorio(int n) {
    return rand() % n; // Genera un número aleatorio entre 0 y 99
}

void imprimeError(char oracion[], int tamOracion, int posicionError){
    char oracionDestino[tamOracion];
    strcpy(oracionDestino, oracion);
    char caracteresErroneos[] = {"!)@#$%^&*(+-=_`~<,.>/?|\\{}[];:'\""};
    int tamCaracteresErroneos = sizeof(caracteresErroneos);
    int elementoCaracterErroneo = generarNumeroAleatorio(tamCaracteresErroneos);
    char caracterErroneo = caracteresErroneos[elementoCaracterErroneo];
    int posicionOracionError = generarNumeroAleatorio(tamOracion);
    oracionDestino[posicionOracionError] = caracterErroneo;
    cout << posicionError+1 << ".- " << oracionDestino << endl;
}

int main(int argc, char const *argv[]){
    //Declaracion de variables a usar durante el programa
    int errores = 8, tamOracion, numero;
    bool valor;
    char oracion[] = {"Siempre usare un disenio orientado a objetos"};
    int posErrores[8];
    tamOracion = sizeof(oracion);

    // Generar aleatoriamente las posiciones de errores
    for (int i = 0; i < 8; i++){
        posErrores[i] = generarNumeroAleatorio(100);
    }

    // Imprimir y verificar los errores
    for (int i = 0; i < 100; i++){
        valor = false;
        for (int j = 0; j < 8; j++){
            if (i == posErrores[j]){
                valor = true;
                numero = posErrores[j];
            }
        }
        if (valor){
            imprimeError(oracion, tamOracion, numero);
        } else {
            cout << i+1 << ".- " << oracion << endl;
        }
    }
    
    return EXIT_SUCCESS;
}