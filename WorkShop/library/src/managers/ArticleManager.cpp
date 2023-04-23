//
// Created by student on 26.05.2022.
//

#include "managers/ArticleManager.h"

ArticleManager::ArticleManager()  {

}

ArticleManager::~ArticleManager() {

}

const ArticleRepository &ArticleManager::getArticleRepository() const {
    return articleRepository;
}

void ArticleManager::setArticleRepository(const ArticleRepository &articleRepository) {
    ArticleManager::articleRepository = articleRepository;
}

void ArticleManager::unregisterArticle(const ArticlePtr &article) {
    if (article == nullptr) throw ArticleException(ArticleException::exceptionArticleNullptr);
    articleRepository.removeObject(article);
}

const ArticlePtr ArticleManager::registerTree(const double &basePrice, const string &species, const uint &age, const uint &width, const uint &height) {
    if (basePrice < 0.) throw ArticleException(ArticleException::exceptionNegativePrice);
    if (species.empty()) throw ArticleException(ArticleException::exceptionEmptySpecies);
    if (age < 0) throw ArticleException(ArticleException::exceptionNegativeParam);
    if (width < 0) throw ArticleException(ArticleException::exceptionNegativeParam);
    if (height < 0) throw ArticleException(ArticleException::exceptionNegativeParam);
    ArticlePtr article = make_shared<Tree>(generateId<ArticleRepository>(articleRepository), basePrice, species, age, width, height);
    articleRepository.addObject(article);
    return article;
}

const ArticlePtr ArticleManager::registerBush(const double &basePrice, const string &species, const uint &age, const uint &width, const uint &height) {
    if (basePrice < 0.) throw ArticleException(ArticleException::exceptionNegativePrice);
    if (species.empty()) throw ArticleException(ArticleException::exceptionEmptySpecies);
    if (age < 0) throw ArticleException(ArticleException::exceptionNegativeParam);
    if (width < 0) throw ArticleException(ArticleException::exceptionNegativeParam);
    if (height < 0) throw ArticleException(ArticleException::exceptionNegativeParam);
    ArticlePtr article = make_shared<Bush>(generateId<ArticleRepository>(articleRepository), basePrice, species, age, width, height);
    articleRepository.addObject(article);
    return article;
}

const ArticlePtr ArticleManager::registerSeedling(const double &basePrice, const string &species, const uint &age, const uint &width, const uint &height) {
    if (basePrice < 0.) throw ArticleException(ArticleException::exceptionNegativePrice);
    if (species.empty()) throw ArticleException(ArticleException::exceptionEmptySpecies);
    if (age < 0) throw ArticleException(ArticleException::exceptionNegativeParam);
    if (width < 0) throw ArticleException(ArticleException::exceptionNegativeParam);
    if (height < 0) throw ArticleException(ArticleException::exceptionNegativeParam);
    ArticlePtr article = make_shared<Seedling>(generateId<ArticleRepository>(articleRepository), basePrice, species, age, width, height);
    articleRepository.addObject(article);
    return article;
}

const ArticlePtr ArticleManager::registerSeedBag(const double &basePrice, const string &species, const uint &seedQuantity) {
    if (basePrice < 0.) throw ArticleException(ArticleException::exceptionNegativePrice);
    if (species.empty()) throw ArticleException(ArticleException::exceptionEmptySpecies);
    if (seedQuantity < 0) throw ArticleException(ArticleException::exceptionNegativeParam);
    ArticlePtr article = make_shared<SeedBag>(generateId<ArticleRepository>(articleRepository), basePrice, species, seedQuantity);
    articleRepository.addObject(article);
    return article;
}

const ArticlePtr ArticleManager::registerPesticide(const double &basePrice, const string &manufacturer, const string &name, const bool &requiresPermit) {
    if (basePrice < 0.) throw ArticleException(ArticleException::exceptionNegativePrice);
    if (manufacturer.empty()) throw ArticleException(ArticleException::exceptionEmptyManufacturer);
    if (name.empty()) throw ArticleException(ArticleException::exceptionEmptyName);
    ArticlePtr article = make_shared<Pesticide>(generateId<ArticleRepository>(articleRepository), basePrice, manufacturer, name, requiresPermit);
    articleRepository.addObject(article);
    return article;
}

const ArticlePtr ArticleManager::registerFertilizer(const double &basePrice, const string &manufacturer, const string &name, SegmentType segment) {
    if (basePrice < 0.) throw ArticleException(ArticleException::exceptionNegativePrice);
    if (manufacturer.empty()) throw ArticleException(ArticleException::exceptionEmptyManufacturer);
    if (name.empty()) throw ArticleException(ArticleException::exceptionEmptyName);
    if (segment != A && segment != B && segment != C && segment != D && segment != E && segment != F) throw ArticleException(ArticleException::exceptionWrongSegmentType);
    ArticlePtr article = make_shared<Fertilizer>(generateId<ArticleRepository>(articleRepository), basePrice, manufacturer, name, segment);
    articleRepository.addObject(article);
    return article;
}

const ArticlePtr ArticleManager::registerShears(const double &basePrice, const string &manufacturer, const string &model, const double &length) {
    if (basePrice < 0.) throw ArticleException(ArticleException::exceptionNegativePrice);
    if (manufacturer.empty()) throw ArticleException(ArticleException::exceptionEmptyManufacturer);
    if (model.empty()) throw ArticleException(ArticleException::exceptionEmptyModel);
    if (length < 0.) throw ArticleException(ArticleException::exceptionNegativeParam);
    ArticlePtr article = make_shared<Shears>(generateId<ArticleRepository>(articleRepository), basePrice, manufacturer, model, length);
    articleRepository.addObject(article);
    return article;
}

const ArticlePtr ArticleManager::registerRake(const double &basePrice, const string &manufacturer, const string &model) {
    if (basePrice < 0.) throw ArticleException(ArticleException::exceptionNegativePrice);
    if (manufacturer.empty()) throw ArticleException(ArticleException::exceptionEmptyManufacturer);
    if (model.empty()) throw ArticleException(ArticleException::exceptionEmptyModel);
    ArticlePtr article = make_shared<Rake>(generateId<ArticleRepository>(articleRepository), basePrice, manufacturer, model);
    articleRepository.addObject(article);
    return article;
}

const ArticlePtr ArticleManager::registerShovel(const double &basePrice, const string &manufacturer, const string &model, const double &bladeWidth) {
    if (basePrice < 0.) throw ArticleException(ArticleException::exceptionNegativePrice);
    if (manufacturer.empty()) throw ArticleException(ArticleException::exceptionEmptyManufacturer);
    if (model.empty()) throw ArticleException(ArticleException::exceptionEmptyModel);
    if (bladeWidth < 0.) throw ArticleException(ArticleException::exceptionNegativeParam);
    ArticlePtr article = make_shared<Shovel>(generateId<ArticleRepository>(articleRepository), basePrice, manufacturer, model, bladeWidth);
    articleRepository.addObject(article);
    return article;
}

ArticlePtr ArticleManager::getArticle(const uint &id) {
    if (articleRepository.findById(id) == nullptr) throw ArticleException(ArticleException::exceptionIncorrectId);
    return articleRepository.findById(id);
}

vector<ArticlePtr> ArticleManager::findAllArticles() {
    if (articleRepository.findAll()[0] == nullptr) throw ArticleException(ArticleException::exceptionEmptyRepo);
    return articleRepository.findAll();
}

void ArticleManager::saveData() {
    ofstream file;
    file.open("../../program/include/articleRepo.txt", ios::trunc);
    if(!file.good()) throw ArticleException(ArticleException::exceptionDatabaseWritingError);

    file << articleRepository.compressedObjects();

    if(!file.good()) throw ArticleException(ArticleException::exceptionDatabaseWritingError);
    file.close();
}

void ArticleManager::loadData() {
    ifstream file;
    file.open("../../program/include/articleRepo.txt", ios::in);
    if(!file.good()) throw ArticleException(ArticleException::exceptionDatabaseReadingError);

    char line[256];

    while (!file.eof()) {
        file.getline(line, 256);
        if (strcmp(line, "") == 0) break;
        string _class = "";
        string id = "";
        string basePrice = "";
        uint i = 0;
        for (i; line[i] != ';'; i++)
            _class += line[i];
        i++;
        if (_class == "Shovel") {
            for (i; line[i] != ';'; i++)
                id += line[i];
            i++;
            for (i; line[i] != ';'; i++)
                basePrice += line[i];
            i++;
            string manufacturer = "";
            for (i; line[i] != ';'; i++)
                manufacturer += line[i];
            i++;
            string model = "";
            for (i; line[i] != ';'; i++)
                model += line[i];
            i++;
            string bladeWith = "";
            for (i; line[i] != ';'; i++)
                bladeWith += line[i];

            registerShovel(stod(basePrice),manufacturer,model,stod(bladeWith));
        }

        else if (_class == "Rake") {
            for (i; line[i] != ';'; i++)
                id += line[i];
            i++;
            for (i; line[i] != ';'; i++)
                basePrice += line[i];
            i++;
            string manufacturer = "";
            for (i; line[i] != ';'; i++)
                manufacturer += line[i];
            i++;
            string model = "";
            for (i; line[i] != ';'; i++)
                model += line[i];
            i++;

            registerRake(stod(basePrice),manufacturer,model);
        }

        else if (_class == "Shears") {
            for (i; line[i] != ';'; i++)
                id += line[i];
            i++;
            for (i; line[i] != ';'; i++)
                basePrice += line[i];
            i++;
            string manufacturer = "";
            for (i; line[i] != ';'; i++)
                manufacturer += line[i];
            i++;
            string model = "";
            for (i; line[i] != ';'; i++)
                model += line[i];
            i++;
            string length = "";
            for (i; line[i] != ';'; i++)
                length += line[i];

            registerShears(stod(basePrice),manufacturer,model,stod(length));
        }

        else if (_class == "Fertilizer") {
            for (i; line[i] != ';'; i++)
                id += line[i];
            i++;
            for (i; line[i] != ';'; i++)
                basePrice += line[i];
            i++;
            string manufacturer = "";
            for (i; line[i] != ';'; i++)
                manufacturer += line[i];
            i++;
            string name = "";
            for (i; line[i] != ';'; i++)
                name += line[i];
            i++;
            string type = "";
            for (i; line[i] != ';'; i++)
                type += line[i];
            SegmentType sup;
            if (type == "A") sup = A;
            else if (type == "B") sup = B;
            else if (type == "C") sup = C;
            else if (type == "D") sup = D;
            else if (type == "E") sup = E;
            else if (type == "F") sup = F;

            registerFertilizer(stod(basePrice),manufacturer,name,sup);
        }

        else if (_class == "Pesticide") {
            for (i; line[i] != ';'; i++)
                id += line[i];
            i++;
            for (i; line[i] != ';'; i++)
                basePrice += line[i];
            i++;
            string manufacturer = "";
            for (i; line[i] != ';'; i++)
                manufacturer += line[i];
            i++;
            string name = "";
            for (i; line[i] != ';'; i++)
                name += line[i];
            i++;
            string permit = "";
            for (i; line[i] != ';'; i++)
                permit += line[i];

            registerPesticide(stod(basePrice),manufacturer,name, stoi(permit));
        }

        else if (_class == "SeedBag") {
            for (i; line[i] != ';'; i++)
                id += line[i];
            i++;
            for (i; line[i] != ';'; i++)
                basePrice += line[i];
            i++;
            string species = "";
            for (i; line[i] != ';'; i++)
                species += line[i];
            i++;
            string seedQuantity = "";
            for (i; line[i] != ';'; i++)
                seedQuantity += line[i];

            registerSeedBag(stod(basePrice), species, stoi(seedQuantity));
        }

        else if (_class == "Seedling") {
            for (i; line[i] != ';'; i++)
                id += line[i];
            i++;
            for (i; line[i] != ';'; i++)
                basePrice += line[i];
            i++;
            string species = "";
            for (i; line[i] != ';'; i++)
                species += line[i];
            i++;
            string age = "";
            for (i; line[i] != ';'; i++)
                age += line[i];
            i++;
            string width = "";
            for (i; line[i] != ';'; i++)
                width += line[i];
            i++;
            string height = "";
            for (i; line[i] != ';'; i++)
                height += line[i];

            registerSeedling(stod(basePrice), species, stoi(age), stoi(width), stoi(height));
        }

        else if (_class == "Bush") {
            for (i; line[i] != ';'; i++)
                id += line[i];
            i++;
            for (i; line[i] != ';'; i++)
                basePrice += line[i];
            i++;
            string species = "";
            for (i; line[i] != ';'; i++)
                species += line[i];
            i++;
            string age = "";
            for (i; line[i] != ';'; i++)
                age += line[i];
            i++;
            string width = "";
            for (i; line[i] != ';'; i++)
                width += line[i];
            i++;
            string height = "";
            for (i; line[i] != ';'; i++)
                height += line[i];

            registerBush(stod(basePrice), species, stoi(age), stoi(width), stoi(height));
        }

        else if (_class == "Tree") {
            for (i; line[i] != ';'; i++)
                id += line[i];
            i++;
            for (i; line[i] != ';'; i++)
                basePrice += line[i];
            i++;
            string species = "";
            for (i; line[i] != ';'; i++)
                species += line[i];
            i++;
            string age = "";
            for (i; line[i] != ';'; i++)
                age += line[i];
            i++;
            string width = "";
            for (i; line[i] != ';'; i++)
                width += line[i];
            i++;
            string height = "";
            for (i; line[i] != ';'; i++)
                height += line[i];

            registerTree(stod(basePrice), species, stoi(age), stoi(width), stoi(height));
        }
    }
    file.close();
}
