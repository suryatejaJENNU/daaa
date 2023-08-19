#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
//<chintu.std.h>
int dp[100][100];


int summing(int freq[],int i,int j) {
  int sum =0;
  int k;
  for(k = i;k <= j ;k++) {
  	sum = sum + freq[k];
  }
  return sum;
}

int obst(int a[],int freq[],int i,int j) {
	int min,val,k,sum;
	if(i > j) {
		return 0;
	}
	if(i == j) {
		return freq[i];
	}
	min = INT_MAX;
	sum = summing(freq,i,j);
	for(k = i;k <= j;k++) {
		val = obst(a,freq,i,k-1) + obst(a,freq,k+1,j);
		if(min > val) {
			min = val;
		}
	}
	return  min+sum;
}


int obstmem(int a[],int freq[],int i,int j) {
	int min,val,k,sum;
	if(i > j) {
		return  dp[i][j] = 0;
	}
	if(i == j) {
		return dp[i][j] = freq[i];
	}
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	min = INT_MAX;
	sum = summing(freq,i,j);
	for(k = i;k <= j;k++) {
		val = obstmem(a,freq,i,k-1) + obstmem(a,freq,k+1,j);
		if(min > val) {
			min = val;
		}
	}
	return dp[i][j] = min+sum;
} 

int obsttab(int a[],int freq[],int n) {
	int i,j,k,l,min,val;
	for(l = 1; l < n;l++) {
		for(i = 1; i < n - l;i++) {
			j = i + l;
			min = INT_MAX;
			for(k = i; k <= j;k++) {
				val = dp[i][k-1]+dp[k+1][j]+summing(freq,i,j);
				if(min > val) {
					min = val;
				}
			}
			dp[i][j] = min;
		}
	}
	return dp[0][n-1];
}




int main() {
	int n;
	printf("enter the value of the n");
	scanf("%d",&n);
	int a[n],freq[n];
	printf("enter the elements of the array");
	for(int i = 0; i < n;i++) {
		scanf("%d",&a[i]);
	}
	printf("enter the frequences of the array");
	for(int i = 0; i < n;i++) {
		scanf("%d",&freq[i]);
	}
	int res;
	res = obst(a,freq,0,n-1);
	printf("obst with recursion = %d\n",res);
	for(int i = 0; i <= n;i++) {
		for(int j = 0; j <= n;j++) {
			dp[i][j]= -1;
		}
	}
	res = obstmem(a,freq,0,n-1);
	printf("obst with memory = %d\n",res);
	res = obsttab(a,freq,n);
	printf("obst with tabulation = %d\n",res);
	

	
}
