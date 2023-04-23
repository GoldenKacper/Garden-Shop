#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "typedefs.h"
#include "model/Rake.h"
#include "model/Shears.h"
#include "model/Shovel.h"


BOOST_AUTO_TEST_SUITE(TestSuiteTool)

    BOOST_AUTO_TEST_CASE(RakeTest) {
        RakePtr r = make_shared<Rake>(1, 15.0, "ToolMaker", "BrandName");
        BOOST_REQUIRE_MESSAGE(r->getId() == 1, "Failed to set rake Id in constructor");
        BOOST_REQUIRE_CLOSE(r->getBasePrice(), 15.0, 0.001);
        BOOST_REQUIRE_MESSAGE(r->getManufacturer() == "ToolMaker", "Failed to set rake manufacturer in constructor");
        BOOST_REQUIRE_MESSAGE(r->getModel() == "BrandName", "Failed to set rake model in constructor");
        BOOST_REQUIRE_CLOSE(r->getPrice(), 15.0, 0.0001);
        r->setBasePrice(1.5);
        r->setManufacturer("NotToolMaker");
        r->setModel("NotBrandName");
        BOOST_REQUIRE_CLOSE(r->getBasePrice(), 1.5, 0.001);
        BOOST_REQUIRE_MESSAGE(r->getManufacturer() == "NotToolMaker", "Failed to set rake manufacturer");
        BOOST_REQUIRE_MESSAGE(r->getModel() == "NotBrandName", "Failed to set rake name");
        BOOST_REQUIRE_CLOSE(r->getPrice(), 1.5, 0.0001);
        BOOST_TEST_MESSAGE("Rake test finished successfully!");
    }

    BOOST_AUTO_TEST_CASE(ShearsTest) {
        ShearsPtr s = make_shared<Shears>(1, 15.0, "ToolMaker", "BrandName", 20.5);
        BOOST_REQUIRE_MESSAGE(s->getId() == 1, "Failed to set shears Id in constructor");
        BOOST_REQUIRE_CLOSE(s->getBasePrice(), 15.0, 0.001);
        BOOST_REQUIRE_MESSAGE(s->getManufacturer() == "ToolMaker", "Failed to set shears manufacturer in constructor");
        BOOST_REQUIRE_MESSAGE(s->getModel() == "BrandName", "Failed to set shears model in constructor");
        BOOST_REQUIRE_CLOSE(s->getLength(), 20.5, 0.001);
        BOOST_REQUIRE_CLOSE(s->getPrice(), 15.0 + 20.5, 0.0001);
        s->setBasePrice(1.5);
        s->setManufacturer("NotToolMaker");
        s->setModel("NotBrandName");
        s->setLength(10.0);
        BOOST_REQUIRE_CLOSE(s->getBasePrice(), 1.5, 0.001);
        BOOST_REQUIRE_MESSAGE(s->getManufacturer() == "NotToolMaker", "Failed to set shears manufacturer");
        BOOST_REQUIRE_MESSAGE(s->getModel() == "NotBrandName", "Failed to set shears name");
        BOOST_REQUIRE_CLOSE(s->getLength(), 10.0, 0.001);
        BOOST_REQUIRE_CLOSE(s->getPrice(), 1.5 + 10.0, 0.0001);
        BOOST_TEST_MESSAGE("Shears test finished successfully!");
    }

    BOOST_AUTO_TEST_CASE(ShovelTest) {
        ShovelPtr s = make_shared<Shovel>(1, 15.0, "ToolMaker", "BrandName", 20.5);
        BOOST_REQUIRE_MESSAGE(s->getId() == 1, "Failed to set shovel Id in constructor");
        BOOST_REQUIRE_CLOSE(s->getBasePrice(), 15.0, 0.001);
        BOOST_REQUIRE_MESSAGE(s->getManufacturer() == "ToolMaker", "Failed to set shovel manufacturer in constructor");
        BOOST_REQUIRE_MESSAGE(s->getModel() == "BrandName", "Failed to set shovel model in constructor");
        BOOST_REQUIRE_CLOSE(s->getBladeWidth(), 20.5, 0.001);
        BOOST_REQUIRE_CLOSE(s->getPrice(), 15.0 * 20.5, 0.0001);
        s->setBasePrice(1.5);
        s->setManufacturer("NotToolMaker");
        s->setModel("NotBrandName");
        s->setBladeWidth(10.0);
        BOOST_REQUIRE_CLOSE(s->getBasePrice(), 1.5, 0.001);
        BOOST_REQUIRE_MESSAGE(s->getManufacturer() == "NotToolMaker", "Failed to set shovel manufacturer");
        BOOST_REQUIRE_MESSAGE(s->getModel() == "NotBrandName", "Failed to set shovel name");
        BOOST_REQUIRE_CLOSE(s->getBladeWidth(), 10.0, 0.001);
        BOOST_REQUIRE_CLOSE(s->getPrice(), 1.5 * 10.0, 0.0001);
        BOOST_TEST_MESSAGE("Shovel test finished successfully!");
    }

BOOST_AUTO_TEST_SUITE_END()

