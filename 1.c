#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
void merge(int number[],int first,int last,int mid)
{
    int number_temp[5000]={0};
    int i=first,j=mid+1,k;
    for(k=0;k<=last-first;k++)
    {
    if (i==mid+1)
    {
    number_temp[k]=number[j++];
    continue;
    }
    if (j==last+1)
    {
    number_temp[k]=number[i++];
    continue;
    }
    if (number[i]<number[j])  number_temp[k]=number[i++];
    else  number_temp[k]=number[j++];
    }
    for (i=first,j=0;i<=last;i++,j++)
    number[i] = number_temp[j];
}
void merge_sort(int number[],int first,int last)
{
    int mid=0;
    if(first<last)
    {
    mid=(first+last)/2;
    merge_sort(number,first,mid);
    merge_sort(number,mid+1,last);
    merge(number,first,last,mid);
    }
}
int main(void)
{
    int i,a[5000],j,start,finsh;
    printf("output the integers(1-5000):\n");
    srand((unsigned)time(NULL));
    for(i=0;i<5000;i++)
    {
        a[i]=1+rand()%100;
        printf("%4d ",a[i]);
    }
    putchar('\n');
	start=clock();
    //merge_sort(a,0,4999);//44
	InsertSort(a,5000);//53
	finsh=clock();
for(j=1;j<=5000;j++)
printf("%4d ",a[j-1]);
 putchar('\n');
 printf("Merge sort run time:\n");
printf("%4d ",finsh-start);
 putchar('\n');
    return 0;
}