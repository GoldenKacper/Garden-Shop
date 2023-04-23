//
// Created by student on 25.05.2022.
//

#include "model/SproutedPlant.h"

SproutedPlant::SproutedPlant(const uint &id, const double &basePrice, const string &specie, const uint &age, const uint &width, const uint &height)
: Plant(id, basePrice, specie), age(age), width(width), height(height) {}

SproutedPlant::~SproutedPlant() {

}

uint SproutedPlant::getAge() const {
    return age;
}

void SproutedPlant::setAge(const uint &age) {
    SproutedPlant::age = age;
}

uint SproutedPlant::getWidth() const {
    return width;
}

void SproutedPlant::setWidth(const uint &width) {
    SproutedPlant::width = width;
}

uint SproutedPlant::getHeight() const {
    return height;
}

void SproutedPlant::setHeight(const uint &height) {
    SproutedPlant::height = height;
}

string SproutedPlant::getInfo() {
    stringstream ss;
    ss << ", plant age: " << getAge() << ", plant width: " << getWidth() <<
    ", plant height: " << getHeight();
    return Plant::getInfo() + ss.str();
}

string SproutedPlant::compressedObject() {
    stringstream ss;
    ss << ";" << getAge() << ";" << getWidth() <<
       ";" << getHeight();
    return Plant::compressedObject() + ss.str();
}
