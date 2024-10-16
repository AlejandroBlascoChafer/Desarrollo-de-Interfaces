#include "dedad.h"

Dedad::DEdad(QWidget* parent){

	QVBoxLayout *principal = new QVBoxLayout();
	QHBoxLayout *layoutSuperior = new QHBoxLayout();
	QHBoxLayout *layoutInferior = new QHBoxLayout();
	
	sb_edad = new QSpinBox;
	sb_edad->setRange(0,100);
	sb_edad->setValue(15);
	
	String mayor = "Eres mayor de edad";
	String menor = "No eres mayor de edad";
	
	etiq_info = new QLabel;
	etiq_edad = new QLabel("Edad: ");
	
	
	
	if (sb_edad->value() >= 18){
		QObject::connect(sb_edad, SIGNAL(valueChanged(int)),
			 etiq_info, SLOT(setText(mayor)));	
	} else {
		QObject::connect(sb_edad, SIGNAL(valueChanged(int)),
			 etiq_info, SLOT(setText(menor)));
	}
	
	principal->addLayout(layoutSuperior);
	principal->addLayout(layoutInferior);
	layoutSuperior->addWidget(etiq_edad);
	layoutSuperior->addWidget(sb_edad);
	layoutInferior->addWidget(etiq_info);
	
	

	
	
	
	
	setLayout(principal);
	
	
	



}
