//
// Created by student on 28.05.2022.
//

#ifndef GARDENSHOP_FINALPRICEPREDICATE_H
#define GARDENSHOP_FINALPRICEPREDICATE_H
#include "model/Article.h"
#include "typedefs.h"
#include <string>

using namespace std;

class FinalPricePredicate {
private:
    double finalPrice;
public:
    /// this is the predicate with which we will search for objects in repositories by final Price
    /// \param finalPrice - final price of product
    explicit FinalPricePredicate(double finalPrice);
    virtual ~FinalPricePredicate();
    /// call operator overload
    /// \param ptr - pointer to the Article which the method will check
    /// \return - whether it found a match | if yes = 1, else = 0
    bool operator()(const ArticlePtr &ptr) const;
};


#endif //GARDENSHOP_FINALPRICEPREDICATE_H
