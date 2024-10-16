#include <iostream>
#include <sstream>

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
	cerr << "La cuenta de " << c.titular << " con numero " << c.numCuenta <<
	" tiene " << c.saldo << " euros" << endl;

}

void ingresar(Cuenta *c){

	float cantidad;
	cerr << "Introduce la cantidad: ";
	cin >> cantidad;
	if ( c != NULL ) 
		(*c).saldo += cantidad;
}

void transferir (Cuenta *c1, Cuenta *c2){

	(*c2).saldo += (*c1).saldo;
	(*c1).saldo = 0;
}




void inicializarCuentas ( Cuenta *datos[10] ){
	string nombres[5] = {"Juan", "Perico", "Andres", "Fulano", "Vengano"};
	
	for (int i = 0; i < 10; i++)
		datos[i] = NULL;
	
	int i = 0;
	
	while (i < 5 ) {
		datos[i] = new Cuenta() ;
		stringstream ss;
		ss << 100 + i;
		string numCuenta = ss.str();
		datos[i]->titular = nombres [i];
		datos[i]->numCuenta = numCuenta;
		datos[i]->saldo = 100*i;
		i++;
	}

}

void mostrarCuentas ( Cuenta *cuentas[] ){
	for ( int i=0; i < 10; i++ )
		if (cuentas[i] != NULL )
			cerr << cuentas[i]->numCuenta << "\t";
	cerr << endl;
	for ( int i=0; i < 10; i++ )
		if (cuentas[i] != NULL )
			cerr << cuentas[i]->titular << "\t";
	cerr << endl;
	for ( int i=0; i < 10; i++ )
		if (cuentas[i] != NULL )
			cerr << cuentas[i]->saldo << "\t";
	cerr << endl;
		
}


bool retirar (Cuenta *c){
	float cantidad;
	cerr << "Introduce cantidad a retirar: ";
	cin >> cantidad;
	
	if (cantidad < c->saldo) {
		c->saldo -= cantidad;
		return true;
	}
	return false;
}




bool cearAPartir ( Cuenta *cuentas[], int cuentaNueva, int cuentaPartir ) {
	
	if ( cuentas[cuentaNueva] == NULL ) {
		cuentas[cuentaNueva] = new Cuenta();
		cuentas[cuentaNueva] -> saldo = cuentas[cuentaPartir]-> saldo /2;
		if ( cuentas[cuentaPartir] != NULL )
			cuentas[cuentaPartir] -> saldo = cuentas[cuentaPartir] -> saldo/2;
		
	}


}



int main (int argc, char *argv[] ) {
	
	Cuenta *cuentas[10];
	
	inicializarCuentas( cuentas );
	
	mostrarCuentas(cuentas);
	
	
	ingresar (  cuentas[1] );
	
	mostrarCuentas ( cuentas );
	
	if (!retirar ( cuentas[1] ) )
		cerr << "No tienes un duro" << endl;
	
	mostrarCuentas ( cuentas );
	
	
	
	
	cearAPartir(cuentas, 5, 3);
		
}
























