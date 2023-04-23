//
// Created by student on 26.05.2022.
//

#ifndef INTRODUCTIONPROJECT_TRUEPREDICATE_H
#define INTRODUCTIONPROJECT_TRUEPREDICATE_H
#include "typedefs.h"

using namespace std;
///
/// \tparam P - should be replaced with a ClientPtr, AtriclePtr or ReceiptPtr
template<class P>
class TruePredicate {
public:
    /// this is the predicate with which we will search for all objects in repositories
    TruePredicate() {}
    ~TruePredicate() {}
    /// call operator overload
    /// must be "const P &ptr", because where it is used the parameter to be inserted is used
    /// the function does nothing with it, but it has to be
    /// \param ptr - pointer to the object which the method will check
    /// \return - always true
    bool operator()(const P &ptr) const {
        return true;
    }
};


#endif //INTRODUCTIONPROJECT_TRUEPREDICATE_H
