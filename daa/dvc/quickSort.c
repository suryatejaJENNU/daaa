#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int partion(int a[],int lb,int ub) {
	int start,end,temp,pivot;
	pivot = a[lb];
	start = lb;
	end = ub;
	while(start < end) {
		while(a[start] <= pivot) {
			start ++;	
		}
		while(a[end] > pivot) {
			end --;
		}
		if(start < end) {
			temp = a[start];
			a[start] = a[end];
			a[end] = temp;
		}
	}
	temp = a[end];
	a[end] = a[lb];
	a[lb] = temp;
	return end;
}

int quickSort(int a[],int lb,int ub) {
	int loc;
	if(lb < ub) {
		loc = partion(a,lb,ub);
		quickSort(a,lb,loc-1);
		quickSort(a,loc+1,ub);
	}
}




int main() {
	int n;
	printf("enter the value of n");
	scanf("%d",&n);
	int a[n];
	for(int i = 0; i < n;i++) {
		scanf("%d",&a[i]);
	}
	quickSort(a,0,n-1);
	for(int i = 0; i < n;i++) {
		printf("%d ",a[i]);
	}
}
