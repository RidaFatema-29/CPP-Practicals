#include <iostream>
#include <string>
using namespace std;

struct node
{
    int appDate;
    string patient;
    node* previous;
    node* next;
};
node* head = NULL;

void create(){
    node* newNode = new node();
    cout<<"Enter Appointment Date : ";
    cin>>newNode->appDate;
    cout<<"Enter Patient Name : ";
    cin>>newNode->patient;
    newNode->next = NULL;

    if(head==NULL){
        newNode->previous= NULL;
        head= newNode;
    }
    else{
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->previous = temp;
    }
}

void display(){
    if(head== NULL){
        cout<<"NO appointment.\n";
        return;
    }
    node* temp = head;
    cout<<"\n\n Appointments : \n ";
    while(temp!=NULL){
        cout<<" Date : "<<temp->appDate<<" \n Patient Name : "<<temp->patient<<endl;
        temp = temp->next;
    }
}

int main(){
    int choice;
    do{
        cout<<"\n\n 1. Create an Appointment. \n 2. Display Appointments. \n 3. Exit\n\n";
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice){
            case 1 :
            create();
            break;

            case 2 :
            display();
            break;

            case 3 :
            cout<<"Exiting ... \n";
            break;

            default :
            cout<<"Invalid";
        }
    }while(choice!=3);
    return 0;
}
