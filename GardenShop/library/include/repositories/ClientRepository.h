//
// Created by student on 26.05.2022.
//

#ifndef INTRODUCTIONPROJECT_CLIENTREPOSITORY_H
#define INTRODUCTIONPROJECT_CLIENTREPOSITORY_H
#include "Repository.h"
#include "model/Client.h"
#include <string>

class ClientRepository : public Repository<ClientPtr>{
public:
    ClientRepository();
    virtual ~ClientRepository();
};


#endif //INTRODUCTIONPROJECT_CLIENTREPOSITORY_H
