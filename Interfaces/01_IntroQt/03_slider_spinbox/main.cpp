#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>

  int main(int argc, char *argv[])
  {
      QApplication app(argc, argv);

      QWidget *window = new QWidget;
      window->setWindowTitle("Enter Your Age");

     QSpinBox *spinBox = new QSpinBox;
     QSlider *slider = new QSlider(Qt::Horizontal);
     QPushButton *boton = new QPushButton("aprètame");
     QLabel *edad = new QLabel("Edad: ");
     QLabel *salario = new QLabel("Salario: ");
 
     spinBox->setRange(0, 130);
     slider->setRange(0, 130);

     QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                      slider, SLOT(setValue(int)));
                      
     QObject::connect(slider, SIGNAL(valueChanged(int)),
                      spinBox, SLOT(setValue(int)));
     spinBox->setValue(35);

     QHBoxLayout *layout = new QHBoxLayout;
     layout->addWidget(edad);
     layout->addWidget(slider);
     layout->addWidget(salario);     
     layout->addWidget(spinBox);
     //layout->addWidget(boton);
     
     window->setLayout(layout);

     window->show();

     return app.exec();
 }

