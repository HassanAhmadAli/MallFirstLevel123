/*created by Hassan Ali and Laith Assad
* Date:2021-10-27
* First part of the project 
*/
#include <iostream>
#include <iomanip>
#include "Mall.h"



using namespace std;


int main()
{
    Mall MallTest;
    Product ProductTest("test", 20211027, 2);
    LISTOfProduct Cart(ProductTest);
    cout << Cart.getFirst().getName() << Cart.getLast().getId();
    Cart.~LISTOfProduct();
    Client ClientTest(27);
    ListOfClient Queue(ClientTest);
    Queue.getFirst().popfromCart();
    Queue.~ListOfClient();
    MallTest.~Mall();
    return 0;
}