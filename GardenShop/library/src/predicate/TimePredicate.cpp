//
// Created by student on 28.05.2022.
//

#include "predicate/TimePredicate.h"

TimePredicate::TimePredicate(const boost::posix_time::ptime &purchaseTime) : purchaseTime(purchaseTime) {}

TimePredicate::~TimePredicate() {

}

bool TimePredicate::operator()(const ReceiptPtr &ptr) const {
    return ptr->getPurchaseTime() == purchaseTime;
}
