#include "Client.h"


Client::Client(int i) :Id(i), Cart(NULL) {
	;
}
void Client::popfromCart() {
	Cart->popFirst();
}
void Client::pushtoCart(Product& p) {
	Cart->pushFirst(p);
}


Client::~Client() {
	Cart->~LISTOfProduct();
}

const int& Client::getId()const {
	return Id;
}

ClientNode::ClientNode(Client& d, ClientNode* n, ClientNode* p) :Data(d), Next(n), Previuse(p) {
	;
}
ClientNode::~ClientNode() {
	Data.~Client();
	Next->~ClientNode();
	delete Next;
	Previuse->~ClientNode();
	delete Previuse;
}

ListOfClient::ListOfClient(Client& c) : First(new ClientNode(c, NULL, NULL)) {

}

Client& ListOfClient::getFirst() {
	if (First)	return First->Data;
	Client* temp = new Client(-1);
	return *temp;
}

void ListOfClient::pushLast(Client& c) {
	ClientNode* p = First, * temp = First;
	while (p) {
		temp = p;
		p = p->Next;
	}
	if (First)temp->Next = new ClientNode(c, NULL, temp);
	First = new ClientNode(c, NULL, NULL);
}

void ListOfClient::popFirst() {
	ClientNode* temp = First->Next;
	First->Next = NULL;
	First = temp;
	First->Previuse = NULL;

}
ListOfClient::~ListOfClient() {
	while (First)
	{
		if (First->Next)
		{
			ClientNode* temp = First;
			First = First->Next;
			temp->~ClientNode();
			delete temp;
		}
	}
	if (First) {
		First->~ClientNode();
		delete First;
	}
	

}