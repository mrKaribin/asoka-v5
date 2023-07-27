#include "Identifier.h"
#include "Object.h"
#include "Core.h"


Identifier::Identifier(Object *parent) {
	original = true;
	id = Core::createIdValue();
	object = parent;
}


Identifier::Identifier(const Identifier &other) {
	id = other.toNumber();
}


Identifier::~Identifier() {
	if (original) {
		Core::deleteIdValue(id);
	}
}


unsigned long long int Identifier::toNumber() const { return id; }


Object* Identifier::getObject() const {
	return object;
}
