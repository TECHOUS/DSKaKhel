
#include <stdio.h>
#include <malloc.h>

struct node
{
  int data;
  struct node *link;
};
struct node * root;
void insertTail(int value)
{
  struct node* temp;
  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = value;
  temp->link = NULL;

  if(root == NULL)
  {
    root = temp;
  }
  else
  {
    struct node*p;
    p = root;

    while(p->link != NULL)
    {
      p = p->link;
    }
    p->link = temp; // the tempnode becomes the newNode;
    temp->link = NULL; // the link of the tempNode becomes NULL;
  }
}
int length()
{
  int count = 0;
  struct node *temp ;
  temp = root;

  while(temp != NULL)
  {
    count++;
    temp = temp->link;
  }
return count;
}
void reverseList()
{
  int i = 0; // the first node
  int j = length()-1; // the last node
  struct node *p,*q;
  p=q=root; // both pointing to root, do not disturb the head.

  while(i<j)
  {
    int k = 0; // temporary variable

    while(k<j) // while(k doesnt reach the end of the node, cause we want q to point to the last node for swapping data)
    {
      k++;
      q = q-> link; // q points to the last node , then goes back to root address then again points to the second last node and then the thirdlast and so on
    }
    // same as array reverse
    int temp = p->data;
    p->data = q->data;
    q->data = temp;
    // incrementing i and decrementing j for swapping
    i++;
    j--;
    p = p->link; // p points to the next node
    q = root; // q goes back to the starting position as singly_linkedlist cant go backward
  }
}

void display()
{
  struct node*temp;
  temp = root;

  while(temp != NULL)
  {
    printf("The node is %d\n",temp->data);
    temp = temp->link;
  }
}
int main()
{
  insertTail(1);
  insertTail(2);
  insertTail(3);
  insertTail(4);
  insertTail(5);

  display();

  printf("the nodes after reversing are\n");
  reverseList();
  display();
}
