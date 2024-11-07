#include "dedad.h"
#include <QVBoxLayout>
#include <QHBoxLayout>



DEdad::DEdad(QWidget* parent) {

	etiq_info = new QLabel();
	etiq_edad = new QLabel("Edad: ");
	sb_edad = new QSpinBox();
	
	
	QHBoxLayout *layoutSuperior = new QHBoxLayout();
	layoutSuperior->addWidget(etiq_edad);
	layoutSuperior->addWidget(sb_edad);
	
	
	QVBoxLayout *layoutPrincipal = new QVBoxLayout();
	layoutPrincipal->addLayout(layoutSuperior);
	layoutPrincipal->addWidget(etiq_info);
	
	
	
	
	
	connect(sb_edad, SIGNAL(valueChanged(int)), this, SLOT(slotInformar(int)));
	
	setLayout(layoutPrincipal);
	
}

void DEdad::slotInformar(int edad) {
		
		if (edad >= 18) {
			etiq_info->setText("Eres Mayor de edad");
		} else {
			etiq_info->setText("Eres Menor de edad");
		}	
		
}
