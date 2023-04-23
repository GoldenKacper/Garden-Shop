//
// Created by student on 26.05.2022.
//

#ifndef INTRODUCTIONPROJECT_CLIENTMANAGER_H
#define INTRODUCTIONPROJECT_CLIENTMANAGER_H
#include "repositories/ClientRepository.h"
#include "exceptions/ClientException.h"
#include "AutoNumerateId.h"
#include "typedefs.h"
#include <string>

#include <fstream>
#include <cstring>

using namespace std;

class ClientManager {
private:
    ClientRepository clientRepository;
public:
    /// class responsible for client logic
    /// constructor, destructors, getters and setters ///
    ClientManager();
    ~ClientManager();
    const ClientRepository &getClientRepository() const;
    void setClientRepository(const ClientRepository &clientRepository);
    /// metods ///
    /// this metod create Client and add his to the Repository
    /// \param name - first name of person
    /// \param surname - suranme of person
    /// \param hasPermit - Does person have permit for buying special chemicals (not required)
    /// \return pointer to created Client
    const ClientPtr registerClient(const string &name, const string &surname, const bool &hasPermit = false);
    /// this metod remove given client with repository
    /// \param client - this client will be remove with repo
    void unregisterClient(const ClientPtr &client); //how do you remove 'const' and '&'
    /// search for client by Id
    /// \param id - identification number
    /// \return client who has the such id
    ClientPtr getClient(const uint &id);
    /// implementation of this metod is in this file
    /// method with which you can search how you want in the repository
    /// \tparam P - the predicate class you want to use
    /// \param predicate - already the specific predicate
    /// \return - list of clients found
    template<class P>
    vector<ClientPtr> findClients(const P &predicate);
    ///
    /// \return all clients of the repository
    vector<ClientPtr> findAllClients();
    /// saves data in the database
    void saveData();
    /// loads data from the database
    void loadData();
};

template<class P>
vector<ClientPtr> ClientManager::findClients(const P &predicate) {
    if (clientRepository.findBy(predicate)[0] == nullptr) throw ClientException(ClientException::exceptionEmptyRepo);
    return clientRepository.findBy(predicate);
}


#endif //INTRODUCTIONPROJECT_CLIENTMANAGER_H
