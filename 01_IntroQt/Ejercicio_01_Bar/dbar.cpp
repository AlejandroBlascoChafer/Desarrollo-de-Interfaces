#include "dbar.h"
#include <QLineEdit>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include <QDebug>

DBar::DBar(QWidget * parent) : QDialog(parent) {
	
	total = 0;
	lyInfBotones = new QHBoxLayout;
	lySupPlatos = new QHBoxLayout;
	
	lyPrincipal = new QVBoxLayout;
	lySeleccion = new QVBoxLayout;
	lyPedido = new QVBoxLayout;

	lyPrincipal->addLayout(lySupPlatos);
	lyPrincipal->addLayout(lyInfBotones);
	
	lySupPlatos->addLayout(lySeleccion);
	lySupPlatos->addLayout(lyPedido);
	setLayout(lyPrincipal);
	
	bAnyadir = new QPushButton("Añadir");
	bMenus = new QPushButton("Menús");
	bRealizarPedido = new QPushButton("Realizar Pedido");
	lPlatos = new QLabel("Platos: ");
	lPrecio = new QLabel("Precio: ");
	lPedido = new QLabel("Pedido: ");
	lTotal = new QLabel("Total: 0 euros");
	sbPrecio = new QSpinBox();
	cbPlatos = new QComboBox();
	chMediaRacion = new QCheckBox("Media ración");
	listaPlatos = new QListWidget();
	
	lySeleccion->addWidget(lPlatos);
	lySeleccion->addWidget(cbPlatos);
	lySeleccion->addWidget(lPedido);
	lySeleccion->addWidget(sbPrecio);
	lySeleccion->addWidget(chMediaRacion);
	lySeleccion->addWidget(bAnyadir);
	lySeleccion->addStretch(1);
	
	lyPedido->addWidget(lPedido);
	lyPedido->addWidget(listaPlatos);
	lyPedido->addWidget(lTotal);
	
	QStringList listaPlatos = {"Bravas", "Croquetas", "Chopitos", "Sepia"};
	sbPrecio->setValue(precios[0]);
	
	lyInfBotones->addWidget(bMenus);
	lyInfBotones->addWidget(bRealizarPedido);	
	view use the default color from the style
	cbPlatos->addItems(listaPlatos);
	
	connect(cbPlatos, SIGNAL(currentIndexChanged(int)),
		this, SLOT(slotCambioPlatoElegido(int)));
		
	connect(bAnyadir, SIGNAL(clicked()), 
		this, SLOT(slotAnyadirPlato()));
	
}

void DBar::slotCambioPlatoElegido(int numPlato){
	sbPrecio->setValue(precios[numPlato]);
}

void DBar::slotAnyadirPlato(){

	listaPlatos->addItem(cbPlatos->currentText());
	total = total + precios[cbPlatos->currentIndex()];
	
	QString mostrar = QString("Total: ") + QString::number(total) + QString(" euros");

	lTotal->setText(mostrar);
	
	comprobarRepetidos();
}

void DBar::comprobarRepetidos(){

	for (int i = 0; i <= listaPlatos->count(); i++){
		for (int j = i+1; j <= listaPlatos->count(); j++){
			if ( listaPlatos->item(i)->text() == listaPlatos->item(j)->text() )
				listaPlatos->item(j)->setBackground(QBrush(Qt::darkRed));
		}
	}



}


