//Program 1: Implement operations (traverse, insert, delete, linear search, selection sort) on an array.
#include <stdio.h>
#include <stdlib.h>
struct Array{
    int *A;
    int size;
    int length;
};

void traverse(struct Array arr){
    int i;
    printf("\nElements of Array are: ");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

void insert(struct Array *arr, int index, int x){
    int i;
    if (index >= 0 && index <= arr->length){
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
    else{
    	printf("\nIndex Out of range!\n");
	}
}

int Delete(struct Array *arr, int index){
    int x = 0;
    int i;
    if (index >= 0 && index < arr->length){
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
        return x;
    }
    else{
    	printf("\nIndex Out of range!\n");
	}
    return 0;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int LinearSearch(struct Array *arr, int key){
    int i;
    for (i = 0; i < arr->length; i++){
        if (key == arr->A[i]){
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

void selectionSort(struct Array *arr){
	int i,j;
    for (i = 0; i < arr->length - 1; i++){
        int minIndex = i;
        for (j = i + 1; j < arr->length; j++){
            if (arr->A[j] < arr->A[minIndex]){
                minIndex = j;
    		}
        }
        swap(&arr->A[i], &arr->A[minIndex]);
    }
    return;
}

int main()
{
    struct Array arr1;
    int x, index;
    int choice;
    printf("Enter size of array: ");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    arr1.length = 0;
    do{
        printf("\n\n***** MENU *****\n");
        printf("OPERATIONS:\n1. Traverse \n2. Insert \n3. Delete \n4. Linear Search \n5. Selection sort \n6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
        	if (arr1.length >= 1){
        		traverse(arr1);
			}
			else{
				printf("No Elements in the array!");
			}
            break;
        case 2:
            printf("Enter an element and index at which you want to insert it: ");
            scanf("%d%d", &x, &index);
            insert(&arr1, index, x);
            break;
        case 3:
            printf("Enter index from which you want to delete an element: ");
            scanf("%d", &index);
            x = Delete(&arr1, index);
            printf("Element %d deleted!",x);
            break;
        case 4:
            printf("Enter element to be searched: ");
            scanf("%d", &x);
            index = LinearSearch(&arr1, x);
            if (index >= 0){
            	printf("Element %d found at index %d.",x,index);
			}
			else{
				printf("\nElement NOT Found!");
			}
            break;
        case 5:
        	if (arr1.length > 1){
                selectionSort(&arr1);
                printf("\nArray is Sorted.");
            }
            else{
            	printf("No Elements to sort!");
			}
            break;
        case 6:
        	exit(0);
        	break;
        default :
        	printf("\nInvalid Choice!");
        	break;
    	}
    } while (choice != 6);
    return 0;
}
