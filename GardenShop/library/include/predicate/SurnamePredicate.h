//
// Created by student on 28.05.2022.
//

#ifndef GARDENSHOP_SURNAMEPREDICATE_H
#define GARDENSHOP_SURNAMEPREDICATE_H
#include "model/Client.h"
#include "typedefs.h"
#include <string>

using namespace std;

class SurnamePredicate {
private:
    string surname;
public:
    /// this is the predicate with which we will search for objects in repositories by Surname
    /// \param surname - suranme of person
    explicit SurnamePredicate(const string &surname);
    virtual ~SurnamePredicate();
    /// call operator overload
    /// \param ptr - pointer to the Client which the method will check
    /// \return - whether it found a match | if yes = 1, else = 0
    bool operator()(const ClientPtr &ptr) const;
};


#endif //GARDENSHOP_SURNAMEPREDICATE_H
