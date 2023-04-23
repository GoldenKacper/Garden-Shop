//
// Created by student on 23.04.2023.
//

#include "UserInterface.h"

void UserInterface::scenario() {
    cout << "Let's start\n";

    ClientManager clientManager;
    ArticleManager articleManager;
    ReceiptManager receiptManager;

    clientManager.loadData();
    articleManager.loadData();
    receiptManager.loadData();

    string name;
    string surname;
    bool permit;
    int id;

    double price;
    string species;
    uint age;
    uint width;
    uint height;
    uint seedQuantity;
    string manufacturer;
    string segmentString;
    SegmentType segment;
    string model;
    double bladeWidth;
    double length;

    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int id2;


    while (!end) {
        initMenu();
        cin >> choice;
        while (choice > 3 || choice < 0) {
            cout << "Wrong Number! Try again\n";
            cin >> choice;
        }

        switch (choice) {
            case 1:
                while (!back) {
                    clientMenu();

                    cin >> choice;
                    while (choice > 5 || choice < 0) {
                        cout << "Wrong Number! Try again\n";
                        cin >> choice;
                    }

                    switch (choice) {
                        case 1:
                            cout << "Now give necessary data\n";
                            cout << "Give name: ";
                            cin >> name;
                            cout << "Give surname ";
                            cin >> surname;
                            cout << "Give permit, write '0' or '1': ";
                            cin >> permit;
                            cout << "Initialize client\n" << clientManager.registerClient(name, surname, permit)->getInfo()
                                 << endl;
                            break;
                        case 2:
                            cout << "Now give necessary data\n";
                            cout << "Give client's id: ";
                            cin >> id;
                            cout << "Unregister client with id = " << id << endl;
                            clientManager.unregisterClient(clientManager.getClient(id));
                            break;
                        case 3:
                            cout << "Now give necessary data\n";
                            cout << "Give client's id: ";
                            cin >> id;
                            cout << "Showing client...\n" << clientManager.getClient(id)->getInfo() <<endl;
                            break;
                        case 4:
                            cout << "Showing all clients\n";
                            cout << clientManager.getClientRepository().report() << endl;
                            break;
                        case 5:
                            clientPredicateMenu();

                            cin >> choice;
                            while (choice > 3 || choice < 1) {
                                cout << "Wrong Number! Try again\n";
                                cin >> choice;
                            }

                            if (choice == 1) {
                                cout << "Now give necessary data\n";
                                cout << "Give the name to search for: ";
                                cin>>name;
                                cout<<"Showing clients...\n";
                                NamePredicate<ClientPtr> namePredicate(name);
                                for (auto & client : clientManager.findClients(namePredicate)) {
                                    cout << client->getInfo();
                                }
                                cout<<endl;
                            } else if (choice == 2) {
                                cout << "Now give necessary data\n";
                                cout << "Give the surname to search for: ";
                                cin>>surname;
                                cout<<"Showing clients...\n";
                                SurnamePredicate surnamePredicate(surname);
                                for (auto & client : clientManager.findClients(surnamePredicate)) {
                                    cout << client->getInfo();
                                }
                                cout<<endl;
                            } else if (choice == 3) {
                                cout << "Now give necessary data\n";
                                cout << "Has permit? if yes, give '1' if no, give '0': ";
                                cin>>permit;
                                cout<<"Showing clients...\n";
                                HasPermitPredicate hasPermitPredicate(permit);
                                for (auto & client : clientManager.findClients(hasPermitPredicate)) {
                                    cout << client->getInfo();
                                }
                                cout<<endl;
                            }
                            break;
                        case 0:
                            cout << "Backing\n";
                            back = true;
                    }
                }
                back = false;
                break;
            case 2:
                while (!back) {
                    articleMenu();

                    cin >> choice;
                    while (choice > 13 || choice < 0) {
                        cout << "Wrong Number! Try again\n";
                        cin >> choice;
                    }

                    switch (choice) {
                        case 1:
                            cout << "Now give necessary data\n";
                            cout << "Give article's id: ";
                            cin >> id;
                            cout << "Unregister article with id = " << id << endl;
                            articleManager.unregisterArticle(articleManager.getArticle(id));
                            break;
                        case 2:
                            cout << "Now give necessary data\n";
                            cout << "Give base price (double): ";
                            cin >> price;
                            cout << "Give species (string): ";
                            cin>>species;
                            cout << "Give age (uint): ";
                            cin>>age;
                            cout << "Give width (uint): ";
                            cin>>width;
                            cout << "Give height (uint): ";
                            cin>>height;
                            cout << "Initialize article\n" << articleManager.registerTree(price, species, age, width, height)->getInfo()
                                 << endl;
                            break;
                        case 3:
                            cout << "Now give necessary data\n";
                            cout << "Give base price (double): ";
                            cin >> price;
                            cout << "Give species (string): ";
                            cin>>species;
                            cout << "Give age (uint): ";
                            cin>>age;
                            cout << "Give width (uint): ";
                            cin>>width;
                            cout << "Give height (uint): ";
                            cin>>height;
                            cout << "Initialize article\n" << articleManager.registerBush(price, species, age, width, height)->getInfo()
                                 << endl;
                            break;
                        case 4:
                            cout << "Now give necessary data\n";
                            cout << "Give base price (double): ";
                            cin >> price;
                            cout << "Give species (string): ";
                            cin>>species;
                            cout << "Give age (uint): ";
                            cin>>age;
                            cout << "Give width (uint): ";
                            cin>>width;
                            cout << "Give height (uint): ";
                            cin>>height;
                            cout << "Initialize article\n" << articleManager.registerSeedling(price, species, age, width, height)->getInfo()
                                 << endl;
                            break;
                        case 5:
                            cout << "Now give necessary data\n";
                            cout << "Give base price (double): ";
                            cin >> price;
                            cout << "Give species (string): ";
                            cin>>species;
                            cout << "Give seed quantity (uint): ";
                            cin>>seedQuantity;
                            cout << "Initialize article\n" << articleManager.registerSeedBag(price, species, seedQuantity)->getInfo()
                                 << endl;
                            break;
                        case 6:
                            cout << "Now give necessary data\n";
                            cout << "Give base price (double): ";
                            cin >> price;
                            cout << "Give manufacturer (string): ";
                            cin>>manufacturer;
                            cout << "Give name (string): ";
                            cin>>name;
                            cout << "Give permit (bool): ";
                            cin>>permit;
                            cout << "Initialize article\n" << articleManager.registerPesticide(price, manufacturer, name, permit)->getInfo()
                                 << endl;
                            break;
                        case 7:
                            cout << "Now give necessary data\n";
                            cout << "Give base price (double): ";
                            cin >> price;
                            cout << "Give manufacturer (string): ";
                            cin>>manufacturer;
                            cout << "Give name (string): ";
                            cin>>name;
                            cout << "Give a class of fertilizer (A,B,C,D,E,F),\nfor example 'A' mean nitrogen, potassium, potassium - containing only one nutrient component: ";
                            cin>>segmentString;

                            if (segmentString=="A") segment = A;
                            else if (segmentString=="B") segment = B;
                            else if (segmentString=="C") segment = C;
                            else if (segmentString=="D") segment = D;
                            else if (segmentString=="E") segment = E;
                            else if (segmentString=="F") segment = F;
                            else {
                                cout << "Wrong value! It will be default set on A\n";
                                segment = A;
                            }

                            cout << "Initialize article\n" << articleManager.registerFertilizer(price, manufacturer, name, segment)->getInfo()
                                 << endl;
                            break;
                        case 8:
                            cout << "Now give necessary data\n";
                            cout << "Give base price (double): ";
                            cin >> price;
                            cout << "Give manufacturer (string): ";
                            cin>>manufacturer;
                            cout << "Give model (string): ";
                            cin>>model;
                            cout << "Give blade width (double): ";
                            cin>>bladeWidth;
                            cout << "Initialize article\n" << articleManager.registerShovel(price, manufacturer, model, bladeWidth)->getInfo()
                                 << endl;
                            break;
                        case 9:
                            cout << "Now give necessary data\n";
                            cout << "Give base price (double): ";
                            cin >> price;
                            cout << "Give manufacturer (string): ";
                            cin>>manufacturer;
                            cout << "Give model (string): ";
                            cin>>model;
                            cout << "Initialize article\n" << articleManager.registerRake(price, manufacturer, model)->getInfo()
                                 << endl;
                            break;
                        case 10:
                            cout << "Now give necessary data\n";
                            cout << "Give base price (double): ";
                            cin >> price;
                            cout << "Give manufacturer (string): ";
                            cin>>manufacturer;
                            cout << "Give model (string): ";
                            cin>>model;
                            cout << "Give length (double): ";
                            cin>>length;
                            cout << "Initialize article\n" << articleManager.registerShears(price, manufacturer, model, length)->getInfo()
                                 << endl;
                            break;
                        case 11:
                            cout << "Now give necessary data\n";
                            cout << "Give article's id: ";
                            cin >> id;
                            cout << "Showing article...\n" << articleManager.getArticle(id)->getInfo() <<endl;
                            break;
                        case 12:
                            cout << "Showing all articles\n";
                            cout << articleManager.getArticleRepository().report() << endl;
                            break;
                        case 13:
                            articlePredicateMenu();

                            cin >> choice;
                            while (choice > 2 || choice < 1) {
                                cout << "Wrong Number! Try again\n";
                                cin >> choice;
                            }

                            if (choice == 1) {
                                cout << "Now give necessary data\n";
                                cout << "Give the base price to search for: ";
                                cin >> price;
                                cout<<"Showing articles...\n";
                                BasePricePredicate basePricePredicate(price);
                                for (auto & article : articleManager.findArticles(basePricePredicate)) {
                                    cout << article->getInfo();
                                }
                                cout<<endl;
                            } else if (choice == 2) {
                                cout << "Now give necessary data\n";
                                cout << "Give the final price to search for: ";
                                cin >> price;
                                cout<<"Showing articles...\n";
                                FinalPricePredicate finalPricePredicate(price);
                                for (auto & article : articleManager.findArticles(finalPricePredicate)) {
                                    cout << article->getInfo();
                                }
                                cout<<endl;
                            }
                            break;
                        case 0:
                            cout << "Backing\n";
                            back = true;
                    }
                }
                back = false;
                break;
            case 3:
                while (!back) {
                    receiptMenu();

                    cin >> choice;
                    while (choice > 10 || choice < 0) {
                        cout << "Wrong Number! Try again\n";
                        cin >> choice;
                    }

                    switch (choice) {
                        case 1:
                            cout << "Now give necessary data\n";
                            cout << "Give time\n";
                            cout << "Year: ";
                            cin>>year;
                            cout << "Month: ";
                            cin>>month;
                            cout << "Day: ";
                            cin>>day;
                            cout << "Hour: ";
                            cin>>hour;
                            cout << "Minute: ";
                            cin>>minute;
                            cout << "Second: ";
                            cin>>second;
                            cout << "Give client's id: ";
                            cin >> id;
                            cout << "Give article's id: ";
                            cin >> id2;
                            cout << "Initialize receipt\n" << receiptManager.addReceipt(pt::ptime(boost::gregorian::date(year, month, day),pt::hours(hour)+pt::minutes(minute)+pt::seconds(second)), clientManager.getClient(id), articleManager.getArticle(id2))->getInfo()
                                 << endl;
                            break;
                        case 2:
                            cout << "Now give necessary data\n";
                            cout << "Give receipt's id: ";
                            cin >> id;
                            cout << "Remove receipt with id = " << id << endl;
                            receiptManager.removeReceipt(receiptManager.getReceipt(id));
                            break;
                        case 3:
                            cout << "Now give necessary data\n";
                            cout << "Give receipt's id: ";
                            cin >> id;
                            cout << "Give article's id: ";
                            cin >> id2;
                            cout << "Initialize in receipt\n" << receiptManager.addToReceipt(receiptManager.getReceipt(id), articleManager.getArticle(id2))->getInfo()
                                 << endl;
                            break;
                        case 4:
                            cout << "Now give necessary data\n";
                            cout << "Give receipt's id: ";
                            cin >> id;
                            cout << "Give article's id: ";
                            cin >> id2;
                            cout << "Remove article with receipt\n";
                            receiptManager.removeWithReceipt(receiptManager.getReceipt(id), articleManager.getArticle(id2));
                            break;
                        case 5:
                            cout << "Now give necessary data\n";
                            cout << "Give receipt's id: ";
                            cin >> id;
                            cout << "Showing receipt...\n" << receiptManager.getReceipt(id)->getInfo() <<endl;
                            break;
                        case 6:
                            cout << "Showing all receipts\n";
                            cout << receiptManager.getReceiptRepository().report() << endl;
                            break;
                        case 7:
                            receiptPredicateMenu();

                            cin >> choice;
                            while (choice > 1 || choice < 1) {
                                cout << "Wrong Number! Try again\n";
                                cin >> choice;
                            }

                            if (choice == 1) {
                                cout << "Now give necessary data\n";
                                cout << "Give time to search for\n";
                                cout << "Year: ";
                                cin>>year;
                                cout << "Month: ";
                                cin>>month;
                                cout << "Day: ";
                                cin>>day;
                                cout << "Hour: ";
                                cin>>hour;
                                cout << "Minute: ";
                                cin>>minute;
                                cout << "Second: ";
                                cin>>second;
                                cout<<"Showing receipts...\n";

                                TimePredicate timePredicate(pt::ptime(boost::gregorian::date(year, month, day),pt::hours(hour)+pt::minutes(minute)+pt::seconds(second)));
                                for (auto & receipt : receiptManager.findReceipts(timePredicate)) {
                                    cout << receipt->getInfo();
                                }
                                cout<<endl;
                            }

                            break;
                        case 8:
                            cout << "Now give necessary data\n";
                            cout << "Give client's id: ";
                            cin >> id;
                            cout << "Showing client's all receipts balance: ";
                            cout << receiptManager.checkClientReceiptsBalance(clientManager.getClient(id)) << endl;
                            break;
                        case 9:
                            cout << "Now give necessary data\n";
                            cout << "Give client's id: ";
                            cin >> id;
                            for (auto & receipt : receiptManager.getClientReceipts(clientManager.getClient(id))) {
                                cout << receipt->getInfo();
                            }
                            cout << endl;
                            break;
                        case 10:
                            cout << "Now give necessary data\n";
                            cout << "Give article's id: ";
                            cin >> id;
                            for (auto & receipt : receiptManager.getArticleReceipts(articleManager.getArticle(id))) {
                                cout << receipt->getInfo();
                            }
                            cout << endl;
                            break;
                        case 0:
                            cout << "Backing\n";
                            back = true;
                    }
                }
                back = false;
                break;
            case 0:
                cout << "Exiting";
                end = true;
        }
    }

    cout << "\nSaving data\n";

    clientManager.saveData();
    articleManager.saveData();
    receiptManager.saveData();
}

void UserInterface::initMenu() {
    cout << "Choose Option:\n\n";
    cout << "1- Client options\n";
    cout << "2- Article options\n";
    cout << "3- Receipt options\n";
    cout << "0- Exit\n\n";
}

void UserInterface::clientMenu() {
    cout << "Choose Option:\n\n";
    cout << "1- Register client\n";
    cout << "2- Unregister client\n";
    cout << "3- Get client\n";
    cout << "4- Find all clients\n";
    cout << "5- Find client by...\n";
    cout << "0- Back\n\n";
}

void UserInterface::clientPredicateMenu() {
    cout << "Choose Option:\n\n";
    cout << "1- find by Name\n";
    cout << "2- find by Surname\n";
    cout << "3- find by Permit\n\n";
}

void UserInterface::articleMenu() {
    cout << "Choose Option:\n\n";
    cout << "1- Unregister article\n";
    cout << "2- Register tree\n";
    cout << "3- Register bush\n";
    cout << "4- Register seedling\n";
    cout << "5- Register seed bag\n";
    cout << "6- Register pesticide\n";
    cout << "7- Register fertilizer\n";
    cout << "8- Register shovel\n";
    cout << "9- Register rake\n";
    cout << "10- Register shears\n";
    cout << "11- Get article\n";
    cout << "12- Find all articles\n";
    cout << "13- Find articles by...\n";
    cout << "0- Back\n\n";
}

void UserInterface::articlePredicateMenu() {
    cout << "Choose Option:\n\n";
    cout << "1- find by Base price\n";
    cout << "2- find by Final price\n\n";
}

void UserInterface::receiptMenu() {
    cout << "Choose Option:\n\n";
    cout << "1- Add receipt\n";
    cout << "2- Remove receipt\n";
    cout << "3- Add to receipt\n";
    cout << "4- Remove with receipt\n";
    cout << "5- Get receipt\n";
    cout << "6- Find all receipts\n";
    cout << "7- Find receipts by...\n";
    cout << "8- Check client's receipts balance\n";
    cout << "9- Get client's receipts\n";
    cout << "10- Get article's receipts\n";
    cout << "0- Back\n\n";
}

void UserInterface::receiptPredicateMenu() {
    cout << "Choose Option:\n\n";
    cout << "1- find by time\n\n";
}
