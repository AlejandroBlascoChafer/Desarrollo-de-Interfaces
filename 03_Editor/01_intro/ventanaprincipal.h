#ifndef _VENTANAPRINCIPAL_H_
#define _VENTANAPRINCIPAL_H_

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QTextEdit>
#include <QToolBar>
#include <QLabel>
#include <QCloseEvent>
#include <QAction>

class VentanaPrincipal : public QMainWindow {
Q_OBJECT

	QAction *accionSalir;
	QAction *accionAbrir;
	QAction *accionGuardarComo;
	QAction *accionGuardar;
	QAction *accionNuevo;
	QMenuBar *barraMenu;
	QMenu *menuArchivo;
	QMenu *menuEditar;
	QTextEdit *editorCentral;
	QToolBar *barraPrincipal;
	QLabel *etiquetaEstado;
	bool modificado;
	QString rutaArchivoActual;
	
	QVector<QAction * > accionesRecientes;
	
public:
	VentanaPrincipal(QWidget *parent = NULL);
	
	
	void crearActions();
	void crearMenus();
	void crearToolBar();
	void crearStatusBar();
	void closeEvent(QCloseEvent *event);
	
	bool guardarArchivo(QString ruta);
	
public slots:
	void slotAbrir();
	void slotGuardar();
	void slotGuardarComo();
	void slotCursor(const QTextCursor&);
	void slotNuevo();
	void slotModificado();
	




};
#endif
