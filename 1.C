#include "stdio.h"
#include "time.h"
#include "stdlib.h"
int main(void)
{
    int i,a[10000],x,k=0;
    printf("output the integers(1-10000):\n");
    srand((unsigned)time(NULL));
    for(i=1;i<=10000;i++)
    {
        a[i-1]=rand()%16+1;
        printf("%4d ",a[i-1]);
      
    }
    putchar('\n');
x=rand()%16+1;
  printf("output the integers x:\n");
  printf("%4d",x);
 putchar('\n');
printf("output the amounts of same number:\n");
for(i=1;i<=10000;i++){
if(x==a[i-1])
{
k++;

}} printf("%4d",k);
 putchar('\n');
return 0;
}