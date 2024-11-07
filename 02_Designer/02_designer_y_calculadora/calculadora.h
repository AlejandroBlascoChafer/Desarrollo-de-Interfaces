#ifndef _CALCULADORA_H_
#define _CALCULADORA_H_

#include "ui_calculadora.h"
#include <QDialog>

class Calculadora : public QDialog, public Ui::Calculadora {
Q_OBJECT

public:
	Calculadora ( QWidget * parent = NULL );
	bool primerSumando;
	int primerNum;
	int segundoNum;
	
	
public slots:
	void slotDigito();
	void slotSumar();
	void slotSumar2();
	
	




};

#endif
