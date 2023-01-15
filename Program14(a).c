//Program 14(a): Implement circular queue using arrays

#include<stdio.h>
#include<stdlib.h>

int n;
int Queue[50];
int front = -1;
int back  = -1;
	
void enqueue(int x){
	if(front== -1 && back == -1){
		front = 0;
		back  = 0;
		Queue[back] = x;
		printf("Element %d enqueued in the queue.",x);	
	}
	else if((back + 1) % n == front){
		printf("Queue is OverFlow!\n");
	}
	else{
		back = (back+1) % n;
		Queue[back] = x;
		printf("Element %d enqueued in the queue.",x);		
	}
}
			
void dequeue(){
	int x;
	if(front==-1 && back == -1){
		printf("Queue is UnderFlow!\n");
		return;
	}
	else if(front == back){
		printf("Element %d dequeued from the queue.",Queue[front]);
		front = -1;
		back  = -1;		
	}
	else{
		printf("Element %d dequeued from the queue.",Queue[front]);
		front = (front + 1) % n; 	
	}
}

void display(){
	int i;
	if (front == -1 && back == -1){
		printf("Queue is Underflow!\n");
		return;
	}
	else{
		printf("Queue: ");
		for (i = front; i <= back; i++){
			printf("%d  ",Queue[i]);
		}	
	}
}


int main(){
	printf("Enter size of the Queue: ");
	scanf("%d",&n);
	
	int choice;
	
	do
	{
		printf ("\n-----------------------------------");
		printf ("\n        QUEUE USING ARRRAYS        ");	
		printf ("\n-----------------------------------");		
		printf ("\nOPERATIONS:\n1. enqueue()\n2. dequeue()\n3. Display \n4. Exit\n");
	
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
			display();
		}
		
		else if(choice == 4){
			exit(0);
		}
		
		else{
			printf("Invalid choice!");
		}
	}
	while (choice!=4);
	return 0;
}


