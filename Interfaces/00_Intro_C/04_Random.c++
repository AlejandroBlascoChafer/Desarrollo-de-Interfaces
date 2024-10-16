#include <stdlib.h>
#include <iostream>


#define TAMANYO 30


using namespace std;

int vector[TAMANYO];

int main (int argc, char *argv[] ){
	int contador = 0;
	int numeroIgual;
	
	for (int i = 0; i < TAMANYO; i++ ){
		vector[i] = random() % 100;
	}
	
	cout << "Números: ";
	for (int i = 0; i < TAMANYO; i++ ){
		cout << vector[i] << " ";
	}	
	cout << endl;
	
	/*int temp = vector[1];
	vector[1]=vector[2];
	vector[2]=temp;*/
	
	
	
	
	for (int i = 0; i < TAMANYO; i++){
		for (int j = 0; j < TAMANYO-1; j++ ){
			if ( vector[j] > vector[j+1] ){
				int temp = vector[j];
				vector[j]=vector[j+1];
				vector[j+1]=temp;
			}
		}
	}
	
	
	cout << "Números: ";
	for (int i = 0; i < TAMANYO; i++ ){
		cout << vector[i] << " ";
	}	
	cout << endl;
	
	return 0;
	
	for (int i = 0; i < TAMANYO-1; i++ ){
		for (int j = i+1; j < TAMANYO; j++){
			if ( (i != j ) && ( vector[i] == vector[j] ) ){
				cout << "El número " << vector[i] << " aparece en la posición " << i << 
				" y la posición " << j << endl;
			}
		}
	}
	

	
}
