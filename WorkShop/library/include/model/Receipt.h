//
// Created by student on 25.05.2022.
//

#ifndef INTRODUCTIONPROJECT_RECEIPT_H
#define INTRODUCTIONPROJECT_RECEIPT_H
#include <memory>
#include <string>
#include <vector>
#include <sstream>
#include "typedefs.h"
#include "model/Client.h"
#include "model/Article.h"
#include <boost/date_time.hpp>

using namespace std;

class Receipt {
private:
    uint Id;
    ClientPtr client;
    vector<ArticlePtr> articles;
    boost::posix_time::ptime purchaseTime;
public:
    ///
    /// \param id - identification number
    /// \param purchaseTime - time when you buy the product
    /// \param client - client who buy the product
    /// \param article - the product that will be added first
    /// constructor, destructors, getters and setters
    Receipt(const uint &id, const boost::posix_time::ptime &purchaseTime, const ClientPtr &client, const ArticlePtr &article);
    ~Receipt();
    uint getId() const;
    const ClientPtr &getClient() const;
    const vector<ArticlePtr> &getArticles() const;
    const boost::posix_time::ptime &getPurchaseTime() const;
    void setClient(const ClientPtr &client);
    void setArticles(const vector<ArticlePtr> &articles);
    void setPurchaseTime(const boost::posix_time::ptime &purchaseTime);
    /// metods ///
    /// \return the total cost of all purchases
    double getPrice();
    ///
    /// \return Information about this receipt (id, time, client info and articles info)
    string getInfo();
    ///
    /// \param article - product which you want to add to the repository
    void addItem(const ArticlePtr &article);
    ///
    /// \param article - product which you want to remove with repository
    void removeItem(const ArticlePtr &article);
    ///
    /// \return - Compressed information, will be send to database
    string compressedObject();
};


#endif //INTRODUCTIONPROJECT_RECEIPT_H
