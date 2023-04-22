//
// Created by student on 28.05.2022.
//

#include "predicate/FinalPrice.h"

FinalPrice::FinalPrice(double finalPrice) : finalPrice(finalPrice) {}

FinalPrice::~FinalPrice() {

}

bool FinalPrice::operator()(const ArticlePtr &ptr) const {
    return ptr->getPrice() == finalPrice;
}
