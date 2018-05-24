#include "choosepicture.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	choosePicture w;
	w.show();
	return a.exec();
}
