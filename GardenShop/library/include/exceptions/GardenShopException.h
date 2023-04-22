//
// Created by student on 28.05.2022.
//

#ifndef GARDENSHOP_GARDENSHOPEXCEPTION_H
#define GARDENSHOP_GARDENSHOPEXCEPTION_H
#include <stdexcept>
using namespace std;

class GardenShopException : public logic_error {
public:
    explicit GardenShopException(const string &arg);
    static const string exceptionEmptyRepo;
    static const string exceptionIncorrectId;
    static const string exceptionArticleNullptr;
    static const string exceptionClientNullptr;
    static const string exceptionReceiptNullptr;
    static const string exceptionDatabaseWritingError;
    static const string exceptionDatabaseReadingError;
};


#endif //GARDENSHOP_GARDENSHOPEXCEPTION_H
