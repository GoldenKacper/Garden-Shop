#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "typedefs.h"
#include "model/Client.h"
#include "model/Receipt.h"
#include "managers/ClientManager.h"
#include "managers/ArticleManager.h"
#include "managers/ReceiptManager.h"
#include "exceptions/GardenShopException.h"


BOOST_AUTO_TEST_SUITE(TestSuitePurchase)

    BOOST_AUTO_TEST_CASE(PurchaseTest) {
        ClientManager cm;
        ArticleManager am;
        ReceiptManager rm;

        cm.registerClient("Cname", "Csurname", false);
        cm.registerClient("Cname2", "Csurname2", true);

        am.registerTree(15.0, "Gatunek", 3, 10, 20);
        am.registerShears(15.0, "ToolMaker", "BrandName", 20.5);
        am.registerPesticide(20.0,"PesticideMaker","Zyklon-B", true);

        boost::posix_time::ptime t1 = boost::posix_time::ptime(boost::gregorian::date(2015,5,13),boost::posix_time::hours(9)+boost::posix_time::minutes(25));
        boost::posix_time::ptime t2 = boost::posix_time::ptime(boost::gregorian::date(2010,3,25),boost::posix_time::hours(12)+boost::posix_time::minutes(00));


        BOOST_REQUIRE_MESSAGE(cm.findAllClients()[0]->getName() == "Cname", "Failed to add client with client manager");
        BOOST_REQUIRE_MESSAGE(cm.findAllClients()[1]->getName() == "Cname2", "Failed to add second client with client manager");

        BOOST_REQUIRE_CLOSE(am.findAllArticles()[0]->getBasePrice(), 15.0, 0.0001);
        BOOST_REQUIRE_CLOSE(am.findAllArticles()[2]->getBasePrice(), 20.0, 0.0001);

        int cid1 = cm.findAllClients()[0]->getId();
        int aid1 = am.findAllArticles()[0]->getId();

        rm.addReceipt(t1,cm.getClient(cid1),am.getArticle(aid1));

        // nie

        BOOST_TEST_MESSAGE("Purchase test finished successfully!");
    }

BOOST_AUTO_TEST_SUITE_END()