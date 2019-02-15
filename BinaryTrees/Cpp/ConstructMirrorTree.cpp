#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

struct Node{
  int data;
  struct Node *left;
  struct Node *right;

  Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};


/* inorder printing */

void inorder(struct Node * root)
{
  if(root == NULL){
    return ;
  }

  inorder(root->left);
  printf("%d => ",root->data);
  inorder(root->right);
}
/* Simple way to construct mirror tree is to traverse both sides and then swap the data */
void constructMirror(struct Node *root){

    if(root == NULL){
      return ;
    }

    constructMirror(root->left); // traversing the left Nodes
    constructMirror(root->right); // traversing the right Nodes

    /* Swapping the datas */
    struct Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

}
int main(){
  struct Node *root = new Node(1);
              root->left = new Node(2);
              root->right = new Node(3);
              root->left->left = new Node(4);
              root->left->right = new Node(5);
              root->right->left = new Node(6);
              root->right->right = new Node(7);

              printf("The inorder tree before mirror is \n");
              inorder(root);
              constructMirror(root);
              printf("\nThe inorder tree after the mirror is \n");
              inorder(root);

}
