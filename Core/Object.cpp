#include "Object.h"


Object::Object(Object* owner) {
    _owner = owner;
}

Object::Object(const Object& other) {
    _id = other.id;
    _owner = other.owner;
}

Object::Object(JsonObject& json) {
    // _owner = json["owner"]; ToDo
}

Object::~Object() {

}

JsonObject Object::toJson() const {
    return JsonObject({
        {"id", QString(string::number(id().toNumber()))},
        {"ownerId", QString(string::number(owner()->id().toNumber()))}
    });
}
