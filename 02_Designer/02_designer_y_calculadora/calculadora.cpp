#include "calculadora.h"
#include <QDebug>

Calculadora::Calculadora ( QWidget *parent ) : QDialog(parent){
	setupUi(this);
	primerSumando = false;
	

	
	connect(bUno, SIGNAL(clicked()),
		this, SLOT(slotDigito()));
	connect(bDos, SIGNAL(clicked()),
		this, SLOT(slotDigito()));
	connect(bTres, SIGNAL(clicked()),
		this, SLOT(slotDigito()));
	connect(bCuatro, SIGNAL(clicked()),
		this, SLOT(slotDigito()));
	connect(bCinco, SIGNAL(clicked()),
		this, SLOT(slotDigito()));
	connect(bSeis, SIGNAL(clicked()),
		this, SLOT(slotDigito()));
	connect(bSiete, SIGNAL(clicked()),
		this, SLOT(slotDigito()));
	connect(bOcho, SIGNAL(clicked()),
		this, SLOT(slotDigito()));
	connect(bNueve, SIGNAL(clicked()),
		this, SLOT(slotDigito()));
	connect(bCero, SIGNAL(clicked()),
		this, SLOT(slotDigito()));
		
		
	if (primerSumando == false)
		connect(bSumar, SIGNAL(clicked()), this, SLOT(slotSumar()));
	else
		connect(bIgual, SIGNAL(clicked()), this, SLOT(slotSumar2()));
	 




}

void Calculadora::slotDigito(){
	int valorAnterior = lcdNumero->value();
	
	QPushButton * botonCulpable = qobject_cast<QPushButton*>(sender());
	
	int digito = botonCulpable->text().toInt();
	int valorNuevo = valorAnterior * 10 + digito;
	
	lcdNumero->display(valorNuevo);

}


void Calculadora::slotSumar(){
	primerNum = lcdNumero->value();
	lcdNumero->display(0);
	primerSumando = true;

}

void Calculadora::slotSumar2(){
	segundoNum = lcdNumero->value();
	int resultado = primerNum + segundoNum;
	lcdNumero->display(resultado);
	

}























