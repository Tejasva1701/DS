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

struct Node* inorderSucc(struct Node*root){
	struct Node* curr = root;
	while(curr && curr->left!=NULL){
		curr = curr->left;
	}
	return curr;
}

struct Node* deleteBST(struct Node* root, int val){
	struct Node* temp;
	if(root==NULL){
		return NULL;
	}
	if(root->data>val){
		root->left = deleteBST(root->left,val);
	}
	else if(root->data<val){
		root->right = deleteBST(root->right,val);
	}
	else{
		if(root->left==NULL){
			temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			temp = root->left;
			free(root);
			return temp;
		}
		else{
			temp = inorderSucc(root->right);
			root->data = temp->data;
			root->right= deleteBST(root->right,temp->data);
		}
	}
	return root;
}

struct Node* searchBST(struct Node* root,int key){
	if(root==NULL){
		return NULL;
	}
	if(root->data==key){
		return root;
	}
	else if(root->data>key){
		return searchBST(root->left,key);
	}
	return searchBST(root->right,key);
}

void in_order(struct Node* root){
	if(root==NULL){
		return;
	}
	in_order(root->left);
	printf("%d ",root->data);
	in_order(root->right); 
}


void pre_order(struct Node* root){
	if(root==NULL){
		return;
	}
	printf("%d ",root->data);
	pre_order(root->left);
	pre_order(root->right);
}


void post_order(struct Node* root){
	if(root==NULL){
		return;
	}
	post_order(root->left);
	post_order(root->right);
	printf("%d ",root->data);
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
		printf("2.Delete an element\n");
		printf("3.Search an element\n");
		printf("4.Display elements of BST in Preorder, Postorder and Inorder\n\n");
		
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
			int x;
			printf("Enter the element: ");
			scanf("%d",&x);
			if(deleteBST!=NULL){
				deleteBST(root,x);
				printf("Element %d deleted from BST!",x);
			}
			else{
				printf("Element doesn't exist!\n");
			}
		}
		else if(choice==3){
			int x;
			printf("Enter the element to search: ");
			scanf("%d",&x);
			struct Node* n = searchBST(root,x);
			if(n != NULL){
				printf("Element %d Found!",n->data);
			}
			else{
				printf("Element NOT Found!");
			}
		}
		else if(choice==4){
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

