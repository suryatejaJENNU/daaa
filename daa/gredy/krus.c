#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int adj[100][100],parent[100];

/*/*int a[6][6]={{-1,3,-1,-1,-1,7},
         {3,-1,5,-1,8,-1},
         {-1,5,-1,6,-1,4},
         {-1,-1,6,-1,4,-1},
         {-1,8,-1,4,-1,2},
         {7,-1,4,-1,2,-1}};*/*/

//min cost is 18



int findparent(int i) 
{
	while(parent[i] != -1)
		i = parent[i];
	return i;
}

void findminedge(int n,int *u,int *v) 

{
	int min = INT_MAX;
	for(int i = 0; i < n;i++) 
	{
		for(int j = 0; j < n;j++)
		{
			if(adj[i][j] != -1 && min > adj[i][j])
			
			{
				min = adj[i][j];
				*u = i;
				*v = j;

			}
		}
	}
}



void krus(int n) 
{
	int k,u = 0,v = 0,pu,pv,cost = 0;
	k = n;
	while(k > 0) 
	{
		findminedge(n,&u,&v);
		pu = findparent(u);
		pv = findparent(v);
		if(pu != pv)
		{
			parent[pv] = pu;
			printf("%d --> %d\n",u,v);
			cost = cost + adj[u][v];
			
		}
		k--;
		adj[u][v] = -1;
		adj[v][u] = -1;
		
	}
	printf("the minmum cost is = %d",cost);
}










int main() 
{
	int n;
	printf("enter the value of the n");
	scanf("%d",&n);
	int i,j;
	for(i = 0; i < n;i++)
	{
		parent[i] = -1;
	}
	for(i =0;i < n;i++)
	{
		for(j = 0; j < n;j++) 
		{
			scanf("%d",&adj[i][j]);
		}
	}
	krus(n);
}
