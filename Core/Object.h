#pragma once

#include "Property.h"
#include "Identifier.h"
#include "../Asoka/Types/json.h"


class Object {
    PROTECTED_PROP(Object, Identifier, _id, id, {this})
    PROTECTED_PROP(Object, Object*, _owner, owner, nullptr)

public:
    Object(Object* owner = nullptr);
    Object(const Object& other);
    Object(JsonObject& json);
    ~Object();

    virtual JsonObject toJson() const;

};
