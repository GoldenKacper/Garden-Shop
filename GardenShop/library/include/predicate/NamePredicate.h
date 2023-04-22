//
// Created by student on 27.05.2022.
//

#ifndef GARDENSHOP_NAMEPREDICATE_H
#define GARDENSHOP_NAMEPREDICATE_H
#include "typedefs.h"
#include <string>

using namespace std;
///
/// \tparam P - should be replaced with a ClientPtr, AtriclePtr or ReceiptPtr
template <class P>
class NamePredicate {
private:
    string name;
public:
    /// this is the predicate with which we will search for objects in repositories by Name
    /// \param name - name of object
    explicit NamePredicate(string name) : name(name) {}
    virtual ~NamePredicate() {}
    /// call operator overload
    /// \param ptr - pointer to the object which the method will check
    /// \return - whether it found a match | if yes = 1, else = 0
    bool operator()(const P &ptr) const {
        return ptr->getName() == name;
    }
};


#endif //GARDENSHOP_NAMEPREDICATE_H
