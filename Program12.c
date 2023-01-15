//Program 12: Implement binary search using recursion. 

#include <stdio.h>

void SortARR(int arr1[],int size){
	int temp, i, j;
	for (i=0; i< size; i++){
		for (j=i; j<size; j++){
			if (arr1[i] > arr1[j]){
				temp = arr1[i];
				arr1[i] = arr1[j];
				arr1[j] = temp;
			}
		}
	}
}

int recursiveBS(int arr[], int low, int high, int key){
   	if (high >= low){
   		int mid = (high + low)/2;
        if(arr[mid]==key){
			return mid;
		}
      	if (arr[mid] > key){
      		return recursiveBS(arr, low, mid-1, key);
		}
	 	return recursiveBS(arr, mid+1, high, key);
   	}
   	return -1;
}


int main(){
	int n;
	int arr[n];
	printf("Enter size of the array: ");
	scanf("%d",&n);
	int i, ele;
	for(i=0; i < n;i++){
		printf("Enter Element: ");
		scanf("%d",&ele);
		arr[i]= ele;
	}
	
	SortARR(arr,n);

	int key;
	printf("Enter the element to be searched: ");
	scanf("%d",&key);
	int index = recursiveBS(arr, 0, n-1, key);
	if(index == -1 ) {
	    printf("Element Not Found!");
	}
	else {
	    printf("Element at index : %d",index);
	}
	return 0;
}
