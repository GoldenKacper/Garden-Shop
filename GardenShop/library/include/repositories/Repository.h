//
// Created by student on 25.05.2022.
//

#ifndef INTRODUCTIONPROJECT_REPOSITORY_H
#define INTRODUCTIONPROJECT_REPOSITORY_H
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include "typedefs.h"
#include "predicate/IdPredicate.h"
#include "predicate/TruePredicate.h"

using namespace std;
/// template of repositories clients, articles, receipts
/// \tparam T - T should be replaced with a ClientPtr, AtriclePtr or ReceiptPtr
template<class T>
class Repository {
private:
    vector<T> repository;
public:
    /// at the beginning, the repo is empty
    /// !now it is a abstract class!
    /// how to create repo? --> Repository<ArticlePtr> artRepo; // remember to include all necessary files
    /// constructor, destructors, getters and setters
    Repository();
    virtual ~Repository() = 0;
    const vector<T> &getRepository() const;
    void setRepository(const vector<T> &repository);
    /// metods ///
    /// \return All information about objects in this repository
    string report() const;
    ///
    /// \param object - this object will be add to repo
    void addObject(const T &object);
    ///
    /// \param object - this object will be remove with repo
    void removeObject(const T &object);
    /// ! my masterpiece !
    /// method with which you can search what you want in the repository
    /// \tparam P - the predicate class you want to use
    /// \param predicate - already the specific predicate
    /// \return the vector of objects matching the predicate
    template<class P>
    vector<T> findBy(const P &predicate) const;
    ///
    /// \return all elements of the repository
    vector<T> findAll() const;
    ///
    /// \param id - identification number
    /// \return - object with given id
    T findById(const uint &id);
    ///
    /// \return compressed inforamtion about all clients, this will be send to database
    string compressedObjects() const ;
};

template<class T>
Repository<T>::Repository() {

}

template<class T>
Repository<T>::~Repository() {

}

template<class T>
const vector<T> &Repository<T>::getRepository() const {
    return repository;
}

template<class T>
void Repository<T>::addObject(const T &object) {
    repository.push_back(object);
}

template<class T>
void Repository<T>::removeObject(const T &object) {
    repository.erase(std::remove(repository.begin(),repository.end(),object),repository.end());
}

template<class T>
string Repository<T>::report() const {
    string report = "| Repository | \n";
    for (auto & object : repository) report += object->getInfo();
    return report;
}

template<class T>
template<class P>
vector<T> Repository<T>::findBy(const P &predicate) const {
    vector<T> result;
    for (auto & object : repository) {
        if (predicate(object)) result.push_back(object);
    }
    if (result.empty()) result.push_back(nullptr);
    return result;
}

template<class T>
void Repository<T>::setRepository(const vector<T> &repository) {
    Repository::repository = repository;
}

template<class T>
vector<T> Repository<T>::findAll() const {
    TruePredicate<T> predicate;
    return findBy(predicate);
}

template<class T>
T Repository<T>::findById(const uint &id) {
    IdPredicate<T> predicate(id);
    return findBy(predicate)[0]; // when manager will be existed you will be in 100% sure you will get one result
}

template<class T>
string Repository<T>::compressedObjects() const {
    string compressed = "";
    for (auto & object : repository) compressed += object->compressedObject();
    return compressed;
}


#endif //INTRODUCTIONPROJECT_REPOSITORY_H
