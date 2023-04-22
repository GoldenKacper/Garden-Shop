#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "typedefs.h"
#include "model/Client.h"


BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    BOOST_AUTO_TEST_CASE(ClientTest) {
        ClientPtr c = make_shared<Client>(1, "Cname", "Csurname", false);
        BOOST_REQUIRE_MESSAGE(c->getId() == 1, "Failed to set client Id in constructor");
        BOOST_REQUIRE_MESSAGE(c->getName() == "Cname", "Failed to set client name in constructor");
        BOOST_REQUIRE_MESSAGE(c->getSurname() == "Csurname", "Failed to set client surname in constructor");
        BOOST_REQUIRE_MESSAGE(c->isHasPermit() == false, "Failed to set client permit in constructor");
        c->setName("NotCname");
        c->setSurname("NotCsurname");
        c->setHasPermit(true);
        BOOST_REQUIRE_MESSAGE(c->getName() == "NotCname", "Failed to set client name");
        BOOST_REQUIRE_MESSAGE(c->getSurname() == "NotCsurname", "Failed to set client surname");
        BOOST_REQUIRE_MESSAGE(c->isHasPermit() == true, "Failed to set client permit");
        BOOST_TEST_MESSAGE("Client test finished successfully!");
    }

BOOST_AUTO_TEST_SUITE_END()