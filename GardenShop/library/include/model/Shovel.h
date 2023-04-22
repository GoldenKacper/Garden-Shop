//
// Created by student on 25.05.2022.
//

#ifndef INTRODUCTIONPROJECT_SHOVEL_H
#define INTRODUCTIONPROJECT_SHOVEL_H
#include "Tool.h"

class Shovel : public Tool{
private:
    double bladeWidth;
public:
    ///
    /// \param id - identification number
    /// \param basePrice - base price of product
    /// \param manufacturer0 - manufacturer of this article
    /// \param model - model of this article
    /// \param bladeWidth - width of blade [dm^2]
    /// constructor, destructors, getters and setters ///
    Shovel(const uint &id, const double &basePrice, const string &manufacturer, const string &model, const double &bladeWidth);
    virtual ~Shovel();
    double getBladeWidth() const;
    void setBladeWidth(const double &bladeWidth);
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


#endif //INTRODUCTIONPROJECT_SHOVEL_H
