#pragma once

class Object;


class Identifier {
public:
	Identifier(Object* object);
    Identifier(const Identifier& other);
	~Identifier();

    unsigned long long int toNumber() const;
	Object* getObject() const;
	
	template <class CLS>
	CLS* getObject() const {
		return static_cast<CLS*>(object);
    }

private:
	bool original = false;
	unsigned long long int id = 0;
	Object* object;
};
