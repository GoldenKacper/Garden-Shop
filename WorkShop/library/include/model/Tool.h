//
// Created by student on 25.05.2022.
//

#ifndef INTRODUCTIONPROJECT_TOOL_H
#define INTRODUCTIONPROJECT_TOOL_H

#include <cstdlib>
#include "Article.h"

class Tool : public Article{
private:
    string manufacturer;
    string model;
public:
    ///
    /// \param id - identification number
    /// \param basePrice - base price of product
    /// \param manufacturer - manufacturer of this article
    /// \param model - model of this article
    /// constructor, destructors, getters and setters ///
    Tool(const uint &id, const double &basePrice, const string &manufacturer, const string &model);
    virtual ~Tool() = 0;
    const string &getManufacturer() const;
    const string &getModel() const;
    void setModel(const string &model);
    void setManufacturer(const string &manufacturer);
    /// metods ///
    /// \return Information about this article
    virtual string getInfo() override;
    ///
    /// \return - Compressed information, will be send to database
    virtual string compressedObject() override;
};


#endif //INTRODUCTIONPROJECT_TOOL_H
