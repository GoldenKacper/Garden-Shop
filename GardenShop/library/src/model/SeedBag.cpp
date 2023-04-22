//
// Created by student on 25.05.2022.
//

#include "model/SeedBag.h"

SeedBag::SeedBag(const uint &id, const double &basePrice, const string &specie, const uint &seedQuantity)
: Plant(id,basePrice,specie),seedQuantity(seedQuantity) {}

SeedBag::~SeedBag() {

}

uint SeedBag::getSeedQuantity() const {
    return seedQuantity;
}

void SeedBag::setSeedQuantity(const uint &seedQuantity) {
    SeedBag::seedQuantity = seedQuantity;
}

string SeedBag::getInfo() {
    stringstream ss;
    ss << ", quantity of seedbags: " << getSeedQuantity() << ", final price: " << setprecision(numberSize(getPrice())) << getPrice() << endl;
    return "## SeedBag ##  " + Plant::getInfo() + ss.str();
}

double SeedBag::getPrice() {
    return getBasePrice() + getSeedQuantity();
}

string SeedBag::compressedObject() {
    stringstream ss;
    ss << ";" << getSeedQuantity() << ";" << setprecision(numberSize(getPrice())) << getPrice() << endl;
    return "SeedBag;" + Plant::compressedObject() + ss.str();
}
