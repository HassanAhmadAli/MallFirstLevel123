#include "Product.h"


Product::Product(string n, int i, int a) :Name(n), Id(i), Amount(a) {
	;
}

void Product::setAmount(int a) {
	Amount = a;
}

string Product::getName()const {
	return Name;
};

int Product::getId()const {
	return Id;
}

int Product::getAmount()const {
	return Amount;
}





ProductNode::ProductNode(Product& d, ProductNode* n, ProductNode* p) :Data(d), Next(n), Previuse(p) {
	;
}
ProductNode::~ProductNode() {
	delete Next;
	delete Previuse;
}







LISTOfProduct::LISTOfProduct(Product& p) : First(new ProductNode(p, NULL, NULL)) {
	;
}

Product& LISTOfProduct::getLast() {
	ProductNode* LastNode = NULL, * CurrentNode = First, * temp = CurrentNode;

	while (CurrentNode)
	{
		temp = CurrentNode;
		LastNode = CurrentNode;
		CurrentNode = CurrentNode->Next;

	}
	if (First)return temp->Data;
	cout << "ERROR the Cart is empty." << endl;
	Product* error = new Product("ERROR", -1, 0);
	return* error;
}

Product& LISTOfProduct::getFirst() {
	return First->Data;
}


Product& LISTOfProduct::searchId(int i) {
	ProductNode* p = First;

	while (p) {
		if (p->Data.getId() == i)return p->Data;
	}
	cout << "ERROR: didn\'t find produt with this ID "
		<< i
		<< endl
		<< endl;
	Product* error = new Product("ERROR", -1, 0);
	return*error;
}

void LISTOfProduct::pushFirst(Product& p) {
	ProductNode* NewFirst = new ProductNode(p, First, NULL);
	First->Previuse = NewFirst;
	First = NewFirst;
}

void LISTOfProduct::popFirst() {
	ProductNode* newFirst = First->Next;
	First->Next = NULL;
	newFirst->Previuse = NULL;
	First = newFirst;
}

LISTOfProduct::~LISTOfProduct() {
	ProductNode* tempNode = NULL, * CurrentNode = First;

	while (CurrentNode)
	{
		tempNode = CurrentNode;
		CurrentNode = CurrentNode->Next;
		delete tempNode;
	}
}