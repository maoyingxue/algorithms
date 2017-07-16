struct complex
{
	float realpart;
	float imagpart;
};
struct complex initcomplex(float z1,float z2);
struct complex add(struct complex z1,struct complex z2);
struct complex multiply(struct complex z1,struct complex z2);
struct complex division(struct complex z1,struct complex z2);