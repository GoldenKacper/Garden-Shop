//
// Created by student on 25.05.2022.
//

#include "model/Fertilizer.h"

Fertilizer::Fertilizer(const uint &id, const double &basePrice, const string &manufacturer, const string &name, SegmentType segment) : Chemical(id, basePrice, manufacturer, name), segment(segment) {}

Fertilizer::~Fertilizer() {

}

SegmentType Fertilizer::getSegment() const {
    return segment;
}

void Fertilizer::setSegment(SegmentType segment) {
    Fertilizer::segment = segment;
}

string Fertilizer::getInfo() {
    stringstream ss;
    switch (segment) {
        case A:
            ss << ", fertilizer class: A";
            break;
        case B:
            ss << ", fertilizer class: B";
            break;
        case C:
            ss << ", fertilizer class: C";
            break;
        case D:
            ss << ", fertilizer class: D";
            break;
        case E:
            ss << ", fertilizer class: E";
            break;
        case F:
            ss << ", fertilizer class: F";
            break;
    }
    ss << ", final price: " << setprecision(numberSize(getPrice())) <<getPrice() << endl;
    return "## Fertilizer ##  " + Chemical::getInfo() + ss.str();
}

double Fertilizer::getPrice() {
    return getBasePrice()*getSegment()/10.0;
}

string Fertilizer::compressedObject() {
    stringstream ss;
    switch (segment) {
        case A:
            ss << ";A";
            break;
        case B:
            ss << ";B";
            break;
        case C:
            ss << ";C";
            break;
        case D:
            ss << ";D";
            break;
        case E:
            ss << ";E";
            break;
        case F:
            ss << ";F";
            break;
    }
    ss << ";" << setprecision(numberSize(getPrice())) <<getPrice() << endl;
    return "Fertilizer;" + Chemical::compressedObject() + ss.str();
}
