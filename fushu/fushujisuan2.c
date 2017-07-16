#include <stdio.h>
#include "fushujisuan.h"
typedef struct
{
   float realpart;
   float imagpart;
}complex;
struct complex initcomplex(float z1,float z2)
{
	struct complex z;
	z.realpart=z1;
	z.imagpart=z2;
    return(z);
};
struct complex add(struct complex z1,struct complex z2)
{
	struct complex z;
	z.realpart=z1.realpart+z2.realpart;
	z.imagpart=z1.imagpart+z2.imagpart;
	return(z);
};
struct complex multiply(struct complex z1,struct complex z2)
{
	struct complex z;
	z.realpart=z1.realpart*z2.realpart-z1.imagpart*z2.imagpart;
	z.imagpart=z1.imagpart*z2.realpart+z1.imagpart*z2.realpart;
    return(z);
};
struct complex division(struct complex z4,struct complex z3)
{
	struct complex z;
	float temp;
	temp=z3.realpart*z3.realpart+z3.imagpart*z3.realpart;
	z.realpart=(z4.realpart*z3.realpart+z4.imagpart*z3.realpart)/temp;
	z.imagpart=(z4.imagpart*z3.realpart-z4.realpart*z3.imagpart)/temp;
	return(z);
};
