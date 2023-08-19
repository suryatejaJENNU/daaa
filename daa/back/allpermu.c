#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int a[100];
int c = 0;

int print(int a[],int n){
   for(int i = 1;i <= n;i++) {
     printf("%d",a[i]);
   }
   c++;
    printf("\n");
}

int nqueens(int index,int n) {
  if(index == n+1) {
     print(a,n);
     return 1;
  }
  else {
  int i;
  for(i =1;i <= n;i++) {
       a[index] = i;
       nqueens(index+1,n);
  }
     }  
  
  }




int main() {
  int n;
  printf("enter the value of the n");
  scanf("%d",&n);
  nqueens(1,n);
  printf("no of outcomes %d",c);


}
