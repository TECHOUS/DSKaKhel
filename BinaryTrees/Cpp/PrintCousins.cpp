#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct Node{
  int data;

  struct Node *left;
  struct Node *right;
};

struct Node *newNode(int data){
  struct Node *temp = (struct Node *) malloc (sizeof(struct Node));

  temp -> data = data;
  temp -> left = NULL;
  temp -> right = NULL;
  return temp;
}

/*

                              1
                            /   \
                           2     3
                          / \   /
                         4  5  6
                              /
                            7

                         1 2 3 4 5 6
                         if key == 6
                        1 2 3 is ignored as its their root or parents and semi parent;
                        4 5 is the cousin as 6 isnt present in its parent node.
                        ignore 6 as its the key


                         */

void findCousins(struct Node *root,int key){

    struct Node *first  = root;
    struct Node *second = root;

    if(root == NULL){
      return ;
    }

    if(root->data == key || (root->left->data == key || root->right->data == key)){
      cout<<"-1"<<endl;
    }

    else{

        if(root->right->left->data == key){
          printf("%d",root->left->left->data);
          printf("%d",root->left->right->data);
        }
    }

    findCousins(root->left,key);
    findCousins(root->right,key);
}

int main()
{
  struct Node *root = newNode(1);
            root->left = newNode(2);
            root->right = newNode(3);
            root->left->left = newNode(4);
            root->left->right = newNode(5);
            root->right->left = newNode(6);
            root->right->left->right = newNode(7);


      findCousins(root,4);


}
