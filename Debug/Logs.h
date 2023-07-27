#pragma once
#pragma execution_character_set("utf-8")

#include "Asoka/Types/string.h"
#include "Logs/FileLog.h"


class Logs {
public:
	explicit Logs() { FileLog::crearFile(); }

	void message(string message) {
		FileLog log(Log::Type::Message, message);
		log.save();
	}

	void warning(string message) {
		FileLog log(Log::Type::Warning, message);
		log.save();
	}

	void error(string message) {
		FileLog log(Log::Type::Error, message);
		log.save();
	}
};
