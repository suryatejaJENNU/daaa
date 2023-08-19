#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
struct point{
int x,y;
};
float bf(struct point p[],int n)
{
 int i,j,k;
 float min=9999,dist;
 for(i=0;i<n-1;i++)
 {
 for(j=i+1;j<n;j++)
 {
   dist=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
   if(min>dist)
   min=dist;
   }
   }
   return min;
   }
void sort(struct point p[],int n)
{
 int i,j;
 struct point t;
 for(i=0;i<n-1;i++)
 {
  for(j=0;j<n-i-1;j++)
  {
   if(p[j].x>p[j+1].x)
   {
   t=p[j];
   p[j]=p[j+1];
   p[j+1]=t;
   }
  }
  }
  } 
 float cpair(struct point p[],int s,int e)
 {
  int i,j,k,m;
  float ds,dl,dr;
  struct point strip[10];
  if(e-s>=2)
   bf(p,e);
  else
  {
   m=(e+s)/2;
   dr=cpair(p,m+1,e);
   dl=cpair(p,s,m);
   k=dr<dl?dr:dl;
   int l=0;
   for(i=0;i<e;i++)
   {
   if(p[i].x>=(p[m].x-k) && p[i].x<=(p[m].x+k))
   strip[l++]=p[i];
   }
   
   ds=bf(strip,l);
   return ds<k?ds:k;
   }
   }  
int main()
{
int n,i,j;
scanf("%d",&n);
struct point p[n];
for(i=0;i<n;i++)
{
   scanf("%d %d",&p[i].x,&p[i].y);
   }
   sort(p,n);
   float res=cpair(p,0,n-1);
   printf("cost is %f",res);
   }
