//
// Created by student on 25.05.2022.
//

#ifndef INTRODUCTIONPROJECT_ARTICLEREPOSITORY_H
#define INTRODUCTIONPROJECT_ARTICLEREPOSITORY_H
#include "Repository.h"
#include "model/Article.h"

class ArticleRepository : public Repository<ArticlePtr>{
public:
    ArticleRepository();
    virtual ~ArticleRepository();
};


#endif //INTRODUCTIONPROJECT_ARTICLEREPOSITORY_H
