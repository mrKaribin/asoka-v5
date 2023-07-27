#ifndef JSON_H
#define JSON_H

#include <QJsonObject>

#include "string.h"


class JsonObject : public QJsonObject{
public:
    JsonObject() : QJsonObject() {}
    JsonObject(std::initializer_list<QPair<QString, QJsonValue>> args) : QJsonObject(args) {}


};


#endif // JSON_H
