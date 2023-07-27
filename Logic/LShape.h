#pragma once

#include "../Core/Object.h"


class LShape : public Object {

public:
    LShape();
    LShape(const Object& other);
    LShape(JsonObject& json);
    ~LShape();

    virtual JsonObject toJson() const override;

};
