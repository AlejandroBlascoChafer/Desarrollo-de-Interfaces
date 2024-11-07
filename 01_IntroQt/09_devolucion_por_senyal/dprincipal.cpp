#include "dprincipal.h"
#include "dtransferencia.h"

#include <QDebug>

DPrincipal::DPrincipal(QWidget *parent){

	botonPrincipal = new QPushButton("start");
	layoutPrincipal = new QVBoxLayout;
	
	layoutPrincipal->addWidget(botonPrincipal);
	
	leNuevaCuenta = new QLineEdit();
	layoutPrincipal->addWidget(leNuevaCuenta);
	
	lEstado = new QLabel("Transferencia pendiente");
	
	layoutPrincipal->addWidget(lEstado);
	
	connect(botonPrincipal, SIGNAL(clicked()), this, SLOT(slotCambio()));
	
	QStringList listaTemporal = {"111111", "222222", "333333"};
	
	listaCuentas = listaTemporal;
	
	dTransferencia = NULL;
	
	setLayout(layoutPrincipal);
	
	connect(leNuevaCuenta, SIGNAL(returnPressed()), 
		this, SLOT(slotAnyadirCuenta()));

}

void DPrincipal::slotCambio(){

	if (dTransferencia==NULL) {
		dTransferencia = new DTransferencia(listaCuentas);
    connect(dTransferencia,SIGNAL(accepted()),this, SLOT(slotTransAceptada()));
    connect(dTransferencia,SIGNAL(rejected()),this, SLOT(slotTransRechazada()));
    
    connect(dTransferencia, SIGNAL(senyalTransfAceptada(QString, float)),
    		this, SLOT(slotTransAceptadaConInfo(QString, float)));
    
    }	

    dTransferencia->show();
}

void DPrincipal::slotTransAceptada(){
	lEstado->setText("Transferencia aceptada");
	
	qDebug() << "Ejecutando slotTransAceptada " << lEstado->text();
	
	
	
	delete dTransferencia;
	dTransferencia = NULL;
}

void DPrincipal::slotTransAceptadaConInfo(QString numeroCuenta, float cantidad){
	//lEstado->setText("Transferencia aceptada");
	
	qDebug() << "Ejecutando slotTransAceptadaConInfo numeroCuenta " << numeroCuenta << 
		" cantidad " << cantidad;
	QString mensaje = QString("Se han transferido ") + QString::number(cantidad) + 
			  QString(" euros a la cuenta ") + QString(numeroCuenta);
			  
			  
	lEstado->setText(mensaje);
	
	//delete dTransferencia;
	//dTransferencia = NULL;
}

void DPrincipal::slotTransRechazada(){
	lEstado->setText("Transferencia denegada");
}

void DPrincipal::slotAnyadirCuenta(){
	if (dTransferencia == NULL)
		return;
	
	QString nuevaCuenta = leNuevaCuenta->text();
	
	dTransferencia->anyadirCuenta(nuevaCuenta);
}

