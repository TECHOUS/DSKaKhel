#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{

  int data;
  struct Node * left;
  struct Node * right;
};
struct Node* root = NULL;
struct Node* newNode(int data)
{
  struct Node * temp = (struct Node*) malloc (sizeof(struct Node));
  temp->data = data; // data is added
  temp->left = NULL; // left root added
  temp->right = NULL; // right added

  return temp;
}

void inorderTraversal(struct Node *root)
{
  if(root == NULL)
  {
    return ;
  }
  inorderTraversal(root->left);
  printf("%d-> ",root->data);
  inorderTraversal(root->right);
}

void preOrderTraversal(struct Node *root)
{
  if(root == NULL)
  {
    return ;
  }


    printf("%d-> ",root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(struct Node *root)
{
  if(root == NULL)
  {
    return ;
  }

  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  printf("%d-> ",root->data);
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

  printf("\nThe Inorder Traversal of the tree is \n");
  inorderTraversal(root);
  printf("\nThe Preorder Traversal of the tree is \n");
  preOrderTraversal(root);
  printf("\nThe PostOrder Traversal of the tree is \n");
  postOrderTraversal(root);

}
