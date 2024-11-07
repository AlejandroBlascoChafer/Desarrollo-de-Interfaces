#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QListWidget>
#include <QCheckBox>
#include <QComboBox>

class DBar : public QDialog {

Q_OBJECT

public:
/* layouts */
	QHBoxLayout  *lyInfBotones, *lySupPlatos;
	QVBoxLayout *lyPrincipal,*lySeleccion, *lyPedido;
/* Componentes */
	QPushButton *bAnyadir, *bMenus, *bRealizarPedido;
	QLabel *lPlatos, *lPrecio, *lPedido;
	QLabel *lTotal;
	QSpinBox *sbPrecio;
	QComboBox * cbPlatos;
	QCheckBox *chMediaRacion;
	QListWidget *listaPlatos;
	int precios[4] = {5,6,7,8};
	int total;
	
	void comprobarRepetidos();
	
	DBar(QWidget * parent = 0) ; 

public slots:
	void slotCambioPlatoElegido(int);
	void slotAnyadirPlato();

};

