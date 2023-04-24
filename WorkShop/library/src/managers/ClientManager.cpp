//
// Created by student on 26.05.2022.
//

#include "managers/ClientManager.h"

ClientManager::ClientManager() {

}

ClientManager::~ClientManager() {

}

const ClientRepository &ClientManager::getClientRepository() const {
    return clientRepository;
}

void ClientManager::setClientRepository(const ClientRepository &clientRepository) {
    ClientManager::clientRepository = clientRepository;
}

const ClientPtr ClientManager::registerClient(const string& name, const string& surname, const bool& hasPermit) {
    if (name.empty()) throw ClientException(ClientException::exceptionEmptyName);
    if (surname.empty()) throw ClientException(ClientException::exceptionEmptySurname);
    ClientPtr client = make_shared<Client>(generateId<ClientRepository>(clientRepository), name, surname, hasPermit);
    if (!client) throw ClientException(ClientException::exceptionEmptyName);
    clientRepository.addObject(client);
    return client;
}

void ClientManager::unregisterClient(const ClientPtr &client) {
    if (client == nullptr) throw ClientException(ClientException::exceptionClientNullptr);
    clientRepository.removeObject(client);
}

ClientPtr ClientManager::getClient(const uint &id) {
    if (clientRepository.findById(id) == nullptr) throw ClientException(ClientException::exceptionIncorrectId);
    return clientRepository.findById(id);
}

vector<ClientPtr> ClientManager::findAllClients() {
    if (clientRepository.findAll()[0] == nullptr) throw ClientException(ClientException::exceptionEmptyRepo);
    return clientRepository.findAll();
}

void ClientManager::saveData() {
    ofstream file;
    file.open("../../program/include/clientRepo.txt", ios::trunc); // /home/student/most_wt_1400_02/GardenShop/WorkShop/program/include/
    if(!file.good()) throw ClientException(ClientException::exceptionDatabaseWritingError);

   file << clientRepository.compressedObjects();

    if(!file.good()) throw ClientException(ClientException::exceptionDatabaseWritingError);
    file.close();
}

void ClientManager::loadData() {
    ifstream file;
    file.open("../../program/include/clientRepo.txt", ios::in);
    if(!file.good()) throw ClientException(ClientException::exceptionDatabaseReadingError);

    char line[256];

    while (!file.eof()) {
        file.getline(line, 256);
        if (strcmp(line, "") == 0) break;
        string id = "";
        string name = "";
        string surname = "";
        string permit = "";
        uint i = 0;
        for (i; line[i] != ';'; i++)
            id += line[i];
        i++;
        for (i; line[i] != ';'; i++)
            name += line[i];
        i++;
        for (i; line[i] != ';'; i++)
            surname += line[i];
        i++;
        for (i; line[i] != ';'; i++)
            permit += line[i];

        registerClient(name,surname,stoi(permit));
    }
    file.close();
}
