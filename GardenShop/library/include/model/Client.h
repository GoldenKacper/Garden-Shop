//
// Created by student on 25.05.2022.
//

#ifndef WORKSHOP_CLIENT_H
#define WORKSHOP_CLIENT_H
#include <string>
using namespace std;

class Client {
private:
    uint Id;
    string name;
    string surname;
    bool hasPermit;
public:
    ///
    /// \param id - identification number
    /// \param name - first name of person
    /// \param surname - suranme of person
    /// \param hasPermit - Does person have permit for buying special chemicals
    /// constructor, destructors, getters and setters
    Client(uint id, const string &name, const string &surname, bool hasPermit = false);
    ~Client();
    uint getId() const;
    bool isHasPermit() const;
    const string &getSurname() const;
    const string &getName() const;
    void setName(const string &name);
    void setHasPermit(bool hasPermit);
    void setSurname(const string &surname);
    /// metods ///
    /// \return - Information about this client
    string getInfo();
    /// this is the syntax:
    ///  Id + ";" + Name + ";" + Surname + ";" + Permit
    /// \return - Compressed information, will be send to database
    string compressedObject();
};


#endif //WORKSHOP_CLIENT_H
