//
// Created by student on 25.05.2022.
//

#include "model/Tree.h"

Tree::Tree(const uint &id, const double &basePrice, const string &specie, const uint &age, const uint &width,const uint &height)
: SproutedPlant(id, basePrice, specie, age, width, height) {}

Tree::~Tree() {

}

string Tree::getInfo() {
    stringstream ss;
    ss << ", final price: " << setprecision(numberSize(getPrice())) << getPrice() << endl;
    return "## Tree ##  " + SproutedPlant::getInfo() + ss.str();
}

double Tree::getPrice() {
    return getBasePrice() + (getAge() + getHeight() + getWidth())*2.0;
}

string Tree::compressedObject() {
    stringstream ss;
    ss << ";" << setprecision(numberSize(getPrice())) << getPrice() << endl;
    return "Tree;" + SproutedPlant::compressedObject() + ss.str();
}
