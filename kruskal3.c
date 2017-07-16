#include <stdio.h>
#include <stdlib.h>
 
#define MAX 100
#define N 6//������Ŀ 
 
/* �����(x,y)��ȨΪw */
typedef struct
{
int x,y;
int w;
}edge;
 
edge e[MAX];
/* father[x]��ʾx�ĸ��ڵ� */
int father[N];
 
/* �ȽϺ�������Ȩֵ(��ͬ��x����)�ǽ������� */
int cmp(const void *a, const void *b)
{
if ((*(edge *)a).w == (*(edge *)b).w)
{
return (*(edge *)a).x - (*(edge *)b).x;
}
return (*(edge *)a).w - (*(edge *)b).w;
}
 
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
for(i=0; i<N;i++)
 father[i] = i;
}
/* ������ */
int main()
{
int i=0,j,n;
int x,y;
  FILE *fr;
fr = fopen("kruskal.txt","r");
if(!fr)
{
printf("fopen failed\n");
exit(1); 
}
/* ��ȡ����Ϣ����ʼ������ */
while(fscanf(fr,"%d %d %d", &e[i].x, &e[i].y, &e[i].w) != EOF)
i++;
/* �������� */
qsort(e, i, sizeof(edge), cmp);
Initialize();
 
for (i = 0; i < N-1; i++)
{
if(!Is_same(e[i].x, e[i].y))
{ 
printf("%d %d\n",e[i].x, e[i].y);
Mark_same(e[i].x, e[i].y);
}
}
 
system("pause");
return 0;
}