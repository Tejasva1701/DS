//Program 8: Implement addition of two polynomial expressions using singly linked list

#include <stdio.h>
#include <malloc.h>

struct Node{
    int coeff;
    int pow;
    struct Node *next;
};
struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;

void create(struct Node *node){
    char ch;
    do{
        printf("\nEnter coefficient:");
        scanf("%d", &node->coeff);
        printf("Enter power:");
        scanf("%d", &node->pow);
        node->next = (struct Node *)malloc(sizeof(struct Node));
        node = node->next;
        node->next = NULL;
        printf("\nWant to add more terms?(y/n):");
        scanf("%s",&ch);
    } while (ch == 'y' || ch == 'Y');
}

void show(struct Node *node){
    while (node->next != NULL){
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if (node->next != NULL)
            printf("+");
    }
}

void polyadd(struct Node *poly1, struct Node *poly2, struct Node *poly){
    while (poly1->next && poly2->next){
        if (poly1->pow > poly2->pow){
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow){
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else{
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        poly->next = (struct Node *)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
    while (poly1->next || poly2->next){
        if (poly1->next){
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next){
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next = (struct Node *)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
}

int main(){
    char ch;
    do{
        poly1 = (struct Node *)malloc(sizeof(struct Node));
        poly2 = (struct Node *)malloc(sizeof(struct Node));
        poly = (struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter values for Polynomial Expression 1");
        create(poly1);
        printf("\nEnter values for Polynomial Expression 2");
        create(poly2);
        printf("\nPolynomial Expression 1: ");
        show(poly1);
        printf("\nPolynomial Expression 2: ");
        show(poly2);
        polyadd(poly1, poly2, poly);
        printf("\n\nAdding Polynomial Expression 1 and 2..");
        printf("Final Polynomial Expression : ");
        show(poly);
        printf("\nDo you Want to continue?(y/n): ");
        scanf("%s",&ch);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}


