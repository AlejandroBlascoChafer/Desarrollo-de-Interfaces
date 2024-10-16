#include <stdio.h>
#include <iostream>
using namespace std;

int main (int argc, char *argv[] ){
	int acumulativo = 0;
	int contador = 0;
	int numero;
	bool acertado = false;
	int vector[10];
	

	do {
		cout << "Introduce un número: ";
	    
	    	cin >> numero;
	    	
	    	if (numero > 10) {
	    		acertado = true;
	    		acumulativo+=numero;
	    		cout << "Has introducido un número mayor que 10, la suma es " << acumulativo << endl;
	    	} else {
	    		acumulativo+=numero;
	    		if (acumulativo > 20) {
	    			acertado = true;
	    			cout << "La suma de los números es " << acumulativo << endl;
	    		}
	    	
	    	}
	    	if (contador < 10){
	    		vector[contador]=numero;
	    		contador++;
	    	}
	    	  	
	    	
	} while (acertado != true);
	
	cout << "Números: ";
	for (int i=contador-1; i >= 0; i--){
		cout << vector[i] << " "; 	
	}
	cout << endl;
}
