//1)insert at beg,end,middle
//2)delete at beg,end,middle
//3)reverse
//4)print

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int x)
    {
        data=x;
        prev=NULL;
        next=NULL;
    }
};
void printList(Node* head)
{Node* temp=head;
    while(temp)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
Node * insertAtBeg(Node* head,int i)
{ Node* temp=new Node(i);
temp->next=head;
head->prev=temp;
head=temp;
return temp;

}
Node* insertAtEnd(Node* head,int i)
{
    Node*temp=new Node(i);
    Node* cur=head;
    while(cur->next)
    {
        cur=cur->next;
    }
    cur->next=temp;
    temp->prev=cur;
    return head;
}
Node* insertAtMiddle(Node* head,int d,int i)
{ Node*temp=new Node(i);
 Node* cur=head;
    while(cur->data!=d)
    {
        cur=cur->next;
    }
    temp->next=cur->next;
    temp->prev=cur;
    cur->next->prev=temp;
    cur->next=temp;
    return head;


}
Node* deleteAtBeg(Node* head)
{
    if(head==NULL)
    {
        return head;
    }
    else{
        Node* t=head;
        head=head->next;
        head->prev=NULL;
        delete t;
        return head;
    }
}
Node* deleteAtEnd(Node* head)
{
    if(head==NULL)
    {
        return head;
    }
    else{
        Node* t=head;
        while(t->next->next)
        {
            t=t->next;
        }
        Node* tt=t->next;
       t->next=NULL;
       tt->prev=NULL;
      delete  tt->next;
      return head;
    }
}
Node* deleteAtMid(Node* head,int d)
{
    if(head==NULL)
    {
        return head;
    }
    else{
        Node* temp=head;
        while(temp->data!=d)
        {
            temp=temp->next;
        }
        if(temp==NULL)
        {
            return head;
        }
        else{
            Node* tt=temp->next;
            temp->next=tt->next;
            tt->prev=NULL;
            tt->next->prev=temp;
            tt->next=NULL;
            delete tt;
            return head;
        }
    }
}

Node* reverse(Node* head)
{ Node* cur=head;
    Node* pre=NULL;
    Node* nex=NULL;
    while(cur)
    { nex=cur->next;
    cur->next=pre;
    cur->prev=nex;
    pre=cur;
    cur=nex;
}
return pre;
}
int main()
{
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->prev=head;
    head->next->next=new Node(3);
    head->next->next->prev=head->next;
    head=insertAtBeg(head,4);
    head=insertAtEnd(head,5);
    head=insertAtMiddle(head,2,7);
    head=reverse(head);
    head=deleteAtBeg(head);
    
    printList(head);
     head=deleteAtMid(head,2);
     printList(head);
    head=deleteAtEnd(head);
    printList(head);
    return 0;
}
