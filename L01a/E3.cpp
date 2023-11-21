/*Escribe un programa en C++ que muestre todas las 
cadenas posibles formadas usando cada uno de los 
caracteres 'a', 'b', 'c', 'd', 'e' y 'f' exactamente una vez.*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
    char letras[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int tam_letras = sizeof(letras);
    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            for(int k = 0; k <= 5; k++){
                for(int l = 0; l <= 5; l++){
                    for(int m = 0; m <= 5; m++){
                        for(int n = 0; n <= 5; n++){
                            if(i != j && i != k && j!= k && i != l && j != l && k != l && i != m && j != m && k){
                                cout << letras[i] << letras[j] << letras[k] << letras[l] << letras[m] << letras[n] << endl;
                            }
                        }
                    }
                }
            }
        }
    }
    return EXIT_SUCCESS;
}