//
// Created by Daniel on 10/31/23.
//

#include <iostream>
#include "Observer.h"

void Observer::updateObservers(std::vector<std::string> att) {
    std::cout << "Observing: "<< Observer::getInst()->observers.size() << std::endl;
    std::vector<ObserverKeyword *> x = Observer::getInst()->observers;

    for (int i = 0; i < Observer::getInst()->observers.size(); i++) {
        x.at(i)->updateAttribute(att);
    }

    Observer::getInst()->observers.clear();
}

