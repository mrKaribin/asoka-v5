#pragma once
#pragma execution_character_set("utf-8")
#include "../../Asoka/Types/string.h"


class Log {
public:
	enum class Type { Message = 1, Warning, Error };

	explicit Log() {
		this->type = Log::Type::Message;
		this->message = "";
	}

	explicit Log(Log::Type type, string message) {
		this->type = type;
		this->message = message;
	}

	virtual void save() = 0;
	virtual void load(int id) = 0;

protected:
	int id = 0;
	Log::Type type;
	string message;

};