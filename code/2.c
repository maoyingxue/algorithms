#include "stdio.h"
#include "stdlib.h"
#define SIZE 50
int a[SIZE][SIZE];
void copy(int n){
	int i,j,m=n/2;
for(i=1;i<=m;i++){
for(j=1;j<=m;j++){
	a[i][j+m]=a[i][j]+m;
a[i+m][j]=a[i][j+m];
a[i+m][j+m]=a[i][j];
}
}
}
void arrange(int n){
if(n==1)
{
a[1][1]=1;
return;

}
arrange(n/2);
copy(n);
}

void main(void){
int i,j,n=8;

arrange(n);
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
printf("%4d ",a[i][j]);
}
putchar('\n');
}
}