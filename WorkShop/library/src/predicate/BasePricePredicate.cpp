//
// Created by student on 28.05.2022.
//

#include "predicate/BasePricePredicate.h"

BasePricePredicate::BasePricePredicate(double basePrice) : basePrice(basePrice) {}

BasePricePredicate::~BasePricePredicate() {

}

bool BasePricePredicate::operator()(const ArticlePtr &ptr) const {
    return ptr->getBasePrice() == basePrice;
}
