//Program 6: To count the number of nodes & reverse the single linked list.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head;

void createList(int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void count(){

    struct Node *temp = head;
    int c = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    printf("\nTotal number of nodes: %d", c);
    printf("\n"); 
}

void display(){
    if (head == NULL)

        printf("List is Empty!\n");
    else
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void reverse(){
    struct Node *curr = head, *traverse = NULL, *prev = NULL;

    while (curr != NULL)
    {
        traverse = curr->next;
        curr->next = prev;
        prev = curr;
        curr = traverse;
    }
    head = prev;
    display();
}

int main(){
    head = NULL;
    while (1)
    {
        int ele;
        printf("Enter Element to insert: ");
        scanf("%d", &ele);
        createList(ele);
        int q;
        printf("Want to add more elements?\n Press 0 to Exit\n Press 1 to continue\n ");
        scanf("%d", &q);
        if (q == 0)
            break;
    }
    count();
    printf("\nSingle Linked List: ");
    display();
	printf("\nReversed Single Linked List: "); 
    reverse();

    return 0;
}


