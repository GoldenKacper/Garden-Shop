//
// Created by student on 25.05.2022.
//

#include "model/Pesticide.h"

Pesticide::Pesticide(const uint &id, const double &basePrice, const string &manufacturer, const string &name, const bool &requiresPermit)
: Chemical(id, basePrice, manufacturer, name),requiresPermit(requiresPermit) {}

Pesticide::~Pesticide() {

}

bool Pesticide::isRequiresPermit() const {
    return requiresPermit;
}

void Pesticide::setRequiresPermit(const bool &requiresPermit) {
    Pesticide::requiresPermit = requiresPermit;
}

string Pesticide::getInfo() {
    stringstream ss;
    ss << ", require permit: " << isRequiresPermit() << ", final price: " <<
    setprecision(numberSize(getPrice())) << getPrice() << endl;
    return "## Pesticide ##  " + Chemical::getInfo() + ss.str();
}

double Pesticide::getPrice() {
    if(isRequiresPermit()){
        return getBasePrice()*2.0;
    }
    return getBasePrice();
}

string Pesticide::compressedObject() {
    stringstream ss;
    ss << ";" << isRequiresPermit() << ";" <<
       setprecision(numberSize(getPrice())) << getPrice() << endl;
    return "Pesticide;" + Chemical::compressedObject() + ss.str();
}
