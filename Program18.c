//Program 18: Implement traversals on Binary Search Tree (using stacks) - Inorder, Preorder, Postorder). 
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};



struct Node* insertBST(struct Node *root, int val){
	if(root==NULL){
		struct Node* root = (struct Node *)malloc(sizeof(struct Node));
  		root->data = val;
  		root->left = root->right = NULL;
  		return root;
	}
	else if(val<root->data){
		root->left = insertBST(root->left,val);
	}
	else{
		root->right= insertBST(root->right,val);
	}
	return root;	
}

void in_order(struct Node* root)
{
    struct Node *stack[100];
    int top = -1;
    struct Node *curr = root;
    while (top != -1 || curr != NULL)
    {
        if (curr != NULL)
        {
            stack[top++] = curr;
            curr = curr->left;
        }
        else
        {
            curr = stack[--top];
            printf("%d ", curr->data);
            curr = curr->right;
        }
    }
}

void pre_order(struct Node* root)
{
    struct Node *stack[100];
    int top = -1;
    if (root == NULL)
        return;

    stack[top] = root;
    top ++;

    while (top != -1)
    {
        root = stack[--top];

        printf("%d ", root->data);
        if (root->right != NULL)
            stack[top++] = root->right;
        if (root->left != NULL)
            stack[top++] = root->left;
    }
}

void post_order(struct Node* root)
{
    struct Node *stack[100];
    if (root== NULL)
        return;

    int top = -1;
    struct Node *curr = root;

    while (1)
    {
        if (curr != NULL)
        {
            if (curr->right)
                stack[++top] = curr->right;
            stack[++top] = curr;
            curr = curr->left;
            continue;
        }

        if (top == -1)
            return;
        curr = stack[top--];

        if (curr->right && top != -1 && stack[top] == curr->right)
        {
            top--;    
            stack[++top] = curr;
            curr = curr->right;
        }
        else
        {
            printf("%d ", curr->data);
            curr = NULL;
        }
    }
}

int main(){
	int root_ele;
	printf("Enter the root of tree: ");
	scanf("%d",&root_ele);
	struct Node* root = NULL;
	root = insertBST(root,root_ele);
	
	char ch = 'y';
	while(ch=='y' || ch=='Y'){
		printf("\n*********** MENU ***********\n");
		printf("1.Insert an element\n");
		printf("2.Display elements of BST in Preorder, Postorder and Inorder\n\n");
		
		int choice;
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		if(choice==1){
			int x;
			printf("Enter the element: ");
			scanf("%d",&x);
			insertBST(root,x);
			printf("Element %d inserted in BST!\n",x);
		}
		
		else if(choice==2){
			char ch1 = 'y';
			while(ch1=='y' || ch1=='Y'){
				printf("\n***** TRAVERSALS *****\n");
				printf("1.Preorder Traversal\n");
				printf("2.Postorder Traversal\n");
				printf("3.Inorder Traversal\n\n");
				
				int choice2;
				printf("Enter your choice: ");
				scanf("%d",&choice2);
				
				if(choice2==1){
					printf("Preorder Traversal: ");
					pre_order(root);
				}
				else if(choice2==2){
					printf("Postorder Traversal: ");
					post_order(root);
				}
				else if(choice2==3){
					printf("Inorder Traversal: ");
					in_order(root);
				}
				else{
					printf("Invalid choice!\n");
				}
				printf("\nWant to continue traversal?(y/n): ");
				scanf("%s",&ch1);
			}
		}
		else{
			printf("\nInvalid choice!\n");
		}
		printf("\nWant to continue?(y/n): ");
		scanf("%s",&ch);	
	}
	return 0;
}



