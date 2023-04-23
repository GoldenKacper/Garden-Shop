//
// Created by student on 28.05.2022.
//

#ifndef GARDENSHOP_OBJECTPREDICATE_H
#define GARDENSHOP_OBJECTPREDICATE_H
#include "typedefs.h"

using namespace std;
///
/// \tparam P - should be replaced with a ClientPtr, AtriclePtr or ReceiptPtr
template<class P>
class ObjectPredicate {
private:
    P objectPtr;
public:
    /// this is the predicate with which we will search for objects in repositories by object
    /// \param objectPtr pointer to specific object
    explicit ObjectPredicate(P objectPtr) : objectPtr(objectPtr) {}
    virtual ~ObjectPredicate() {}
    /// call operator overload
    /// \param ptr - pointer to the object which the method will check
    /// \return - whether it found a match | if yes = 1, else = 0
    bool operator()(const P &ptr) const {
        return ptr == objectPtr;
    }
};


#endif //GARDENSHOP_OBJECTPREDICATE_H
