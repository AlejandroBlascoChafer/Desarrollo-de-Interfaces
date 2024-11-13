#include "ventanaprincipal.h"
#include <QDebug>
#include <QStatusBar>
#include <QPushButton>
#include <QTextCursor>
#include <QMessageBox>
#include <QFileDialog>


VentanaPrincipal::VentanaPrincipal(QWidget *parent):QMainWindow(parent) {

	crearActions();
	crearMenus();
	crearToolBar();
	crearStatusBar();
	
	editorCentral = new QTextEdit();
	this->setCentralWidget(editorCentral);
	QTextDocument *documento = editorCentral->document();
	
	connect(documento, SIGNAL(cursorPositionChanged(const QTextCursor)), 
		this, SLOT(slotCursor(QTextCursor)));
		
	modificado=false;
	
	resize(800,600);

}



void VentanaPrincipal::crearActions(){
	accionGuardarComo = new QAction("Guardar como", this);
	accionGuardarComo->setShortcut(QKeySequence::SaveAs);
	
	accionAbrir = new QAction("Abrir", this);
	accionAbrir->setToolTip("Leer y cargar un archivo");
	accionAbrir->setShortcut(QKeySequence::Open);
	
	accionSalir = new QAction("Salir", this);
	accionSalir->setShortcut(QKeySequence::Close);	
	
	connect(accionSalir, SIGNAL(triggered()), 
		this, SLOT(close()));
	connect(accionAbrir, SIGNAL(triggered()), 
		this, SLOT(slotAbrir()));
	connect(accionGuardarComo, SIGNAL(triggered()), 
		this, SLOT(slotGuardarComo()));
		
	accionNuevo = new QAction("Nuevo", this);
	connect(accionNuevo, SIGNAL(triggered()), 
		this, SLOT(slotNuevo()));
		
	connect(editorCentral, SIGNAL(textChanged()), 
		this, SLOT(slotModificado()));
}

void VentanaPrincipal::crearMenus(){

	barraMenu = this->menuBar();
	
	menuArchivo = new QMenu("Archivo");
	barraMenu->addMenu(menuArchivo);
	
	menuEditar = barraMenu->addMenu("Editar");
	
	menuArchivo->addAction(accionSalir);
	menuArchivo->addAction(accionAbrir);
	menuArchivo->addAction(accionGuardarComo);
	menuArchivo->addAction(accionNuevo);

}

void VentanaPrincipal::crearToolBar(){

	barraPrincipal = this->addToolBar("Barra principal");
	barraPrincipal->addAction(accionSalir);
	barraPrincipal->addAction(accionAbrir);
	barraPrincipal->addAction(accionNuevo);
	
}

void VentanaPrincipal::crearStatusBar(){
	etiquetaEstado = new QLabel("No has escrito nada");
	QPushButton *botonEstado = new QPushButton("Estado");
	this->statusBar()->addWidget(etiquetaEstado);
	this->statusBar()->addWidget(botonEstado);

}
void VentanaPrincipal::slotCursor(const QTextCursor cursor){
	int linea = cursor.blockNumber();
	int columna = cursor.columnNumber();
	QString texto = QString("Linea: ") + QString::number(linea) + 
			QString(", Columna: ") + QString::number(columna);
	
	etiquetaEstado->setText(texto);
	
}

void VentanaPrincipal::slotAbrir(){
	qDebug() << "Estoy abriendo un fichero";
	QString rutaFichero = QFileDialog::getOpenFileName(this, "Abrir fichero", "./", 
				"Fichero de texto (*.txt)");
	
	QFile fichero(rutaFichero);			
				
	if ( ! fichero.open(QIODevice::ReadOnly) )
		return;
		
	QTextStream stream (&fichero);
		
	while (!stream.atEnd())
		editorCentral->append(stream.readLine());

	modificado=false;

}
void VentanaPrincipal::slotModificado(){
	modificado = true;

}
void VentanaPrincipal::slotGuardarComo(){
	qDebug() << "Estoy guardando un fichero";
	
	int posicion = 0;
	QTextStream stream;
	while (editorCentral->document()->findBlockByNumber(posicion)) {
		stream << 
	
	
	}
	QString linea;
	
	
	
	
	
}
void VentanaPrincipal::slotNuevo(){
	
	int respuesta = QMessageBox::Yes;
	if (modificado == true) {		
		respuesta = QMessageBox::warning(this, tr("nuevo doc"), tr("Quieres eliminar los cambios?"), 
				QMessageBox::No | QMessageBox::Yes);
	}
	
	if (respuesta == QMessageBox::Yes) {
		editorCentral->document()->clear();		
		QString texto = QString("Linea: ") + QString::number(0) + 
				QString(", Columna: ") + QString::number(0);
		
		etiquetaEstado->setText(texto);
	}
	


}



