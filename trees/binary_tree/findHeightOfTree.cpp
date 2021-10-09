#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node * root = NULL;

struct Node* newNode(int data)
{
  struct Node* temp = (struct Node *) malloc (sizeof(struct Node));
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}


int height(struct Node * root)
{
  if(root == NULL)
  {
    return 0;
  }

  int lheight = height(root->left);
  int rheight = height(root->right);

  //printf("Lheight is %d\n",lheight);
  //printf("Rheight is %d\n",rheight);

  if(lheight > rheight)
  {
    return lheight+1;
  }
  return rheight+1;
}



int main()
{
  struct Node * root = newNode(1);
                root->left = newNode(2);
                root->left->left = newNode(10);
                root->left->right = newNode(12);
                root->right = newNode(3);
                root->right->left = newNode(15);
                root->right->right = newNode(18);


int treeHeight = height(root);

printf("The height of the tree --> %d =>",treeHeight);
}


/*

                                      1       ==> 0th Level
                                    /   \
                                  2      3    ==> 1st level
                                / \     / \
                              10  12  15  18   ==> 2nd Level


    */
