#include <iostream>

using namespace std;

class Cuenta {

private:

public:

	string titular;
	string numCuenta;
	float saldo;
	
	void ingresar(float cantidad);
	
	bool retirar (float cantidad);
	
	
};
