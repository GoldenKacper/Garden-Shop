//
// Created by student on 25.05.2022.
//

#include "model/Chemical.h"

Chemical::Chemical(const uint &id, const double &basePrice, const string &manufacturer, const string &name)
: Article(id, basePrice), manufacturer(manufacturer), name(name) {}

Chemical::~Chemical() {

}

const string &Chemical::getManufacturer() const {
    return manufacturer;
}

void Chemical::setManufacturer(const string &manufacturer) {
    Chemical::manufacturer = manufacturer;
}

const string &Chemical::getName() const {
    return name;
}

void Chemical::setName(const string &name) {
    Chemical::name = name;
}

string Chemical::getInfo() {
    stringstream ss;
    ss << ", manufacturer: " << getManufacturer() <<", name: " << getName();
    return Article::getInfo() + ss.str();
}

string Chemical::compressedObject() {
    stringstream ss;
    ss << ";" << getManufacturer() <<";" << getName();
    return Article::compressedObject() + ss.str();
}
