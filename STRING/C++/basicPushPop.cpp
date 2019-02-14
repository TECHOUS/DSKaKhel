#include<stdio.h>
#include<malloc.h>

int top = 0;
int * STACK;
void push(int value)
{
  STACK[top++] = value;
}
int pop()
{
  top--;
  return STACK[top];
}

void display()
{
  for(int i = top ; i >= 0 ; i--)
  {
    printf("%d\n",STACK[i]);
  }
}

int main()
{
  int size,choice,element;
  printf("Enter the size of the stack\n");
  scanf("%d",&size);

  STACK = (int *) malloc(size * sizeof(int));
  printf("ENTER YOUR CHOICE\n1.PUSH()\n2.POP() and display the popped element\n3.display()\n");
  scanf("%d",&choice);
  while(choice != -1)
  {
    switch(choice)
    {
      case 1:
          printf("\nENTER THE ELEMENT TO PUSH\n");
          scanf("%d",&element);
          push(element);
      break;
      case 2:
          printf("\nThe popped element is : %d\n",pop());
      break;
      case 3:
      printf("\nTHIS IS THE DISPLAY PART\n");
      display();
      break;
    }
    printf("\nENTER YOUR CHOICE\n1.PUSH()\n2.POP() and display the popped element\n3.display()\n");
    scanf("%d",&choice);
  }
  return 0;
}
