#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include "dTransferencia.h"


DTransferencia :: DTransferencia (QWidget* parent){


	qLabelCuenta = new QLabel("Cuenta destino: ");
	qLabelCantidad = new QLabel("Cantidad: ");
	qLabelComision = new QLabel("Comision");
	
	qleCuenta = new QLineEdit();
	qleCantidad = new QLineEdit();
	
	qpbAceptar = new QPushButton("Aceptar");
	qpbCancelar = new QPushButton("Cancelar");
	
	
	QVBoxLayout *layoutPrincipal = new QVBoxLayout();
	QHBoxLayout *layoutSuperior = new QHBoxLayout();
	QHBoxLayout *layoutMedio = new QHBoxLayout();

	
	layoutPrincipal->addLayout(layoutSuperior);
	layoutPrincipal->addLayout(layoutMedio);
	
	layoutSuperior->addWidget(qLabelCuenta);
	layoutSuperior->addWidget(qleCuenta);
	layoutSuperior->addWidget(qpbAceptar);
	
	layoutMedio->addWidget(qLabelCantidad);
	layoutMedio->addWidget(qleCantidad);
	layoutMedio->addWidget(qpbCancelar);
	
	layoutPrincipal->addWidget(qLabelComision);
	
	setLayout(layoutPrincipal);
	
	connect(qpbCancelar, SIGNAL(clicked()), this, SLOT(reject()));
	connect(qpbCancelar, SIGNAL(clicked()), this, SLOT(accept()));
	
	connect(qleCuenta, SIGNAL(textChanged(QString)), this, SLOT(slotVerificar(QString)));
	connect(qleCantidad, SIGNAL(textChanged(QString)), this, SLOT(slotVerificar(QString)));

	

}


void DTransferencia::slotVerificar(QString inutil) {


	QString textoNumCuenta = qleCuenta->text();
	QString cantidad = qleCantidad->text();
	
	QRegularExpression reDestino("^\\d{6}$");
	
	QRegularExpressionMatch mCuenta = reDestino.match(textoNumCuenta);
	//QRegularExpressionMatch mCantidad = ;
	
	bool destinoOK = false;
	if ( mCuenta.hasMatch() ) 
		destinoOK = true;



	if (destinoOK)
		qpbAceptar -> setEnabled(true);
	else 
		qpbAceptar -> setEnabled(false);
}




























