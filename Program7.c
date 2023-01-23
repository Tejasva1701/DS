//Program 7: To merge two sorted linked lists and display the final sorted linked list

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
} *head = NULL, *first = NULL, *second = NULL, *third = NULL, *last = NULL;

struct Node *Create(int A[], int n){
    int i;
    struct Node *temp, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;

    for (i = 1; i < n; i++){
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
    return head;
}

void Display(struct Node *temp){
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Merge(struct Node *first, struct Node *second){
    if (first->data < second->data){
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    else{
        third = last = second;
        second = second->next;
        last->next = NULL;
    }

    while (first != NULL && second != NULL){
        if (first->data < second->data){
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else{
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }

    if (first != NULL)
        last->next = first;
    else
        last->next = second;
}

void sort(struct Node *temp){ 
    int swapped, i; 
    struct Node *ptr1; 
    struct Node *ptr2 = NULL; 
    
    if (temp == NULL) 
        return; 
  
    do{ 
        swapped = 0; 
        ptr1 = temp; 
  
        while (ptr1->next != ptr2){ 
            if (ptr1->data > ptr1->next->data){ 
            	int t = ptr1->data; 
    			ptr1->data = ptr1->next->data; 
    			ptr1->next->data = t;
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        ptr2 = ptr1; 
    } while (swapped); 
} 
 
int main(){
    int n1, n2;
    printf("Enter the size of List 1: ");
    scanf("%d", &n1);
    int a[n1];
    printf("Enter elements for Linked list 1:\n");
    int i;
	for (i = 0; i < n1; i++)
        scanf("%d", &a[i]);
    printf("\nEnter the size of List 2:");
    scanf("%d", &n2);
    int b[n2];
    printf("Enter elements for Linked list 2:\n");
    for (i = 0; i < n2; i++){
        scanf("%d", &b[i]);
    }
    first = Create(a, n1);
    second = Create(b, n2);
	
	printf("\nSorted Linked List 1: ");
	sort(first);
    Display(first);
	
	printf("\nSorted Linked List 2: ");
	sort(second);
    Display(second);

    Merge(first, second);

    printf("\nFinal Merged Linked List: \n");
    Display(third);
    return 0;
}


