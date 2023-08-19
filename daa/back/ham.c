#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//sample input
/*0 1 0 0 1
0 0 0 1 0
0 0 0 1 1
0 1 1 0 0
1 0 1 0 0*/
//answer 0 4 3 2 1


int a[10];
int adj[10][10];

int isSafe(int n,int index,int val) {
	if(index == n-1) {
		for(int j = 0;j < index;j++) {
			if(a[j] == val || adj[a[index-1]][val] == 0 || adj[val][0]) {
				return 0;
			}
		}
		return 1;		
		
	}
	else if(index < n) {
		for(int j = 0; j < index;j++) {
			if(a[j] == val || adj[a[index-1]][val] == 0)
	     		{
	     			return 0;
	     		}
		}
		return 1;
	}
}


void print(int a[],int n) {
	for(int i = 0;i <n;i++) {
		printf("%d",a[i]);
	}
	printf("\n");
}


int ham(int n,int index) {
	if(index == n){
		print(a,n);
		return 1;
	}
	else{
		int i;
		for(i = 1;i <n;i++) {
			if(isSafe(n,index,i)){
				a[index] = i;
				ham(n,index+1);
			}
		}
	}
}




int main() {
	int n;
	printf("enter the value of the n");
	scanf("%d",&n);
	int i,j;
	for(i = 0; i < n;i++) {
		for(j = 0; j < n ;j++) {
			scanf("%d",&adj[i][j]);
		}
	}
	a[0] = 0;
	ham(n,1);
	
}













