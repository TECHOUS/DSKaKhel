#include <stdio.h>
#include <string.h>

char arr[10000];
char stack[10000];
char ans[10000];
char new[10000];
int len = 0;

void push(char ch){
	stack[len] = ch;
	len++;
}

void pop(){
	if(len)
		len--;
	else
		return;
}

char peek(){
	if(len)
		return stack[len-1];
	else
		return '\0';
}

void print_st(){
	int flag = 0;
	for(int i=len-1;i>=0;i--){
		flag = 1;
		printf("%c ",stack[i]);
	}
	if(!flag)
		printf("stack is empty\n");
}

int check_prec(char ch){	
	if((ch=='/' || ch=='*') && (peek()=='+' || peek()=='-' || peek()=='(')){
		return 1;
	}
	else
		return 0;
}

void reverse(){	
	//reverse new
	int length = strlen(new);
	for(int i=length-1;i>=0;i--){
		if(new[i]=='(')
			arr[length-1-i] = ')';
		else if(new[i]==')')
			arr[length-1-i] = '(';
		else
			arr[length-1-i] = new[i];
	}
}

int main(){
	printf("Infix->Prefix\n");
	printf("enter the expression ");
	scanf("%s",new);
	printf("Prefix form->\n");
	reverse();
	int track = 0;
	for(int i=0;i<strlen(arr);i++){
		if(arr[i]=='+' || arr[i]=='-' || arr[i]=='*' || arr[i]=='/' || arr[i]=='(' || arr[i]==')'){
			
			if(len==0 || peek()=='(' || check_prec(arr[i])==1 || arr[i]=='('){
				push(arr[i]);
			}
			else{
				if(arr[i]==')'){
					while(peek()!='('){
						ans[track] = peek();
						track++;
						pop();
					}
					pop();
				}
				else{
					while(len!=0 && peek()!='('){
						ans[track] = peek();
						track++;
						pop();
					}
					push(arr[i]);
				}	
			}		
		}	
		else{
			ans[track] = arr[i];
			track++;
		}
	}
	while(len!=0){
		ans[track] = peek();
		track++;
		pop();
	}
	for(int i=strlen(ans)-1;i>=0;i--)
		printf("%c",ans[i]);
	printf("\n");
}