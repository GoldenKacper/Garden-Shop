//
// Created by student on 25.05.2022.
//

#include "exceptions/ArticleException.h"


ArticleException::ArticleException(const string &arg) : GardenShopException(arg) {}

const string ArticleException::exceptionNegativePrice = "You have given negative price, enter a positive number";
const string ArticleException::exceptionEmptySpecies = "You haven't given the Species, you should fill in it";
const string ArticleException::exceptionNegativeParam = "You have given negative number, try give try to enter a positive number";
const string ArticleException::exceptionEmptyManufacturer = "You haven't given the Manufacturer, you should fill in it";
const string ArticleException::exceptionEmptyName = "You haven't given the Name, you should fill in it";
const string ArticleException::exceptionEmptyModel = "You haven't given the Model, you should fill in it";
const string ArticleException::exceptionWrongSegmentType = "You have given wrong SegmentType's param, choose one of these: 'A', 'B', 'C', 'D', 'E', 'F'";

