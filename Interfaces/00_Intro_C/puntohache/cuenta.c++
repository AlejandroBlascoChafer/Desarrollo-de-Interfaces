#include <iostream>
#include "cuenta.h"

using namespace std;
	
void Cuenta::ingresar(float cantidad){
	saldo+=cantidad;
}

bool Cuenta::retirar (float cantidad) {
	if (cantidad > saldo) return false;
	saldo -= cantidad;
	return true;
}
	
	

