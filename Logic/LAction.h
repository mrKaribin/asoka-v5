#ifndef ACTION_H
#define ACTION_H

#include "../Core/eobject.h"


class LActionInstance : public EObject {
public:
    LActionInstance() : EObject() {}

    virtual void run() = 0;

};


template<class CLS, typename RET, typename ARG>
class LAction : public LActionInstance {
public:
    Action(): Action() {}
    Action(): Action() {}

    void init(RET (CLS::*function_)(ARG)) {

    }

private:
    RET (CLS::*function)(ARG) = nullptr;
};


#endif // ACTION_H
