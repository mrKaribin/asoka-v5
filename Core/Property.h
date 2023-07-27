#pragma once
#include <stdexcept>


#define PRIVATE_PROP(cls, type, name, publicName, value) \
private: type name = value; \
public: Property<cls, type> publicName = { this, &this->name };

#define PROTECTED_PROP(cls, type, name, publicName, value) \
protected: type name = value; \
public: Property<cls, type> publicName = { this, &this->name };


template<class CLS, typename TYPE>
class Property {
public:
	Property(CLS *object, TYPE *value, bool readable = true, bool writable = true) {
		this->object = object;
		this->value = value;
		this->readable = readable;
		this->writable = writable;
	}

	~Property() {
		this->object = nullptr;
		this->getter = nullptr;
		this->setter = nullptr;
	}

	Property<CLS, TYPE>& setGetter(TYPE (CLS::* getter) (TYPE) const) {
		this->getter = getter;
		return *this;
	}

	Property<CLS, TYPE>& setSetter(TYPE(CLS::* setter) (TYPE)) {
		this->setter = setter;
		return *this;
	}

	operator TYPE() const {
		return this->get();
	}

    TYPE& operator()() const {
		return const_cast<TYPE&>(this->get());
	}

	Property<CLS, TYPE> operator=(TYPE value) {
		this->set(value);
		return *this;
	}

	const TYPE& get() const {
		if (this->readable) {
			if (this->getter != nullptr) {
				return (this->object->*(this->getter))(*this->value);
			}
			else {
				return this->defaultGetter();
			}
		}
		else {
			throw std::exception("This property is not readable.");
		}
	}

	void set(TYPE value) {
		if (this->writable) {
			if (this->setter != nullptr) {
				*this->value = (this->object->*(this->setter))(value);
			}
			else {
				this->defaultSetter(value);
			}
		}
		else {
			throw std::exception("This property is not writable.");
		}
	}

	void lock() {
		while (this->locked) {}
		this->locked = true;
	}

	void unlock() {
		this->locked = false;
	}

private:
	TYPE& defaultGetter() const {
		return *this->value;
	}

	void defaultSetter(TYPE value) {
		*this->value = value;
	}

	CLS *object = nullptr;
	TYPE *value;
	bool readable = true;
	bool writable = true;
	bool locked = false;
	TYPE (CLS::* setter) (TYPE value) = nullptr;
	TYPE (CLS::* getter) (TYPE value) const = nullptr;
};

