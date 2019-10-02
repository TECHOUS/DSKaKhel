#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* front;
struct node* rear;

struct node* getnewnode(int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
}
void enqueue(int data){
	if(front == NULL){
		front = getnewnode(data);
		rear = front;
		return;
	}
	rear->next = getnewnode(data);
	rear = rear->next;
}
void dequeue(){
	if(front == rear){
		struct node* temp = front;
		free(temp);
		front = rear = NULL;
		return;
	}
	struct node* temp = front;
	front = front->next;
	free(temp);
}
void print_ll(){
	struct node* temp = front;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}
void search(int val){
	struct node* temp = front;
	int i=1;
	while(temp != NULL){
		if(temp->data == val){
			printf("%d is found at position %d\n",val,i);
			return;
		}
		i++;
		temp = temp->next;
	}
	printf("%d is not present in the list\n",val);
}
int main(){
	front = NULL;rear = NULL;
	printf("operations in the queue are-> 0-enqueue, 1-dequeue, 2-search, 3-display, 4-display front, 5-display rear, 6-check if empty ");
	while(1){
	printf("\nenter your choice ");int q;scanf("%d",&q);
		switch(q){
			case(0):
				printf("enter number to be inserted ");
				int num;
				scanf("%d",&num);	
				enqueue(num);
				print_ll();
			break;
			case(1):
				if(front == NULL)
					printf("queue is empty\n");
				else{
					dequeue();
					print_ll();
				}
			break;
			case(2):
				if(front == NULL)
					printf("queue is empty\n");
				else{
					printf("\nenter the number to be searched ");
					int val;scanf("%d",&val);
					search(val);
				}
			break;
			case(3):
				if(front == NULL)
					printf("queue is empty\n");
				else
					print_ll();
			break;
			case(4):
				printf("%d",front->data);
				break;
			case(5):
				printf("%d",rear->data);
				break;
			case(6):
				if(front == NULL)
					printf("queue is empty\n");
				else
					printf("queue is not empty\n");
			break;
			default:
				printf("invalid");
		}
	printf("\ndo you want to continue(y/n)? ");
	char ch;scanf(" %c",&ch);
	if(ch=='y')
		continue;
	else
		break;
	}
}