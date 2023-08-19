#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct point {
	int x,y;

};
struct point p[100];

   void convex(int n) {
      int i,j,k,f,d,a,b,c;
      for(i = 0; i<n-1;i++) {
      	 for(j = i+1;j < n;j++){
      	     a = p[i].x - p[j].x;
      	     b = p[j].y - p[i].y;
      	     c = p[i].x * p[j].y - p[j].x *p[i].y;
      	     int np = 0,nn = 0;
      	     for(k = 0; k < n;k++) {
      	          if(k == i && k == j) {
      	             continue;
      	          }
      	        d = a*p[k].x + b * p[k].y+c;
      	        if (d > 0)
      	         np++;
      	        else if( d <0) 
      	        nn++;
      	     }
     if (np == 0|| nn == 0) {
       printf("the polygon points x1 = %d,y1 = %d,x2 = %d,y2 = %d\n",p[i].x,p[i].y,p[j].x,p[j].y);
     } 
      
  	     
 }
  
      
}
}  



int main() {
     FILE *file = fopen("/home/student/Documents/daaaa/cost.txt","w");
   int n,i,j,min,x1,x2,y1,y2,d;
   printf("enter the value of the n");
   scanf("%d",&n);
   if(file == NULL) {
 	printf("enter the while opening the file");
   }
   else {
     for(i = 0; i< n;i++) {
     
	fprintf(file,"%d %d\n",rand() % 10,rand() % 10);
     }
   
   }
fclose(file);
file = fopen("/home/student/Documents/daaaa/cost.txt","r");

      if(file == NULL) {
 	printf("enter the while opening the file");
   }
   else {
     for(i = 0; i< n;i++) {
     
	fscanf(file,"%d %d\n",&p[i].x,&p[i].y);
	printf("%d %d\n",p[i].x,p[i].y);
     }
   
   }
fclose(file);
convex(n);

}
