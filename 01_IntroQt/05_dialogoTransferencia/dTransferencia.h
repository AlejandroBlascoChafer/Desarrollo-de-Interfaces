#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class DTransferencia : public QDialog {
Q_OBJECT

public:
	DTransferencia (QWidget * parent = NULL);
	
	QLabel *qLabelCuenta;	
	QLabel *qLabelCantidad;
	QLabel *qLabelComision;
	
	QLineEdit *qleCuenta;
	QLineEdit *qleCantidad;
	
	QPushButton *qpbAceptar;
	QPushButton *qpbCancelar;
	
	
	
public slots:
	void slotVerificar(QString);
	
	
	






};
