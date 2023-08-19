#include<stdio.h>
#include<stdlib.h>
int b[10];

int mergging(int a[],int lb,int mid,int ub) {
	int i,j,k;
	i = lb;
	j = mid+1;
	k = lb;
	while(i <= mid && j <= ub) {
		if(a[i] <= a[j]) {
			b[k++] = a[i++];
		}
		else{
			b[k++] = a[j++];
		}
	}
	while(i <= mid) {
		b[k++] = a[i++];
	}
	while(j <= ub) {
		b[k++] = a[j++];
	}
	for(k = lb; k <= ub;k++) {
		a[k] = b[k];
	}
}




int mergeSort(int a[],int lb,int ub) {
	int mid;
	if(lb < ub) {
		mid = (lb + ub) /2;
		mergeSort(a,lb,mid);
		mergeSort(a,mid+1,ub);
		mergging(a,lb,mid,ub);	
	}	
}









int main() {
	int n;
	printf("enter the value of the n");
	scanf("%d",&n);
	int a[n];
	for(int i  = 0; i < n;i++) {
		scanf("%d",&a[i]);
	}
	mergeSort(a,0,n-1);
	for(int i = 0; i < n;i++) {
		printf("%d",a[i]);
	}
}
