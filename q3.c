/*
Parallel Prefix-Sum.
*/

#include<omp.h>
#include<stdio.h>
#include <math.h>
#include<time.h>

int main(){
	
 int one[8];
 int two[8];
 int i=0,j=0,h=0;

 for(i=0;i<8; i++){

           one[i]=1;
           two[i]=0;
  }
         
 int k=ceil(log(8));
 k=k+1;
 int three[k][8];

 for(i=0; i<k; i++){

     for(j=0; j<8; j++){
   
            three[i][j]=0;
             
          }
  }

  for(i=0; i<8; i++){

            three[0][i]=one[i];
              
  }


 double time;
 clock_t start, end;
 //Parallelizing starts here
 start = clock();


 #pragma omp parallel num_threads(2)
      
 {
     int id = omp_get_thread_num();
     for(h=id; h<=k; h=h+2){

           for(j=pow(2,h);j<=8;j=j+pow(2,h)){

                    three[h][j-1]=three[h-1][(j/2)-1]+three[h-1][j-(int)pow(2,h-1)-1];
            } 
                 
      }
 }

 int l=0;
 #pragma omp parallel num_threads(2)
 { 
     int id = omp_get_thread_num();
     for(h=k-1-id; h>=0; h=h-2){

        for(k=pow(2,h); k<8; k=l+pow(2,h)){

               for(l=k; l<(k+pow(2,h)); l++){

                    two[l]=three[h][k-1]+two[l];
                 
               }
         }
      }
  }


 end = clock();
 time = ((double) (end - start)) / CLOCKS_PER_SEC;
 printf("\n Time :%lf \n",time);
 for(l=0; l<8; l++){

                    two[l]=two[l]+one[l];
                    printf("%d ",two[l]);
  }

  printf("\n");

}

