//
// Created by student on 25.05.2022.
//

#include "model/Client.h"

Client::Client(uint id, const string &name, const string &surname, bool hasPermit) :
Id(id), name(name), surname(surname), hasPermit(hasPermit) {}

Client::~Client() {

}

uint Client::getId() const {
    return Id;
}

const string &Client::getName() const {
    return name;
}

const string &Client::getSurname() const {
    return surname;
}

bool Client::isHasPermit() const {
    return hasPermit;
}

void Client::setName(const string &name) {
    Client::name = name;
}

void Client::setSurname(const string &surname) {
    Client::surname = surname;
}

void Client::setHasPermit(bool hasPermit) {
    Client::hasPermit = hasPermit;
}

string Client::getInfo() {
    if ( []() -> bool { return true ;}) {
        return "| Personal data | Id: " + to_string(getId()) + ", name: "+getName() + ", surname: " + getSurname() +
               ", permit: " + to_string(isHasPermit()) + "\n";
    }
}

string Client::compressedObject() {
    return to_string(getId()) + ";" + getName() + ";" + getSurname() + ";" + to_string(isHasPermit()) + "\n";
}
