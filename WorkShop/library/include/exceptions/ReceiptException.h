//
// Created by student on 25.05.2022.
//

#ifndef INTRODUCTIONPROJECT_RECEIPTEXCEPTION_H
#define INTRODUCTIONPROJECT_RECEIPTEXCEPTION_H
#include "GardenShopException.h"

class ReceiptException : public GardenShopException{
public:
    explicit ReceiptException(const string &arg);
    static const string exceptionEmptyTime;
    static const string exceptionReceiptNotFound;
    static const string exceptionArticleNotFound;
    static const string exceptionClientNotFound;
};


#endif //INTRODUCTIONPROJECT_RECEIPTEXCEPTION_H
