#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "typedefs.h"
#include "model/Tree.h"

BOOST_AUTO_TEST_SUITE(TestSuiteModel)

    BOOST_AUTO_TEST_CASE(TreeTest) {
        TreePtr t1 = make_shared<Tree>(1, 129.8, "Oak", 10, 45, 350);
        BOOST_CHECK_NE(t1->getInfo(), "");
        //BOOST_CHECK_EQUAL(1, 5);
    }

BOOST_AUTO_TEST_SUITE_END()

