#include<stdio.h>
#include<stdlib.h>
int min(int a,int b){
if(a>b)
return b;
return a;
}
int a[10][10],dp[10][10];

int subsum(int wt[],int sum,int n) {
	if(sum == 0) {
	  return 0;
	}
	if(n == 0) {
	  return 99999;
	}
	if(wt[n -1] <= sum) {
	    return min(1+subsum(wt,sum-wt[n-1],n) ,subsum(wt,sum,n-1));
	}
        else {
          return subsum(wt,sum,n-1);
        }
	}


int submem(int wt[],int sum,int n) {
	if(sum == 0) {
	  return 0;
	}
	if(n == 0 ) {
	return 999999;
	}
	if(a[n][sum] != -1) {
	  return a[n][sum];
	}
	
	
       if(wt[n-1] <= sum) {
       return a[n][sum] =min( 1+submem(wt,sum-wt[n-1],n) ,submem(wt,sum,n-1));
       
       }
       else {
       return a[n][sum] = submem(wt,sum,n-1);
       }
}


int subtab(int wt[],int sum,int n) {
	int i,j;
	for(i=0;i<=n;i++) {
           for(j = 0; j<=sum;j++) {
           if(j == 0) {
            dp[i][j] = 0;
           }
           if(i == 0) {
            dp[i][j] = 999999;
           }
           if(wt[i-1] <= j) {
           dp[i][j] = min(1+dp[i][j - wt[i-1]] , dp[i-1][j]);
           
           }
           else{
            dp[i][j] =dp[i-1][j];
           }
           
           }
      }
      return a[n][sum];

}



int main() {
	int n,i,end,sum,j;
	printf("enter the size of the weights");
	scanf("%d",&n);
	
	int wt[n];
	printf("enter the weights");
	for(i = 0 ; i < n;i++) {
	 scanf("%d",&wt[i]);
	
	}
	printf("enter the sum");
	scanf("%d",&sum);
	
	end = subsum(wt,sum,n);
	printf("sum of subsets %d",end);
	
	for (i = 0; i <= n;i++) {
	  for (j = 0;j <= sum;j++) {
	    a[i][j] = -1;
	  }
	}
	end = submem(wt,sum,n);
	printf("\nsum of subsets using memory %d",end);
	end = subtab(wt,sum,n);
	printf("\nsum of subsets using tabulation %d",end);
		
}
