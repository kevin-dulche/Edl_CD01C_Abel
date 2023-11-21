/*Escribe un programa C++ que tenga una interfaz 
Poligono que tiene los métodos abstractos área() 
y perímetro(). Implementa clases para Triángulo, 
Cuadrilátero, Pentágono, Hexágono y Octágono, 
que implementen esta interfaz, con los significados 
obvios para los métodos área() y perímetro(). 
Implementa también las clases, TriánguloIsósceles, 
TriánguloEquilátero, Rectángulo y Cuadrado, que 
tienen las relaciones de herencia apropiadas. 
Finalmente, escribe una interfaz de usuario simple 
que permita a los usuarios crear polígonos de varios 
tipos, ingresar sus dimensiones geométricas y luego 
generar su área y perímetro.
*/

#include <iostream>
#include <cmath>
using namespace std;

// Interfaz Poligono
class Poligono {
    public:
        virtual double area() const = 0;
        virtual double perimetro() const = 0;
};

class Triangulo : public Poligono {
    protected:
        double lado1, lado2, lado3, altura;

    public:
        Triangulo(double l1, double l2, double l3) : lado1(l1), lado2(l2), lado3(l3){}

        double area() const override {
            return (lado1 * altura)/2;
        }

        double perimetro() const override {
            return lado1 + lado2 +lado3;
        }
};

// Clase para TriánguloIsósceles (hereda de Triangulo)
class TrianguloIsosceles : public Triangulo {
    public:
        TrianguloIsosceles(double base, double lado) : Triangulo(base, lado, lado){
            altura = sqrt((lado*lado) - ((base/2)*(base/2)));
        }

};

// Clase para TriánguloEquilatero (hereda de Triangulo)
class TrianguloEquilatero : public Triangulo {
    public:
        TrianguloEquilatero(double lado) : Triangulo(lado, lado, lado){
            altura = sqrt((lado*lado) - ((lado/2)*(lado/2)));
        }
    
        double area() const override {
            return (lado1 * altura)/2;
        }

        double perimetro() const override {
            return lado1 + lado2 + lado3;
        }
};

// Clase base para Cuadrilátero
// class Cuadrilatero : public Poligono {
//     protected:
//         double lado1, lado2, lado3, lado4;

//     public:
//         Cuadrilatero(double l1, double l2, double l3, double l4) : lado1(l1), lado2(l2), lado3(l3), lado4(l4) {}
// };

int main(int argc, char const *argv[]){
    TrianguloIsosceles T1(12,10);
    double area = T1.area();
    double perimetro = T1.perimetro();

    cout << "El area de un triangulo con base 12 y lados de 10 es: " << area << " y el perimetro es: " << perimetro << endl;

    TrianguloEquilatero TE1(2);
    area = TE1.area();
    perimetro = TE1.perimetro();

    cout << "El area de un triangulo con lados de 2 es: " << area << " y el perimetro es: " << perimetro << endl;
    return EXIT_SUCCESS;
}