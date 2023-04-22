//
// Created by student on 26.05.2022.
//

#ifndef INTRODUCTIONPROJECT_IDPREDICATE_H
#define INTRODUCTIONPROJECT_IDPREDICATE_H
#include "typedefs.h"

using namespace std;
///
/// \tparam P - should be replaced with a ClientPtr, AtriclePtr or ReceiptPtr
template<class P>
class IdPredicate {
private:
    uint Id;
public:
    /// this is the predicate with which we will search for objects in repositories by Id
    /// \param id - identification number
    explicit IdPredicate(uint id) : Id(id) {}
    virtual ~IdPredicate() {}
    /// call operator overload
    /// \param ptr - pointer to the object which the method will check
    /// \return - whether it found a match | if yes = 1, else = 0
    bool operator()(const P &ptr) const {
        return ptr->getId() == Id;
    }
};


#endif //INTRODUCTIONPROJECT_IDPREDICATE_H
