#pragma once
#include <qstring.h>


class string: public QString {
public:
	string() : QString() {}
	string(const char* ch) : QString(ch) {}
	string(QChar ch) : QString(ch) {}
	string(string &&other) noexcept : QString(other) {}
	string(const string &other) : QString(other) {}
	string(const QString &other) : QString(other) {}

	string operator=(const string &other) {return QString::operator=(other);}
};
