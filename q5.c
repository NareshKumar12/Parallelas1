/*
Parallel Pointer Doubling to find roots of a graph.
*/

#include<omp.h>
#include<stdio.h>
#include<time.h>
 
int main(){

 int a[10];
 int i;
 for(i=0;i<10;i++){
        a[i]=rand()%10;
   }
       int root=2;


printf("\n");

for(i=0; i<10 ;i++)
{
      printf("%d ",i);
}
printf("\n");
for(i=0; i<10; i++)
{
      printf("%d ",a[i]);
}
int j,l;
int hight=4;
clock_t start, end;


//Parallelizing starts here
double time;

start = clock();

for(i=0; i<hight; i++){

 #pragma omp parallel num_threads(2)
 {

  int id = omp_get_thread_num();
  for(j=id; j<10; j=j+2){
   if(a[j]!=root){
 
      a[j]=a[a[j]];
 
    }
   }
  }
 printf("\n");
 for(l=0; l<10 ;l++){

      printf("%d ",l);

  }
  printf("\n");
  for(l=0; l<10; l++){

      printf("%d ",a[l]);
   }
 
}

 end = clock();
 time = ((double) (end - start)) / CLOCKS_PER_SEC;
 printf("\n \n Time : %lf \n",time);
 printf("\n");
 for(i=0; i<10 ;i++){
 
      printf("%d ",i);

 }
 printf("\n");
 for(i=0; i<10; i++){

      printf("%d ",a[i]);
 }

 printf("\n");
 
}
