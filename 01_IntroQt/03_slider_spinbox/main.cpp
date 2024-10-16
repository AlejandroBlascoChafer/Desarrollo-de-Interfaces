#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QLCDNumber>
	
  int main(int argc, char *argv[])
  {
      QApplication app(argc, argv);

      QWidget *window = new QWidget;
      window->setWindowTitle("Enter Your Age");

     QSpinBox *spinBox = new QSpinBox;
     QSlider *slider = new QSlider(Qt::Horizontal);     
     QLCDNumber *numero = new QLCDNumber(10);
     QLabel *valor = new QLabel("Valor: ");
     QPushButton *btnDecimal = new QPushButton("Decimal");
     QPushButton *btnBinario = new QPushButton("Binario");
     
     
     
     
     
 
     spinBox->setRange(0, 130);
     slider->setRange(0, 130);
     
     
     
     QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                      slider, SLOT(setValue(int)));
                      
     QObject::connect(slider, SIGNAL(valueChanged(int)),
                      spinBox, SLOT(setValue(int)));
                      
     QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                      numero, SLOT(display(int)));
                      
     QObject::connect(slider, SIGNAL(valueChanged(int)),
                      numero, SLOT(display(int)));
                      
	QObject::connect(btnBinario, SIGNAL(clicked()),
			 numero, SLOT(setBinMode()));
	QObject::connect(btnDecimal, SIGNAL(clicked()),
			 numero, SLOT(setDecMode()));
                      
     
                      
     spinBox->setValue(35);

     QVBoxLayout *principal = new QVBoxLayout;
     QHBoxLayout *layout2 = new QHBoxLayout;
     QHBoxLayout *layout3 = new QHBoxLayout;
     QHBoxLayout *layout4 = new QHBoxLayout;
     
     
     principal->addLayout(layout2);
     principal->addLayout(layout3);
     principal->addWidget(btnBinario);
     layout2->addWidget(btnDecimal);
     
     layout2->addWidget(btnDecimal);
     layout2->addWidget(spinBox);
     layout2->addWidget(slider);
     
     layout3->addWidget(valor);
     layout3->addWidget(numero);
     
         
     
     
     
     window->setLayout(principal);

     window->show();
     

     return app.exec();
 }

