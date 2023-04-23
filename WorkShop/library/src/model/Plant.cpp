//
// Created by student on 25.05.2022.
//

#include "model/Plant.h"

Plant::Plant(const uint &id, const double &basePrice, const string &specie)
: Article(id, basePrice), specie(specie) {}

Plant::~Plant() {

}

const string &Plant::getSpecies() const {
    return specie;
}

void Plant::setSpecies(const string &specie) {
    Plant::specie = specie;
}

string Plant::getInfo() {
    stringstream ss;
    ss << ", species: " << getSpecies();
    return Article::getInfo() + ss.str();
}

string Plant::compressedObject() {
    stringstream ss;
    ss << ";" << getSpecies();
    return Article::compressedObject() + ss.str();
}
