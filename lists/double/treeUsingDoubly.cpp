#include<stdio.h>
#include<malloc.h>
#include <iostream>

using namespace std;
/*
 Process execution
 +++++++++++++++++++
The idea can be described using below steps.
1) Write a general purpose function that concatenates two given circular doubly lists (This function is explained below).
2) Now traverse the given tree
….a) Recursively convert left subtree to a circular DLL. Let the converted list be leftList.
….a) Recursively convert right subtree to a circular DLL. Let the converted list be rightList.
….c) Make a circular linked list of root of the tree, make left and right of root to point to itself.
….d) Concatenate leftList with list of single root node.
….e) Concatenate the list produced in step above (d) with rightList.

Note that the above code traverses tree in Postorder fashion. We can traverse in inorder fashion also. We can first concatenate left subtree and root, then recur for right subtree and concatenate the result with left-root concatenation.

*/

/*

How to Concatenate two circular DLLs?

Get the last node of the left list. Retrieving the last node is an O(1) operation, since the prev pointer of the head points to the last node of the list.
Connect it with the first node of the right list
Get the last node of the second list
Connect it with the head of the list.
*/

struct NODE
{
  struct NODE *left,*right;
  int data;
};

// append  rightlist at the end of leftList

NODE *concatenate(NODE *leftlist , NODE *rightlist)
{
  // if any of the list is empty return the other list
  if(leftlist == NULL)
  {
    return rightlist;
  }
  if(rightlist == NULL)
  {
    return leftlist;
  }

  // store the last node of left list;
  NODE *leftLast = leftlist->left;
  // store the last node of the right list;
  NODE *rightLast = rightlist->left;

// connect the last node of the left list  with the first node of the right list
leftLast->right = rightlist;
rightlist->left= leftLast;

// left of the first node points to the last of the rightlist;
  leftlist->left=rightLast;
// right nodes last refers to the first of the node list
  rightLast->right = leftlist;

  return leftlist;
}

NODE *binTreelist(NODE *root)
{
  if(root == NULL)
  {
    return NULL;
  }
  NODE *left = binTreelist(root->left);
  NODE *right = binTreelist(root->right);
  root->left = root->right = root;
  return concatenate(concatenate(left,root),right);
}


void displayCirList(NODE *head)
{
  cout<<"The circular list in the whole code is"<<endl;

  NODE *it = head;

  do{
    cout<<it->data<<endl;
    it = it->right;
  }
  while(head!=it);
  cout<<"\n";
}

NODE *newNode(int data)
{
    NODE *temp = new NODE();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
  NODE *root = newNode(4);
  root->left = newNode(2);
  root->right = newNode(5);
  root->left->left = newNode(1);
  root->left->right = newNode(3);
  root->right->left = newNode(6);


  NODE *head = binTreelist(root);
  displayCirList(head);
  return 0;
}
