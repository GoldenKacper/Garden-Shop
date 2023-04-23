//
// Created by student on 25.05.2022.
//

#include "model/Shears.h"

Shears::Shears(const uint &id, const double &basePrice, const string &manufacturer, const string &model, const double &length)
        : Tool(id, basePrice, manufacturer, model), length(length) {}

Shears::~Shears() {

}

double Shears::getLength() const {
    return length;
}

void Shears::setLength(const double &length) {
    Shears::length = length;
}

string Shears::getInfo() {
    stringstream ss;
    ss << ", length of shears: " << setprecision(numberSize(getLength())) <<
    getLength() << ", final price: " << setprecision(numberSize(getPrice())) << getPrice() << endl;
    return "## Shears ##  " + Tool::getInfo() + ss.str();
}

double Shears::getPrice() {
    return getBasePrice() + getLength();
}

string Shears::compressedObject() {
    stringstream ss;
    ss << ";" << setprecision(numberSize(getLength())) <<
       getLength() << ";" << setprecision(numberSize(getPrice())) << getPrice() << endl;
    return "Shears;" + Tool::compressedObject() + ss.str();
}
