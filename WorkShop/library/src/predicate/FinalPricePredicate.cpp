//
// Created by student on 28.05.2022.
//

#include "predicate/FinalPricePredicate.h"

FinalPricePredicate::FinalPricePredicate(double finalPrice) : finalPrice(finalPrice) {}

FinalPricePredicate::~FinalPricePredicate() {

}

bool FinalPricePredicate::operator()(const ArticlePtr &ptr) const {
    return ptr->getPrice() == finalPrice;
}
