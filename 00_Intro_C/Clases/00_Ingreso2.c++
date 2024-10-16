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

int main (int argc, char *argv[] ) {
	
	Cuenta c;
	c.titular = "Juan";
	c.numCuenta = "000";
	c.saldo = 100;

	
	
	
	mostrar(c);
	ingresar(&c);
	mostrar(c);
	

	/*if (c.retirar(100))
		cout << "Has podido retirar 100 euros" << endl;
	
	if (c.retirar(2000))
		cout << "No has podido retirar 2000 euros" << endl;
		
	else 
		cout << "No tenías tanto dinero" << endl;*/
		
	

}


