#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;


class Product
{
	const string Name;
	const int Id;
	int Amount;
	Product();
public:
	Product(string, int, int = 0);
	void setAmount(int);
	string getName()const;
	int getId()const;
	int getAmount()const;

};

class ProductNode {
public:
	Product Data;
	ProductNode* Next;
	ProductNode* Previuse;
	ProductNode(Product&, ProductNode*, ProductNode*);
	~ProductNode();
private:
	ProductNode();
};

class LISTOfProduct/*Cart*/ {
public:
	LISTOfProduct(Product&);
	Product& getLast();
	Product& getFirst();
	Product& searchId(int i);
	void pushFirst(Product&);
	void popFirst();
	~LISTOfProduct();
private:
	LISTOfProduct();
	ProductNode* First;
};

#endif