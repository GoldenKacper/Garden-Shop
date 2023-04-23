//
// Created by student on 26.05.2022.
//

#ifndef INTRODUCTIONPROJECT_RECEIPTREPOSITORY_H
#define INTRODUCTIONPROJECT_RECEIPTREPOSITORY_H
#include "Repository.h"
#include "model/Receipt.h"

class ReceiptRepository : public Repository<ReceiptPtr>{
public:
    ReceiptRepository();
    virtual ~ReceiptRepository();
    /// how much the client has spent (on all receipts)
    /// \param client - the client we are checking for
    /// \return total price of all receipts for that person
    const double clientReceiptsBalance(const ClientPtr &client);
    /// returns all receipts on which the client was
    /// \param client - you are looking for receipts for this client
    /// \return - list of found receipts
    const vector<ReceiptPtr> getClientReceipts(const ClientPtr &client);
    /// returns all receipts on which the article was
    /// \param article - you are looking for receipts for this article
    /// \return - list of found receipts
    const vector<ReceiptPtr> getArticleReceipts(const ArticlePtr &article);
};


#endif //INTRODUCTIONPROJECT_RECEIPTREPOSITORY_H
