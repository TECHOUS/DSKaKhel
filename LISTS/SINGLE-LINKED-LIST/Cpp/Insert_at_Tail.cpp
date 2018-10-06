#include<iostream>
#include<stdio.h>
using namespace std;

struct Node{


    int data;
    struct Node *next;
};
struct Node* head = NULL; // at start the head is null


void Insert_TAIL(int value){


struct Node *temp = new Node;
struct Node *container;
temp->data = value;
temp->next = NULL;

container = head ;

if(head == NULL)
   {
       head = temp;
   }
else
    {

        while( container->next != NULL)
        {
            container=container->next;
        }

        container->next = temp;


    }
    cout<<"ENTERED INTO TAIL SUCCESSFULLY "<<endl;

}


int main()
{
    int choice,element;

    cout<<"ENTER 1 to push towards tail"<<endl;
    cin>>choice;

    while(choice != -1)
    {

        switch(choice)
        {

        case 1:
            cout<<"ENTER THE ELEMENT TO ENTER"<<endl;
            cin>>element;
            Insert_TAIL(element);
            break;
        }
         cout<<"ENTER 1 to push towards tail"<<endl;
    cin>>choice;
    }
}
