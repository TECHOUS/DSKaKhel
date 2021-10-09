#include<stdio.h>
#include<malloc.h>

struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};

int search(int arr[],int start,int end,int value);

struct Node * newNode(int data);

struct Node * buildTree(int in[],int pre[],int inStrt,int inEnd)
{
  static int preIndex = 0;

  if(inStrt > inEnd)
  {
    return NULL;
  }

  struct Node *tNode = newNode(pre[preIndex++]);

  if(inStrt == inEnd)
  {
    return tNode;
  }

  int inIndex = search(in,inStrt,inEnd,tNode->data);

  tNode->left = buildTree(in,pre,inStrt,inIndex-1);
  tNode->right = buildTree(in , pre , inIndex+1, inEnd);
  return tNode;
}

int search(int arr[],int strt,int end,int value)
{
  int i ;
  for(i = strt ; i <= end ; i++)
  {
    if(arr[i] == value)
    {
      return i;
    }
  }
}

struct Node *newNode(int data)
{
  struct Node *node = (struct Node *) malloc ( sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node -> right = NULL;

  return(node);
}

void printInorder(struct Node* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    printf("%d ", node->data);

    /* now recur on right child */
    printInorder(node->right);
}

int main()
{
  int in[] = { 1,2,3,4,5 };
    int pre[] = { 4,2,1,3,5 };
    int len = sizeof(in) / sizeof(in[0]);
    struct node* root = buildTree(in, pre, 0, len - 1);

    /* Let us test the built tree by printing Insorder traversal */
    printf("Inorder traversal of the constructed tree is \n");
    printInorder(root);
}
