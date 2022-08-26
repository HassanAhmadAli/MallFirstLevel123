#ifndef MALL_H
#define MALL_H
#include "Client.h"

class Mall {
	
	LISTOfProduct* Cart;
	ListOfClient* Queue;
public:
	
	Mall();
	~Mall();
};
#endif