cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        src/model/Client.cpp include/model/Client.h
        src/exceptions/ClientException.cpp include/exceptions/ClientException.h src/exceptions/ArticleException.cpp include/exceptions/ArticleException.h src/exceptions/ReceiptException.cpp include/exceptions/ReceiptException.h src/model/Article.cpp include/model/Article.h src/model/Plant.cpp include/model/Plant.h src/model/Chemical.cpp include/model/Chemical.h src/model/Tool.cpp include/model/Tool.h src/model/Shovel.cpp include/model/Shovel.h src/model/Rake.cpp include/model/Rake.h src/model/Shears.cpp include/model/Shears.h src/model/Fertilizer.cpp include/model/Fertilizer.h src/model/Pesticide.cpp include/model/Pesticide.h src/model/SeedBag.cpp include/model/SeedBag.h src/model/SproutedPlant.cpp include/model/SproutedPlant.h src/model/Seedling.cpp include/model/Seedling.h src/model/Bush.cpp include/model/Bush.h src/model/Tree.cpp include/model/Tree.h src/model/Receipt.cpp include/model/Receipt.h include/repositories/Repository.h src/repositories/ArticleRepository.cpp include/repositories/ArticleRepository.h src/repositories/ClientRepository.cpp include/repositories/ClientRepository.h src/repositories/ReceiptRepository.cpp include/repositories/ReceiptRepository.h include/predicate/IdPredicate.h include/predicate/TruePredicate.h src/managers/ClientManager.cpp include/managers/ClientManager.h src/managers/ArticleManager.cpp include/managers/ArticleManager.h src/managers/ReceiptManager.cpp include/managers/ReceiptManager.h include/AutoNumerateId.h src/AutoNumerateId.cpp include/predicate/NamePredicate.h src/exceptions/GardenShopException.cpp include/exceptions/GardenShopException.h src/predicate/SurnamePredicate.cpp include/predicate/SurnamePredicate.h src/predicate/HasPermitPredicate.cpp include/predicate/HasPermitPredicate.h src/predicate/BasePricePredicate.cpp include/predicate/BasePricePredicate.h src/predicate/FinalPrice.cpp include/predicate/FinalPrice.h src/predicate/RequiresPermitPredicate.cpp include/predicate/RequiresPermitPredicate.h src/predicate/TimePredicate.cpp include/predicate/TimePredicate.h include/predicate/ObjectPredicate.h)

#Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES} include/typedefs.h)

target_include_directories(Library PUBLIC include)
enable_testing()

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)
set(SOURCE_TEST_FILES LibraryTest/master.cpp LibraryTest/PlantTest.cpp LibraryTest/ChemicalTest.cpp LibraryTest/ToolTest.cpp LibraryTest/ClientTest.cpp LibraryTest/ReceiptTest.cpp LibraryTest/PurchaseTest.cpp) # tu w przyszłości będą dodawane pliki źródłowe testów
add_executable (LibraryTest ${SOURCE_TEST_FILES} include/typedefs.h)
target_link_libraries (LibraryTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

add_test(LibraryTest1 LibraryTest
        --report_level=detailed
        --log_level=message
        --color_output=yes
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})