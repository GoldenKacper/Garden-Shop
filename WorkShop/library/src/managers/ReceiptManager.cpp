//
// Created by student on 26.05.2022.
//

#include "managers/ReceiptManager.h"

ReceiptManager::ReceiptManager() {

}

ReceiptManager::~ReceiptManager() {

}

const ReceiptRepository &ReceiptManager::getReceiptRepository() const {
    return receiptRepository;
}

void ReceiptManager::setReceiptRepository(const ReceiptRepository &receiptRepository) {
    ReceiptManager::receiptRepository = receiptRepository;
}

const ReceiptPtr ReceiptManager::addReceipt(const pt::ptime &time, const ClientPtr &client, const ArticlePtr &article) {
    if (time == pt::not_a_date_time) throw ReceiptException(ReceiptException::exceptionEmptyTime);
    if (client == nullptr) throw ReceiptException(ReceiptException::exceptionClientNullptr);
    if (article == nullptr) throw ReceiptException(ReceiptException::exceptionArticleNullptr);
    ReceiptPtr receipt = make_shared<Receipt>(generateId<ReceiptRepository>(receiptRepository), time, client, article);
    receiptRepository.addObject(receipt);
    return receipt;
}

void ReceiptManager::removeReceipt(const ReceiptPtr &receipt) {
    if (receipt == nullptr) throw ReceiptException(ReceiptException::exceptionReceiptNullptr);
    receiptRepository.removeObject(receipt);
}

const ReceiptPtr ReceiptManager::addToReceipt(const ReceiptPtr &receipt, const ArticlePtr &article) {
    if (receipt == nullptr) throw ReceiptException(ReceiptException::exceptionReceiptNullptr);
    if (article == nullptr) throw ReceiptException(ReceiptException::exceptionArticleNullptr);
    getReceipt(receipt->getId())->addItem(article); // no worries because getReceipt will check whether not return nullptr
    return receipt; // getReceipt(receipt->getId()) I don't know which option is better
}

const ReceiptPtr ReceiptManager::removeWithReceipt(const ReceiptPtr &receipt, const ArticlePtr &article) {
    if (receipt == nullptr) throw ReceiptException(ReceiptException::exceptionReceiptNullptr);
    if (article == nullptr) throw ReceiptException(ReceiptException::exceptionArticleNullptr);
    getReceipt(receipt->getId()); // the call will check for an exception from getReceipt
    if (!checkArticle(receipt, article)) throw ReceiptException(ReceiptException::exceptionArticleNotFound);
    getReceipt(receipt->getId())->removeItem(article);
    return receipt; // getReceipt(receipt->getId()) I don't know which option is better
}

ReceiptPtr ReceiptManager::getReceipt(const uint &id) {
    if (receiptRepository.findById(id) == nullptr) throw ReceiptException(ReceiptException::exceptionReceiptNotFound);
    return receiptRepository.findById(id);
}

bool ReceiptManager::checkArticle(const ReceiptPtr &receipt, const ArticlePtr &article) {
    for (auto &art: receipt->getArticles())
        if (article->getId() == art->getId()) return true;
    return false;
}

vector<ReceiptPtr> ReceiptManager::findAllReceipts() {
    if (receiptRepository.findAll()[0] == nullptr) throw ReceiptException(ReceiptException::exceptionEmptyRepo);
    return receiptRepository.findAll();
}
//
const double ReceiptManager::checkClientReceiptsBalance(const ClientPtr &client) {
    if (client == nullptr) throw ReceiptException(ReceiptException::exceptionClientNullptr);
    if (receiptRepository.clientReceiptsBalance(client) == 0.) throw ReceiptException(ReceiptException::exceptionClientNotFound);
    return receiptRepository.clientReceiptsBalance(client);
}

vector<ReceiptPtr> ReceiptManager::getClientReceipts(const ClientPtr &client) {
    if (client == nullptr) throw ReceiptException(ReceiptException::exceptionClientNullptr);
    if (receiptRepository.getClientReceipts(client)[0] == nullptr) throw ReceiptException(ReceiptException::exceptionClientNotFound);
    return receiptRepository.getClientReceipts(client);
}

vector<ReceiptPtr> ReceiptManager::getArticleReceipts(const ArticlePtr &article) {
    if (article == nullptr) throw ReceiptException(ReceiptException::exceptionArticleNullptr);
    if (receiptRepository.getArticleReceipts(article)[0] == nullptr) throw ReceiptException(ReceiptException::exceptionArticleNotFound);
    return receiptRepository.getArticleReceipts(article);
}

void ReceiptManager::saveData() {
    ofstream file;
    file.open("../../program/include/receiptRepo.txt", ios::trunc);
    if(!file.good()) throw ReceiptException(ReceiptException::exceptionDatabaseWritingError);

    file << receiptRepository.compressedObjects();

    if(!file.good()) throw ReceiptException(ReceiptException::exceptionDatabaseWritingError);
    file.close();
}

void ReceiptManager::loadData() {
    ifstream file;
    file.open("../../program/include/receiptRepo.txt", ios::in);
    if(!file.good()) throw ReceiptException(ReceiptException::exceptionDatabaseReadingError);

    char line[256];

    while (!file.eof()) {
        file.getline(line, 256);
        if (strcmp(line, "") == 0) break;
        string id = "";
        string time = "";
        string articleSize = "";
        string clientId = "";
        uint i = 0;
        for (i; line[i] != ';'; i++)
            id += line[i];
        i++;

        string year = "";
        string month = "";
        string day = "";
        string hour = "";
        string minute = "";
        string second = "";

        for (i; line[i] != '-'; i++)
            year += line[i];
        i++;
        for (i; line[i] != '-'; i++)
            month += line[i];
        i++;
        for (i; line[i] != ' '; i++)
            day += line[i];
        i++;
        for (i; line[i] != ':'; i++)
            hour += line[i];
        i++;
        for (i; line[i] != ':'; i++)
            minute += line[i];
        i++;
        for (i; line[i] != ';'; i++)
            second += line[i];
        i++;
        for (i; line[i] != ';'; i++)
            articleSize += line[i];
        i++;
        for (i; line[i] != ';'; i++)
            clientId += line[i];
        i++;
        int size = stoi(articleSize);
        string* articlesId = new string[size];
        for (int k = 0; k < size; ++k) {
            for (i; line[i] != ';'; i++)
                articlesId[k] += line[i];
            i++;
        }

        ClientManager clientManager;
        clientManager.loadData();
        ClientPtr client = clientManager.getClient(stoi(clientId));

        ArticleManager articleManager;
        articleManager.loadData();
        ArticlePtr article1 = articleManager.getArticle(stoi(articlesId[0]));

        if (month == "Jan") month = "1";
        else if (month == "Feb") month = "2";
        else if (month == "Mar") month = "3";
        else if (month == "Apr") month = "4";
        else if (month == "May") month = "5";
        else if (month == "Jun") month = "6";
        else if (month == "Jul") month = "7";
        else if (month == "Aug") month = "8";
        else if (month == "Sep") month = "9";
        else if (month == "Oct") month = "10";
        else if (month == "Nov") month = "11";
        else if (month == "Dec") month = "12";

        ReceiptPtr receipt = addReceipt(pt::ptime(boost::gregorian::date(stoi(year), stoi(month), stoi(day)),pt::hours(stoi(hour))+pt::minutes(stoi(minute))+pt::seconds(stoi(second))), client, article1);

        for (int j = 1; j < stoi(articleSize); ++j) {
            ArticlePtr article2 = articleManager.getArticle(stoi(articlesId[j]));
            addToReceipt(receipt,article2);
        }

        delete [] articlesId;
    }
    file.close();
}
