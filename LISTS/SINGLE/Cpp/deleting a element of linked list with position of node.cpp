#include <bits/stdc++.h>
using namespace std;
struct LLNode
{
    int data;
    struct LLNode* next;
};
void insertAtBeginning(struct LLNode** head, int dataToBeInserted)
{
    struct LLNode* curr = new LLNode;
    curr->data = dataToBeInserted;
    curr->next = NULL;    
    if(*head == NULL)
            *head=curr; 
        
    else{
            curr->next=*head; 
            *head=curr;
        }
}
void display(struct LLNode**node)
{
    struct LLNode *temp= *node;
    while(temp!=NULL)
        {
            if(temp->next!=NULL)
            cout<<temp->data<<"->";
            else
            cout<<temp->data;
            
            temp=temp->next; 
        }
    cout<<endl;
}
void deleteNode(struct LLNode **head_ref, int pos)
{
    
   if (*head_ref == NULL)
   {
      return;
   }
   struct LLNode* temp = *head_ref;
    if (pos == 0)
    {
        *head_ref = temp->next; 
        free(temp);               
        return;
    }
    for (int i=0; temp!=NULL && i<pos-1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL){
        return;
    }
    struct LLNode *next = temp->next->next;
    free(temp->next);  
    temp->next = next; 
}
int main()
{
    struct LLNode* head = NULL;
    int i;
    int l;
    cout<<"enter the number of elements in list\n";
    cin>>i;
    for(int j=0;j<i;j++){
    	int q;
		cin>>q;
    	insertAtBeginning(&head, q);
	}

 
    cout<<"Input linked list: ";
    display(&head);
    int k;
    cout<<"Enter pos to be deleted: ";
    cin>>k;
   
    deleteNode(&head, k);

    cout<<"Output linked list: ";
    display(&head);
    return 0;
}
