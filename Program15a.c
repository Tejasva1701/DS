#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
struct Node* top = NULL;

void push(int data){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 			
	temp->data = data;	
	if (top==NULL){
		temp-> next=NULL;
	}
	else {
		temp->next = top;
	}
	top = temp;
	printf("Element %d pushed in the stack.",data);
}

void pop(){	
	if (top == NULL) {
		printf("\nStack Underflow!");
	}
	else {
		struct Node* temp;
		temp = top;
		top = top->next;
		free(temp);
		printf("Element dequeued from the queue.");
	}
}
	
int main(){
	int choice;
	
	do
	{
		printf ("\n-----------------------------------");
		printf ("\n      STACKS USING LINKED LIST      ");	
		printf ("\n-----------------------------------");		
		printf ("\nOPERATIONS:\n1. push()\n2. pop()\n3. Exit\n");
	
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		if(choice == 1){
			int x;
			printf("Enter the value: ");
			scanf("%d",&x);
			push(x);
		}
		
		else if(choice == 2){
			pop();
		}
		

		else if(choice == 3){
			exit(0);
		}
		
		else{
			printf("Invalid choice!");
		}
	}
	while (choice!=3);
	return 0;
}
