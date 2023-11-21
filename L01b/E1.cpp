/*Diseña e implementa una clase Línea, la cual representa 
una línea dada por la fórmula y=ax+b. Tu clase debe almacenar 
a y b como atributos double. Escribe un método intersecta(l) 
que devuelva la coordenada x en la que esta línea se cruza con la línea l. 
Escriba un programa en C++ que cree una cantidad de objetos Linea y pruebe 
cada par para la intersección. Tu programa debe imprimir un mensaje de error 
apropiado para líneas paralelas.*/

#include <iostream>
#include <cmath>
#include <limits> // Necesario para numeric_limits
using namespace std;

class Linea {
private:
    double a;
    double b;

public:
    // Constructor que recibe los coeficientes 'a' y 'b'
    Linea(double coeficienteA, double coeficienteB) : a(coeficienteA), b(coeficienteB) {}

    // Método para obtener la coordenada x de intersección con otra línea
    double intersecta(const Linea& otraLinea) const {
        // Verificar si las líneas son paralelas
        if (abs(a - otraLinea.a) < 1e-6) {
            // Líneas paralelas, no hay intersección
            cerr << "Las líneas son paralelas. No hay intersección." << endl;
            return numeric_limits<double>::quiet_NaN(); // Devolver NaN como indicador de error
        }

        // Calcular la coordenada x de intersección
        return (otraLinea.b - b) / (a - otraLinea.a);
    }
};

int main() {
    // Crear varias instancias de la clase Linea y probar intersecciones
    Linea linea1(2.0, 1.0); // Ejemplo: y = 2x + 1
    Linea linea2(-1.0, 5.0); // Ejemplo: y = -1x + 5

    // Calcular la coordenada x de intersección
    double interseccionX = linea1.intersecta(linea2);

    if (!isnan(interseccionX)) {
        cout << "Las lineas se cruzan en x = " << interseccionX << endl;
    }

    return 0;
}