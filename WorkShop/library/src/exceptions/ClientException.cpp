//
// Created by student on 25.05.2022.
//

#include "exceptions/ClientException.h"

ClientException::ClientException(const string &arg) : GardenShopException(arg) {}

const string ClientException::exceptionEmptyName = "You haven't given the name, you should fill in it";
const string ClientException::exceptionEmptySurname = "You haven't given the surname, you should fill in it";

