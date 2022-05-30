
#pragma once

#include "Main_View.h"
#include <QtWidgets/QApplication>



int main(int argc, char* argv[])
{
	
	QLocale curLocale(QLocale("chcp 1251"));
	QLocale::setDefault(curLocale);


		QApplication a(argc, argv);

		Main_View start;

		start.setWindowTitle("Face and LPR");

		start.show();

		return a.exec();
}
