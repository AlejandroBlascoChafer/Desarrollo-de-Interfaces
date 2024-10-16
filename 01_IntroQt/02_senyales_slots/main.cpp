#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     QPushButton *button = new QPushButton("Quit");
     QObject::connect(button, SIGNAL(clicked()),
                      &app, SLOT(quit()));
                      
                      
     /* button.addEventListener("clic", quit);*/
     /* <input type="button" onClick="quit" */
     button->show();
    return app.exec();
 }

