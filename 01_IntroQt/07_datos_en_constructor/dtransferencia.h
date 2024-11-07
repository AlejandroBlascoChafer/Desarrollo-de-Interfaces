#ifndef DTRANSFERENCIA_H
#define DTRANSFERENCIA_H

#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QComboBox>

class DTransferencia : public QDialog {
Q_OBJECT

public:
	DTransferencia ( QStringList listaCuentas, QWidget * parent = NULL);

	QLabel *labelNumCuenta;
	QLabel *labelCantidad;
	QLabel *labelComision;
	QLineEdit *leCuenta;
	QLineEdit *leCantidad;
	QPushButton *enviar;
	QPushButton *cancelar;
	QHBoxLayout *layoutSuperior;
	QHBoxLayout *layoutMedio;
	QHBoxLayout *layoutBajo;
	QVBoxLayout *layoutPrincipal;
	QComboBox *cbDestino;
	
public slots:
	
	void slotVerificar(QString);


};

#endif
