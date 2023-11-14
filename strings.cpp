#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]){
    string s = "ser";
    string t = " no " + s;      // t = "no ser"
    string u = s + " o" + t;    // u = "ser o no ser"
    if (s > t)                  // verdadero: "ser" > "no ser"
        cout << u << endl;      // salida: "ser o no ser"

    s = "Juan";                 // s = "Juan"
    int i = s.size();           // i = 4
    char c = s[3];              // c = 'n'
    s += " Arce";               // ahora s = "Juan Arce"
    cout << s << endl;
    
    return EXIT_SUCCESS;
}