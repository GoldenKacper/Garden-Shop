//
// Created by student on 25.05.2022.
//
#include <iostream>
#include "typedefs.h"
#include <boost/date_time.hpp>
#include "managers/ClientManager.h"
#include "managers/ArticleManager.h"
#include "managers/ReceiptManager.h"

using namespace std;
namespace pt = boost::posix_time;

int main(){
    cout << "Jest OK\n";

    ClientManager clientManager;
    ArticleManager articleManager;
    ReceiptManager receiptManager;

    clientManager.loadData();
    articleManager.loadData();
    receiptManager.loadData();

    /*ArticlePtr a4 = articleManager.registerSeedBag(1.5, "tulip", 2);
    //articleManager.saveData();

    ReceiptPtr r1 = receiptManager.getReceipt(1);
    receiptManager.addToReceipt(r1, a4);*/
    /*ClientPtr c2 = clientManager.registerClient("Tomasz", "Duda");
    ArticlePtr a3 = articleManager.registerBush(12.4,"Berry",7,30,200);
    ReceiptPtr r2 = receiptManager.addReceipt(pt::second_clock::local_time(), c2, a3);

    ClientPtr c1 = clientManager.registerClient("Bartek", "Wojtaszek");
    ArticlePtr a1 = articleManager.registerTree(12.4,"Oak",16,50,2300);
    ArticlePtr a2 = articleManager.registerShovel(123.006, "PlArmy", "Saper", 5.8);
    ReceiptPtr r1 = receiptManager.addReceipt(pt::second_clock::local_time(), c1, a1);
    receiptManager.addToReceipt(r1,a2);*/

    clientManager.saveData();
    articleManager.saveData();
    receiptManager.saveData();


    /*
    clientManager.saveData();
    articleManager.saveData();
    receiptManager.saveData();*/

    //articleManager.loadData();
    //ArticlePtr a2 = articleManager.registerShovel(123.006, "PlArmy", "Saper", 5.8);
    //clientManager.loadData();
    //ClientPtr c2 = clientManager.registerClient("Kinga", "Radwanska",1);
    /*
    ClientPtr c1 = clientManager.registerClient("Bartek", "Wojtaszek");
    ClientPtr c2 = clientManager.registerClient("Tomasz", "Duda");
    ArticlePtr a1 = articleManager.registerTree(12.4,"Oak",16,50,2300);
    ArticlePtr a2 = articleManager.registerShovel(123.006, "PlArmy", "Saper", 5.8);
    ArticlePtr a3 = articleManager.registerBush(12.4,"Berry",7,30,200);
    ArticlePtr a4 = articleManager.registerSeedBag(1.5, "tulip", 2);
    ReceiptPtr r1 = receiptManager.addReceipt(pt::second_clock::local_time(), c1, a1);
    ReceiptPtr r2 = receiptManager.addReceipt(pt::second_clock::local_time(), c2, a2);
    receiptManager.addToReceipt(r1, a3);
    receiptManager.addToReceipt(r1, a4);
    receiptManager.addToReceipt(r2, a1);
    cout << "Test 1\n";
    cout << receiptManager.getReceiptRepository().report() << endl;
    vector<ReceiptPtr> reTab1 = receiptManager.getArticleReceipts(a1);
    cout << "Test 2\n";
    for (auto & r : reTab1) cout << r->getInfo();
    vector<ReceiptPtr> reTab2 = receiptManager.getClientReceipts(c2);
    cout << "\nTest 3\n";
    for (auto & r : reTab2) cout << r->getInfo();
    ObjectPredicate<ReceiptPtr> objectPredicate(r1);
    vector<ReceiptPtr> reTab3 = receiptManager.findReceipts(objectPredicate);
    cout << "\nTest 4\n";
    for (auto & r : reTab3) cout << r->getInfo();

    cout << "\nWszystko działa!!!\n";

    cout << clientManager.getClient(1)->compressedObject() << endl;
    cout << clientManager.getClientRepository().compressedObjects() << endl;
     */

    //clientManager.saveData();
    //cout << clientManager.getClientRepository().report() << endl;


    //cout << articleManager.getArticleRepository().report();
    //articleManager.saveData();

    //receiptManager.saveData();
    cout << receiptManager.getReceiptRepository().report() << endl;


    return 0;
}
