#include <stdio.h>
#include <iostream>
using namespace std;

int main (int argc, char *argv[] ) {

    int numeroSecreto = 5;
    int numeroUsuario;
    int contador = 0;
    
    cout << "Introduce el número secreto: ";
    cin >> numeroUsuario;
    
    while ( numeroUsuario != numeroSecreto ){
         cout << "Número incorrecto, introduce el número secreto: ";
         cin >> numeroUsuario;
         contador++;
    }
    contador++;
    cout << "Has acertado el numero secreto, lo has conseguido en " << contador << " intentos." << endl;
    
    
    
}
