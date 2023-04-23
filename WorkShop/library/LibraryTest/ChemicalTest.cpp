#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "typedefs.h"
#include "model/Fertilizer.h"
#include "model/Pesticide.h"


BOOST_AUTO_TEST_SUITE(TestSuiteChemical)

    // A = 15, B = 14, C = 13, D = 12, E = 11, F = 10
    BOOST_AUTO_TEST_CASE(FertilizerTest) {
        FertilizerPtr f = make_shared<Fertilizer>(1, 15.0, "ChemicalMaker", "BrandName", SegmentType::B);
        BOOST_REQUIRE_MESSAGE(f->getId() == 1, "Failed to set fertilizer Id in constructor");
        BOOST_REQUIRE_CLOSE(f->getBasePrice(), 15.0, 0.001);
        BOOST_REQUIRE_MESSAGE(f->getManufacturer() == "ChemicalMaker", "Failed to set fertilizer manufacturer in constructor");
        BOOST_REQUIRE_MESSAGE(f->getName() == "BrandName", "Failed to set fertilizer name in constructor");
        BOOST_REQUIRE_MESSAGE(f->getSegment() == SegmentType::B, "Failed to set fertilizer grade in constructor");
        BOOST_REQUIRE_CLOSE(f->getPrice(), 15.0  * 1.4, 0.0001);
        f->setBasePrice(1.5);
        f->setManufacturer("NotChemicalMaker");
        f->setName("NotBrandName");
        f->setSegment(SegmentType::F);
        BOOST_REQUIRE_CLOSE(f->getBasePrice(), 1.5, 0.001);
        BOOST_REQUIRE_MESSAGE(f->getManufacturer() == "NotChemicalMaker", "Failed to set fertilizer manufacturer");
        BOOST_REQUIRE_MESSAGE(f->getName() == "NotBrandName", "Failed to set fertilizer name");
        BOOST_REQUIRE_MESSAGE(f->getSegment() == SegmentType::F, "Failed to set fertilizer grade");
        BOOST_REQUIRE_CLOSE(f->getPrice(), 1.5  * 1.0, 0.0001);
        BOOST_TEST_MESSAGE("Tree test finished successfully!");
    }

    BOOST_AUTO_TEST_CASE(PesticideTest) {
        PesticidePtr p = make_shared<Pesticide>(1, 15.0, "ChemicalMaker", "BrandName", true);
        BOOST_REQUIRE_MESSAGE(p->getId() == 1, "Failed to set pesticide Id in constructor");
        BOOST_REQUIRE_CLOSE(p->getBasePrice(), 15.0, 0.001);
        BOOST_REQUIRE_MESSAGE(p->getManufacturer() == "ChemicalMaker", "Failed to set pesticide manufacturer in constructor");
        BOOST_REQUIRE_MESSAGE(p->getName() == "BrandName", "Failed to set pesticide name in constructor");
        BOOST_REQUIRE_MESSAGE(p->isRequiresPermit() == true, "Failed to set permit requirment in constructor");
        BOOST_REQUIRE_CLOSE(p->getPrice(), 15.0 * 2, 0.0001);
        p->setBasePrice(1.5);
        p->setManufacturer("NotChemicalMaker");
        p->setName("NotBrandName");
        p->setRequiresPermit(false);
        BOOST_REQUIRE_CLOSE(p->getBasePrice(), 1.5, 0.001);
        BOOST_REQUIRE_MESSAGE(p->getManufacturer() == "NotChemicalMaker", "Failed to set pesticide manufacturer");
        BOOST_REQUIRE_MESSAGE(p->getName() == "NotBrandName", "Failed to set pesticide name");
        BOOST_REQUIRE_MESSAGE(p->isRequiresPermit() == false, "Failed to set permit requirment");
        BOOST_REQUIRE_CLOSE(p->getPrice(), 1.5, 0.0001);
        BOOST_TEST_MESSAGE("Pesticide test finished successfully!");
    }


BOOST_AUTO_TEST_SUITE_END()