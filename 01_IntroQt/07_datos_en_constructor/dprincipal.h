#ifndef DPRINCIPAL_H
#define DPRINCIPAL_H

#include <QWidget>
#include <QPushButton>
#include <QDialog>
#include <QVBoxLayout>
#include "dtransferencia.h"
#include <QLabel>

class DPrincipal : public QDialog {
Q_OBJECT

public:
	DPrincipal (QWidget * parent = NULL);
	
	QLabel *lEstado;
	QPushButton *botonPrincipal;
	QVBoxLayout *layoutPrincipal; 
	DTransferencia * dTransferencia;
	QStringList listaCuentas;
	
	
public slots:
	void slotCambio();
	void slotTransAceptada();
	void slotTransRechazada();

};

#endif
