//
// Created by student on 25.05.2022.
//

#include "model/Receipt.h"

Receipt::Receipt(const uint &id, const boost::posix_time::ptime &purchaseTime, const ClientPtr &client,const ArticlePtr &article)
: Id(id), purchaseTime(purchaseTime), client(client){
    articles.push_back(article);
}

Receipt::~Receipt() {

}

const ClientPtr &Receipt::getClient() const {
    return client;
}

void Receipt::setClient(const ClientPtr &client) {
    Receipt::client = client;
}

const vector<ArticlePtr> &Receipt::getArticles() const {
    return articles;
}

void Receipt::setArticles(const vector<ArticlePtr> &articles) {
    Receipt::articles = articles;
}

const boost::posix_time::ptime &Receipt::getPurchaseTime() const {
    return purchaseTime;
}

void Receipt::setPurchaseTime(const boost::posix_time::ptime &purchaseTime) {
    Receipt::purchaseTime = purchaseTime;
}

uint Receipt::getId() const {
    return Id;
}

double Receipt::getPrice() {
    double price = 0;
    for (auto & article : articles) price += article->getPrice();
    return price;
}

string Receipt::getInfo() {
    stringstream time;
    time << getPurchaseTime();
    stringstream total;
    total << setprecision(2) << fixed;
    total << getPrice();
    stringstream articleInfo;
    for (auto & article : articles) articleInfo << article->getInfo();
    return "| Receipt |\nId: " + to_string(getId()) + ", purchase time: " + time.str() + " " +
            getClient()->getInfo() + articleInfo.str() + "TOTAL: "+ total.str() +"\n| End Receipt |\n";
}

void Receipt::addItem(const ArticlePtr &article) {
    articles.push_back(article);
}

void Receipt::removeItem(const ArticlePtr &article) {
    articles.erase(std::remove(articles.begin(),articles.end(),article),articles.end());
}

string Receipt::compressedObject() {
    stringstream time;
    time << getPurchaseTime();
    stringstream articleId;
    for (auto & article : articles) articleId << article->getId()<< ";";
    return to_string(getId()) + ";" + time.str() + ";" + to_string(articles.size()) + ";" +
            to_string(getClient()->getId()) + ";" + articleId.str()+"\n";
}
