#include <stdio.h>
#include <iostream>
using namespace std;

int main (int argc, char *argv[] ) {

    int anyoNacimiento;
    
    int anyoActual = 2024;
    
    cout << "Introduce tu año de nacimiento: ";
    
    cin >> anyoNacimiento;
    
    //printf("Hola Mundo. Tienes %d anyos \n", ( anyoActual - anyoNacimiento ) );
    
    cout << "Tienes " << ( anyoActual - anyoNacimiento ) << " anyos" << endl;
    
    if (( anyoActual - anyoNacimiento ) >= 18){
    
        cout << "Eres mayor de edad" << endl;
        
    } else {
    
        cout << "Eres menor de edad" << endl;
        
    }
}
