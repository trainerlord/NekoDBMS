//
// Created by Daniel on 10/31/23.
//

#ifndef NEKODBMS_OBSERVER_H
#define NEKODBMS_OBSERVER_H


#include <list>
#include "ObserverKeyword.h"

class Observer {
protected:
    inline static Observer* inst = 0;

public:
    std::vector<ObserverKeyword *> observers;
    void updateObservers(std::vector<std::string> att);
    void awaitAttribute(ObserverKeyword *obs) { Observer::observers.push_back(obs); }

    static Observer *getInst()  {
        if (Observer::inst == nullptr) {
            Observer::inst = new Observer();
        }
        return Observer::inst;
    }
};


#endif //NEKODBMS_OBSERVER_H
