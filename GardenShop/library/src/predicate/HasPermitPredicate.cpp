//
// Created by student on 28.05.2022.
//

#include "predicate/HasPermitPredicate.h"

HasPermitPredicate::HasPermitPredicate(bool hasPermit) : hasPermit(hasPermit) {}

HasPermitPredicate::~HasPermitPredicate() {

}

bool HasPermitPredicate::operator()(const ClientPtr &ptr) const {
    return ptr->isHasPermit() == hasPermit;
}
