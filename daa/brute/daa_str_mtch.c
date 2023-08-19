#include<stdio.h>
#include<string.h>

int main(){
	char str1[100];
	char str2[100];
	printf("Enter main string : ");
	gets(str1);
	printf("Enter sub String : ");
	gets(str2);
	int f=1;
	int i;
	for(i=0;i<=(strlen(str1)-strlen(str2));i++){
		if(str1[i] == str2[0]){
			int l=1,j,k=1;
			  for(j=i+1;j<(i+strlen(str2));j++){
			  	if(str1[j] == str2[k++]){
			  		++l;
				  }
			  }                                    
			  if(l == strlen(str2)){
			  	f = 0;
			  	printf("index starts from  %d",i);
			  	break;
			  }
		}
		
	}
	if(f == 1) {
		printf("Not found");
	}
}
