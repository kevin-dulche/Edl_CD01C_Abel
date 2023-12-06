#include <iostream>
#include <string>

#include "lista_ligada_c.h"

using namespace std;


/*
 Cuenta y devuelve el número de elementos que hay en lista ligada circular l.
 */
int contarElementos(ListaLigadaC &l) {
    int numElems = 0;
    // implementar
    NodoC* temp = l.cursor;

    if (temp != NULL){
        do{
            numElems++;
            temp = temp->siguiente;
        } while (temp != l.cursor);
    }
    
    return numElems;
}


/*
 Determina si las listas ligadas circulares l y m son la misma lista de elementos. Si son la misma lista, devuelve true, false en caso contrario.
 */
bool sonIguales(ListaLigadaC &l, ListaLigadaC &m) {
    bool iguales = true;
    // implementar
    NodoC* tempL = l.cursor;
    NodoC* tempM = m.cursor;

    if (tempL != NULL && tempM != NULL) {
        do {
            if (tempL->elem != tempM->elem) {
                iguales = false;
                break;
            }
            tempL = tempL->siguiente;
            tempM = tempM->siguiente;
        } while (tempL != l.cursor && tempM != m.cursor);

        if ((tempL == l.cursor && tempM != m.cursor) || (tempL != l.cursor && tempM == m.cursor)) {
            iguales = false;
        }
    } else {
        iguales = false;
    }

    return iguales;
}


/*
 Agrega a l los elementos de m.
 */
void agregar(ListaLigadaC &l, ListaLigadaC &m) {
    // implementar
    if (l.cursor != NULL && m.cursor != NULL) {
        NodoC* temp = m.cursor;
        do {
            l.insertar(temp->elem);
            temp = temp->siguiente;
        } while (temp != m.cursor);
    }
}


/*
 Divide a la lista circular l, la cual tiene un número par de elementos, en dos listas ligadas circulares de la mitad del tamaño y las devuelve en las listas m1 y m2.
 */
void dividir(ListaLigadaC &l, ListaLigadaC &m1, ListaLigadaC &m2) {
    // implementar
    if (l.cursor != NULL) {
        int totalElementos = contarElementos(l);
        int mitad = totalElementos / 2;
        NodoC* temp = l.cursor;
        for (int i = 0; i < totalElementos; ++i) {
            temp = temp->siguiente;
            if (i < mitad){
                m1.insertar(temp->elem);
            }
            if (i >= mitad){
                m2.insertar(temp->elem);
            }
        }
    }
}


/* NO MODIFICAR */
int main() {
    ListaLigadaC l1;
    cout << "Lista: " << l1 << endl;
    l1.insertar("Another one bites the dust");
    cout << "Lista: " << l1 << endl;
    l1.insertar("Sweet child o-mine");
    cout << "Lista: " << l1 << endl;
    l1.insertar("Roadhouse blues");
    cout << "Lista: " << l1 << endl;
    l1.insertar("She's a rainbow");
    cout << "Lista: " << l1 << endl << endl;

    // Ejercicio 2a
    cout << "Hay " << contarElementos(l1) << " canciones" << endl << endl;

    ListaLigadaC l2;
    cout << "Lista: " << l2 << endl;
    l2.insertar("Roadhouse blues");
    cout << "Lista: " << l2 << endl;
    l2.insertar("She's a rainbow");
    cout << "Lista: " << l2 << endl;
    l2.insertar("Another one bites the dust");
    cout << "Lista: " << l2 << endl;
    l2.insertar("Sweet child o'mine");
    cout << "Lista: " << l2 << endl << endl;

    // Ejercicio 2b
    bool iguales = sonIguales(l1, l2);
    if (iguales)
        cout << "Las listas son iguales" << endl << endl;
    else
        cout << "Las listas no son iguales" << endl << endl;

    ListaLigadaC l3;
    cout << "Lista: " << l3 << endl;
    l3.insertar("Sunday bloody sunday");
    cout << "Lista: " << l3 << endl;
    l3.insertar("I want to hold your hand");
    cout << "Lista: " << l3 << endl;
    l3.insertar("Sultans of swing");
    cout << "Lista: " << l3 << endl;
    l3.insertar("Close to me");
    cout << "Lista: " << l3 << endl;
    l3.insertar("Personal Jesus");
    cout << "Lista: " << l3 << endl;
    l3.insertar("You really got me");
    cout << "Lista: " << l3 << endl << endl;
    
    // Ejercicio 2c
    cout << "Agregar" << endl;
    agregar(l2, l3);
    cout << "Lista: " << l2 << endl << endl;

    // Ejercicio 2d
    ListaLigadaC l4;
    ListaLigadaC l5;
    dividir(l2, l4, l5);
    cout << "Lista: " << l4 << endl;
    cout << "Lista: " << l5 << endl;
    
    exit(0);

    return 0;
}