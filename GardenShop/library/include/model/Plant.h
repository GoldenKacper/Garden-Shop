//
// Created by student on 25.05.2022.
//

#ifndef INTRODUCTIONPROJECT_PLANT_H
#define INTRODUCTIONPROJECT_PLANT_H
#include "Article.h"

class Plant : public Article{
private:
    string specie;
public:
    ///
    /// \param id - identification number
    /// \param basePrice - base price of product
    /// \param specie - specie of plant
    /// constructor, destructors, getters and setters ///
    Plant(const uint &id, const double &basePrice, const string &specie);
    virtual ~Plant() = 0;
    const string &getSpecies() const;
    void setSpecies(const string &specie);
    /// metods ///
    /// \return Information about this article
    virtual string getInfo() override;
    ///
    /// \return - Compressed information, will be send to database
    virtual string compressedObject() override;
};


#endif //INTRODUCTIONPROJECT_PLANT_H
