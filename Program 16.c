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
			printf("%d\t",SparseM[i][j]);
        }
		printf("\n");
    }

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(SparseM[i][j] == 0){
            	count++;
			}  	
        }
    }
    if(count > ((m * n)/2)){
   		printf("\nMatrix is a Sparse Matrix ");
    }
    else{
    	printf("\nMatrix is NOT a Sparse Matrix ");
	}     
}
