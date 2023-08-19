#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
//<chintu.std.h>
int dp[100][100];

int mcm(int a[],int i,int j) {
	int min,val,k;
	if(i == j) {
		return 0;
	}
	min = INT_MAX;
	for(k = i; k < j;k++) {
		val = mcm(a,i,k)+mcm(a,k+1,j) + a[i-1]*a[k]*a[j];
		if(min > val) {
			min = val;
		}
	}
	return min;
}


int mcmmem(int a[],int i,int j) {
	int min,val,k;
	if(i == j) {
		return dp[i][j] = 0;
	}
	min = INT_MAX;
	for(k = i; k < j;k++) {
		val = mcmmem(a,i,k)+mcmmem(a,k+1,j) + a[i-1]*a[k]*a[j];
		if(min > val) {
			min = val;
		}
	}
	return dp[i][j] = min;
}


int mcmtab(int a[],int p,int n) {
	int i,j,k,l,min,val;
	for(l = 0; l < n;l++) {
		for(i = 1; i < n-l;i++) {
			j = i + l;
			if(i == j) {
				dp[i][j] = 0;
				continue;
			}
			min = INT_MAX;
			for(k = i; k < j;k++) {
				val = dp[i][k] + dp[k+1][j] +( a[i-1] * a[k] * a[j]);
				if(min > val) {
					min = val;
				}
			}
			dp[i][j] = min;
		}
	}
	return dp[1][n-1];
}


int main() {
	int n;
	printf("enter the value of the n");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements of the array");
	for(int i = 0; i < n;i++) {
		scanf("%d",&a[i]);
	}
	int res;
	res = mcm(a,1,n-1);
	printf("mcm with recursion = %d\n",res);
	for(int i = 0; i <= n;i++) {
		for(int j = 0; j <= n;j++) {
			dp[i][j]= -1;
		}
	}
	res = mcmmem(a,1,n-1);
	printf("mcm with memory = %d\n",res);
	res  = mcmtab(a,1,n);
	printf("mcm with tabulation = %d",res);
	
}
