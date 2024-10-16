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

int main (int argc, char *argv[] ) {
	
	Cuenta c1;
	c1.titular = "Juan";
	c1.numCuenta = "100";
	c1.saldo = 1000;
	
	Cuenta c2;
	c2.titular = "Paco";
	c2.numCuenta = "200";
	c2.saldo = 1000;

	
	
	
	//mostrar(c1);
	//mostrar(c2);
	//ingresar(&c);
	
	//c1.saldo=100;
	//c2.saldo=100;
	//C1.saldo debe ser 0
	//C2.saldo debe ser 200
	
	//Cuenta *una, *otra;
	
	//una = &c1;
	//otra = &c2;
	
	//transferir (una, otra);
	//mostrar(c1);
	//mostrar(c2);
	

	/*if (c.retirar(100))
		cout << "Has podido retirar 100 euros" << endl;
	
	if (c.retirar(2000))
		cout << "No has podido retirar 2000 euros" << endl;
		
	else 
		cout << "No tenías tanto dinero" << endl;*/
		
	

}


