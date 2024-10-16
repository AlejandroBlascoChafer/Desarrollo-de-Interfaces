#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Cuenta {

private:

public:
	string titular;
	string numCuenta;
	float saldo;

	Cuenta (string n_titular, string n_numCuenta, float n_saldo): 
		titular(n_titular), numCuenta(n_numCuenta), saldo(n_saldo){
	
	}
	
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




void inicializarCuentas ( vector<Cuenta> *datos ){

	string nombres[5] = {"Juan", "Perico", "Andres", "Fulano", "Vengano"};
	
	int i = 0;
	while (i < 5 ) {
		Cuenta nueva("","",0);
		stringstream ss;
		ss << 100 + i;
		string numCuenta = ss.str();
		nueva.titular = nombres[i];
		nueva.numCuenta = numCuenta;
		nueva.saldo = 100*i;
		i++;
		datos->push_back(nueva);
	}

}

void mostrarCuentas ( vector<Cuenta> cuentas ){
	for ( int i=0; i < cuentas.size(); i++ )
		cout << cuentas[i].numCuenta << "\t";
	cout << endl;
	for ( int i=0; i < cuentas.size(); i++ )
		cout << cuentas[i].titular << "\t";
	cout << endl;
	for ( int i=0; i < cuentas.size(); i++ )
		cout << cuentas[i].saldo << "\t";
	cout << endl;
		
}


bool retirar (Cuenta &c){
	float cantidad;
	cout << "Introduce cantidad a retirar: ";
	cin >> cantidad;
	
	if (cantidad < c.saldo) {
		c.saldo -= cantidad;
		return true;
	}
	return false;








}



int main (int argc, char *argv[] ) {
	
	
	vector<Cuenta> cuentas;
	
	Cuenta c("100", "Juan", 0);
	cuentas.push_back(c);
	
	
	//inicializarCuentas( &cuentas );
}
























