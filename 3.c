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
    printf("����˿͸���n:\n");
    scanf("%d",&n);
    putchar('\n');

printf("����n���˿�����Ҫ�ķ���ʱ������t[i]:\n");
for(i=1;i<=n;i++){
scanf("%d",&t[i]);
} 
paidui(t,s,n);
printf("���n���˿ͷ���˳��:\n");
for(i=1;i<=n;i++){
printf("��%d����",s[i]);
} 

  putchar('\n');
return 0;
}