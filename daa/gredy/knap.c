#include<stdio.h>
#include<stdlib.h>
int wt[10],val[10];

void swap(int a[],int i ,int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


void sort(int wt[],int val[],int n) 
{
	for(int i = 0;i < n-1;i++) 
	{
		for(int j = 0; j < n-i-1;j++)
		{
			if(val[j]/wt[j] < val[j+1]/wt[j+1])
			{
				swap(wt,j,j+1);
				swap(val,j,j+1);
			}
		}
	}
}


int factknap(int wt[],int val[],int w,int n) 
{
	int sum = 0;
	sort(wt,val,n);
	for(int i = 0; i < n;i++)
	{
		if(wt[i] <= w) 
		{
			sum = sum + val[i];
			w = w- wt[i];
		}
		else 
		{
			sum = sum + (w * val[i]/wt[i]);
			break;
		}
		
	  
	}
	return sum;
}








int main()
{
	int n,w,i,j;
	printf("enter the value of the n");
	scanf("%d",&n);
	printf("enter the weights ");
	for(i = 0; i < n;i++) 
	{
		scanf("%d",&wt[i]);
	}
	printf("enter the values");
	for(i = 0;i < n;i++)
	{
		scanf("%d",&val[i]);
	}
	printf("enter the bag weight");
	scanf("%d",&w);
	int result;
	result = factknap(wt,val,w,n);
	printf("the final sum = %d",result);
}

