#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

/*                                  *curr
                                    1
                                  /   \
                                2       3
                              /   \    /  \
                              4    5   6   7

                Right Node of 2 => 3;
                Right Node of 4 => 5 6 7;

                COMPLETED

                              */

struct Node *newNode(int data){

      struct Node *tempNode = (struct Node *) malloc (  sizeof(struct Node) );
      tempNode -> data  = data;
      tempNode -> left = NULL;
      tempNode ->right = NULL;

      return tempNode;
    }

void findRightNodes(struct Node *root , int key){

  queue <Node *> q ;
  struct Node *curr = root;
  if(root == NULL){
      return;
    }


    q.push(curr);


  while(!q.empty())
  {
    // curr = q.pop();
    //cout<<curr->data<<endl;
    if(curr->left != NULL){
      q.push(curr->left);
    }
    if(curr->right != NULL){
      q.push(curr->right);
    }

    if(curr->data == key){
      q.pop();
      cout<< q.front()->data;
      break;
    }
    q.pop();
    curr = q.front();
  }

}




int main(){

  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);

  findRightNodes(root,6);
}
