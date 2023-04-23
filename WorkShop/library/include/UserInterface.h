//
// Created by student on 23.04.2023.
//

#ifndef GARDENSHOP_USERINTERFACE_H
#define GARDENSHOP_USERINTERFACE_H
#include <iostream>
#include "typedefs.h"
#include "predicate/HasPermitPredicate.h"
#include "predicate/NamePredicate.h"
#include "predicate/SurnamePredicate.h"
#include "predicate/BasePricePredicate.h"
#include "predicate/FinalPricePredicate.h"
#include "predicate/RequiresPermitPredicate.h"
#include "predicate/TimePredicate.h"
#include "managers/ClientManager.h"
#include "managers/ArticleManager.h"
#include "managers/ReceiptManager.h"

using namespace std;
namespace pt = boost::posix_time;

class UserInterface {
private:
    int choice;
    bool back = false;
    bool end = false;
public:
    void scenario();

    void initMenu();

    void clientMenu();
    void clientPredicateMenu();

    void articleMenu();
    void articlePredicateMenu();

    void receiptMenu();
    void receiptPredicateMenu();
};


#endif //GARDENSHOP_USERINTERFACE_H
