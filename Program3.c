//Program 3: Implement insertion and deletion (at the beginning, at specified location, at the end) on circular single linked list.
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *last = NULL;

void Display()
{
	int data;
    struct Node* temp;
    if (last == NULL){
    	printf("\nList is Empty");
	}
        
    else {
    	printf("\nCircular Linked List: ");
        temp = last->next;
		do{
			printf("%d ",temp->data);
			temp = temp->next;
		}while(temp!= last->next);
    }
}

void InsertAtBeginning(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (last == NULL){
		newNode->data = data;
		newNode->next=newNode;
		last=newNode;
	}
	
	else {
		newNode->data=data;
		newNode->next= last->next;
		last->next=newNode;
	}
}
void InsertAtEnd(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (last==NULL){
		newNode->data=data;
		newNode->next=newNode;
		last=newNode;
	}
	
	else{
		newNode->data=data;
		newNode->next=last->next;
		last->next=newNode;
		last=newNode;
	}
}
void InsertAtIndex(int data,int index){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	
	struct Node *temp = last;
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
	struct Node *newNode;
	if (last==NULL){
		printf("\nList is Empty.");
	}
	else
	{
		newNode=last->next;
		last->next = newNode->next;
		free(newNode); 
	}
}

void DeleteFromEnd(){
	struct Node *newNode,*temp;
	if (last==NULL){
		printf("\nList is Empty");
	}
	
	else {
		newNode=last;
		while(newNode->next!=last){
			temp=newNode;
			newNode=newNode->next;
		}
		temp->next=newNode->next;
		free(newNode);
	}
}

void DeleteFromIndex(int index){
	struct Node *temp = last;
	int i;
	for(i=1; i< index; i++) {
		if(temp->next!= last) {
		    temp = temp->next;
		}
	}
	temp->next = temp->next->next;
}

int main(){
	int choice;
	printf("\nCIRCULAR SINGLE LINKED LIST"); 
    do
	{	
		printf("\n\n******** MENU ********\n");
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

