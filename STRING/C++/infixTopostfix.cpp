/*#include<stdio.h>
#include<malloc.h>
int top = 0;
char *STACK;
char str[10000];
char *res;

/* for pushing the operators into stack */
/*
void push(char value)
{
  STACK[top++] = value;
}
/* for popping the operators into stack */
/*int pop()
{
  top--;
  return STACK[top];
}
/* for displaying the stack */
/*void displayStack()
{
  for(int i = 0 ; i < top ; i++)
  {
    printf("%c",STACK[i]);
  }
}

/* manually gives away the precedence */
/*int precedence(char op)
{
  if (op == '+' || op == '-')
  {
    return 1;
  }
  else if(op == '*' || op == '/')
  {
    return 2;
  }
  else
  {
    return -1;
  }
}
/* the conversion takes place here */
/*void infixTopostfix(char str[],int count)
{
  int i,k=0;
  char x;
  STACK = (char *) malloc((10*count) * sizeof(char));
  res = (char *) malloc((10*count) * sizeof(char));
  i = 0;
  push('(');
  while(str[i]!='\0')
  {
    if(str[i]>='a' && str[i]<='z')
    {
      res[k++] = str[i];
    }
    else if(str[i] == '+' || str[i] =='-' || str[i]=='*' || str[i]=='/')
    {
            x = pop();
        while(precedence(x) >= precedence(STACK[top]))
        {
          res[k++] = x;
          x = pop();
        }
        push(str[i]);
    }

    i++;
  }
  //printf("%d\n",top);
  puts(res);
  displayStack();
}

/* main function for function calling */
/*int main()
{
  int i = 0 ,count = 0;
  gets(str);
  while(str[i]!='\0')
  {
    count++;
    i++;
  }
  infixTopostfix(str,count);
  count = 0;


}
*/

#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
char stack[20];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

main()
{
    char exp[20];
    char *e, x;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c",pop());
            push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        printf("%c",pop());
    }
}
