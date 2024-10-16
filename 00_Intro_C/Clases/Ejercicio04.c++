#include <iostream>

using namespace std;
class Cuenta {

private:

public:
	string titular;
	string numCuenta;
	float saldo;

	/*void ingresar (float cantidad) {
		
	}*/
	
	bool retirar (float cantidad) {
		if (cantidad > saldo) return false;
		saldo -= cantidad;	
	}
	
	
	
};



void mostrar (Cuenta c) {
	cout << "La cuenta de " << c.titular << " con numero " << c.numCuenta <<
	" tiene " << c.saldo << " euros" << endl;

}

void ingresar(Cuenta *c){

	float cantidad;
	cout << "Introduce la cantidad: ";
	cin >> cantidad;
	
	(*c).saldo += cantidad;
	
}

void transferir (Cuenta *c1, Cuenta *c2){

	(*c2).saldo += (*c1).saldo;
	(*c1).saldo = 0;
}

void operator<< (Cuenta &c1, Cuenta &c2){
	c1.saldo += c2.saldo;
	c2.saldo = 0;
} 

int main (int argc, char *argv[] ) {
	
	Cuenta c1;
	c1.titular = "Juan";
	c1.numCuenta = "100";
	c1.saldo = 1000;
	
	Cuenta c2;
	c2.titular = "Paco";
	c2.numCuenta = "200";
	c2.saldo = 2000;
	
	mostrar(c1);
	mostrar(c2);
	
	cout << endl;
	
	c1 << c2;
	
	
	mostrar(c1);
	mostrar(c2);
	

}


