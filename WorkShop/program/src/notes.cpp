//
// Created by student on 25.05.2022.
//


/*ClientManager clientManager;
ArticleManager articleManager;
ReceiptManager receiptManager;

ClientPtr c1 = clientManager.registerClient("Bartek", "Wojtaszek");
ClientPtr c2 = clientManager.registerClient("Tomasz", "Duda");
ArticlePtr a1 = articleManager.registerTree(12.4,"Oak",16,50,2300);
ArticlePtr a2 = articleManager.registerShovel(123.006, "PlArmy", "Saper", 5.8);
ArticlePtr a3 = articleManager.registerBush(12.4,"Berry",7,30,200);
ReceiptPtr r1 = receiptManager.addReceipt(pt::second_clock::local_time(), c1, a1);
//cout << r1->getInfo() << endl;
ReceiptPtr r2 = receiptManager.addReceipt(pt::second_clock::local_time(), c2, a2);
cout << receiptManager.getReceiptRepository().report() << endl;
receiptManager.removeReceipt(r1);
receiptManager.addToReceipt(r2, a3);
receiptManager.removeWithReceipt(r2, a3);
receiptManager.addToReceipt(r2, a3);
receiptManager.addToReceipt(r2, a3);
ReceiptPtr r3 = receiptManager.addReceipt(pt::second_clock::local_time(), c2, a3);
cout << receiptManager.getReceiptRepository().report() << endl;
cout << receiptManager.checkClientReceiptsBalance(c2) << endl;*/

/*ClientManager clientManager;
//vector<ClientPtr> cls2 = clientManager.findAllClients();
//for (auto & cl : cls2) cout << cl->getInfo();
clientManager.registerClient("Bartek", "Wojtaszek");
ClientPtr c1 = clientManager.registerClient("Bartek", "Wojtaszek");
clientManager.registerClient("Bartek", "Wojtaszek");
clientManager.registerClient("Bartek", "Wojtaszek");
cout << clientManager.getClientRepository().report();
clientManager.unregisterClient(c1);
cout << clientManager.getClientRepository().report() << endl;
ClientPtr c2 = clientManager.getClient(4);
cout << c2->getInfo() << endl;

TruePredicate<ClientPtr> pre1;
vector<ClientPtr> cls1 = clientManager.findClients(pre1);
for (auto & cl : cls1) cout << cl->getInfo();*/
//IdPredicate<ClientPtr> pre2(6);
//vector<ClientPtr> cls3 = clientManager.findClients(pre2);

/*ArticleManager articleManager;
ArticlePtr a1 = articleManager.registerTree(12.4,"Oak",16,50,2300);
cout << articleManager.getArticleRepository().getRepository()[0]->getInfo() << endl;
ArticlePtr a2 = articleManager.registerTree(123.006,"Birch",19,53,7700);
cout << a2->getInfo() << endl;
articleManager.unregisterArticle(a2);
for (auto & art : articleManager.getArticleRepository().getRepository()) cout << art->getInfo() << endl;
ArticlePtr a3 = articleManager.registerBush(12.4,"Oak",16,50,2300);
ArticlePtr a4 = articleManager.registerSeedling(12.4,"Oak",16,50,2300);

//ArticlePtr fer1 = make_shared<Fertilizer>(5,45.5,"Bosh","nawoz",A);
articleManager.registerSeedBag(22.2,"rose",25);
articleManager.registerFertilizer(45.5, "Bosh", "Smolin", B);
articleManager.registerPesticide(33.3,"Intel","Cpu", false);
articleManager.registerShears(35,"Intel","shears", 45.5);
articleManager.registerShovel(36,"Intel","shovel", 45.5);
articleManager.registerRake(36,"Intel","shovel");
cout << articleManager.getArticleRepository().report() << endl;

vector<ArticlePtr> arts1 = articleManager.findAllArticles();
for (auto & art : arts1) cout << art->getInfo(); cout << endl;
IdPredicate<ArticlePtr> pre1(3);
vector<ArticlePtr> arts2 = articleManager.findArticles(pre1);
for (auto & art : arts2) cout << art->getInfo(); cout << endl;
ArticlePtr a5 = articleManager.getArticle(6);
cout << a5->getInfo() << endl;

BasePricePredicate pre2(36);
vector<ArticlePtr> arts3 = articleManager.findArticles(pre2);
for (auto & art : arts3) cout << art->getInfo(); cout << endl;*/


/*

Client c1(1 ,"Kacper" ,"Polakowski");
cout << c1.getInfo() << endl;
try {
    throw ClientException(ClientException::exceptionEmptyName);
}
catch (const ClientException & error ) {
    cout << error.what() << endl;
}

Shovel sh1(1,12.544,"Mercedes","Benz",3.4);
cout << sh1.getInfo() << endl;

Rake ra1(1,120.544,"Mercedes","Benz");
cout << ra1.getInfo() << endl;

Shears she1(1,120.544,"Mercedes","Benz",5.566);
cout << she1.getInfo() << endl;

Pesticide pe1(1,1.333,"WD","-40", true);
cout << pe1.getInfo() << endl;

Fertilizer fe1(1,34.5,"Bosh","snail_killer", B);
cout << fe1.getInfo() << endl;

SeedBag sb1(1,9.99,"kwaitek",4);
cout << sb1.getInfo() << endl;

Seedling sl1(1,15.666,"pomidor",0,8,10);
cout << sl1.getInfo() << endl;

Bush bu1(1,154.666,"jagoda",3,50,150);
cout << bu1.getInfo() << endl;

Tree tr1(1,1555.666,"lipa",13,333,2000);
cout << tr1.getInfo() << endl;

ClientPtr c2 = make_shared<Client>(2, "Bartosz", "Wojtaszek", true);
ArticlePtr tr2 = make_shared<Tree>(2, 1234.566, "brzoza", 15, 400, 2500);
ArticlePtr fe2 = make_shared<Fertilizer>(1, 24.5, "chwast killer", "wersja dla komarow", D);
ReceiptPtr r1 = make_shared<Receipt>(1,boost::posix_time::second_clock::local_time(), c2, tr2);
cout << r1->getInfo() << endl;
r1->addItem(fe2);
cout << r1->getInfo() << endl;
r1->removeItem(tr2);
cout << r1->getInfo() << endl;

// Repository<> is now abstract class so...
//Repository<ArticlePtr> artRepo;
//artRepo.addObject(tr2);
//cout << artRepo.report() << endl;

ArticleRepository artRepo2;
artRepo2.addObject(tr2);
artRepo2.addObject(fe2);
cout << artRepo2.report() << endl;

ClientRepository clRepo1;
clRepo1.addObject(c2);
cout << clRepo1.report() << endl;

ReceiptRepository reRepo1;
reRepo1.addObject(r1);
cout << reRepo1.report() << endl;

IdPredicate<ArticlePtr> idPredicate1(1);
bool accept = idPredicate1(fe2);
cout << accept << endl;

ArticleRepository artRepoPre1;
artRepoPre1.setRepository(artRepo2.findBy(idPredicate1));
cout << artRepoPre1.report() << endl;

ArticleRepository artRepoPre2;
artRepoPre2.setRepository(artRepo2.findAll());
cout << artRepoPre2.report() << endl;

ArticlePtr art2 = artRepo2.findById(2);
cout << art2->getInfo() << endl;

*/




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


