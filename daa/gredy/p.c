#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdlib.h>



void prims(int a[][6],int v[],int n) 
{
	int l,i,j,u,k,min;
	v[0] = 1;
	for(l = 0; l < n -1;l++)
	{ 
		u = 0;
		k = 0;
		min = INT_MAX;
		for(i = 0;i < n;i++)
		{
			if(v[i] == 1) 
			{
				for(j = 0; j < n;j++) 
				{
					if(v[j] != 1 && a[i][j] != -1) 
					{
						if(min > a[i][j]) 
						{
							min = a[i][j];
							u = i;
							k = j;
						}		
					}
				}
				
			}
		
		
		
		}
		//printf("min value = %d\n",min);
		v[k] = 1;
		printf("%d-%d = %d\n",u,k,a[u][k]);
		
		
		
	}
}













int main(){
	int n;	
	printf("enter the value of the n");
	scanf("%d",&n);
	
	//printf("enter the values ");
	int a[n][n];
	int i,j;
	for(i = 0;i < n;i++) 
	{
		for(j = 0; j < n ;j++) 
		{
			scanf("%d",&a[i][j]);
		}
	}
	/*int a[6][6]={{-1,3,-1,-1,-1,7},
         {3,-1,5,-1,8,-1},
         {-1,5,-1,6,-1,4},
         {-1,-1,6,-1,4,-1},
         {-1,8,-1,4,-1,2},
         {7,-1,4,-1,2,-1}};*/
	int visited[n];
	for(i =0; i < n;i++) 
	{
		visited[i] = -1;
	}
	prims(a,visited,n);
}
