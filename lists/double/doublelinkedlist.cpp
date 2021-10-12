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
Node * insertatbeg(Node* head,int i)
{ Node* temp=new Node(i);
temp->next=head;
head->prev=temp;
head=temp;
return temp;

}
Node* insertatend(Node* head,int i)
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
Node* insertatmiddle(Node* head,int d,int i)
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
Node* delatbeg(Node* head)
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
Node* delatend(Node* head)
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
Node* delatmid(Node* head,int d)
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
    head=insertatbeg(head,4);
    head=insertatend(head,5);
    head=insertatmiddle(head,2,7);
    head=reverse(head);
    head=delatbeg(head);
    
    printList(head);
     head=delatmid(head,2);
     printList(head);
    head=delatend(head);
    printList(head);
    return 0;
}
