#include<iostream>
#include<stdlib.h>
using namespace std;

/*

                              1     => level 1
                            /   \
                          2       3
                        / \      /  \
                      4   5     6    7  => level 3




*/
struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};
struct Node *root = NULL;

struct Node *newNode(int data)
{
  struct Node *temp = (struct Node *) malloc ( sizeof(struct Node));
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

int height(struct Node *root)
{
  if(root == NULL)
  {
    return 0;
  }

  int lheight = height(root->left);
  int rheight = height(root->right);

  if(lheight > rheight)
  {
    return lheight + 1;
  }
  return rheight + 1;
}
void printOddEven(struct Node *root,int height)
{
    if(root == NULL)
    {
      return ;
    }
    if(height % 2 != 0)
    {
      printf("%d => ",root->data);
    }

    printOddEven(root->left,height-1);
    printOddEven(root->right,height-1);
}

int main()
{
  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right = newNode(3);
  root->right->left = newNode(6);
  root->right->right = newNode(7);

  printOddEven(root,height(root));
}
