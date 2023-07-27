#pragma once
#include <string>

#include "Asoka/Types/string.h"


class ClassTest{
public:
	explicit ClassTest(string className, string moduleName = "");

	string getModuleName() { return this->moduleName; }
	string getClassName() { return this->className; }


	void run(bool throwExceptions = false);
	void checkPoint(bool condition);
	bool isSuccessfull() { return this->successfull; }

	virtual void test() = 0;

private:
	string moduleName = "";
	string className = "";
	bool throwExceptions = false;
	bool successfull = true;
};

