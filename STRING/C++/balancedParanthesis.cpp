#include<iostream>
#include <stack>
#include<string.h>
using namespace std;
// logic of the balanced paranthesis problem {{}}
int balancedParanthesis(char expression[])
{
  stack <char> s;
  int x;

  for(int i = 0 ; i < strlen(expression); i++)
  {
    if(expression[i] == '{')
    {
      s.push(expression[i]);
    }
    else
    {
      s.pop();
    }
  }

    if(s.empty())
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }

int main()
{
  int ans;
  char str[1000];
  gets(str);
  if(balancedParanthesis(str) == 1){
    cout<<"Balanced";
  }
  else{
    cout<<"Not balanced";
  }
  return 0;
}
