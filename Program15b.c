#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
struct Node* front = NULL;
struct Node* back  = NULL;
void enqueue(int data){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 						
	temp->data = data;	
	if (front==NULL){
		front=temp;
	}
	else {
		back->next = temp;
	}
	back = temp;
	back->next = front;
	printf("Element %d enqueued in the Queue.",data);
}

		
int dequeue(){	
	struct Node* temp;
	temp = front;
	int data;
	if (front == NULL){
		printf("\nQueue is Underflow!");
		return -1;
	}
	else if(front == back){
		data= front->data;
		free(front);
		printf("Element dequeued from the queue.");
		front= NULL;
		back = NULL;		
	}
	else {
		front = front->next;
		back->next= front;
		free(temp);
		printf("Element dequeued from the queue.");
	}
	return data;
}

int main(){
	int choice;
	
	do
	{
		printf ("\n-----------------------------------");
		printf ("\n      QUEUE USING LINKED LIST      ");	
		printf ("\n-----------------------------------");		
		printf ("\nOPERATIONS:\n1. enqueue()\n2. dequeue()\n3. Exit\n");
	
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		if(choice == 1){
			int x;
			printf("Enter the value: ");
			scanf("%d",&x);
			enqueue(x);
		}
		
		else if(choice == 2){
			dequeue();
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
