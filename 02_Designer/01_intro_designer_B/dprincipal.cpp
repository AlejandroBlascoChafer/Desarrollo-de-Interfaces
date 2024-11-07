#include "dprincipal.h"

DPrincipal::DPrincipal( QWidget *parent ) : QDialog(parent){
	setupUi(this);
	
	cbPlatos->addItem("Huevos rotos");

	connect(bPedido, SIGNAL(clicked()), 
		this, SLOT(accept()));
		
		
	connect(cbPlatos, SIGNAL(currentIndexChanged(int)), 
		this, SLOT(slotCambioPlato(int)));
	 




 }
