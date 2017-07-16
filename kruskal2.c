#include <stdio.h>
#include <stdlib.h>
 
#define MAX 100
#define N 6//顶点数目 
/* 定义边(x,y)*/
typedef struct
{
	int x,y;
}edge;
edge e[MAX];
/* father[x]表示x的父节点 */
int father[N+1];
/* 判断集合是否相同 */
int Is_same(int i, int j)
{
//找到i的父节点
while(father[i] != i)
{
i =  father[i];
}
//找到i的父节点
while(father[j] != j)
{
j = father[j];
}
return i == j ? 1 : 0;
}
/* 合并x,y所在的集合 */
void Mark_same(int i, int j)
{
int temp;
if(i > j)
{
temp = i;
i = j;
j = temp;
} 
//找到i的父节点
while(father[i] != i)
{
i= father[i];
}
father[j] = i;//将j指向其父节点
}
//初始化 father数组 
void Initialize()
{
int i;
for(i=1; i<=N;i++)
 father[i] = i;
}
/* 主函数 */
int main(){
	int i=1;    
/* 输入边信息并初始化集合 */
printf("以（u,v）形式输入以1~6为顶点边8组:\n");
for(i=1;i<=8;i++)
scanf("%d,%d",&e[i].x,&e[i].y);
Initialize();
printf("根据输入顺序，依次判断输出8条边中不形成环的边:\n");
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