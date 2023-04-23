//
// Created by student on 25.05.2022.
//

#ifndef INTRODUCTIONPROJECT_TYPEDEFS_H
#define INTRODUCTIONPROJECT_TYPEDEFS_H
#include <memory>
#include <functional>


/// includes predicates' libraries
#include "predicate/IdPredicate.h"
#include "predicate/TruePredicate.h"
#include "predicate/NamePredicate.h"
/*
#include "predicate/BasePricePredicate.h"
#include "predicate/FinalPricePredicate.h"
#include "predicate/HasPermitPredicate.h"
#include "predicate/RequiresPermitPredicate.h"
#include "predicate/SurnamePredicate.h"
#include "predicate/TimePredicate.h"
*/

/// foreshadowing class declarations
class Client;
class Receipt;
class Article;
class Tool;
class Chemical;
class Plant;
class Shovel;
class Rake;
class Shears;
class Fertilizer;
class Pesticide;
class SeedBag;
class SproutedPlant;
class Seedling;
class Bush;
class Tree;
class ArticleManager;
class ClientManager;
class ReceiptManager;
class ClientRepository;
class ArticleRepository;
class ReceiptReppository;
class ArticleException;
class ClientException;
class ReceiptException;
/// it is possible that they will be unnecessary things


/// template class won't be working
/*
class Repository;

class IdPredicate;
class TruePredicate;
class NamePredicate;
 */

/// foreshadowing predicates' libraries
/*
class BasePricePredicate;
class FinalPricePredicate;
class HasPermitPredicate;
class RequiresPermitPredicate;
class SurnamePredicate;
class TimePredicate;
*/

/// file with different types of definiton
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Receipt>  ReceiptPtr;
typedef std::shared_ptr<Article> ArticlePtr;
typedef std::shared_ptr<Tool> ToolPtr;
typedef std::shared_ptr<Chemical> ChemicalPtr;
typedef std::shared_ptr<Plant> PlantPtr;
typedef std::shared_ptr<Shovel> ShovelPtr;
typedef std::shared_ptr<Rake> RakePtr;
typedef std::shared_ptr<Shears>  ShearsPtr;
typedef std::shared_ptr<Fertilizer> FertilizerPtr;
typedef std::shared_ptr<Pesticide> PesticidePtr;
typedef std::shared_ptr<SeedBag> SeedBagPtr;
typedef std::shared_ptr<SproutedPlant> SproutedPlantPtr;
typedef std::shared_ptr<Seedling> SeedlingPtr;
typedef std::shared_ptr<Bush> BushPtr;
typedef std::shared_ptr<Tree> TreePtr;
typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;
typedef std::shared_ptr<ArticleRepository> ArticleRepositoryPtr;
typedef std::shared_ptr<ReceiptReppository> ReceiptRepositoryPtr;
typedef std::shared_ptr<ArticleManager> ArticleManagerPtr;
typedef std::shared_ptr<ClientManager> ClientManagerPtr;
typedef std::shared_ptr<ReceiptManager> ReceiptManagerPtr;
typedef std::shared_ptr<ArticleException> ArticleExceptionPtr;
typedef std::shared_ptr<ClientException> ClientExceptionPtr;
typedef std::shared_ptr<ReceiptException> ReceiptExceptionPtr;

/// it is possible that they will be unnecessary things
/// template class won't be working
/*
typedef std::shared_ptr<Repository> RepositoryPtr;
typedef std::shared_ptr<IdPredicate> IdPredicatePtr;
typedef std::shared_ptr<TruePredicate> TruePredicatePtr;
*/

#endif //INTRODUCTIONPROJECT_TYPEDEFS_H
