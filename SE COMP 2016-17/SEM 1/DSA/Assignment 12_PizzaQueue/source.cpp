#include <iostream>
#include <string>
using namespace std;

class cQueue
{
    string *Orders;
    int iMaxOrders;
    int iFront, iRear;
public:
    cQueue();
    ~cQueue();
    void vAddOrder();
    void vServeOrder();
};

cQueue::cQueue()
{
    iFront = 0;
    iRear =0;
    cout<<"Enter max no. of orders: ";
    cin>>iMaxOrders;
    Orders = new string[iMaxOrders+1];
}
cQueue::~cQueue()
{
    delete []Orders;
}
void cQueue::vAddOrder()
{
    cout<<"Enter the name of the pizza: ";
    string inp;
    cin>>inp;
    if((iRear+1)%(iMaxOrders+1) != iFront)
    {
        iRear = (iRear+1)%(iMaxOrders+1);
        Orders[iRear] = inp;
    }
    else
    {
        cout<<"The Queue is full!\n";

    }
}

void cQueue::vServeOrder()
{
    if(iFront != iRear)
    {
        iFront = (iFront+1)%(iMaxOrders+1);
        cout<<"Your Order is ready: "<<Orders[iFront]<<endl;

    }
    else
    {
        cout<<"The Queue is empty!\n";
    }
}

int main()
{
    char inp;
    cQueue QPizzaHut;
    do{
        cout<<"1. Order Pizza\n";
        cout<<"2. Serve Pizza\n";
        cin>>inp;
        switch(inp)
        {
        case '1':
            QPizzaHut.vAddOrder();
            break;
        case '2':
            QPizzaHut.vServeOrder();
            break;
        }

        cout<<"Do you want to continue?(y) ";
        cin>>inp;
    }while(inp == 'y');
    return 0;
}
//---------------OUTPUT-----------------------------
/*

Enter max no. of orders: 2
1. Order Pizza
2. Serve Pizza
1
Enter the name of the pizza: Chicken
Do you want to continue?(y) y
1. Order Pizza
2. Serve Pizza
1
Enter the name of the pizza: Italian
Do you want to continue?(y) y
1. Order Pizza
2. Serve Pizza
1
Enter the name of the pizza: Veg
The Queue is full!
Do you want to continue?(y) y
1. Order Pizza
2. Serve Pizza
2
Your Order is ready: Chicken
Do you want to continue?(y) y
1. Order Pizza
2. Serve Pizza
2
Your Order is ready: Italian
Do you want to continue?(y) y
1. Order Pizza
2. Serve Pizza
2
The Queue is empty!
Do you want to continue?(y) n
*/
