#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dp[10][10];


int knapsack(int wt[],int val[],int w,int n){
	int d,r;
	if(n == 0 || w == 0){
		return 0;
	}
	if(wt[n-1] <= w) {
		d = val[n-1]+knapsack(wt,val,w - wt[n-1],n-1); 
		r = knapsack(wt,val,w,n-1);
		return (d > r?d:r);	
	}
	else{
		return knapsack(wt,val,w,n-1);
	}
	
}

int knapmem(int wt[],int val[],int w,int n){
	int d,r;
	if(n == 0 || w == 0){
		return dp[n][w] = 0;
	}
	if(dp[n][w] != -1) {
		return dp[n][w];
	}
	if(wt[n-1] <= w) {
		d = val[n-1]+knapsack(wt,val,w - wt[n-1],n-1); 
		r = knapsack(wt,val,w,n-1);
		return dp[n][w] = (d > r?d:r);	
	}
	else{
		return dp[n][w] = knapsack(wt,val,w,n-1);
	}

	
}

int knaptab(int wt[],int val[],int w,int n){
	int i,j,d,r;
	for(i = 0; i <= n;i++) {
        	for(j = 0; j <= w;j++){
			if(i == 0 || j == 0) {
				dp[i][j] = 0;
				continue;
			}
			if(wt[i-1] <= j) {
				d = val[i-1]+dp[i-1][j - wt[i-1]];
				r = dp[i-1][j];
				dp[i][j] = d > r?d:r;
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
	        }
	}
	return dp[n][w];
}






int main() {
	int n,i,j;
	printf("enter the value of the n");
	scanf("%d",&n);
	int wt[n],val[n];
	printf("enter the weights");
	for(i = 0;i < n;i++) {
		scanf("%d",&wt[i]);
	}
	printf("enter thr values");
	for(i = 0; i < n;i++){
		scanf("%d",&val[i]);	
	}
	int w,result;
	printf("enter the bag weights");
	scanf("%d",&w);
	result = knapsack(wt,val,w,n);
	printf("with resursion = %d\n",result);
	for(i = 0;i <= n;i++) {
		for(j = 0; j <= w;j++) {
			dp[i][j] = -1;
		}
	}
	result = knapmem(wt,val,w,n);
	printf("with memory = %d\n",result);
	result = knaptab(wt,val,w,n);
	printf("with memory = %d",result);
	
	
}
