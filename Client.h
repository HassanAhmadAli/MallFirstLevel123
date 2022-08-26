#ifndef CLIENT_H
#define CLIENT_H
#include "Product.h"

class Client
{
	const int Id;
	LISTOfProduct* Cart;
	Client();
public:
	Client(int);
	const int& getId()const;
	void pushtoCart(Product&);
	void popfromCart();
	~Client();
};


class ClientNode {
public:
	Client Data;
	ClientNode* Next;
	ClientNode* Previuse;
	ClientNode(Client&, ClientNode*, ClientNode*);
	~ClientNode();
private:
	ClientNode();
};



class ListOfClient/*Queue*/ {
public:
	ListOfClient(Client&);
	Client& getFirst();
	void pushLast(Client&);
	void popFirst();
	~ListOfClient();
private:
	ListOfClient();
	ClientNode* First;
};

#endif