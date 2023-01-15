//Program 13: Implement operations (enqueue, dequeue) on a queue using arrays. 
//Check the status of the queue whether it is empty or full.
 
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
	printf("Element %d enqueued in the queue.\n",x);	
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
	printf("Element dequeued from the queue.\n") ;
}

void display(){
	int i;
	if (front == -1 || front > back){
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

