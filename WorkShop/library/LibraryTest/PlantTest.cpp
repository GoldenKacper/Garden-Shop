#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "typedefs.h"
#include "model/Bush.h"
#include "model/Tree.h"
#include "model/Seedling.h"
#include "model/SeedBag.h"


BOOST_AUTO_TEST_SUITE(TestSuitePlant)

    BOOST_AUTO_TEST_CASE(TreeTest) {
        TreePtr t = make_shared<Tree>(1, 15.0, "Gatunek", 3, 10, 20);
        BOOST_REQUIRE_MESSAGE(t->getId() == 1, "Failed to set tree Id in constructor");
        BOOST_REQUIRE_CLOSE(t->getBasePrice(), 15.0, 0.001);
        BOOST_REQUIRE_MESSAGE(t->getSpecies() == "Gatunek", "Failed to set tree species in constructor");
        BOOST_REQUIRE_MESSAGE(t->getAge() == 3, "Failed to set tree age in constructor");
        BOOST_REQUIRE_MESSAGE(t->getWidth() == 10, "Failed to set tree width in constructor");
        BOOST_REQUIRE_MESSAGE(t->getHeight() == 20, "Failed to set tree height in constructor");
        BOOST_REQUIRE_CLOSE(t->getPrice(), 15.0 + (3.0 + 10.0 + 20.0)*2.0, 0.0001);
        t->setBasePrice(1.5);
        t->setSpecies("Niegatunek");
        t->setAge(1);
        t->setWidth(400);
        t->setHeight(200);
        BOOST_REQUIRE_CLOSE(t->getBasePrice(), 1.5, 0.001);
        BOOST_REQUIRE_MESSAGE(t->getSpecies() == "Niegatunek", "Failed to set tree species in setter");
        BOOST_REQUIRE_MESSAGE(t->getAge() == 1, "Failed to set tree age in setter");
        BOOST_REQUIRE_MESSAGE(t->getWidth() == 400, "Failed to set tree width in setter");
        BOOST_REQUIRE_MESSAGE(t->getHeight() == 200, "Failed to set tree height in setter");
        BOOST_REQUIRE_CLOSE(t->getPrice(), 1.5 + (1.0 +400.0 + 200.0)*2.0, 0.0001);
        BOOST_TEST_MESSAGE("Tree test finished successfully!");
    }

    BOOST_AUTO_TEST_CASE(BushTest) {
        BushPtr b = make_shared<Bush>(1, 15.0, "Gatunek", 3, 10, 20);
        BOOST_REQUIRE_MESSAGE(b->getId() == 1, "Failed to set bush Id in constructor");
        BOOST_REQUIRE_CLOSE(b->getBasePrice(),15.0, 0.001);
        BOOST_REQUIRE_MESSAGE(b->getSpecies() == "Gatunek", "Failed to set bush species in constructor");
        BOOST_REQUIRE_MESSAGE(b->getAge() == 3, "Failed to set bush age in constructor");
        BOOST_REQUIRE_MESSAGE(b->getWidth() == 10, "Failed to set bush width in constructor");
        BOOST_REQUIRE_MESSAGE(b->getHeight() == 20, "Failed to set bush height in constructor");
        BOOST_REQUIRE_CLOSE(b->getPrice(), 15.0 + 3.0 + 10.0 + 20.0, 0.0001);
        b->setBasePrice(1.5);
        b->setSpecies("Niegatunek");
        b->setAge(1);
        b->setWidth(400);
        b->setHeight(200);
        BOOST_REQUIRE_CLOSE(b->getBasePrice(),1.5, 0.001);
        BOOST_REQUIRE_MESSAGE(b->getSpecies() == "Niegatunek", "Failed to set bush species in setter");
        BOOST_REQUIRE_MESSAGE(b->getAge() == 1, "Failed to set bush age in setter");
        BOOST_REQUIRE_MESSAGE(b->getWidth() == 400, "Failed to set bush width in setter");
        BOOST_REQUIRE_MESSAGE(b->getHeight() == 200, "Failed to set bush height in setter");
        BOOST_REQUIRE_CLOSE(b->getPrice(), 1.5 + 1.0 + 400.0 + 200.0, 0.0001);
        BOOST_TEST_MESSAGE("Bush test finished successfully!");
    }

    BOOST_AUTO_TEST_CASE(SeedlingTest) {
        SeedlingPtr s = make_shared<Seedling>(1, 15.0, "Gatunek", 3, 10, 20);
        BOOST_REQUIRE_MESSAGE(s->getId() == 1, "Failed to set seedling Id in constructor");
        BOOST_REQUIRE_CLOSE(s->getBasePrice(),15.0, 0.001);
        BOOST_REQUIRE_MESSAGE(s->getSpecies() == "Gatunek", "Failed to set seedling species in constructor");
        BOOST_REQUIRE_MESSAGE(s->getAge() == 3, "Failed to set seedling age in constructor");
        BOOST_REQUIRE_MESSAGE(s->getWidth() == 10, "Failed to set seedling width in constructor");
        BOOST_REQUIRE_MESSAGE(s->getHeight() == 20, "Failed to set seedling height in constructor");
        BOOST_REQUIRE_CLOSE(s->getPrice(), 15.0 + (3.0 + 10.0 + 20.0)/2, 0.0001);
        s->setBasePrice(1.5);
        s->setSpecies("Niegatunek");
        s->setAge(1);
        s->setWidth(400);
        s->setHeight(200);
        BOOST_REQUIRE_CLOSE(s->getBasePrice(),1.5, 0.001);
        BOOST_REQUIRE_MESSAGE(s->getSpecies() == "Niegatunek", "Failed to set seedling species in setter");
        BOOST_REQUIRE_MESSAGE(s->getAge() == 1, "Failed to set seedling age in setter");
        BOOST_REQUIRE_MESSAGE(s->getWidth() == 400, "Failed to set seedling width in setter");
        BOOST_REQUIRE_MESSAGE(s->getHeight() == 200, "Failed to set seedling height in setter");
        BOOST_REQUIRE_CLOSE(s->getPrice(), 1.5 +(1.0 + 400.0 + 200.0)/2.0, 0.0001);
        BOOST_TEST_MESSAGE("Seedling test finished successfully!");
    }

    BOOST_AUTO_TEST_CASE(SeedBagTest) {
        SeedBagPtr s = make_shared<SeedBag>(1, 15.0, "Gatunek",10);
        BOOST_REQUIRE_MESSAGE(s->getId() == 1, "Failed to set seedbag Id in constructor");
        BOOST_REQUIRE_CLOSE(s->getBasePrice(),15.0, 0.001);
        BOOST_REQUIRE_MESSAGE(s->getSpecies() == "Gatunek", "Failed to set seedbag species in constructor");
        BOOST_REQUIRE_MESSAGE(s->getSeedQuantity() == 10, "Failed to set seedbag seed quantity in constructor");
        BOOST_REQUIRE_CLOSE(s->getPrice(), 15.0 + 10.0, 0.0001);
        s->setBasePrice(1.5);
        s->setSpecies("Niegatunek");
        s->setSeedQuantity(200);
        BOOST_REQUIRE_CLOSE(s->getBasePrice(),1.5, 0.001);
        BOOST_REQUIRE_MESSAGE(s->getSpecies() == "Niegatunek", "Failed to set seedbag species in setter");
        BOOST_REQUIRE_MESSAGE(s->getSeedQuantity() == 200, "Failed to set seedbag seed quantity");
        BOOST_REQUIRE_CLOSE(s->getPrice(), 1.5 + 200, 0.0001);
        BOOST_TEST_MESSAGE("Seedbag test finished successfully!");
    }

BOOST_AUTO_TEST_SUITE_END()