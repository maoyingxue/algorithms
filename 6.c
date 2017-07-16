#include <stdio.h>
#include <stdlib.h>
void merge(int number[],int first,int last,int mid)
{
    int number_temp[50]={0};
    int i=first,j=mid+1,k;
    for(k=1;k<=last-first+1;k++)
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
    for (i=first,j=1;i<=last;i++,j++)
    number[i] = number_temp[j];
}

void merge_sort(int number[],int m,int n)
{
    int i;
  for(i=1;i<=(m-1);i++){
    merge(number,1,n*(i+1),n*i);
    }
}
int main(void)
{
    int i,a[]={0,2,8,1,9,4,5,3,7},j;
    for(i=1;i<=8;i++)
printf("%4d",a[i]);
	putchar('\n');
    merge_sort(a,4,2);
for(j=1;j<=8;j++)
printf("%4d",a[j]);
 putchar('\n');
    return 0;
}