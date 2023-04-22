//
// Created by student on 28.05.2022.
//

#ifndef GARDENSHOP_BASEPRICEPREDICATE_H
#define GARDENSHOP_BASEPRICEPREDICATE_H
#include "model/Article.h"
#include "typedefs.h"
#include <string>

using namespace std;

class BasePricePredicate {
private:
    double basePrice;
public:
    /// this is the predicate with which we will search for objects in repositories by base Price
    /// \param basePrice - base price of product
    explicit BasePricePredicate(double basePrice);
    virtual ~BasePricePredicate();
    /// call operator overload
    /// \param ptr - pointer to the Article which the method will check
    /// \return - whether it found a match | if yes = 1, else = 0
    bool operator()(const ArticlePtr &ptr) const;
};


#endif //GARDENSHOP_BASEPRICEPREDICATE_H
