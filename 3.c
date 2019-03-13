#include "stdio.h"
#include "stdlib.h"
int paidui(int t[],int s[],int n){
    int i,a=1000,u,b;
	for(u=1;u<=n;u++){
	for(i=1;i<=n;i++){
	if(t[i]<a)
	{ 
	a=t[i];
    b=i;
	}
	}
    t[b]=1000;
	a=1000;
	s[u]=b;}

return 0;}
int main(void)
{
	int i,t[50]={0},n=0,s[50]={1000};
    printf("输入顾客个数n:\n");
    scanf("%d",&n);
    putchar('\n');

printf("输入n个顾客所需要的服务时间数组t[i]:\n");
for(i=1;i<=n;i++){
scanf("%d",&t[i]);
} 
paidui(t,s,n);
printf("输出n个顾客服务顺序:\n");
for(i=1;i<=n;i++){
printf("第%d个〉",s[i]);
} 

  putchar('\n');
return 0;
}