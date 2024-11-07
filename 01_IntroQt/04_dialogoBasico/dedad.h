#include <QLabel>
#include <QWidget>
#include <QSpinBox>
	
class DEdad : public QWidget {
Q_OBJECT

public:

	DEdad(QWidget *parent = NULL);
	
	QLabel *etiq_edad;
	QLabel *etiq_info;
	QSpinBox *sb_edad;
	
public slots:
	void slotInformar(int);

};
