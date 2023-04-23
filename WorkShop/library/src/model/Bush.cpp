//
// Created by student on 25.05.2022.
//

#include "model/Bush.h"

Bush::Bush(const uint &id, const double &basePrice, const string &specie, const uint &age, const uint &width,const uint &height)
           : SproutedPlant(id, basePrice, specie, age, width, height) {}

Bush::~Bush() {

}

string Bush::getInfo() {
    stringstream ss;
    ss << ", final price: " << setprecision(numberSize(getPrice())) << getPrice() << endl;
    return "## Bush ##  " + SproutedPlant::getInfo() + ss.str();
}

double Bush::getPrice() {
    return getBasePrice() + getAge() + getHeight() + getWidth();
}

string Bush::compressedObject() {
    stringstream ss;
    ss << ";" << setprecision(numberSize(getPrice())) << getPrice() << endl;
    return "Bush;" + SproutedPlant::compressedObject() + ss.str();
}
