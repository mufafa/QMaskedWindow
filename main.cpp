#include <QApplication>
#include <QPushButton>
#include "mainwindow.h"
#include "transperant.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    Transperant transperant ;
//    transperant.show();

    MainWindow main;
    main.show();

	return a.exec();
}
