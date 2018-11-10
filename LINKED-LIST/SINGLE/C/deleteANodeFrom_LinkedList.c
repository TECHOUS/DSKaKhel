#include<stdio.h>
#include<malloc.h>


struct node
{
  int data;
  struct node *link;
};
struct node * root;

// to insert at end
void insertAtTail(int value)
{
  struct node * temp;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = value;
  temp->link = NULL;

  if(root == NULL)
  {
    root = temp;
  }
  else
  {
    struct node *p;
    p = root;

    while(p->link != NULL)
    {
      p = p->link;
    }
    p->link = temp;
    temp->link = NULL;
  }
}

// to find length
int length()
{
  int count = 0;
  struct node* tempNode;
  tempNode = root;

  while(tempNode != NULL)
  {
    count++;
    tempNode = tempNode->link;
  }
return count;
}
// to delete

void deleteNode(int position)
{
  if(position > length())
  {
    printf("Sorry the position to delete dosent exist , currently there are %d nodes in the linked list\n",length());
  }
  else if(position == 1)
  {
    // the user wants to delete the first node
    struct node * temp;
    temp = root;
    root = temp->link; // root points the second node
    temp->link = NULL; //detaching the first node
    free(temp); // freeing the memory
  }
  else
  {
    struct node* p;
    struct node* q;
    p = root; // initially it contains root
    int i = 1;

    while(i < position-1)
    {
      p = p -> link;
      i++;
    }
    q = p->link; // next address we are storing;
    p->link = q->link;
    q->link = NULL;
    free(q);
  }
}
//to display
void display()
{
  struct node* temp;
  temp = root;

  while(temp != NULL)
  {
    printf("%d ",temp->data);
    temp = temp->link;
  }
  printf("\n");

}

int main()
{
  insertAtTail(1);
  insertAtTail(2);
  insertAtTail(3);
  insertAtTail(4);
  insertAtTail(5);
  display();
  deleteNode(3);
  display();
}
