/*
Parallel Matrix-Vector Multiplication.
*/

#include<omp.h>
#include<stdio.h>
#include<time.h>

int main(){


 int matrix[10][10];
 int a[10];
 int b[10];
 int i=0,j=0;

 for(i=0;i<10; i++){

              for(j=0; j<10; j++){

                    matrix[i][j]=rand()%10;
                    printf("%d ",matrix[i][j]);
               }
               printf("\n");
               a[i]=i*2;
  }
      
  printf("\n");
  for(i=0; i<10; i++){

           printf("%d ",a[i]);

  }
  
  printf("\n");

  printf("\n");
  clock_t start, end;
  double time;

  //Parallelizing starts here
  start = clock();

  #pragma omp parallel num_threads(2)
  
  {
	int id = omp_get_thread_num();
        int l,m,sum=0;
	for(l=id;l<10;l=l+2){

              sum=0;
              #pragma omp #pragma omp parallel num_thread(2)
                    
              {
                   for(m=0;m<10;m++){

                          printf("%d ",omp_get_thread_num());
                          sum=matrix[l][m]*a[m]+sum;
                        }
               }
                      b[l]=sum;
       }

 }//pragma

 end = clock();
 time = ((double) (end - start)) / CLOCKS_PER_SEC;
 printf("\n Time : %lf \n",time);
 for(i=0;i<10;i++){
                    printf("%d ",b[i]);
 }

   printf("\n");

}
