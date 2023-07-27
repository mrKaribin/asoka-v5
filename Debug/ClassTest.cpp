#include "ClassTest.h"
#include "Asoka.h"


ClassTest::ClassTest(string className, string moduleName) {
	this->className = className;
	this->moduleName = moduleName;
	asoka::tester->addTest(this);
}

void ClassTest::run(bool throwExceptions) {
	this->throwExceptions = throwExceptions;
	this->successfull = true;
	this->test();
}

void ClassTest::checkPoint(bool condition) {
	if (!condition) {
		this->successfull = false;
		if (this->throwExceptions) {
			throw std::exception();
		}
	}
}
