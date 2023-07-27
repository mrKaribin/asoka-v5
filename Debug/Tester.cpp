#include "Tester.h"
#include "../Asoka.h"


void Module::run() {
	this->successfull = true;
	for (auto test : this->tests) {
		try {
			test->test();
			if (test->isSuccessfull()) {
				//asoka::logs->message(string("  + ����� " + test->getClassName() + " ������� ������ �����"));
			}
			else {
				successfull = false;
			}
		}
		catch (std::exception& except) {
			//asoka::logs->error(string("������ ����� � ������ " + this->name + " � ������ " + test->getClassName()));
		}
	}
	if (this->successfull) {
		//asoka::logs->message(string("+ ������ " + this->name + " ������� ������ �����"));
	}
	else {
		string message = "- ������ " + this->name + " �� ������ ��� �����";
	}
}


void Tester::run() {
	//asoka::logs->message(string("������ ������������ ���� �������"));
	for (auto item : this->modules) {
		Module* module = item.second;
		module->run();
	}
}