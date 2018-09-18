#include<iostream>
using namespace std;

struct node
{

    int data;
    struct node *next;
};

node *head = NULL;

void INSERT_HEAD(int value)
{
    node *newNode;
    newNode = new node;
    newNode->data = value;

    if(head == NULL)
    {   newNode->next = NULL;
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }

    cout<<"DATA INSERTED AT HEAD SUCCESSFULLY"<<endl;
}


int main()
{int choice,element;
    cout<<"ENTER THE CHOICE\n1.INSERT AT HEAD"<<endl;
    cin>>choice;

    while(choice != -1)
    {
    switch(choice)
    {

    case 1:
        cout<<"ENTER THE ELEMENT"<<endl;
        cin>>element;
        INSERT_HEAD(element);
        break;
    }
    cout<<"ENTER THE CHOICE\n1.INSERT AT HEAD"<<endl;
    cin>>choice;
}
}

