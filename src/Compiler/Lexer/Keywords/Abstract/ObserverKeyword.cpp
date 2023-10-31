//
// Created by Daniel on 10/30/23.
//
#include <stdexcept>
#include <iostream>
#include "ObserverKeyword.h"
#include "Observer.h"


void ObserverKeyword::checkAttribute(int *currentWordIndex, std::vector<std::string> text) {
    //std::cout << "updating" << std::endl;

    std::string attribute = text.at(*currentWordIndex + 1);
    if (!attribute.starts_with("@")) {
        if (!attribute.ends_with(';')) {
            throw std::invalid_argument("Invaild Source Code");
        }
        attribute.pop_back();
        Observer::getInst()->updateObservers({attribute});
        *currentWordIndex += 1;
    }
}
