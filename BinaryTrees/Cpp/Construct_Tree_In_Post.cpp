#include<iostream>
#include<stdlib.h>
using namespace std;

/*
                               1      => ROOT
                          /         \
                        2           3   => level 1
                      / \          /
                    4    5        6    => level 2

                    inorder = (left->root->right)  => [4,2,5,1,6,3];
                    postorder = (left->right->root) => [4,5,2,6,3,1];
                    preorder = (root->left->right) => [1,2,4,5,3,6];

                    pseudocode;
*/

struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *newNode(int data){
  struct Node *tempNode = (struct Node *) malloc ( sizeof(struct Node) );
  tempNode -> data = data;
  tempNode -> left = NULL;
  tempNode -> right = NULL;
  return tempNode;
}

int find_Inorder_Index(int inorder[],int data , int size)
{
  printf("The data is %d\n",data);
  int i;
  for(i = size ; i >= 0 ; i--)
  {
    if(inorder[i] == data)
    {
      break;
    }
  }
  return i;
}

struct Node *buildNodes(int in[],int post[],int start,int end,int *end_root)
{

  if(start > end){
    return NULL;
  }


  struct Node *root = newNode(post[*end_root]);
  (*end_root)--;
  if(start == end){
    return root;
  }
  // this will search the data in the inorder array and return the index
  int searchIndex = find_Inorder_Index(in,root->data,end);

  // this whole thing will construct the right side of the tree
  root->right = buildNodes(in,post,searchIndex+1,end,end_root);

  // this whole thing will construct the left side of the tree
  root->left = buildNodes(in,post,start,searchIndex-1,end_root);

  return (root);

}

struct Node *constructTree(int in[],int post[],int N)
{
  int end_root = N-1;
  // sending the address of the end root
  struct Node *root = buildNodes(in,post,0,N-1,&end_root);
  return (root);
}

void printPreorder(struct Node *root){

  if(root == NULL){
    return ;
  }

  printf("%d=>",root->data);
  printPreorder(root->left);
  printPreorder(root->right);
}

int main(){

    int in[6] = {4,2,5,1,6,3};
    int post[6] = {4,5,2,6,3,1};
    int N = 6;
    struct Node *root;

    root = constructTree(in,post,N);
    printPreorder(root);
}
