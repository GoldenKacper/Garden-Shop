//
// Created by student on 26.05.2022.
//

#ifndef INTRODUCTIONPROJECT_RECEIPTMANAGER_H
#define INTRODUCTIONPROJECT_RECEIPTMANAGER_H
#include "managers/ArticleManager.h"
#include "managers/ClientManager.h"
#include "repositories/ReceiptRepository.h"
#include "exceptions/ReceiptException.h"
#include "predicate/ObjectPredicate.h"
#include "AutoNumerateId.h"
#include "typedefs.h"
#include <string>

#include <fstream>
#include <cstring>

using namespace std;
namespace pt = boost::posix_time;

class ReceiptManager {
private:
    ReceiptRepository receiptRepository;
public:
    /// class responsible for client logic
    /// constructor, destructors, getters and setters ///
    ReceiptManager();
    ~ReceiptManager();
    const ReceiptRepository &getReceiptRepository() const;
    void setReceiptRepository(const ReceiptRepository &receiptRepository);
    /// metods ///
    /// this metod create Receipt and add it to the Repository
    /// \param time - time when you buy the product
    /// \param client - client who was buying
    /// \param article - the article he bought
    /// \return pointer to created Receipt
    const ReceiptPtr addReceipt(const pt::ptime &time, const ClientPtr &client, const ArticlePtr &article);
    /// his metod remove given receipt with repository
    /// \param receipt - this receipt will be remove with repo
    void removeReceipt(const ReceiptPtr &receipt);
    /// add a single item to the receipt
    /// \param receipt - the receipt to which you are adding
    /// \param article - the article you are adding
    /// \return pointer to the receipt from the article was added
    const ReceiptPtr addToReceipt(const ReceiptPtr &receipt, const ArticlePtr &article);
    /// removes a single item from the receipt
    /// \param receipt - the receipt which you are removing
    /// \param article - the article you are removing
    /// \return pointer to the receipt from the article was removed
    const ReceiptPtr removeWithReceipt(const ReceiptPtr &receipt, const ArticlePtr &article);
    /// search for receipt by Id
    /// \param id - identification number
    /// \return receipt which has the such id
    ReceiptPtr getReceipt(const uint &id);
    /// implementation of this metod is in this file
    /// method with which you can search how you want in the repository
    /// \tparam P - the predicate class you want to use
    /// \param predicate - already the specific predicate
    /// \return - list of receipts found
    template<class P>
    vector<ReceiptPtr> findReceipts(const P &predicate);
    ///
    /// \return all receipts of the repository
    vector<ReceiptPtr> findAllReceipts();
    /// how much the client has spent (on all receipts)
    /// \param client - the client we are checking for
    /// \return total price of all receipts for that person
    const double checkClientReceiptsBalance(const ClientPtr &client);
    /// returns all receipts on which the client was
    /// \param client - you are looking for receipts for this client
    /// \return - list of found receipts
    vector<ReceiptPtr> getClientReceipts(const ClientPtr &client); // earlier "getAllClientReceipts"
    /// returns all receipts on which the article was
    /// \param article - you are looking for receipts for this article
    /// \return - list of found receipts
    vector<ReceiptPtr> getArticleReceipts(const ArticlePtr &article);
    /// saves data in the database
    void saveData();
    /// loads data from the database
    void loadData();
private:
    /// checks if the article is on the receipt
    /// \param receipt - check in this receipt
    /// \param article - the article you are looking for
    /// \return true - if it there was, false - if it there not was
    bool checkArticle(const ReceiptPtr &receipt, const ArticlePtr &article);
};

template<class P>
vector<ReceiptPtr> ReceiptManager::findReceipts(const P &predicate) {
    if (receiptRepository.template findBy(predicate)[0] == nullptr) throw ReceiptException(ReceiptException::exceptionEmptyRepo);
    return receiptRepository.template findBy(predicate);
}


#endif //INTRODUCTIONPROJECT_RECEIPTMANAGER_H
