//
// Created by student on 26.05.2022.
//

#ifndef GARDENSHOP_AUTONUMERATEID_H
#define GARDENSHOP_AUTONUMERATEID_H
#include "managers/ClientManager.h"
#include "repositories/ClientRepository.h"
#include "typedefs.h"
#include "model/Client.h"
#include <vector>
#include <memory>

///
/// \tparam R - repository object (ClientRepository ArticleRepository ReceiptRepository)
/// \param repository - class repository
/// \return - unique Id
template<class R>
uint generateId(const R &repository) {
    uint quantity = repository.getRepository().size();
    vector<uint> ids1;
    for (int i = 0; i < quantity; i++) ids1.push_back(repository.getRepository()[i]->getId());
    uint *ids = new uint [quantity + 1];
    for (int i = 0; i < quantity; i++) ids[ids1[i]] = 1;
    ids[quantity + 1] = 0;
    for (int i = 1; i <= quantity + 1; i++) {
        if (ids[i] == 0) {
            delete[] ids;
            return i;
        }
    }
}

#endif //GARDENSHOP_AUTONUMERATEID_H
