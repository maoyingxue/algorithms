#include <stdio.h>
#include <stdlib.h>

int n=3;
int w[]={0,100,14,10};
int p[]={0,20,18,15};

int F(int i,int y)
{
    if(i==n) return (y<w[n])?0:p[n];
	if(y<w[i]) return F(i+1,y);
	if(F(i+1,y)>=F(i+1,y-w[i])+p[i])
		return F(i+1,y);
	else 
		return F(i+1,y-w[i])+p[i];

}
int main(){
    int t,i,y=116,x[4]={0};
	t=F(1,116);
	printf("最大价值:\n");
    printf("%d\n",t);
	for(i=1;i<n;i++)
	{
		if(F(i,y)>F(i+1,y)){
		x[i]=1;
		y=y-w[i];
		}
		else x[i]=0;
	}
	if(y>=w[n])
    x[n]=1;
	else 
		x[n]=0;
	printf("是否携带(1(携带)/0(不带)):\n");
	for(i=1;i<=n;i++){
	   printf("%d ",x[i]);
	}
	printf("\n");
}