//
// Created by student on 25.05.2022.
//

#ifndef INTRODUCTIONPROJECT_FERTILIZER_H
#define INTRODUCTIONPROJECT_FERTILIZER_H

#include <cstdlib>
#include "Chemical.h"

enum SegmentType{A = 15, B = 14, C = 13, D = 12, E = 11, F = 10};

class Fertilizer : public Chemical{
private:
    SegmentType segment;
public:
    ///
    /// \param id - identification number
    /// \param basePrice - base price of product
    /// \param manufacturer - manufacturer of this article
    /// \param name - model of this article
    /// \param segment - class of fertilizer (A,B,C,D,E,F), for example 'A' mean nitrogen, potassium, potassium - containing only one nutrient component
    /// constructor, destructors, getters and setters ///
    Fertilizer(const uint &id, const double &basePrice, const string &manufacturer, const string &name, SegmentType segment);
    virtual ~Fertilizer();
    SegmentType getSegment() const;
    void setSegment(SegmentType segment);
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


#endif //INTRODUCTIONPROJECT_FERTILIZER_H
