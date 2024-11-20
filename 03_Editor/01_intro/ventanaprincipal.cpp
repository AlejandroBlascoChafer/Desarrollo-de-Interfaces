#include "ventanaprincipal.h"
#include <QDebug>
#include <QStatusBar>
#include <QPushButton>
#include <QTextCursor>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextBlock>



VentanaPrincipal::VentanaPrincipal(QWidget *parent):QMainWindow(parent) {

	editorCentral = new QTextEdit();

	crearActions();
	crearMenus();
	crearToolBar();
	crearStatusBar();
	
	
	this->setCentralWidget(editorCentral);
	QTextDocument *documento = editorCentral->document();
	
	connect(documento, SIGNAL(cursorPositionChanged(const QTextCursor &)), 
		this, SLOT(slotCursor(const QTextCursor &)));
		
	connect(editorCentral, SIGNAL(textChanged()), 
		this, SLOT(slotModificado()));
		
	modificado=false;
	
	resize(800,600);
	

}

void VentanaPrincipal::closeEvent(QCloseEvent *event) {	
				
	if (modificado) {
		int respuesta = QMessageBox::Yes;
 		respuesta = QMessageBox::warning(this, tr("Cerrar la ventana"), 
 				tr("Hay cambios no guardados, quieres salir sin guardar?"),
				QMessageBox::Cancel | QMessageBox::Save | QMessageBox::Yes);
				
		if (respuesta == QMessageBox::Cancel)
			event->ignore();
			
		if (respuesta == QMessageBox::Save)
			slotGuardar();
			
	}
	
}

void VentanaPrincipal::crearActions(){
	accionGuardarComo = new QAction("Guardar como", this);
	accionGuardarComo->setShortcut(QKeySequence::SaveAs);
	
	accionGuardar = new QAction("Guardar", this);
	
	accionAbrir = new QAction("Abrir", this);
	accionAbrir->setToolTip("Leer y cargar un archivo");
	accionAbrir->setShortcut(QKeySequence::Open);
	
	accionSalir = new QAction("Salir", this);
	accionSalir->setShortcut(QKeySequence::Close);
	
	
	for (int = 0; i < 5; i++) {
		QAction *accion = new QAction("Una", this)
		accionesReciente.append(accion));
	}
	
	
	connect(accionSalir, SIGNAL(triggered()), 
		this, SLOT(close()));
		
	connect(accionAbrir, SIGNAL(triggered()), 
		this, SLOT(slotAbrir()));
		
	connect(accionGuardarComo, SIGNAL(triggered()), 
		this, SLOT(slotGuardarComo()));
		
	connect(accionGuardar, SIGNAL(triggered()), 
		this, SLOT(slotGuardar()));
		
	accionNuevo = new QAction("Nuevo", this);
	connect(accionNuevo, SIGNAL(triggered()), 
		this, SLOT(slotNuevo()));
		
		
}

void VentanaPrincipal::crearMenus(){

	barraMenu = this->menuBar();
	
	menuArchivo = new QMenu("Archivo");
	barraMenu->addMenu(menuArchivo);
	
	menuEditar = barraMenu->addMenu("Editar");
	
	menuArchivo->addAction(accionSalir);
	menuArchivo->addAction(accionAbrir);
	menuArchivo->addAction(accionGuardar);
	menuArchivo->addAction(accionGuardarComo);
	menuArchivo->addAction(accionNuevo);

}




void VentanaPrincipal::crearToolBar(){

	barraPrincipal = this->addToolBar("Barra principal");
	barraPrincipal->addAction(accionSalir);
	barraPrincipal->addAction(accionAbrir);
	barraPrincipal->addAction(accionNuevo);
	barraPrincipal->addAction(accionGuardarComo);
	barraPrincipal->addAction(accionGuardar);
}



void VentanaPrincipal::crearStatusBar(){
	etiquetaEstado = new QLabel("No has escrito nada");
	QPushButton *botonEstado = new QPushButton("Estado");
	this->statusBar()->addWidget(etiquetaEstado);
	this->statusBar()->addWidget(botonEstado);

}




bool VentanaPrincipal::guardarArchivo(QString ruta){

	QFile fichero(ruta);
	
	if ( fichero.open(QIODevice::WriteOnly) == false ) {
		qDebug() << "Imposible escribir archivo";
		return false;
	}	

	QTextStream stream(&fichero);
	
	QTextDocument *documento = editorCentral->document();
	int numBloques = documento->blockCount();
	
	int indice = 0;	
	while ( indice < numBloques ) {
		QTextBlock bloqueText;
		bloqueText = documento->findBlockByNumber(indice);		
		
		QString linea = bloqueText.text();
		
		if (linea.isEmpty()){
			stream << endl;
		} else {
			stream << linea << endl;
		}
		indice++;
		
	}
	rutaArchivoActual = ruta;
	stream.flush();
	fichero.close();
	modificado = false;
	return true;
}





/******************************************************************************/
/**********slotCursor(const QTextCursor &cursor)                           ****/
/******************************************************************************/
void VentanaPrincipal::slotCursor(const QTextCursor &cursor){
	int linea = cursor.blockNumber();
	int columna = cursor.columnNumber();
	QString texto = QString("Linea: ") + QString::number(linea) + 
			QString(", Columna: ") + QString::number(columna);
	
	etiquetaEstado->setText(texto);
	
}





/******************************************************************************/
/**********slotAbrir()                                            *************/
/******************************************************************************/
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

	rutaArchivoActual = rutaFichero;
	modificado=false;
}





/******************************************************************************/
/**********slotModificado()                                       *************/
/******************************************************************************/
void VentanaPrincipal::slotModificado(){
	modificado = true;
}




/******************************************************************************/
/**********slotGuardar()                                            *************/
/******************************************************************************/
void VentanaPrincipal::slotGuardar(){
	qDebug() << "Guardando";
	if (rutaArchivoActual.isEmpty()){
		slotGuardarComo();
	} else {
		guardarArchivo(rutaArchivoActual);	
	}
}





/******************************************************************************/
/**********slotGuardarComo()                                      *************/
/******************************************************************************/

void VentanaPrincipal::slotGuardarComo(){
	
	QString rutaFichero;
	rutaFichero = QFileDialog::getSaveFileName();
	
	guardarArchivo(rutaFichero);

	
}
/******************************************************************************/
/**********slotNuevo()                                            *************/
/******************************************************************************/
void VentanaPrincipal::slotNuevo(){
	
	int respuesta = QMessageBox::Yes;
	if (modificado == true) {		
		respuesta = QMessageBox::warning(this, tr("nuevo doc"), tr("Quieres eliminar los cambios?"), 
				QMessageBox::No | QMessageBox::Yes);
	}
	
	if (respuesta == QMessageBox::Yes) {
		editorCentral->document()->clear();
		rutaArchivoActual.clear();
		QString texto = QString("Linea: ") + QString::number(0) + 
				QString(", Columna: ") + QString::number(0);
		
		etiquetaEstado->setText(texto);
		modificado = false;
	}
	


}



