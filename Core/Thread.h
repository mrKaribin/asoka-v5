#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <thread>

#define THREADED(lambda): std::thread t(lambda);


class Thread : public QObject
{
    Q_OBJECT

public:
    Thread();

protected:
    virtual void run();

private:

};

#endif // THREAD_H
