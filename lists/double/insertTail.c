#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node * left;
  struct Node * right;
};

struct Node * root = NULL;

void insertTail(int value)
{
  struct Node * tempNode;
  tempNode = (struct Node *) malloc (sizeof(struct Node));

  tempNode->data = value;
  tempNode->left = NULL;
  tempNode->right = NULL;

  if(root == NULL)
  {
    root = tempNode;
  }
  else
  {
    struct Node * p;
    p = root;
    while(p->right != NULL)
    {
      p = p->right;
    }
    p->right = tempNode;
    tempNode -> left = p;
  }
}

void display()
{
  struct Node * t = root;
  int i
  while(t != NULL)
  {
    printf("the node at pos %d is %d \n",t->data);
    t = t->right;
  }
}



int main()
{
  insertTail(1);
  insertTail(2);
  insertTail(3);
  insertTail(4);
  insertTail(5);

  display();
}
