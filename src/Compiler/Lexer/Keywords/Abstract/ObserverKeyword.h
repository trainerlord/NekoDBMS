//
// Created by Daniel on 10/30/23.
//

#ifndef NEKODBMS_OBSERVERKEYWORD_H
#define NEKODBMS_OBSERVERKEYWORD_H


#include "BasicKeyword.h"

class ObserverKeyword: public BasicKeyword {
private:
    Token *token;
protected:
    inline static std::vector<ObserverKeyword *> observers = {};
public:
    ObserverKeyword() = default;
    void awaitAttribute() { ObserverKeyword::observers.push_back(this); }
    void updateAttribute(std::vector<std::string> att);

    static void updateObservers(std::string att);

    static void updateObservers(std::vector<std::string> att);
};


#endif //NEKODBMS_OBSERVERKEYWORD_H
