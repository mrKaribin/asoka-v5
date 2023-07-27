#pragma once
#pragma execution_character_set("utf-8")
#include <qfile.h>
#include <qtextstream.h>

#include "Log.h"


class FileLog : public Log {
public:
	explicit FileLog() : Log() {}
	explicit FileLog(Log::Type type, string message) : Log(type, message) {}

	void save() override {
		QFile file("D:/Projects/Asoka/v4.0/Logs.txt");
		if (file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append)) {
			QTextStream out(&file);
			if (this->type == Log::Type::Warning)
				out << "Warning: ";
			if (this->type == Log::Type::Error)
				out << "Error: ";
			out << this->message.toUtf8() << "\n";
			file.flush();
			file.close();
		}
		else {
			string name = file.fileName();
			bool exists = file.exists();
			int i = 0;
		}
	}

	void load(int id) override {

	}

	static void crearFile() {
		QFile file("D:/Projects/Asoka/v4.0/Logs.txt");
		if (file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
			file.write("\n");
			file.flush();
			file.close();
		}
	}
};