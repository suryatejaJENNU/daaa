#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>


int sumsub(int wt[],int sum,int n){
	if(sum == 0){
		return 1;
	}
	if(n == 0) {
		return 0;
	} 
	if(wt[n-1] <= sum) {
		return sumsub(wt,sum-wt[n-1],n-1) || sumsub(wt,sum,n-1);
	}
	else{
		return sumsub(wt,sum,n-1);
	}
}


int main() {
	int n,i,sum;
	printf("enter the value of the n");
	scanf("%d",&n);
	int wt[n];
	for(i = 0; i < n;i++) {
		scanf("%d",&wt[i]);
		sum = sum + wt[i];
	}
	if(sum % 2 != 0) {
		printf("not possible");	
	}
	else {
		sum = sum /2 ;
		int end;
		end = sumsub(wt,sum,n);
		if(end == 1) {
			printf("sum is possible");
		}
		else{
			printf("sum is not possible");
		}
	
	}
	
}
