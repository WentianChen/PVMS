
#ifndef PVMS_Publisher_H
#define PVMS_Publisher_H


#include "Subscriber.h"
#include <list>

class Publisher {
private:
    std::list<Subscriber*> _Subscribers;

public:
    void Register(Subscriber *Subscriber) {
        _Subscribers.push_back(Subscriber);
    }

    void Remove(Subscriber *Subscriber) {
        _Subscribers.remove(Subscriber);
    }

    void Notify() {
        for (auto sub = _Subscribers.begin(); sub != _Subscribers.end(); sub++) {
            (*sub)->Update();
        }
    }

};


#endif //PVMS_Publisher_H
