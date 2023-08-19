#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
struct point {
int x;
int y;
};
int bruteforce(struct point p[],int st,int end)
{
int i,j,dist,min;
min=INT_MAX;
for(i=st;i<end-1;i++)
{
for(j=i+1;j<end;j++)
{
dist=((p[i].x-p[j].x)*(p[i].x-p[j].x))+((p[i].y-p[j].y)*(p[i].y-p[j].y));
if(dist<min)
{
min=dist;
}
}
}
return min;
}
void sort(struct point p[],int end)
{
int i,j;
struct point temp;
for(i=0;i<end-1;i++)
{
for(j=0;j<end-i-1;j++)
{
if(p[j].x>p[j+1].x){
temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;
}
}
}
for(i=0;i<end;i++)
{
printf("(%d,%d)",p[i].x,p[i].y);
}
}
int cpair(struct point p[],int start,int end)
{
int i,j,k,l,dl,dr,ds,mid,s;
struct point strip[100];
if(end-start<=2)
{
return bruteforce(p,start,end);
}
else
{
mid=(start+end)/2;
dl=cpair(p,start,mid);
dr=cpair(p,mid+1,end);
k=dl>dr?dr:dl;
l=0;
for(i=0;i<end;i++)
{
if(p[i].x>=(p[mid].x)-k&&p[i].x<=(p[mid].x)+k)
{
strip[l++]=p[i];
}
}
}
ds=bruteforce(strip,0,l);
return ds>k?k:ds;
}
int main()
{
struct point p[100];
int n;
printf("enter the array size:");
scanf("%d",&n);
int i;
printf("enter the array elements:");
for(i=0;i<n;i++)
{
scanf("%d%d",&p[i].x,&p[i].y);
}
sort(p,n);
int l=cpair(p,0,n-1);
printf("%d\n",l);
//return 0;
}















