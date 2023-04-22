//
// Created by student on 25.05.2022.
//

#include "model/Seedling.h"

Seedling::Seedling(const uint &id, const double &basePrice, const string &specie, const uint &age, const uint &width,const uint &height)
:SproutedPlant(id, basePrice, specie, age, width, height) {}

Seedling::~Seedling() {

}

string Seedling::getInfo() {
    stringstream ss;
    ss << ", final price: " << setprecision(numberSize(getPrice())) << getPrice() << endl;
    return "## Seedling ##  " + SproutedPlant::getInfo() + ss.str();
}

double Seedling::getPrice() {
    return getBasePrice() + (getAge() + getHeight() + getWidth())/2.0;
}

string Seedling::compressedObject() {
    stringstream ss;
    ss << ";" << setprecision(numberSize(getPrice())) << getPrice() << endl;
    return "Seedling;" + SproutedPlant::compressedObject() + ss.str();
}
