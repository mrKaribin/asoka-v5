#pragma once
#include "Asoka/Types/string.h"
#include "Debug/Tester.h"
#include "Debug/Logs.h"


class asoka {
public:
	static Logs* logs;
	static Tester* tester;

	static void initialization();

};

