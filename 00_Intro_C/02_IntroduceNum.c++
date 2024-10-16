#include <stdio.h>
#include <iostream>
using namespace std;

int main (int argc, char *argv[] ){
	int acumulativo = 0;
	int numero;
	bool acertado = false;

	do {
		cout << "Introduce un número: ";
	    
	    	cin >> numero;
	    	
	    	if (numero > 10) {
	    		acertado = true;
	    		cout << "Has introducido un número mayor que 10, la suma es " << acumulativo << endl;
	    	} else {
	    		acumulativo+=numero;
	    		if (acumulativo > 20) {
	    			acertado = true;
	    			cout << "La suma de los números es " << acumulativo << endl;
	    		}
	    	
	    	}	
	} while (acertado != true);
}
