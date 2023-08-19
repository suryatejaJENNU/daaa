#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int maxHeapfiy(int a[],int n ,int i) {
	int left,right,largest;
	largest = i;
	left = 2 * i;
	right = (2 * i) + 1;
	while(left <= n && a[left] > a[largest]) {
		largest = left;
	}
	while(right <= n && a[right] > a[largest]) {
		largest = right;
	}
	if(largest != i) {
		int temp;
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		maxHeapfiy(a,n,largest);
	}
}




int bulidmaxHeap(int a[],int n) {
	int temp;
	for(int i = n /2 ; i >= 1;i--) {
		maxHeapfiy(a,n,i);
	}
	for(int i = n;i >= 1;i--) {
		temp = a[1];
		a[1] = a[i];
		a[i] = temp;
		maxHeapfiy(a,i-1,1);
	}
		
}





int main() {
	int n;
	printf("enter the value of the n");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements of the array");
	for(int i = 1; i <= n;i++) {
		scanf("%d",&a[i]);
	}
	bulidmaxHeap(a,n);
	printf("array after sorting");
	for(int i = 1;i <= n;i++) {
		printf("%d ",a[i]);
	}
}
