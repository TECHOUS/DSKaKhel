#include<stdio.h>
#include<malloc.h>
#define SIZE 10
int top = 0;
int top1 = 0;
int *stack;
int *stack1;

void push(int value)
{
  stack[top++] = value;
}
void pushRev(int value)
{
  stack1[top1++] = value;
}

int pop()
{
  top--;
  return stack[top];
}
void reverseStack() // this is with extra space
{
  stack1 = (int * ) malloc(SIZE * sizeof(int));
  while(top!=0)
  {
    pushRev(pop());
  }

  for(int i = 0 ; i < top1 ; i++)
  {
    printf("%d",stack1[i]);
  }
}
int main()
{
  stack = (int *) malloc (SIZE * sizeof(int));
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  reverseStack();
}
