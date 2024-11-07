#include "ventanaprincipal.h"
#include <QDebug>
#include <QStatusBar>
#include <QPushButton>
#include <QTextCursor>

VentanaPrincipal::VentanaPrincipal(QWidget *parent):QMainWindow(parent) {

	crearActions();
	crearMenus();
	crearToolBar();
	crearStatusBar();
	
	editorCentral = new QTextEdit();
	this->setCentralWidget(editorCentral);
	QTextDocument *documento = editorCentral->document();
	
	connect(documento, SIGNAL(cursorPositionChanged(QTextCursor)), 
		this, SLOT(slotCursor(QTextCursor)));
	
	resize(800,600);

}

void VentanaPrincipal::slotCursor(const QTextCursor cursor){
	int linea = cursor.blockNumber();
	int columna = cursor.columnNumber();
	QString texto = QString("Linea: ") + QString::number(linea) + 
			QString(", Columna: ") + QString::number(columna);
	
	etiquetaEstado->setText(texto);
	
}

void VentanaPrincipal::crearActions(){
	accionGuardarComo = new QAction("Guardar como", this);
	accionGuardarComo->setShortcut(QKeySequence::SaveAs);
	
	accionAbrir = new QAction("Abrir", this);
	accionAbrir->setIcon(QIcon("./Imagenes/blueprint.png"));
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
}

void VentanaPrincipal::crearMenus(){

	barraMenu = this->menuBar();
	
	menuArchivo = new QMenu("Archivo");
	barraMenu->addMenu(menuArchivo);
	
	menuEditar = barraMenu->addMenu("Editar");
	
	menuArchivo->addAction(accionSalir);
	menuArchivo->addAction(accionAbrir);
	menuArchivo->addAction(accionGuardarComo);

}

void VentanaPrincipal::crearToolBar(){

	barraPrincipal = this->addToolBar("Barra principal");
	barraPrincipal->addAction(accionSalir);
	barraPrincipal->addAction(accionAbrir);
	
}

void VentanaPrincipal::crearStatusBar(){
	etiquetaEstado = new QLabel("No has escrito nada");
	QPushButton *botonEstado = new QPushButton("Estado");
	this->statusBar()->addWidget(etiquetaEstado);
	this->statusBar()->addWidget(botonEstado);

}

void VentanaPrincipal::slotAbrir(){
	qDebug() << "Estoy abriendo un fichero";
}
void VentanaPrincipal::slotGuardarComo(){
	qDebug() << "Estoy guardando un fichero";
}



