//
// Created by student on 25.05.2022.
//

#include "exceptions/ReceiptException.h"

ReceiptException::ReceiptException(const string &arg) : GardenShopException(arg) {}

const string ReceiptException::exceptionEmptyTime = "You don't give a purchase time, you should fill in it";
const string ReceiptException::exceptionReceiptNotFound = "there isn't such receipt in the repo";
const string ReceiptException::exceptionArticleNotFound = "there isn't such article in the repo";
const string ReceiptException::exceptionClientNotFound = "there isn't such client in the repo";

