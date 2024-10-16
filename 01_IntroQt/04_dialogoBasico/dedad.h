#include <QLabel>
#include <QWidget>
#include <QSpinBox>
	
class DEdad : public Qwidget {

public:
	DEdad(QWidget *parent = NULL);
	
	QLabel *etiq_edad;
	QLabel *etiq_info;
	QSpinBox *sb_edad;

}
