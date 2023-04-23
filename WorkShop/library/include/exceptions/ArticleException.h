//
// Created by student on 25.05.2022.
//

#ifndef INTRODUCTIONPROJECT_ARTICLEEXCEPTION_H
#define INTRODUCTIONPROJECT_ARTICLEEXCEPTION_H
#include "GardenShopException.h"

class ArticleException : public GardenShopException {
public:
    explicit ArticleException(const string &arg);
    static const string exceptionNegativePrice;
    static const string exceptionEmptySpecies;
    static const string exceptionNegativeParam;
    static const string exceptionEmptyManufacturer;
    static const string exceptionEmptyName;
    static const string exceptionEmptyModel;
    static const string exceptionWrongSegmentType;
};


#endif //INTRODUCTIONPROJECT_ARTICLEEXCEPTION_H
