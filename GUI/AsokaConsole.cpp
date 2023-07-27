#pragma execution_character_set("utf-8")
#include <qboxlayout.h>

#include "AsokaConsole.h"
#include "Asoka.h"



AsokaConsole::AsokaConsole() : QWidget() {
	this->setGeometry(400, 300, 800, 600);
	this->setWindowTitle("Asoka Console");

	QBoxLayout* layout = new QBoxLayout(QBoxLayout::TopToBottom, this);
	QBoxLayout* bottomBoxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
	string name = "Close";
	this->exitButton = new QPushButton(name, this);
	
	layout->addStretch(1);
	bottomBoxLayout->addStretch(1);
	bottomBoxLayout->addWidget(this->exitButton);
	layout->addLayout(bottomBoxLayout);
	this->setLayout(layout);

	connect(this->exitButton, &QPushButton::clicked, this, &AsokaConsole::closed);
	connect(this->exitButton, &QPushButton::clicked, this, &QWidget::deleteLater);
}

AsokaConsole::~AsokaConsole() {
	this->exitButton = nullptr;
}
