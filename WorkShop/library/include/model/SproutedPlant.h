//
// Created by student on 25.05.2022.
//

#ifndef INTRODUCTIONPROJECT_SPROUTEDPLANT_H
#define INTRODUCTIONPROJECT_SPROUTEDPLANT_H
#include "Plant.h"

class SproutedPlant : public Plant{
private:
    uint age;
    uint width;
    uint height;
public:
    ///
    /// \param id - identification number
    /// \param basePrice - base price of product
    /// \param specie - specie of plant
    /// \param age - age of plant [year]
    /// \param width - width of plant [cm]
    /// \param height - height of plant [cm]
    /// constructor, destructors, getters and setters ///
    SproutedPlant(const uint &id, const double &basePrice, const string &specie, const uint &age, const uint &width, const uint &height);
    virtual ~SproutedPlant() = 0;
    uint getAge() const;
    uint getWidth() const;
    uint getHeight() const;
    void setAge(const uint &age);
    void setWidth(const uint &width);
    void setHeight(const uint &height);
    /// metods ///
    /// \return Information about this article
    virtual string getInfo() override;
    ///
    /// \return - Compressed information, will be send to database
    virtual string compressedObject() override;
};


#endif //INTRODUCTIONPROJECT_SPROUTEDPLANT_H
