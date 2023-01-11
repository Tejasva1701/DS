#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[],int n){ 
	int i;	
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
        }
}
 
void InsertionSort(int arr[],int n){
	int i;
    for(i = 1 ; i < n; i++){	
        int temp = arr[i];
        int j = i-1;	
        while(j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];	
            j--;		
        }
        arr[j+1] = temp;		
    }
}

void ShellSort(int arr[], int n) {
	int i;
  	for(i = n/2; i > 0; i /= 2) {
  		int j;
    	for (j = i; j < n; j++) {
      		int temp = arr[i];
      		int k;
      		for(k = j; k >= i && arr[k - i] > temp; k-=i) {
        		arr[j] = arr[k - i];
      		}
      		arr[j] = temp;
    	}
	}
}

void Merge(int arr[], int mid, int low, int high)
{
    int i, j, k, arr2[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high){
        if (arr[i] < arr[j]){
            arr2[k] = arr[i];
            i++;
            k++;
        }
        else{
            arr2[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid){
        arr2[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high){
        arr2[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++){
        arr[i] = arr2[i];
    }
}

void MergeSort(int arr[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        Merge(arr, mid, low, high);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
}

 void HeapSort(int arr[], int n) {
 	int i;
    for (i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    for (i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
    heapify(arr, i, 0);
    }
}

void BubbleSort(int arr[],int n){   
    int i;
    for(i = 0; i < n-1; i++){ 
		int j;               
        for(j = 0; j < n-i-1; j++){   
            if(arr[j] > arr[j+1]){   
            	int temp = arr[j];
            	arr[j] = arr[j+1];
            	arr[j+1] = temp;
            }
        }
    }
}

int divide(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot){
            i++;
        }

        while (arr[j] > pivot){
            j--;
        }

        if (i < j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void QuickSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = divide(arr, low, high); 
        QuickSort(arr, low, mid - 1);  
        QuickSort(arr, mid + 1, high);
    }
}

int main(){
	int n;
	int arr[n];
	
	printf("Enter the size of array: ");
	scanf("%d",&n);
	
	int i;
	printf("***** Enter Elements of Array *****\n");
	for (i=0; i<n; i++){
		int ele;
		printf("Enter element %d: ",i+1);
		scanf("%d",&ele);
		arr[i] = ele;
	}
	
	char ans = 'y';
	while(ans=='y' || ans == 'Y'){
		printf("\n\n");
		printf("\n********* SORTING TECHNIQUES *********\n");-
		printf("\n1.Insertion Sort()  \n2.Shell Sort()  \n3.Merge Sort()  \n4.Heap Sort()  \n5.Bubble Sort()  \n6.Quick Sort  \n7.Exit\n");
		
		int choice;
		printf("\nEnter Your Choice: ");
		scanf("%d",&choice);
		
		if(choice == 1){
			printf("\n\n----INSERTION SORT----");
			printf("\n\nUnsorted Array: ");
		    printArr(arr,n);
		    InsertionSort(arr,n);                     
		    printf("\n\nSorted Array: ");
		    printArr(arr,n);
		}
		
		else if(choice == 2){
			printf("\n\n----SHELL SORT----");
			printf("\n\nUnsorted Array: ");
		    printArr(arr,n);
		    ShellSort(arr,n);                     
		    printf("\n\nSorted Array: ");
		    printArr(arr,n);
		}
		
		else if(choice == 3){
			printf("\n\n----MERGE SORT----");
			printf("\n\nUnsorted Array: ");
		    printArr(arr,n);
		    MergeSort(arr,0,n-1);                     
		    printf("\n\nSorted Array: ");
		    printArr(arr,n);
		}
		
		else if(choice == 4){
			printf("\n\n----HEAP SORT----");
			printf("\n\nUnsorted Array: ");
		    printArr(arr,n);
		    InsertionSort(arr,n);                     
		    printf("\n\nSorted Array: ");
		    printArr(arr,n);
		}
		
		else if(choice == 5){
			printf("\n\n----BUBBLE SORT----");
			printf("\n\nUnsorted Array: ");
		    printArr(arr,n);
		    BubbleSort(arr,n);                     
		    printf("\n\nSorted Array: ");
		    printArr(arr,n);
		}
		
		else if(choice == 6){
			printf("\n\n----QUICK SORT----");
			printf("\n\nUnsorted Array: ");
		    printArr(arr,n);
		    QuickSort(arr,0,n-1);                     
		    printf("\n\nSorted Array: ");
		    printArr(arr,n);
		}
		
		else{
			printf("\nInvalid Choice!\n");
		}
		printf("\n\nWant to continue?(y/n): ");
		scanf("%s",&ans);
	}
	return 0;
}

