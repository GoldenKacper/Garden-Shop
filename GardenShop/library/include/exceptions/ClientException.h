//
// Created by student on 25.05.2022.
//

#ifndef INTRODUCTIONPROJECT_CLIENTEXCEPTION_H
#define INTRODUCTIONPROJECT_CLIENTEXCEPTION_H
#include "GardenShopException.h"

class ClientException : public GardenShopException {
public:
    explicit ClientException(const string &arg);
    static const string exceptionEmptyName;
    static const string exceptionEmptySurname;
};


#endif //INTRODUCTIONPROJECT_CLIENTEXCEPTION_H
