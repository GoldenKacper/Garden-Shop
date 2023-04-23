//
// Created by student on 28.05.2022.
//

#include "exceptions/GardenShopException.h"

GardenShopException::GardenShopException(const string &arg) : logic_error(arg) {}

const string GardenShopException::exceptionEmptyRepo = "This Repository is empty";
const string GardenShopException::exceptionIncorrectId = "You have given Id which isn't in the Repository";
const string GardenShopException::exceptionArticleNullptr = "You haven't given the ArticlePtr or have given nullptr, you should fill in it";
const string GardenShopException::exceptionClientNullptr = "You haven't given the ClientPtr or have given nullptr, you should fill in it";
const string GardenShopException::exceptionReceiptNullptr = "You haven't given the ReceiptPtr or have given nullptr, you should fill in it";
const string GardenShopException::exceptionDatabaseWritingError = "Writing error ;-(";
const string GardenShopException::exceptionDatabaseReadingError = "Reading error ;-(";

