#include <dtransferencia.h>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

DTransferencia::DTransferencia(QStringList listaCuentas, QWidget *Parent){

	labelNumCuenta = new QLabel("numcuenta");
	labelCantidad = new QLabel("cantidad");
	labelComision = new QLabel("comision");
	
	cbDestino = new QComboBox();
	cbDestino->addItem("000000");
	
	cbDestino->addItems(listaCuentas);
	
	leCantidad = new QLineEdit;
	enviar = new QPushButton("enviar");
	
	cancelar = new QPushButton("cancelar");
	layoutSuperior = new QHBoxLayout;
	layoutMedio = new QHBoxLayout;
	layoutBajo = new QHBoxLayout;
	layoutPrincipal = new QVBoxLayout;
	
	
	
	layoutSuperior->addWidget(labelNumCuenta);
	layoutSuperior->addWidget(cbDestino);
	layoutSuperior->addWidget(enviar);
	layoutPrincipal->addLayout(layoutSuperior);
	
	layoutMedio->addWidget(labelCantidad);
	layoutMedio->addWidget(leCantidad);
	layoutMedio->addWidget(cancelar);
	layoutPrincipal->addLayout(layoutMedio);
	
	layoutBajo->addWidget(labelComision);
	layoutPrincipal->addLayout(layoutBajo);
	
	connect(cancelar, SIGNAL(clicked()), this, SLOT(reject()));
	
	//connect(enviar, SIGNAL(clicked()), this, SLOT(accept()));
	connect(enviar, SIGNAL(clicked()), this, SLOT(slotBotonAceptar()));
	
	
	connect(cbDestino, SIGNAL(currentTextChanged(QString)), 
		this, SLOT(slotVerificar(QString)));
	
	connect(leCantidad, SIGNAL(textChanged(QString)), 
	this, SLOT(slotVerificar(QString)));
	
	setLayout(layoutPrincipal);
	
	
}

void DTransferencia::slotVerificar(QString inutil){

	
	QString textoNumCuenta = cbDestino->currentText();
	
	QString cantidad = leCantidad->text();
	
	QRegularExpression reCuenta("^\\d{6}$");
	
	QRegularExpressionMatch mCuenta = reCuenta.match(textoNumCuenta);
	
	QRegularExpression reCantidad("^\\d+\.{0,1}\\d+$");
	QRegularExpressionMatch mCantidad = reCantidad.match(cantidad);
	
	bool destinoOK = mCuenta.hasMatch();
	bool cantidadOK = mCantidad.hasMatch();
	
	
	if (destinoOK && cantidadOK) {
		enviar->setEnabled(true);
	} else {
		enviar->setEnabled(false);
	}
	

}
void DTransferencia::slotBotonAceptar(){

	emit senyalTransfAceptada(cbDestino->currentText(), leCantidad->text().toFloat());

}

void DTransferencia::anyadirCuenta(QString nuevaCuenta){
	cbDestino->addItem(nuevaCuenta);
}
