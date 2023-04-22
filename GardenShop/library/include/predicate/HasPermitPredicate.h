//
// Created by student on 28.05.2022.
//

#ifndef GARDENSHOP_HASPERMITPREDICATE_H
#define GARDENSHOP_HASPERMITPREDICATE_H
#include "model/Client.h"
#include "typedefs.h"
#include <string>

using namespace std;

class HasPermitPredicate {
private:
    bool hasPermit;
public:
    /// this is the predicate with which we will search for objects in repositories by Permit
    /// \param hasPermit - Does person have permit for buying special chemicals
    explicit HasPermitPredicate(bool hasPermit);
    virtual ~HasPermitPredicate();
    /// call operator overload
    /// \param ptr - pointer to the client which the method will check
    /// \return - whether it found a match | if yes = 1, else = 0
    bool operator()(const ClientPtr &ptr) const;
};


#endif //GARDENSHOP_HASPERMITPREDICATE_H
