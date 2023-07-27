#ifndef EOBJECT_H
#define EOBJECT_H

#include <qobject>

#include "Object.h"


class EObject : public QObject, public Object {
    Q_OBJECT

public:
    EObject(Object* owner = nullptr, QObject* parent = nullptr): QObject(parent), Object(owner) {}
};


#endif // EOBJECT_H
