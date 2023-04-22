//
// Created by student on 28.05.2022.
//

#ifndef GARDENSHOP_TIMEPREDICATE_H
#define GARDENSHOP_TIMEPREDICATE_H
#include "model/Receipt.h"
#include "typedefs.h"
#include <string>

using namespace std;

class TimePredicate {
private:
    boost::posix_time::ptime purchaseTime;
public:
    /// this is the predicate with which we will search for objects in repositories by Time
    /// \param purchaseTime - time when you buy the product
    explicit TimePredicate(const boost::posix_time::ptime &purchaseTime);
    virtual ~TimePredicate();
    /// call operator overload
    /// \param ptr - pointer to the receipt which the method will check
    /// \return - whether it found a match | if yes = 1, else = 0
    bool operator()(const ReceiptPtr &ptr) const;
};


#endif //GARDENSHOP_TIMEPREDICATE_H
