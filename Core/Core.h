#pragma once
#include <vector>

#include "EObject.h"


class Core : public EObject {
    Q_OBJECT

public:
	explicit Core();

	static const unsigned long long int createIdValue();
	static void deleteIdValue(const unsigned long long int value);

private:

	static std::vector<unsigned long long int> ids;
};
