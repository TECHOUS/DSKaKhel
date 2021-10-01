#include <stdio.h>
#include <malloc.h>
struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *root = NULL;

void insert(int data)
{
  struct Node *tempNode = (struct Node *)malloc(sizeof(struct Node));
  struct Node *current;
  struct Node *parent;

  tempNode->data = data;
  tempNode->left = NULL;
  tempNode->right = NULL;

  //if tree is empty

  if (root == NULL)
  {
    root = tempNode;
  }
  else
  {
    current = root;
    parent = NULL;

    while (1)
    {
      parent = current;
      if (data < parent->data)
      {
        current = current->left;

        if (current == NULL)
        {
          parent->left = tempNode;
          return;
        }
      }
      else
      {
        current = current->right;

        if (current == NULL)
        {
          parent->right = tempNode;
          return;
        }
      }
    }
  }
}

struct Node *search(int data)
{
  struct Node *current = root;

  printf("visiting elements");

  while (current->data != data)
  {
    if (current != NULL)
    {
      printf("%d", current->data);

      if (current->data > data)
      {
        current = current->left;
      }
      else
      {
        current = current->right;
      }
    }
    if (current == NULL)
    {
      return NULL;
    }
  }

  return current;
}

void printInorder(struct Node *root)
{

  if (root == NULL)
  {
    return;
  }

  printInorder(root->left);
  printf("%d ", root->data);
  printInorder(root->right);
}
int main()
{
  int i;
  int array[7] = {27, 14, 35, 10, 19, 31, 42};

  for (i = 0; i < 7; i++)
    insert(array[i]);

  i = 31;
  struct Node *temp = search(i);

  if (temp != NULL)
  {
    printf("[%d] Element found.", temp->data);
    printf("\n");
  }
  else
  {
    printf("[ x ] Element not found (%d).\n", i);
  }

  i = 15;
  temp = search(i);

  if (temp != NULL)
  {
    printf("[%d] Element found.", temp->data);
    printf("\n");
  }
  else
  {
    printf("[ x ] Element not found (%d).\n", i);
  }

  printf("\nInorder traversal: ");
  printInorder(root);
  return 0;
}
