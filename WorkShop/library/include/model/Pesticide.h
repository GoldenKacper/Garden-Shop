//
// Created by student on 25.05.2022.
//

#ifndef INTRODUCTIONPROJECT_PESTICIDE_H
#define INTRODUCTIONPROJECT_PESTICIDE_H
#include "Chemical.h"

class Pesticide : public Chemical{
private:
    bool requiresPermit;
public:
    ///
    /// \param id - identification number
    /// \param basePrice - base price of product
    /// \param manufacturer - manufacturer of this article
    /// \param name - model of this article
    /// \param requiresPermit - whether you need a permit to buy it
    /// constructor, destructors, getters and setters ///
    Pesticide(const uint &id, const double &basePrice, const string &manufacturer, const string &name, const bool &requiresPermit);
    virtual ~Pesticide();
    bool isRequiresPermit() const;
    void setRequiresPermit(const bool &requiresPermit);
    /// metods ///
    /// \return Information about this article
    virtual string getInfo() override;
    ///
    /// \return real (finally) cost of article
    virtual double getPrice() override;
    ///
    /// \return - Compressed information, will be send to database
    virtual string compressedObject() override;
};


#endif //INTRODUCTIONPROJECT_PESTICIDE_H
