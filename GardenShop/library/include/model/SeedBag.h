//
// Created by student on 25.05.2022.
//

#ifndef INTRODUCTIONPROJECT_SEEDBAG_H
#define INTRODUCTIONPROJECT_SEEDBAG_H
#include "Plant.h"

class SeedBag : public Plant{
private:
    uint seedQuantity;
public:
    ///
    /// \param id - identification number
    /// \param basePrice - base price of product
    /// \param specie - specie of plant
    /// \param seedQuantity - quantity of seed bags
    /// constructor, destructors, getters and setters ///
    SeedBag(const uint &id, const double &basePrice, const string &specie, const uint &seedQuantity);
    virtual ~SeedBag();
    uint getSeedQuantity() const;
    void setSeedQuantity(const uint &seedQuantity);
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


#endif //INTRODUCTIONPROJECT_SEEDBAG_H
