//
// Created by student on 28.05.2022.
//

#include "predicate/SurnamePredicate.h"

SurnamePredicate::SurnamePredicate(const string &surname) : surname(surname) {}

SurnamePredicate::~SurnamePredicate() {

}

bool SurnamePredicate::operator()(const ClientPtr &ptr) const {
    return ptr->getSurname() == surname;
}
