#include <QApplication>

#include "ventanaprincipal.h"

int main (int argc, char *argv[]){

    QApplication app(argc, argv);
	    
    
    VentanaPrincipal *ventanaPrincipal = new VentanaPrincipal();
    ventanaPrincipal->show();
    
	
	
    
    return app.exec();
}
