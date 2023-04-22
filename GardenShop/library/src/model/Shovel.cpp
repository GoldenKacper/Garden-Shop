//
// Created by student on 25.05.2022.
//

#include "model/Shovel.h"

Shovel::Shovel(const uint &id, const double &basePrice, const string &manufacturer, const string &model, const double &bladeWidth)
        : Tool(id, basePrice, manufacturer, model), bladeWidth(bladeWidth) {}

Shovel::~Shovel() {

}

double Shovel::getBladeWidth() const {
    return bladeWidth;
}

void Shovel::setBladeWidth(const double &bladeWidth) {
    Shovel::bladeWidth = bladeWidth;
}

string Shovel::getInfo() {
    stringstream ss;
    ss << ", blade width: " << setprecision(numberSize(getBladeWidth())) <<
    getBladeWidth() << ", final price: " << setprecision(numberSize(getPrice())) << getPrice() << endl;
    return "## Shovel ##" + Tool::getInfo() + ss.str();
}

double Shovel::getPrice() {
    return getBasePrice()*getBladeWidth();
}

string Shovel::compressedObject() {
    stringstream ss;
    ss << ";" << setprecision(numberSize(getBladeWidth())) <<
    getBladeWidth() << ";" << setprecision(numberSize(getPrice())) << getPrice() << endl;
    return "Shovel;" + Tool::compressedObject() + ss.str();
}
