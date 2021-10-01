#include<iostream>
#include<stdlib.h>
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


int countLeafNodes(struct Node *root){

  if(root == NULL){
    return 0;
  }

  if(root->left == NULL && root->right == NULL){
    return 1;
  }

  return countLeafNodes(root->left) + countLeafNodes(root->right);

}

int countNonLeafNodes(struct Node *root){

  if(root == NULL || (root->left == NULL && root->right == NULL))
  {
    return 0;
  }

  return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}

int main(){

  struct Node *root = new Node(1);

  root->left = new Node(2);
  root->left->left = new Node(3);
  root->left->right = new Node(4);
  root->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);


  int leaf = countLeafNodes(root);
  int nonLeaf = countNonLeafNodes(root);
  cout<<"The Leaf Nodes are " << leaf << endl;
  cout<<"the Non Leaf Nodes are " << nonLeaf << endl;
}
