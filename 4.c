#include <stdio.h>  
  
//队列长度  
#define LEN 30  
int arr[LEN];  
  
//初始化队列  
void init_list()  
{  
    int i = 0;  
    for (i = 0;i < LEN;i++)  
    {  
        arr[i] = 0;  
    }  
}  
  
//获得指定标号的队列位置  
int get_pos(int index)  
{  
    return arr[index];  
}  
  
//获得队首标号  
int get_head()  
{  
    int i = 0;  
    int index = 0;  
      
    for(i = 1;i < LEN;i++)  
    {  
        if (get_pos(index) == 0 && get_pos(i) > 0)  
        {  
            index = i;  
            continue;  
        }  
          
        if (get_pos(i) != 0 && get_pos(i) < arr[index])  
        {  
            index = i;  
        }  
    }  
      
    return index;  
}  
  
//获得队尾标号  
int get_end()  
{  
    int i = 0;  
    int index = 0;  
      
    for(i = 1;i < LEN;i++)  
    {  
        if (arr[i] > arr[index])  
        {  
            index = i;  
        }  
    }  
      
    return index;  
}  
  
//检查队列中是否有对应标号  
//有返回1,没有返回0  
int check_in(int index)  
{  
    if (arr[index] > 0)  
    {  
        return 1;  
    }  
    else  
    {  
        return 0;  
    }  
}  
  
//进栈  
int push(int index)  
{  
    int i = 0;  
      
    //检查是否已经在队列中  
    if (check_in(index) != 0)  
    {  
        return 0;  
    }  
      
    //获得队尾标号  
    i = get_end();  
    //插入队尾  
    arr[index] = get_pos(i) + 1;  
      
    return 1;  
}  
  
//出栈  
void pop()  
{  
    int i = 0;  
      
    //获得队首标号  
    i = get_head();  
    //出栈  
    arr[i] = 0;  
    //其他标号前移1位  
    for (i = 0;i < LEN;i++)  
    {  
        if (get_pos(i) > 1)  
        {  
            arr[i]--;  
        }  
    }  
}  
  
int main()  
{  
   int a;
	//测试操作  
    //初始化队列  
    init_list();  
    //入栈  
    push(3);  
    push(5);  
    push(7);  
    push(9);  
    push(25);  
    //输出队首标号  
    printf("队首是%d\n",get_head());  
    //输出队尾标号  
    printf("队尾是%d\n",get_end());  
	//输出队列中元素个数
	a=get_pos(get_end())-get_pos(get_head())+1;
	printf("队列中元素个数%d\n",a);
    //出栈  
    pop();  
    //输出队首标号  
    printf("队首是%d\n",get_head());  
    //输出队尾标号  
    printf("队尾是%d\n",get_end());  
    //输出队列中元素个数
	a=get_pos(get_end())-get_pos(get_head())+1;
	printf("队列中元素个数%d\n",a);
    //出栈  
    pop();  
    //输出队首标号  
    printf("队首是%d\n",get_head());  
    //输出队尾标号  
    printf("队尾是%d\n",get_end());  
    //输出队列中元素个数
	a=get_pos(get_end())-get_pos(get_head())+1;
	printf("队列中元素个数%d\n",a);
    return 0;  
}  