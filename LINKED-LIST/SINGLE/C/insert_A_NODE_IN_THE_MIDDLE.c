#include<stdio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *link;
};

struct node* root;

void insertAtTail(int value)
{

  struct node * tempNode;
  tempNode = (struct node*)malloc(sizeof(struct node));
  tempNode->data = value;
  tempNode->link = NULL;

  if(root == NULL)
  {
    root = tempNode;
  }
  else
  {
    struct node *p;

    p = root;

    while(p->link != NULL)
    {
      p = p->link;
    }

    p->link = tempNode; // holds the address of temp
    tempNode->link = NULL; // holds NULL
  }

}
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
void addAfter(int value,int position)
{
  int i = 1;
  if(position > length())
  {
    printf("Invalid Location, the list has %d nodes",length());
  }
  else
  {
    struct node * tempNode;
    tempNode = (struct node*)malloc(sizeof(struct node));
    struct node * p;
    tempNode->data = value;//creating the node
    tempNode->link = NULL;//creating the node
    p = root;
    while(i < position)
    {
      p = p->link; // traversing every nodes untill the desired position
      i++;
    }
    tempNode->link = p->link; // right connect
    p->link = tempNode; //left connection
  }
}

void display()
{
  struct node *temp;
  temp = root;

  while(temp != NULL)
  {del
      printf("%d ",temp->data);
      temp = temp->link;
  }

}
int main()
{
  insertAtTail(1);
  insertAtTail(2);
  insertAtTail(3);
  insertAtTail(4);
  insertAtTail(5);
  //printf("The length is = %d\n",length());
  addAfter(9,3);
  display();
}
