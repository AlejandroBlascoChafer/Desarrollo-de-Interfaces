#include "dprincipal.h"
#include "dtransferencia.h"

DPrincipal::DPrincipal(QWidget *parent){

	botonPrincipal = new QPushButton("start");
	layoutPrincipal = new QVBoxLayout;
	
	layoutPrincipal->addWidget(botonPrincipal);
	
	lEstado = new QLabel("Transferencia pendiente");
	
	layoutPrincipal->addWidget(lEstado);
	
	connect(botonPrincipal, SIGNAL(clicked()), this, SLOT(slotCambio()));
	
	QStringList listaTemporal = {"111111", "222222", "333333"};
	listaCuentas = listaTemporal;
	
	dTransferencia = NULL;
	
	setLayout(layoutPrincipal);

}

void DPrincipal::slotCambio(){

	if (dTransferencia==NULL) {
		dTransferencia = new DTransferencia(listaCuentas);
    connect(dTransferencia,SIGNAL(accepted()),this, SLOT(slotTransAceptada()));
    connect(dTransferencia,SIGNAL(rejected()),this, SLOT(slotTransRechazada()));
    
    }	

    dTransferencia->show();
}

void DPrincipal::slotTransAceptada(){
	lEstado->setText("Transferencia aceptada");
}

void DPrincipal::slotTransRechazada(){
	lEstado->setText("Transferencia denegada");
}
