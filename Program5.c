//Program 5: Implement insertion and deletion (at the beginning, at specified location, at the end) on circular double linked list

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;

void InsertAtBeginning(int x){
	struct Node *ptr= (struct Node *)malloc(sizeof(struct Node));
    ptr->data = x;
    ptr->next = head;
    ptr->prev = NULL;

    if (head == NULL)
    {
        ptr->next = ptr;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
    head = ptr;
}

void InsertAtEnd(int x)
{
    struct Node *ptr = head;
    struct Node *temp;

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->prev = ptr;
    temp->next = head;
}

void InsertAtIndex(int index,int x){
    struct Node *ptr = head;
    struct Node *temp;
    int i;

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;

    for (i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next = temp;
}

void DeleteFromBeginning()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
		struct Node *ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        struct Node *temp = malloc(sizeof(struct Node));
        temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = ptr;
        ptr->next = head;
        free(temp);
    }
}

void DeleteFromEnd()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        struct Node *temp;
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->prev->next = head;
        head->prev = temp->prev;
        temp->prev = NULL;
        temp->next = NULL;
        free(temp);
    }
}

void DeleteFromIndex(struct Node *ptr, int index)
{
    struct Node *q = NULL;
    int x = -1, i;
    if (index == 1)
    {
        q = head;
        x = head->data;

        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = head->next;
        head = head->next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = ptr;
            ptr = ptr->next;
        }
        q->next = ptr->next;
        x = ptr->data;
        free(ptr);
        return x;
    }
}

void Display()
{
    if (head == NULL)
    {
        printf("\nList is Empty");
        return;
    }
    else
    {
        struct Node *temp = head;
        printf("Circular Double Linked list: ");
        while (temp->next != head)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
}

int main()
{
	int choice;
   	printf("\nCIRCULAR DOUBLE LINKED LIST ");
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
        	InsertAtIndex(pos+1,x);
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
	        DeleteFromIndex(head,pos+1);
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


