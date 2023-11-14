#include <iostream>
using namespace std;

class Contador
{
    private:
        int cuenta;
    public:
        Contador();
        int getCuenta();
        void incrementarEn(int x);
};

Contador::Contador(){
    cuenta = 0;
}

int Contador::getCuenta(){
    return cuenta;
}

void Contador::incrementarEn(int x){
    cuenta += x;
}

int main(int argc, char const *argv[])
{
    Contador ctr;                       // una instancia de Contador
    cout << ctr.getCuenta() << endl;    // imprime el valor inicial (0)
    ctr.incrementarEn(3);               // incrementa en 3
    cout << ctr.getCuenta() << endl;    // imprime 3
    ctr.incrementarEn(5);               // incrementa en 5
    cout << ctr.getCuenta() << endl;    // imprime 8
    return EXIT_SUCCESS;
}