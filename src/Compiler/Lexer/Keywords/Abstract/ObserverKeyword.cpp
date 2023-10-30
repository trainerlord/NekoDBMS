//
// Created by Daniel on 10/30/23.
//
#include "ObserverKeyword.h"


void ObserverKeyword::updateAttribute(std::vector<std::string> att) {
    this->token->setValue(att);
}

void ObserverKeyword::updateObservers(std::vector<std::string> att) {

    std::vector<ObserverKeyword *>::iterator obs;
    for (obs = ObserverKeyword::observers.begin(); obs !=ObserverKeyword::observers.end(); obs++) {
        (*obs)->updateAttribute(att);
    }

    ObserverKeyword::observers.clear();
}
