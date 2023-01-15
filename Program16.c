//Program 16: Implement Sparse Array

#include<stdio.h>
#include<stdlib.h>

int main(){
	int m,n;
    int SparseM[10][10];
    int count = 0;
    printf("Enter number of rows: ");
    scanf("%d",&m);
    printf("Enter number of Columns: ");
    scanf("%d",&n);
    int i,j;
    for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("Enter element A%d%d : ",i+1,j+1);
			scanf("%d",&SparseM[i][j]);
		}
    }
    printf("\nSparse Matrix: \n");
    for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%d  ",SparseM[i][j]);
        }
		printf("\n");
    }

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(SparseM[i][j] != 0){
            	count++;
			}  	
        }
    }
    if(count < ((3*(m * n))/4)){
   		printf("\nMatrix is a Sparse Matrix ");
    }
    else{
    	printf("\nMatrix is NOT a Sparse Matrix ");
	}   
	
	int CompactM[3][count];
    int k = 0;
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            if (SparseM[i][j] != 0)
            {
                CompactM[0][k] = i;
                CompactM[1][k] = j;
                CompactM[2][k] = SparseM[i][j];
                k++;
            }
        }
    }
    printf("\n\nFollowing representation is in the order\ni: Row number \nj: Column Number \ne: Element at (i,j) in original matrix\n\n");
	for (i = 0; i < 3; i++){
        for (j = 0; j < count; j++)
            printf("%d   ",CompactM[i][j]);
        printf("\n");
    }  
	
	return 0;
}


