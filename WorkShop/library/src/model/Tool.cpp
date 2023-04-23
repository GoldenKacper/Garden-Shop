//
// Created by student on 25.05.2022.
//

#include "model/Tool.h"

Tool::Tool(const uint &id, const double &basePrice, const string &manufacturer, const string &model) :
Article(id, basePrice),manufacturer(manufacturer),model(model) {}

Tool::~Tool() {

}

const string &Tool::getManufacturer() const {
    return manufacturer;
}

const string &Tool::getModel() const {
    return model;
}

void Tool::setManufacturer(const string &manufacturer) {
    Tool::manufacturer = manufacturer;
}

void Tool::setModel(const string &model) {
    Tool::model = model;
}

string Tool::getInfo() {
    stringstream ss;
    ss <<  ", manufacturer: " << getManufacturer() <<", model: " << getModel();
    return Article::getInfo() + ss.str();
}

string Tool::compressedObject() {
    stringstream ss;
    ss <<  ";" << getManufacturer() <<";" << getModel();
    return Article::compressedObject() + ss.str();
}
