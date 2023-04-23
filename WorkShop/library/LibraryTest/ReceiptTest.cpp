#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "typedefs.h"
#include "model/Client.h"
#include "model/Tree.h"
#include "model/Shears.h"
#include "model/Receipt.h"


BOOST_AUTO_TEST_SUITE(TestSuiteReceipt)

    BOOST_AUTO_TEST_CASE(ReceiptTest) {
        ClientPtr c1 = make_shared<Client>(1, "Cname", "Csurname", false);
        ClientPtr c2 = make_shared<Client>(2, "Cname2", "Csurname2", true);
        ShearsPtr s = make_shared<Shears>(1, 15.0, "ToolMaker", "BrandName", 20.5);
        TreePtr t = make_shared<Tree>(1, 15.0, "Gatunek", 3, 10, 20);

        boost::posix_time::ptime t1 = boost::posix_time::ptime(boost::gregorian::date(2015,5,13),boost::posix_time::hours(9)+boost::posix_time::minutes(25));
        boost::posix_time::ptime t2 = boost::posix_time::ptime(boost::gregorian::date(2010,3,25),boost::posix_time::hours(12)+boost::posix_time::minutes(00));

        ReceiptPtr r = make_shared<Receipt>(1,t1,c1,s);
        BOOST_REQUIRE_MESSAGE(r->getId() == 1, "Failed to set receipt Id in constructor");
        BOOST_REQUIRE_MESSAGE(r->getClient() == c1, "Failed to set receipt client in constructor");
        BOOST_REQUIRE_MESSAGE(r->getArticles()[0] == s, "Failed to set receipt article in constructor");
        BOOST_REQUIRE_MESSAGE(r->getPurchaseTime() == t1, "Failed to set receipt purchase time in constructor");
        BOOST_REQUIRE_CLOSE(r->getPrice(), 15.0 + 20.5, 0.0001);

        r->removeItem(s);
        r->removeItem(t);
        r->addItem(t);
        r->setPurchaseTime(t2);
        r->setClient(c2);
        BOOST_REQUIRE_MESSAGE(r->getClient() == c2, "Failed to set receipt client in constructor");
        BOOST_REQUIRE_MESSAGE(r->getArticles()[0] == t, "Failed to set receipt article in constructor");
        BOOST_REQUIRE_MESSAGE(r->getPurchaseTime() == t2, "Failed to set receipt purchase time in constructor");
        BOOST_REQUIRE_CLOSE(r->getPrice(), 15.0 + (3.0 + 10.0 + 20.0)*2.0, 0.0001);

        BOOST_TEST_MESSAGE("Receipt test finished successfully!");
    }

BOOST_AUTO_TEST_SUITE_END()