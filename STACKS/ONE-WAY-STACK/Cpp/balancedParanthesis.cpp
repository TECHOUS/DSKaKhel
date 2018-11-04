#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
bool isempty();

/*=======> IMPLEMENTATION OF STACK <=======*/
static int top = -1; //storing top of a stack
char *stack; //dynamic stack


/*===============> ISEMPTY <===============*/
//returns boolean whether the stack is empty or not
bool isempty()
{
  return top==-1;
}

/*================> PUSH <=================*/
void push(char value)
{
  stack[++top] = value;
}

/*================> POP <==================*/
void pop()
{
  if(isempty())
  {
    cout << "UNDERFLOW" << endl;
    exit(0);
  }
  stack[top]=0;
  top--;
}

/*================> PEEK <=================*/
//return the top element of the stack
char peek()
{
  return stack[top];
}

/*==============> print the stack <=========*/
void display()
{
  for(int i = 0 ; i <= top ; i++)
  {
    cout <<"| " <<stack[i]<<" |"<<endl;
  }
  if(top!=-1)
  {
    cout << "-----" << endl;
  }
}

/*==================> SIZE <==============*/
int size()
{
  return top+1;
}
/* ******************************************* */
//returns the bracket inversion
char invertBracket(char expr)
{
  switch(expr)
  {
    case ']':
      return '[';
    case '}':
      return '{';
    case ')':
      return '(';
    default:
      return ' ';
  }
}
bool balancedParanthesis(string expression)
{
  stack = new char[expression.size()]; //allocating dynamic stack
  
  int i = 0;
  while(expression[i] != '\0')
  {
    if(expression[i] == '[' || expression[i]=='{' || expression[i]== '(')
    {
      push(expression[i]);
    }
    else if(expression[i]==']' || expression[i]=='}' || expression[i]==')')
    {
      if(isempty())
      {
        return false;
      }
      //check top
      if(invertBracket(expression[i])==peek()) //if bracket is same as the top element of the stack
      {
        pop();
      }
    }
    i++;
  }
  if(isempty())
  {
    delete [] stack;
    return true;
  }
  else
  {
    delete [] stack;
    return false;
  }
}

int main()
{
  int ans;
  string str;
  getline(cin,str);
  if(balancedParanthesis(str))
  {
    cout << "BRACKETS ARE BALANCED" << endl;
  }
  else
  {
    cout << "BRACKETS NOT BALANCED" << endl;
  }
}
