//Program 2: Implement insertion and deletion (at the beginning, at specified location, at the end) on single linked list.
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};
struct Node* head = NULL;

void Display(){
	struct Node *temp = head;
	if (head == NULL){
    	printf("\nList is empty!");
	}
	else{
		printf("\nSingle Linked List: ");
		while(temp != NULL) {
		  	printf("%d ->",temp->data);
		  	temp = temp->next;
		}
		printf("NULL");	
	}
}

void InsertAtBeginning(int data){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}

void InsertAtEnd(int data){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	
	struct Node *temp = head;
	while(temp->next != NULL){
	  temp = temp->next;
	}
	temp->next = newNode;	
}

void InsertAtIndex(int data, int index){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	
	struct Node *temp = head;
	int i;
	for(i=1; i < index; i++) {
	    if(temp->next != NULL){
	    	temp = temp->next;
	  	}
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

void DeleteFromBeginning(){
	if (head==NULL){
		printf("\nList is Empty.");
	}
	else{
		struct Node *temp = head;
		head = head->next;
		free(temp); 
	}
}

void DeleteFromEnd(){
	struct 	Node* temp = head;
	if (head==NULL){
		printf("\nList is Empty");
	}
	else{
		while(temp->next->next!=NULL){
		temp = temp->next;
		}
		temp->next = NULL;
	}
}

void DeleteFromIndex(int index){
	struct Node *temp = head;
	int i;
	for(i=1; i< index; i++) {
		if(temp->next!=NULL) {
		    temp = temp->next;
		}
	}
	temp->next = temp->next->next;
}


int main(){
	int choice; 
	printf("\nSINGLE LINKED LIST ");
    do
	{
		printf("\n******** MENU ********\n");
    	printf("1.Insertion At Beginning\n");
		printf("2.Insertion At End\n");
		printf("3.Insertion at a Specified Location\n");
		printf("4.Deletion From Beginning\n");
		printf("5.Deletion From End\n");
		printf("6.Deletion at a Specified Location\n");
		printf("7.Exit\n"); 
	
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		if(choice == 1){
			int x;
			printf("Enter the element: ");
	    	scanf("%d",&x);
	        InsertAtBeginning(x);
        	Display();
		}
		
		else if(choice == 2){
			int x;
			printf("Enter the element: ");
	    	scanf("%d",&x);
	        InsertAtEnd(x);
			Display();
		}
		
		else if(choice == 3){
			int x,pos;
			printf("Enter the element and index at which you want to insert it: ");
	    	scanf("%d%d",&x,&pos);
        	InsertAtIndex(x,pos);
			Display();  
		}
		
		else if(choice == 4){
			DeleteFromBeginning();
	        printf("Element Deleted from Beginning!");
			Display(); 
		}
		
		else if(choice == 5){
			DeleteFromEnd();
	        printf("Element Deleted from End!");
	        Display();
		}
		
		else if(choice == 6){
			int pos;
			printf("Enter the index from where you want to deleted an element: ");
        	scanf("%d",&pos);
	        DeleteFromIndex(pos);
			Display();  
		}
		
		else if(choice == 7){
			exit(0);
		}
		
		else{
			printf("Invalid choice!");
		}
	}
	while (choice!=7);
	return 0;
}

