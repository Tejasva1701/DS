#include<stdio.h>
#include<stdlib.h>

int n;
int Queue[50];
int front = -1;
int back  = -1;

void enqueue(int x){
	if(back == n-1){
		printf("Queue is OverFlow!\n");
		return;
	}
	back++;
	Queue[back] = x;
	printf("Element %d enqueued in the queue.",x);	
	if(front == -1){
		front++;
	}
}
		
void dequeue(){
	if(front==-1 || front>back){
		printf("Queue is UnderFlow!\n");
		return;
	}
	front++;
	printf("Element dequeued from the queue.") ;
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
