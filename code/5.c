#include <stdio.h>
#include <stdlib.h>
 
#define MAX 100
#define N 6//������Ŀ 
/* �����(x,y)*/
typedef struct
{
	int x,y;
}edge;
edge e[MAX];
/* father[x]��ʾx�ĸ��ڵ� */
int father[N+1];
/* �жϼ����Ƿ���ͬ */
int Is_same(int i, int j)
{
//�ҵ�i�ĸ��ڵ�
while(father[i] != i)
{
i =  father[i];
}
//�ҵ�i�ĸ��ڵ�
while(father[j] != j)
{
j = father[j];
}
return i == j ? 1 : 0;
}
/* �ϲ�x,y���ڵļ��� */
void Mark_same(int i, int j)
{
int temp;
if(i > j)
{
temp = i;
i = j;
j = temp;
} 
//�ҵ�i�ĸ��ڵ�
while(father[i] != i)
{
i= father[i];
}
father[j] = i;//��jָ���丸�ڵ�
}
//��ʼ�� father���� 
void Initialize()
{
int i;
for(i=1; i<=N;i++)
 father[i] = i;
}
/* ������ */
int main(){
	int i=1;    
/* �������Ϣ����ʼ������ */
printf("�ԣ�u,v����ʽ������1~6Ϊ�����8��:\n");
for(i=1;i<=8;i++)
scanf("%d,%d",&e[i].x,&e[i].y);
Initialize();
printf("��������˳�������ж����8�����в��γɻ��ı�:\n");
for (i=1;i<=8;i++)
{
if(!Is_same(e[i].x, e[i].y))
{ 
printf("%d,%d\n",e[i].x, e[i].y);
Mark_same(e[i].x, e[i].y);
}
}
return 0;
}