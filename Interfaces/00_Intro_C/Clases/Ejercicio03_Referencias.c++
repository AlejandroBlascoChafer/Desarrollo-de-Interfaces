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

/*int main (int argc, char *argv[] ) {
	
	Cuenta c1;
	c1.titular = "Juan";
	c1.numCuenta = "000";
	c1.saldo = 100;
	
	Cuenta c2;
	c2.titular = "Paco";
	c2.numCuenta = "000";
	c2.saldo = 100;

	
	
	
	mostrar(c1);
	mostrar(c2);
	//ingresar(&c);
	
	//c1.saldo=100;
	//c2.saldo=100;
	//C1.saldo debe ser 0
	//C2.saldo debe ser 200
	
	Cuenta *una, *otra;
	
	una = &c1;
	otra = &c2;
	
	transferir (una, otra);
	mostrar(c1);
	mostrar(c2);
	

	if (c.retirar(100))
		cout << "Has podido retirar 100 euros" << endl;
	
	if (c.retirar(2000))
		cout << "No has podido retirar 2000 euros" << endl;
		
	else 
		cout << "No tenías tanto dinero" << endl;
		
}*/



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

	Cuenta *total;
	total = &(unir ( c1, c2, c3 ));
	
	//total debe ser una cuenta distinta y las otras 3 se quedan a 0
	
	mostrar(c1); mostrar(c2); mostrar(c3);
	mostrar(*total);
	 





}








