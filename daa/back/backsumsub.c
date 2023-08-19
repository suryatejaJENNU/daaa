#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int a[100],wt[100];
int c = 0;
int w;


int print(int a[],int n){
   int sum = 0;
   for(int i = 0;i < n;i++) {
     if(a[i] == 1) {
       sum = sum + wt[i];
     }
   }
   if(sum == w){
     for(int i =0;i < n;i++) {
       printf("%d",a[i]);
     }
     printf("\n");

   }
   
}

int nqueens(int index,int n) {
  if(index == n) {
     print(a,n);
     return 1;
  }
  else {
  int i;
  for(i =0;i < 2;i++) {
       a[index] = i;
       nqueens(index+1,n);
  }
     }  
  
  }




int main() {
  int n;
  printf("enter the value of the n");
  scanf("%d",&n);
  printf("enter the weights\n");
  for(int i =0;i < n;i++) {
      scanf("%d",&wt[i]);
  }
  printf("enter the weights");
  scanf("%d",&w);
  nqueens(0,n);



}
