#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define SIZE 100
char Stack[SIZE];
int top = -1;

int isEmpty()
{
  return top == -1;
}
int isFull()
{
  return top == SIZE-1;
}

void push(char value)
{

    Stack[top++] = value;
}

int pop()
{
  top--;
  return Stack[top];
}
void evalExpression(char *str);
int main()
{
  char * str;
  str = (char*)malloc(10*sizeof(char));
  gets(str);
  evalExpression(str);
}

void evalExpression(char *str)
{
  int i = 0;
  while(str[i] != '\0')
  {
    //printf("%c",str[i]);
    if(isdigit(str[i]))
    {

      push(str[i]-'0');
    }
    else
    {
      int op2 = pop();
      int op1 = pop();
    //  printf("The values are %d %d",op1,op2);
      //printf("The char is %c",str[i]);
      switch (str[i])
      {
        case '+' :  push(op2+op1); break;
        case '-' : push(op2-op1); break;
        case '*' : push(op2*op1); break;
        case '/' : push(op2 / op1); break;
      }
    }
    i++;
  }
  printf("%d",pop());
}
