#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node * left ;
  struct Node * right;
};
struct Node * root = NULL;


void insertHead (int value)
{
  struct Node * temp;
  temp = (struct Node *) malloc (sizeof(struct Node));
  temp->data = value;
  temp->left = NULL;
  temp->right = NULL;


  if(root == NULL)
  {
    root = temp;
  }
  else
  {
    temp -> right = root; // storing the root address in temp->right;
    root->left = temp; // root->left is the left node of the new root created
    root = temp; // assigning the new Node as root;
  }
}

int length()
{

  struct Node * t = root;
  int count = 0;

  while(t != NULL)
  {
    count++;
    t = t->right;
  }

  return count;
}

void display()
{
  struct Node * t = root;
  while(t != NULL)
  {
    printf("%d ",t->data);
    t = t->right;
  }

  printf("\nthe count is %d \n",length());
}

int main()
{
  insertHead(1);
  insertHead(2);
  insertHead(3);
  insertHead(4);
  insertHead(5);


  display();
}
