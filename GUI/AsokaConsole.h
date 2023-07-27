#pragma once
#include <qwidget.h>
#include <qpushbutton.h>


class AsokaConsole : public QWidget {
	Q_OBJECT

public:
	explicit AsokaConsole();
	~AsokaConsole();

private:
	QPushButton* exitButton = nullptr;

signals:
	void closed();

};