#pragma once
#pragma execution_character_set("utf-8")
#include <vector>
#include <map>
#include <stdexcept>

#include "ClassTest.h"


class Module {
public:
	Module(string name) {
		this->name = name;
	}

	void addTest(ClassTest* test) {
		this->tests.push_back(test);
	}

	void run();

private:
	string name = "";
	bool successfull = true;
	std::vector<ClassTest*> tests = {};

};


class Tester {
public:
	Tester() {
		string moduleName = "default";
		this->defaultModule = new Module(moduleName);
		this->modules.insert({ moduleName,  this->defaultModule });
	}

	void addTest(ClassTest* test) {
		if (test->getModuleName().isEmpty()) { 
			this->defaultModule->addTest(test);
		}
		else {
			auto iter = this->modules.find(test->getModuleName());
			if (iter != this->modules.end()) {
				iter->second->addTest(test);
			}
			else {
				string moduleName = test->getModuleName();
				Module* module = new Module(moduleName);
				this->modules.insert({ moduleName, module });
				module->addTest(test);
			}
		}
	}

	void run();

private:
	Module* defaultModule = nullptr;
	std::map<string, Module*> modules;

};