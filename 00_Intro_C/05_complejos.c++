#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>

using namespace std;


class Complejo {

public:
	float real;
	float imag;
	
	Complejo (float p_real,float p_imag): real(p_real), imag(p_imag) {
		/*real = p_real;
		imag = p_imag;*/
	}
	
	Complejo(){
	}
	
	string toString(){
		stringstream ss;
		if (imag >= 0)
			ss << real << " + " << imag << "i";
		else
			ss << real << " - " << -imag << "i";
		return ss.str();
	}
	
	
	Complejo operator+ (Complejo s){

		Complejo resultado;
		resultado.real=real+s.real;
		resultado.imag=imag+s.imag;
		return resultado;

	}
	
	Complejo operator+ (float s){

		Complejo resultado;
		resultado.real=real+s;
		resultado.imag = imag;
		return resultado;

	}
	
	Complejo operator- (float s){

		Complejo resultado;
		resultado.real=real-s;
		resultado.imag = imag;
		return resultado;

	}
	
	Complejo operator- (Complejo s){

		Complejo resultado;
		resultado.real=real-s.real;
		resultado.imag=imag-s.imag;
		return resultado;

	}
	
	Complejo operator- (){
		Complejo resultado;
		resultado.real = -real;
		resultado.imag = -imag;
		return resultado;
	}
	
	float modulo(){
		return sqrtf( pow(real, 2) + pow(imag, 2) );
	}
	
	bool operator> (Complejo s){
		return modulo() > s.modulo();
	}
	
	bool operator< (Complejo s){
		return modulo() < s.modulo();
	}
	
	
};






	

int main (int argc, char *argv[]) {

	Complejo c;
	c.real = 7; c.imag = -5;
	
	//cout << "El número complejo de c es ( " << c.toString() << " )" << endl;
	
	
	Complejo c2 ;
	c2.real = -6; c2.imag = 9;
	
	//omplejo suma;
	//suma = sumar(c, c2);
	
	//cout << "La suma de c y c2 es " << suma.toString() << endl;
	//cout << "La suma de c y c2 es " << sumar(c, c2).toString() << endl;
	
	
	
	//cout << "La suma de c y c2 es " << (suma = c + c2).toString() << endl;
	
	Complejo otro = c2 + 5;
	cout << otro.toString() << endl;
	
	Complejo resta = c2 - c;
	cout << resta.toString() << endl;
	
	Complejo otromas = -c2;
	cout << otromas.toString() << endl;
	
	Complejo yotromas = c2 - 5 + c;
	cout << yotromas.toString() << endl;
	
	
	Complejo grande(5,7);
	Complejo pequenyo(-2, -5);
	
	
	
	if ( grande > pequenyo )
		cout << "Todo bien" << endl;
	else
		cout << "Todo mal" << endl;
	
	
	
	






}

