#include<iostream>
#include<stdlib.h>
using namespace std;
/*
  Using recursion it holds all the node values such that they print when the level returns to 1.

                          1   ==> 1 ===> PRINT 1
                        /   \
                      2       3 ==> 2 ==> PRINT 2 3
                    /   \    /  \
                  4     5   6    7 ==> 3 ==> PRINT 4 5 6 7

*/



struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node* root = NULL;

struct Node *newNode(int data){
  struct Node* temp = (struct Node*) malloc ( sizeof(struct Node));
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;


  return temp;
}

int height(struct Node* root){
  if(root == NULL){
    return 0;
  }

  int lheight = height(root->left);
  int rheight = height(root->right);

  if(lheight > rheight){
    return lheight+1;
  }
  return rheight + 1;

}

void levelOrder(struct Node * root,int level)
{
  if(root == NULL)
  {
    return ;
  }

  if(level == 1)
  {
    printf("%d -> ",root->data);
  }
  if(level > 1)
  {
    levelOrder(root->left,level-1);
    levelOrder(root->right,level-1);
  }

}


void printLevelOrder(struct Node* root){
  int treeHeight = height(root);
  int i;

  for(i = 1 ; i <= treeHeight ; i++)
  {
    levelOrder(root,i);
    printf("\n");
  }
}



int main()
{
  struct Node* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);

  printLevelOrder(root);
}
