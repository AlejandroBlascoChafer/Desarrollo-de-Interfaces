#include <QApplication>
#include "dbar.h"

int main (int argc, char *argv[]){

    QApplication app(argc, argv);
	    
    
    DBar *dBar = new DBar;
    dBar->show();
    
	
	
    
    return app.exec();
}
