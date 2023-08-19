#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int heapify(int a[],int n,int i) 
{
	int left,right,small;
	small = i;
	left = (2 * i) + 1;
	right = (2 * i) + 2;
	if(left < n && a[left] < a[small])
	{
		small = left;
	}
	if(right < n && a[right] < a[small])
	{
		small = right;
	}
	if(small != i) 
	{
		int temp = a[small];
		a[small] = a[i];
		a[i] = temp;
		heapify(a,n,small);
	}
}

int opt_merge(int a[],int n,int ans)
{
	int sum,temp,i;
	if(n == 1)
	{       
		printf("total sum = %d\n",ans);
		return a[0];
	}
	for(i = n-1;i>=n-2;i--)
	{
		temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		heapify(a,i,0);
	}
	sum = a[n-1] + a[n-2];
	ans += sum;
	//printf("%d\n",sum);
	a[n-2] = sum;
	n = n -1;
	opt_merge(a,n,ans);
}

int buildminheap(int a[],int n){
	int sindex = (n/2) ;
	for(int i =sindex ; i >= 0 ;i--)  {
	   heapify(a,n,i);
      }
}



int main() 
{
	int n,res;
	printf("enter the value of the n");
	scanf("%d",&n);
	int i,r;
	int a[n];
	for(i = 0; i < n;i++) 
	{
		scanf("%d",&a[i]);
	}
	buildminheap(a,n);
	int ans = 0;
	for(int i=0;i<n;i++) printf("%d ",a[i]);
	res = opt_merge(a,n,ans);
	printf("the final optial merge solution %d",res);
}
