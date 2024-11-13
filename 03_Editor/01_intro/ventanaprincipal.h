#ifndef _VENTANAPRINCIPAL_H_
#define _VENTANAPRINCIPAL_H_

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QTextEdit>
#include <QToolBar>
#include <QLabel>

class VentanaPrincipal : public QMainWindow {
Q_OBJECT

	QAction *accionSalir;
	QAction *accionAbrir;
	QAction *accionGuardarComo;
	QAction *accionNuevo;
	QMenuBar *barraMenu;
	QMenu *menuArchivo;
	QMenu *menuEditar;
	QTextEdit *editorCentral;
	QToolBar *barraPrincipal;
	QLabel *etiquetaEstado;
public:
	VentanaPrincipal(QWidget *parent = NULL);
	bool modificado;
	
	void crearActions();
	void crearMenus();
	void crearToolBar();
	void crearStatusBar();
	
public slots:
	void slotAbrir();
	void slotGuardarComo();
	void slotCursor(QTextCursor);
	void slotNuevo();
	void slotModificado();
	




};
#endif
