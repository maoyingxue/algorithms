#include "stdio.h"
#include "time.h"
#include "stdlib.h"
void InsertSort(int r[ ],int n)
{
	int i,j,x;
	for(i=1;i<n;i++)
	{
		 x=r[i];
		for(j=i-1;j>=0;j--)
			if(r[j]>x) 
				r[j+1]=r[j];
			else break;
		 r[j+1]=x;
	}

}

int main(void)
{
    int i,a[16],j;
    printf("output the integers(1-16):\n");
    srand((unsigned)time(NULL));
    for(i=0;i<16;i++)
    {
        a[i]=1+rand()%16;
        printf("%4d ",a[i]);
    }
    putchar('\n');
    InsertSort(a,16);
for(j=1;j<=16;j++)
printf("%4d ",a[j-1]);
putchar('\n');
    return 0;
}