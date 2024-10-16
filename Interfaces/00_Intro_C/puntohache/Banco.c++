#include <iostream>
#include "cuenta.h"

using namespace std;


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



Cuenta &unir (Cuenta &c1, Cuenta &c2, Cuenta &c3) {

	float saldoTotal = c1.saldo + c2.saldo + c3.saldo;
	
	c1.saldo = 0;
	c2.saldo = 0;
	c3.saldo = 0;
	
	Cuenta *cuentaResultado;
	cuentaResultado = new Cuenta;
	cuentaResultado -> saldo = saldoTotal;
	
	return *cuentaResultado;
	


}




int main (int argc, char *argv[]){

	Cuenta c1;  c1.saldo = 100;
	Cuenta c2;  c2.saldo = 200;
	Cuenta c3;  c3.saldo = 300;
	c2.ingresar(1000);

	Cuenta *total;
	total = &(unir ( c1, c2, c3 ));
	
	//total debe ser una cuenta distinta y las otras 3 se quedan a 0
	
	mostrar(c1); mostrar(c2); mostrar(c3);
	mostrar(*total);
	 





}








