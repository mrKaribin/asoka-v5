#pragma once
#pragma execution_character_set("utf-8")

#include "Debug/ClassTest.h"
#include "../Property.h"



class People {
    PRIVATE_PROP(People, string, name_, name, "")
    PRIVATE_PROP(People, int, age_, age, 0)
    PRIVATE_PROP(People, bool, gender_, gender, false)

    PRIVATE_PROP(People, std::vector<People*>, friends_, friends, {})
    PRIVATE_PROP(People, People*, bestFriend_, bestFriend, nullptr)

public:
	People() {}
	People(string name, int age, bool gender) {
		this->name = name;
		this->age = age;
		this->gender = gender;
	}

	People operator=(People& other) {
		this->name = other.name;
		this->age = other.age;
		this->gender = other.gender;
	}

};


class PropertyTest : public ClassTest {
public:
	PropertyTest() : ClassTest("Property", "Core") {}

	void test() override {
		People people("Колян", 16, true);

		string name = people.name;
		int age = people.age;
		bool gender = people.gender;

		people.name = "Кирилл";
		people.age = 25;
		people.gender = false;
		people.bestFriend = new People("Анастасия", 32, false);

		people.friends().push_back(new People("Даша", 13, false));
		people.friends().push_back(new People("Вова", 34, true));
		people.friends().push_back(new People("Лев", 22, true));

		name = people.name;
		age = people.age;
		gender = people.gender;
		People bestFriend = *people.bestFriend;
		string friendName = people.bestFriend()->name;

		for (auto frnd : people.friends()) {
			string name = frnd->name;
		}
	}
};
