//
// Created by student on 28.05.2022.
//

#include "predicate/RequiresPermitPredicate.h"

RequiresPermitPredicate::RequiresPermitPredicate(bool requiresPermit) : requiresPermit(requiresPermit) {}

RequiresPermitPredicate::~RequiresPermitPredicate() {

}

bool RequiresPermitPredicate::operator()(const PesticidePtr &ptr) const {
    return ptr->isRequiresPermit() == requiresPermit;
}
