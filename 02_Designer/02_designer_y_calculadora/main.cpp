#include <QApplication>

#include "calculadora.h"

int main (int argc, char *argv[]){

    QApplication app(argc, argv);
	    
    
    Calculadora *calculadora = new Calculadora();
    calculadora->show();
    
	
	
    
    return app.exec();
}
