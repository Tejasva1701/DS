//Program 9: Implement operations (push, pop) on a stack using arrays. 
//Check the status of the stack whether there is underflow or overflow. 

#include <stdio.h>
#include <stdlib.h>

int n;
int stack[100];
int top=-1;
void push(int x){
	if(top == n-1){
		printf("Stack Overflow!\n");
		return;
	}
	top++;
	stack[top] = x;
	printf("Element %d pushed in the stack.",x);		
}
		
void pop(){
	if(top == -1){
		printf ("Stack Underflow!\n");
		return;
	}
	top--;
	printf("Element popped from the stack.");
}

void display() {
   	if(top >= 0) {
      	printf("Stack: ");
      	int i;
      	for(i=top; i>=0; i--){
      		printf("%d ",stack[i]);
		}
		printf("\n");	
   } 
   	else{
   		printf("Stack Underflow!");
	   }
}

int main(){
	printf("Enter size of the stack: ");
	scanf("%d",&n);
		
	int choice;
	
	do
	{
		printf ("\n-----------------------------------");
		printf ("\n        STACK USING ARRRAYS        ");	
		printf ("\n-----------------------------------");		
		printf ("\nOPERATIONS:\n1. push()\n2. pop()\n3. Display \n4. Exit\n");
	
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


