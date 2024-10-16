#include <QApplication>
#include <QLabel>
#include <unistd.h>

int main(int argc, char *argv[])
{
     QApplication app(argc, argv);
     QLabel *label;
     
     label = new QLabel( "<h2><i> Hello </i> " " <font color=red>Qt!</font></h2> " );
     
     (*label).show();
     
     sleep (5);
     app.exec();
		
		return 0;
 }

