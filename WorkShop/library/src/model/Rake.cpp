//
// Created by student on 25.05.2022.
//

#include "model/Rake.h"

Rake::Rake(const uint &id, const double &basePrice, const string &manufacturer, const string &model)
: Tool(id,basePrice,manufacturer,model) {}

Rake::~Rake() {

}

string Rake::getInfo() {
    stringstream ss;
    ss << ", final price: " << setprecision(numberSize(getPrice())) << getPrice() << endl;
    return "## Rake ##  " + Tool::getInfo() + ss.str();
}

double Rake::getPrice() {
    return getBasePrice();
}

string Rake::compressedObject() {
    stringstream ss;
    ss << ";" << setprecision(numberSize(getPrice())) << getPrice() << endl;
    return "Rake;" + Tool::compressedObject() + ss.str();
}
