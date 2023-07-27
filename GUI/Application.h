#pragma once
#include <qapplication.h>


class Application: public QApplication {
	Q_OBJECT
	
public:

	explicit Application(int& argc, char** argv) : QApplication(argc, argv) {}
};