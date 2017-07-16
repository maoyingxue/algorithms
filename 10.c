#include "stdio.h"
#include "stdlib.h"
int paidui(int t[],int n){
    int i,a,u;
	for(u=1;u<=n;u++){
	for(i=u+1;i<=n;i++){
	if(t[u]>t[i])
	{ a=t[u];
	    t[u]=t[i];
		t[i]=a;
	}
	}
}
return 0;}
int main(void)
{
	int i,t[100]={0},n=0;
    printf("input the number of customers:\n");
    scanf("%d",&n);
    putchar('\n');

printf("input array t[n]:\n");
for(i=1;i<=n;i++){
scanf("%d",&t[i]);
} 
paidui(t,n);
printf("output array t[n] after sort:\n");
for(i=1;i<=n;i++){
printf("%d ",t[i]);
} 

  putchar('\n');
return 0;
}