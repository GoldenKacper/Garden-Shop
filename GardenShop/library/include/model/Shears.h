//
// Created by student on 25.05.2022.
//

#ifndef INTRODUCTIONPROJECT_SHEARS_H
#define INTRODUCTIONPROJECT_SHEARS_H
#include "Tool.h"

class Shears : public Tool{
private:
    double length;
public:
    ///
    /// \param id - identification number
    /// \param basePrice - base price of product
    /// \param manufacturer - manufacturer of this article
    /// \param model - model of this article
    /// \param length - length of shears
    /// constructor, destructors, getters and setters ///
    Shears(const uint &id, const double &basePrice, const string &manufacturer, const string &model, const double &length);
    virtual ~Shears();
    double getLength() const;
    void setLength(const double &length);
    /// metods ///
    /// \return Information about this article
    string getInfo() override;
    ///
    /// \return real (finally) cost of article
    double getPrice() override;
    ///
    /// \return - Compressed information, will be send to database
    virtual string compressedObject() override;
};


#endif //INTRODUCTIONPROJECT_SHEARS_H
