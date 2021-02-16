#include <stdio.h>
#include <stdlib.h>
#include "compress.h"

void compress_CRS(int **A, int *nz, int *col_ind, int *row_ptr){
    int i,j,counter=0,counter2=0,counter3=0,variable;               
      
    for(i=0; i<R; i++){
    	variable = 0;
        for(j=0; j<C; j++){
            if(A[i][j] != 0){
                col_ind[counter++] = j;
                if(variable==0){
                	 row_ptr[counter2++] = counter3;
                    variable = 1;
                }
                counter3++;
	}
                
            }
        }
    row_ptr[counter2] = counter3;

    puts("");
    printf("\n CRS col_ind: ");
    for(i=0; i<counter3; i++){
        printf("%d " , col_ind[i]);
    }

    printf("\n CRS row_ptr: ");
    for(i=0; i<R+1; i++){
        printf("%d " , row_ptr[i]);
    }
 	
}

int **decompress_CRS(int *nz, int *col_ind, int *row_ptr){
 
    int i,j,k,counter=0;          

    int **decompA = malloc(R * sizeof *decompA);
    for(i=0; i<R; i++){
        decompA[i] = malloc(C * sizeof *decompA[i]);
    }

    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            if(j!=col_ind[counter]){
            	 decompA[i][j] =0;
            }else{
               decompA[i][j] = nz[counter++];
            }  
        }
    }
	puts("");
    printf("\n CRS Decompressed A\n");
    for(k=0; k<R; k++){
        for(j=0; j<C; j++){
            printf("%d ", decompA[k][j]);
        }
        printf("\n");
    }

    return decompA;
}

void compress_CCS(int **A, int *nz, int *row_ind, int *col_ptr){

    int i,j,counter=0,counter2=0,variable;               
    int counter3 = 0,counter4=0;           
  

    for(i=0; i<R; i++){	
        variable=0;
        for(j=0; j<C; j++){
            if( A[j][i] != 0 ){
                nz[counter++] = A[j][i];         
      			 row_ind[counter2++] = j;
      			 if( variable == 0){
                    col_ptr[counter3++] = counter4;               
                       variable= 1;
                }
                counter4++;
            }
        }
         col_ptr[counter3] = counter4;
    }
  
	puts("");
    printf(" CCS row_ind: ");
    for(i=0; i<counter2; i++){
        printf("%d " , row_ind[i]);
    }
	puts("");
    printf(" CCS col_ptr: ");
    for(i=0; i<R+1; i++){
        printf("%d " , col_ptr[i]);
    }
}

int **decompress_CCS(int *nz, int *row_ind, int *col_ptr){
    int i,j,counter=0;            

    int **decompA = malloc(R * sizeof *decompA);
    for(i=0; i<R; i++){
        decompA[i] = malloc(C * sizeof *decompA[i]);
    }

    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            if(j!=row_ind[counter]){
                  decompA[j][i] = 0;
            }else{  
			decompA[j][i] = nz[counter++];  
            }  
        }
    }

    printf("\n");
    printf("\nDecompressed A\n");
    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            printf("%d ", decompA[i][j]);
        }
        printf("\n");
    }
    return decompA;
}
 

void compress_IJ(int **A, int *nz, int *rows, int *cols){
	printf("\n Compress IJ:");
    int i,j,counter=0,counter2=0,counter3=0; 
	
    
    for(i=0; i<R; i++){
        for(j=0; j<C; j++){      
            if(A[i][j] != 0 ){    	
                 rows[counter2++] =i;   
                 cols[counter3++]=j;
            } 
            }
        }
        puts("");
        printf("Rows:");
        for(i=0; i<19; i++){
        		printf("%d ",rows[i]);
		}
		puts("");
		 printf("Cols:");
		 for(i=0; i<19; i++){
        		printf("%d ",cols[i]);
		}
		puts("");
    }
    

