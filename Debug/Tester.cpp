#include "Tester.h"
#include "../Asoka.h"


void Module::run() {
	this->successfull = true;
	for (auto test : this->tests) {
		try {
			test->test();
			if (test->isSuccessfull()) {
				//asoka::logs->message(string("  + Класс " + test->getClassName() + " успешно прошел тесты"));
			}
			else {
				successfull = false;
			}
		}
		catch (std::exception& except) {
			//asoka::logs->error(string("Ошибка теста в модуле " + this->name + " в классе " + test->getClassName()));
		}
	}
	if (this->successfull) {
		//asoka::logs->message(string("+ Модуль " + this->name + " успешно прошел тесты"));
	}
	else {
		string message = "- Модуль " + this->name + " не прошел все тесты";
	}
}


void Tester::run() {
	//asoka::logs->message(string("Запуск тестирования всех модулей"));
	for (auto item : this->modules) {
		Module* module = item.second;
		module->run();
	}
}