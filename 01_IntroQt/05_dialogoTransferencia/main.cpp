#include <QApplication>

#include "dTransferencia.h"
	
int main(int argc, char *argv[]) {

  	QApplication app(argc, argv);
  	
  	DTransferencia *dTransferencia = new DTransferencia();
  	dTransferencia->show();
  	

  	
  	return app.exec();
  
  
  
  
  
  
  
  
  
  }
