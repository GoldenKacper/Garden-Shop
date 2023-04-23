//
// Created by student on 25.05.2022.
//

#ifndef INTRODUCTIONPROJECT_CHEMICAL_H
#define INTRODUCTIONPROJECT_CHEMICAL_H

#include <cstdlib>
#include "Article.h"

class Chemical : public Article{
private:
    string manufacturer;
    string name;
public:
    ///
    /// \param id - identification number
    /// \param basePrice - base price of product
    /// \param manufacturer - manufacturer of this article
    /// \param name - name of product
    /// constructor, destructors, getters and setters ///
    Chemical(const uint &id, const double &basePrice, const string &manufacturer, const string &name);
    virtual ~Chemical() = 0;
    const string &getManufacturer() const;
    const string &getName() const;
    void setManufacturer(const string &manufacturer);
    void setName(const string &name);
    /// metods ///
    /// \return Information about this article
    virtual string getInfo() override;
    ///
    /// \return - Compressed information, will be send to database
    virtual string compressedObject() override;
};


#endif //INTRODUCTIONPROJECT_CHEMICAL_H
