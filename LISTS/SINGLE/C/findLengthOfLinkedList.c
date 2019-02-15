#include<stdio.h>
#include<malloc.h>

/* Make the structure of the linked list */

struct node
{
  int data;
  struct node* link;
};

struct node* root;

void insertHead(int value)
{
  struct node* tempNode; //declare a temp variable
  tempNode = (struct node*)malloc(sizeof(struct node));// assign memory
  tempNode->data = value; // inserting the value
  tempNode->link = NULL; // cause if its the first element
  if(root == NULL) // if no elements in the list
  {
    root = tempNode; // head points to the newNode
  }
  else // if root is noot the first node
  {
    tempNode->link = root;
    root = tempNode;
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

int main()
{
  insertHead(5);
  insertHead(6);
  insertHead(7);
  insertHead(8);

  int length1 = length();
  printf("The length is %d",length1);
}
