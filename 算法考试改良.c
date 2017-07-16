#include "stdio.h"   
#include "string.h"   
int w[16+1]={0};
int a=0;
//cÓïÑÔÎÞboolÐÍ
int find(int low,int high){

    int mid,d=0;
	mid=(low+high)/2;
	
	if(low+1==high){
		if(w[low]>w[high])
		{	a=high;

	}
	if(w[low]<w[high]) 
		{	a=low;		
	}
		
	}
	else{	find(low,mid);
	find(mid+1,high);}

if(a==0)
			return 0;
		else 
			return 1;
}
void main(){
	int b,i;
	for(i=1;i<=16;i++)
		w[i]=5;
	w[14]=4;
	b=find(1,16);
if(b=1)
	printf("true\n");
else
printf("false\n");
	printf("%d\n",a);
}