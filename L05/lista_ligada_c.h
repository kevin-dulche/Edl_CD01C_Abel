#include <string>

#include "nodo_c.h"

class ListaLigadaC {
public:
    ListaLigadaC();
    ~ListaLigadaC();
    void insertar(const Elem e);
    void eliminar();
    void avanzar();
    Elem cola() const;
    Elem frente() const;
    bool esVacia() const;
    NodoC* cursor;

private:
    friend std::ostream& operator<<(std::ostream &, const ListaLigadaC &);
};



ListaLigadaC::ListaLigadaC()
    : cursor(NULL) { }



/*
 Libera la memoria ocupada por todos los nodos de la lista.
 */
ListaLigadaC::~ListaLigadaC() {
    // implementar
    NodoC* actual = cursor;
    while (actual->siguiente != cursor){
        NodoC* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    delete actual; // Elimina el ultimo nodo
}


void ListaLigadaC::insertar(const Elem e) {
    // implementar
    NodoC* NodoN = new NodoC;
    NodoN->elem = e;
    NodoN->siguiente = NULL;

    if (cursor == NULL){
        cursor = NodoN;
        cursor->siguiente = cursor;
    } else {
        NodoN->siguiente = cursor->siguiente;
        cursor->siguiente = NodoN;
    }
}

void ListaLigadaC::eliminar() {
    // implementar
    if (cursor != NULL){
        NodoC* siguiente = cursor->siguiente;
        if (siguiente != cursor){
            cursor->siguiente = siguiente->siguiente;
            delete siguiente;
        } else {
            delete cursor;
            cursor = NULL;
        }
    }
}


void ListaLigadaC::avanzar() {
    if (cursor != NULL){
        cursor = cursor->siguiente;
    }
}


Elem ListaLigadaC::cola() const {
    return cursor->elem;
}


Elem ListaLigadaC::frente() const {
    return cursor->siguiente->elem;
}


bool ListaLigadaC::esVacia() const {
    return cursor == NULL;
}


std::ostream& operator<<(std::ostream &strm, const ListaLigadaC &lista) {
    std::string elem = "";
    NodoC *aux = lista.cursor;
    
    if (aux != NULL) {
        while (aux->siguiente != lista.cursor) {
            elem += aux->siguiente->elem + ", ";
            aux = aux->siguiente;
        }
        elem += aux->siguiente->elem;
    }
    return strm << "(" << elem << "*)";
}