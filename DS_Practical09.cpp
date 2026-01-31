#include<iostream>
#include<queue>
#include<string>
using namespace std;

const int MAX_ORDERS= 10;

queue<string> orderQueue;

void menu(){
    cout<<"\n\n Menu :- ";
    cout<<"\nPlace an order.";
    cout<<"\nServe an order.";
    cout<<"\nList current orders.";
    cout<<"\nExit.";
    cout<<"\n\nEnter your Choice : ";
}

void place(){
    if(orderQueue.size()==MAX_ORDERS){
        cout<<"\nOrder cannot be placed...cuz Order Queue is full";
    }
    else{
        string order;
        cout<<"\nEnter Your Order : ";
        cin>>order;
        orderQueue.push(order);
        cout<<"\nOrder placed successfully...";
    }
}

void serve(){
    if(orderQueue.empty()){
        cout<<"\nOrder Queue is Empty... No order to serve";
    }
    else{
        string name = orderQueue.front();
        orderQueue.pop();
        cout<<name<<"\nOrder successfully served...";
    }
}

void show(){
    if(orderQueue.empty()){
        cout<<"\nOrder Queue is Empty";
    }
    else{
        cout<<"\nTotal Orders : \n";
        queue<string> tempQueue = orderQueue;
        while(!tempQueue.empty()){
            cout<<tempQueue.front()<<" ";
            tempQueue.pop();
        }
    }
}

int main(){
    int choice;
    cout<<"\n\nPIZZA PARLOR ";
    do{
        menu();
        cin>>choice;

        switch(choice){
            case 1:
            place();
            break;

            case 2:
            serve();
            break;

            case 3:
            show();
            break;

            case 4:
            cout<<"Exiting...";
            break;

            default:
            break;
        }
    }while(choice!=4);
}