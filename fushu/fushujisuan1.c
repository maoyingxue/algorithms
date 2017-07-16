#include <stdio.h>
#include "fushujisuan.h"
int main()
{ 
    struct complex z1,z2,z3,z4,z;
    z1=initcomplex(8.0,6.0);
    z2=initcomplex(4.0,3.0);
    z3=add(z1,z2);
    z4=multiply(z1,z2);
    z=division(z4,z3); 
    printf("%f+%fi\n",z.realpart,z.imagpart);
    return 0;
}