#include "Core.h"


Core::Core() {

}


const unsigned long long int Core::createIdValue() {
	for (unsigned long long int i; i < 10000000000; i++) {
		bool ok = true;
		for (const unsigned long long int id : Core::ids) {
			if (i == id) {
				ok = false;
				break;
			}
		}

		if (ok) {
			Core::ids.push_back(i);
			return i;
		}
	}
	throw std::exception();
}


void Core::deleteIdValue(unsigned long long int value) {
	auto iter = std::find(Core::ids.begin(), Core::ids.end(), value);
	Core::ids.erase(iter);
}

std::vector<unsigned long long int> Core::ids = {};