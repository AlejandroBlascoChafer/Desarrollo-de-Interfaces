#include <iostream>

using namespace std;


void incrementar(int *p){

	*p = *p + 1;
	
}

int main (int argc, char *argv[]){


	int i=8;
	
	int *p = &i;
	cout << "i vale " << i << endl;

	*p = 100;
	cout << "i vale " << i << endl;

	int aux;	
	aux = *p;	
	cout << "aux vale " << aux << endl;
	
	incrementar(&i);
	
	cout << "i vale " << i << endl;

}
