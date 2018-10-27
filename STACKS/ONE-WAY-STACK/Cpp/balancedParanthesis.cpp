#include<stdio.h>
#include<malloc.h>

int top = 0;
 char *stack;

/* Basic push pop implementation */
void push(char value)
{
  stack[top++] = value;
}
int pop()
{
  top--;
  return stack[top];
}
/* ******************************************* */

/* display function */
void display()
{
  for(int i = 0 ; i < top ; i++)
  {
    printf(" %c",stack[i]);
  }
}

void balancedParanthesis(char expression[])
{
  stack = (char *) malloc (10 * sizeof(char));
  int i = 0 ;
  while(expression[i] != '\0')
  {
    if (expression[i] == '[' || expression[i]=='{' || expression[i]== '(')
    {
      push(expression[i]);
    }

    i++;
  }
  printf("%d",top);
      display();
}

int main()
{
  int ans;
  char str[1000];
  gets(str);
  balancedParanthesis(str);
  return 0;
}
