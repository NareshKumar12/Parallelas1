/*
Parallel Matrix Transpose.
*/

#include<omp.h>
#include<stdio.h>
#include<time.h>

int main(){

 int matrix[10][10];
 int i=0,j=0;

 for(i=0;i<10; i++){

      for(j=0; j<10; j++) {

                     matrix[i][j]=rand()%10;
                     printf("%d ",matrix[i][j]);
      }
                 printf("\n");
 }

 printf("\n");
 clock_t start, end;
 double time;

 
//Parallelizing starts here
 start = clock();

 #pragma omp parallel num_threads(2)
 {
 
 int id = omp_get_thread_num();
 if(id==0){
             int temp=0;
             for (i=0;i<10;i=i+2){

		   for(j=i;j<10;j++){

                      temp=matrix[i][j];
                      matrix[i][j]=matrix[j][i];
                      matrix[j][i]=temp;
                   }
		}
      
 }else{
         int temp1=0;
	  for (i=1;i<10;i=i+2){

              for(j=i;j<10;j++){

                      temp1=matrix[i][j];
                      matrix[i][j]=matrix[j][i];
                      matrix[j][i]=temp1;
                }
	     }
   }
		
 }

 end = clock();
 time = ((double) (end - start)) / CLOCKS_PER_SEC;
 printf("Time : %lf  \n \n",time);
   
 for(i=0;i<10; i++){

    for(j=0; j<10; j++) {

                    printf("%d ",matrix[i][j]);

     }
              printf("\n");
  }

}
