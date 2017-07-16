#include "stdio.h"
#include "stdlib.h"
void greedyMoney(double m[],int k,double n) 
{ 
   int i; 
   for(i=1;i<=k;i++) 
   { 
      while(n>=m[i] && n>0) 
      { 
          printf("%.1f ",m[i]);  
          n = n-m[i]; 
      } 
   }  

   printf("\n"); 
     
} 
 
int main(void) 
{ 
  double money[] = {0,100,50,20,10,5,1,0.5,0.1}; 
  int k; 
  k =sizeof(money)/sizeof(money[1])-1;  
  greedyMoney(money,k,68.9); 

   printf("\n"); 

} 
 
