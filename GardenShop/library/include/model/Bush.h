//
// Created by student on 25.05.2022.
//

#ifndef INTRODUCTIONPROJECT_BUSH_H
#define INTRODUCTIONPROJECT_BUSH_H
#include "SproutedPlant.h"

class Bush : public SproutedPlant{
public:
    ///
    /// \param id - identification number
    /// \param basePrice - base price of product
    /// \param specie - specie of plant
    /// \param age - age of plant [year]
    /// \param width - width of plant [cm]
    /// \param height - height of plant [cm]
    /// constructor, destructors, getters and setters ///
    Bush(const uint &id, const double &basePrice, const string &specie, const uint &age, const uint &width,const uint &height);
    virtual ~Bush();
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


#endif //INTRODUCTIONPROJECT_BUSH_H
