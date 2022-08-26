#include "Mall.h"

Mall::Mall() :Cart(NULL) , Queue(NULL) {

}

Mall::~Mall() {
	Queue->~ListOfClient();
	delete Cart;
	Cart->~LISTOfProduct();
	delete Queue;
}