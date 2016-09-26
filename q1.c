/*
Parallel Addition with at least 100 numbers.
*/

#include<omp.h>
#include<stdio.h>
#include<time.h>

int main(){

 int i;
 int s1=0,s2=0;
 clock_t start, end;
 double time;

 //Parallelizing starts here
 start = clock();
 #pragma omp parallel num_threads(2)

 {
	
 int id = omp_get_thread_num();

 if(id==0){
		
       for (i=0;i<100;i=i+2){

	           s1=s1+rand();
	
       }

 }else{
                  
        for (i=1;i<100;i=i+2){

	            s2=s2+rand();
		
        }
                      
     }
		
 }

 end = clock();
 time = ((double) (end - start)) / CLOCKS_PER_SEC;
 printf("\n Time : %lf\n",time);
 printf("Total = %d\n",s1+s2);

}
