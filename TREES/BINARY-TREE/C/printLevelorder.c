#include<stdio.h>
#include<malloc.h>

struct Node
{
  int data;
  struct Node *left,*right;
};


void printGivenLevel(struct Node* root, int level);
int height (struct Node * node);

struct Node * newNode(int data);

void printLevelOrder(struct Node * root)
{
  int h = height(root);
  int i;

  for(i = 1; i<= h ; i++)
  {
    printGivenLevel(root,i);
  }
}

void printGivenLevel(struct Node * root,int level)
{
  if(root == NULL)
  {
    return;
  }
  if(level == 1)
  {
    printf("%d",root->data);

  }
  else if(level > 1)
  {
    printGivenLevel(root->left , level -1);
    printGivenLevel(root->right , level -1);
  }
}

int height(struct Node * node)
{
  if(node == NULL)
  {
    return 0;
  }
  else
  {
    int lheight = height(node->left);
    int rheight = height(node->right);



    if(lheight > rheight)
    {
      return lheight+1;
    }
    else
    {
      return rheight+1;
    }
  }
}
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}
int main()
{
  struct Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root);

    return 0;
}
