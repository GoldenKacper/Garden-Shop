//
// Created by student on 25.05.2022.
//

#include <cstdlib>
#include "model/Article.h"

Article::Article(const uint &id, const double &basePrice) : Id(id), basePrice(basePrice) {}

Article::~Article() {

}

uint Article::getId() const {
    return Id;
}

double Article::getBasePrice() const {
    return basePrice;
}

void Article::setBasePrice(const double &basePrice) {
    Article::basePrice = basePrice;
}

int Article::numberSize(double number) {
    int digits = 2;
    while (number >= 1.) {
        number /= 10;
        digits++;
    }
    return digits;
}

string Article::getInfo() {
    stringstream ss;
    ss << "|  Product information |  Id: " << getId() << ", basic price: " <<
    setprecision(numberSize(getBasePrice())) << getBasePrice();
    return ss.str();
}

string Article::compressedObject() {
    stringstream ss;
    ss << getId() << ";" <<
       setprecision(numberSize(getBasePrice())) << getBasePrice();
    return ss.str();
}
