#include<stdio.h>
#include<string.h>
char arr[10000];
char stack[10000];
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
int main(){
	printf("enter the string: ");
	scanf("%s",arr);
	for(int i=0;i<strlen(arr)/2;i++){
		push(arr[i]);
	}
	int flag = 0;
	if(strlen(arr) % 2){
		for(int i=strlen(arr)/2 + 1;i<strlen(arr);i++){
			if(peek() != arr[i]){
				printf("string is not palindrome\n");
				flag = 1;
				break;
			}
			else
				pop();
		}
	}
	else{
		for(int i=strlen(arr)/2;i<strlen(arr);i++){
			if(peek() != arr[i]){
				printf("string is not palindrome\n");
				flag = 1;				
				break;
			}
			else{
				pop();
			}
		}
	}
	if(!flag)
		printf("string is a palindrome\n");
}