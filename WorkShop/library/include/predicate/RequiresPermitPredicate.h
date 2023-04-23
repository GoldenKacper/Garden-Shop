//
// Created by student on 28.05.2022.
//

#ifndef GARDENSHOP_REQUIRESPERMITPREDICATE_H
#define GARDENSHOP_REQUIRESPERMITPREDICATE_H
#include "model/Pesticide.h"
#include "typedefs.h"
#include <string>

using namespace std;

class RequiresPermitPredicate {
private:
    bool requiresPermit;
public:
    /// this is the predicate with which we will search for objects in repositories by Requires Permit
    /// \param requiresPermit - whether you need a permit to buy it
    explicit RequiresPermitPredicate(bool requiresPermit);
    virtual ~RequiresPermitPredicate();
    /// call operator overload
    /// \param ptr - pointer to the Pesticide which the method will check
    /// \return - whether it found a match | if yes = 1, else = 0
    bool operator()(const PesticidePtr &ptr) const;
};


#endif //GARDENSHOP_REQUIRESPERMITPREDICATE_H
