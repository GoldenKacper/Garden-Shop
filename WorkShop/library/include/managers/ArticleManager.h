//
// Created by student on 26.05.2022.
//

#ifndef INTRODUCTIONPROJECT_ARTICLEMANAGER_H
#define INTRODUCTIONPROJECT_ARTICLEMANAGER_H
#include "repositories/ArticleRepository.h"
#include "exceptions/ArticleException.h"
#include "model/Tree.h"
#include "model/Bush.h"
#include "model/Seedling.h"
#include "model/SeedBag.h"
#include "model/Pesticide.h"
#include "model/Fertilizer.h"
#include "model/Shears.h"
#include "model/Rake.h"
#include "model/Shovel.h"
#include "AutoNumerateId.h"
#include "typedefs.h"
#include <string>

#include <fstream>
#include <cstring>

using namespace std;

class ArticleManager {
private:
    ArticleRepository articleRepository;
public:
    /// class responsible for article logic
    /// constructor, destructors, getters and setters ///
    ArticleManager();
    ~ArticleManager();
    const ArticleRepository &getArticleRepository() const;
    void setArticleRepository(const ArticleRepository &articleRepository);
    /// metods ///
    /// this metod remove given article with repository
    /// \param article - this article will be remove with repo
    void unregisterArticle(const ArticlePtr &article);
    /// Register metods
    /// These methods record the given type of article
    /// below are all the parameters of these metods, I think you can match them to the appropriate functions
    /// \param basePrice - base price of product
    /// \param species - specie of plant
    /// \param seedQuantity - quantity of seed bags
    /// \param age - age of plant [year]
    /// \param width - width of plant [cm]
    /// \param height - height of plant [cm]
    /// \param manufacturer - manufacturer of this article
    /// \param name - name of product
    /// \param requiresPermit - whether you need a permit to buy it
    /// \param segment - class of fertilizer (A,B,C,D,E,F), for example 'A' mean nitrogen, potassium, potassium - containing only one nutrient component
    /// \param model - model of this article
    /// \param length - length of shears
    /// \param bladeWidth - width of blade [dm^2]
    /// \return pointer to created Article
    const ArticlePtr registerTree(const double &basePrice, const string &species, const uint &age, const uint &width, const uint &height);
    ///
    const ArticlePtr registerBush(const double &basePrice, const string &species, const uint &age, const uint &width, const uint &height);
    ///
    const ArticlePtr registerSeedling(const double &basePrice, const string &species, const uint &age, const uint &width, const uint &height);
    ///
    const ArticlePtr registerSeedBag(const double &basePrice, const string &species, const uint &seedQuantity);
    ///
    const ArticlePtr registerPesticide(const double &basePrice, const string &manufacturer, const string &name, const bool &requiresPermit = true);
    ///
    const ArticlePtr registerFertilizer(const double &basePrice, const string &manufacturer, const string &name, SegmentType segment);
    ///
    const ArticlePtr registerShears(const double &basePrice, const string &manufacturer, const string &model, const double &length);
    ///
    const ArticlePtr registerRake(const double &basePrice, const string &manufacturer, const string &model);
    ///
    const ArticlePtr registerShovel(const double &basePrice, const string &manufacturer, const string &model, const double &bladeWidth);
    ///
    /// search for article by Id
    /// \param id - identification number
    /// \return article which has the such id
    ArticlePtr getArticle(const uint &id);
    /// implementation of this metod is in this file
    /// method with which you can search how you want in the repository
    /// \tparam P - the predicate class you want to use
    /// \param predicate - already the specific predicate
    /// \return - list of articles found
    template<class P>
    vector<ArticlePtr> findArticles(const P &predicate);
    ///
    /// \return all articles of the repository
    vector<ArticlePtr> findAllArticles();
    /// saves data in the database
    void saveData();
    /// loads data from the database
    void loadData();
};

template<class P>
vector<ArticlePtr> ArticleManager::findArticles(const P &predicate) {
    if (articleRepository.findBy(predicate)[0] == nullptr) throw ArticleException(ArticleException::exceptionEmptyRepo);
    return articleRepository.template findBy(predicate);
}


#endif //INTRODUCTIONPROJECT_ARTICLEMANAGER_H
