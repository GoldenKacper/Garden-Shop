//
// Created by student on 26.05.2022.
//

#include "repositories/ReceiptRepository.h"

ReceiptRepository::ReceiptRepository() {}

ReceiptRepository::~ReceiptRepository() {

}

const double ReceiptRepository::clientReceiptsBalance(const ClientPtr &client) {
    double result = 0.;
    for (auto & receipt : getRepository())
        if (receipt->getClient()->getId() == client->getId()) result += receipt->getPrice();
    return result;
}

const vector<ReceiptPtr> ReceiptRepository::getClientReceipts(const ClientPtr &client) {
    vector<ReceiptPtr> result;
    for (auto & receipt : getRepository())
        if (receipt->getClient()->getId() == client->getId()) result.push_back(receipt);
    if (result.empty()) result.push_back(nullptr);
    return result;

}

const vector<ReceiptPtr> ReceiptRepository::getArticleReceipts(const ArticlePtr &article) {
    vector<ReceiptPtr> result;
    for (auto & receipt : getRepository())
        for (auto & art : receipt->getArticles())
            if (art->getId() == article->getId()) result.push_back(receipt);
    if (result.empty()) result.push_back(nullptr);
    return result;
}
