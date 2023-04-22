//
// Created by student on 25.05.2022.
//

#ifndef INTRODUCTIONPROJECT_ARTICLE_H
#define INTRODUCTIONPROJECT_ARTICLE_H
#include <memory>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <sstream>

using namespace std;

class Article {
private:
    uint Id;
    double basePrice;
public:
    ///
    /// \param id - identification number
    /// \param basePrice - base price of product
    /// constructor, destructors, getters and setters ///
    Article(const uint &id, const double &basePrice);
    virtual ~Article();
    uint getId() const;
    double getBasePrice() const;
    void setBasePrice(const double &basePrice);
    /// metods ///
    /// \return Information about this article
    virtual string getInfo();
    ///
    /// \return - Compressed information, will be send to database
    virtual string compressedObject();
    ///
    /// \return real (finally) cost of article
    virtual double getPrice() = 0;

protected:
    ///
    /// \param - a double number which you want to count the numbers above 0
    /// \return - number of digits above 0
    int numberSize(double number);
};


#endif //INTRODUCTIONPROJECT_ARTICLE_H
