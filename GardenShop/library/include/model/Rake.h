//
// Created by student on 25.05.2022.
//

#ifndef INTRODUCTIONPROJECT_RAKE_H
#define INTRODUCTIONPROJECT_RAKE_H
#include "Tool.h"

class Rake : public Tool{
public:
    ///
    /// \param id - identification number
    /// \param basePrice - base price of product
    /// \param manufacturer - manufacturer of this article
    /// \param model - model of this article
    /// constructor, destructors, getters and setters ///
    Rake(const uint &id, const double &basePrice, const string &manufacturer, const string &model);
    virtual ~Rake();
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


#endif //INTRODUCTIONPROJECT_RAKE_H
