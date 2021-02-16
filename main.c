#include <stdio.h>
#include <stdlib.h>
#include "compress.h"


int main(int argc, char *argv[]) {
	
    int i,j,nzSize=0,counter=0;                    
    
    int matrix[R][C] = {{10,0,0,0,2,0},
                            {3,9,0,0,0,3},
                            {0,7,8,7,0,0},
                            {3,0,8,7,5,0},
                            {0,8,0,9,9,10},
                            {0,4,0,0,2,1}};
    
    
    int **A = malloc(R * sizeof *A);
    for(i=0; i<R; i++){
        A[i] = malloc(C * sizeof *A[i]);
    }

    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            A[i][j] = matrix[i][j];

            if(matrix[i][j] != 0 ){
                nzSize++;
            }
        }
    }

   
    int *nz = (int *) malloc(nzSize*sizeof(int));
    int *col_ind = (int *) malloc(nzSize*sizeof(int));
    int *row_ptr = (int *) malloc((R+1)*sizeof(int));
    int *col_ptr = (int *) malloc((C+1)*sizeof(int));
    int *row_ind = (int *) malloc(nzSize*sizeof(int));
    int *rows = (int *) malloc( R*C*sizeof(int));
    int *cols = (int *) malloc( R*C*sizeof(int));

 

    printf("Nz :");
    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            if( matrix[i][j] != 0 ){
                nz[counter] = matrix[i][j];
                printf("%d ", nz[counter++]);
            }
        }
    }

  
    compress_CRS(A, nz, col_ind, row_ptr);
    decompress_CRS(nz, col_ind, row_ptr);
    compress_CCS(A, nz, row_ind, col_ptr);
    decompress_CCS(nz, row_ind, col_ptr);
    compress_IJ(A, nz, rows, cols);

  
  
    for (i=0; i<R; i++){
        free(A[i]);
    }
    free(A);
    free(nz);

}
