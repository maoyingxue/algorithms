#include <stdio.h>  
  
//���г���  
#define LEN 30  
int arr[LEN];  
  
//��ʼ������  
void init_list()  
{  
    int i = 0;  
    for (i = 0;i < LEN;i++)  
    {  
        arr[i] = 0;  
    }  
}  
  
//���ָ����ŵĶ���λ��  
int get_pos(int index)  
{  
    return arr[index];  
}  
  
//��ö��ױ��  
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
  
//��ö�β���  
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
  
//���������Ƿ��ж�Ӧ���  
//�з���1,û�з���0  
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
  
//��ջ  
int push(int index)  
{  
    int i = 0;  
      
    //����Ƿ��Ѿ��ڶ�����  
    if (check_in(index) != 0)  
    {  
        return 0;  
    }  
      
    //��ö�β���  
    i = get_end();  
    //�����β  
    arr[index] = get_pos(i) + 1;  
      
    return 1;  
}  
  
//��ջ  
void pop()  
{  
    int i = 0;  
      
    //��ö��ױ��  
    i = get_head();  
    //��ջ  
    arr[i] = 0;  
    //�������ǰ��1λ  
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
	//���Բ���  
    //��ʼ������  
    init_list();  
    //��ջ  
    push(3);  
    push(5);  
    push(7);  
    push(9);  
    push(25);  
    //������ױ��  
    printf("������%d\n",get_head());  
    //�����β���  
    printf("��β��%d\n",get_end());  
	//���������Ԫ�ظ���
	a=get_pos(get_end())-get_pos(get_head())+1;
	printf("������Ԫ�ظ���%d\n",a);
    //��ջ  
    pop();  
    //������ױ��  
    printf("������%d\n",get_head());  
    //�����β���  
    printf("��β��%d\n",get_end());  
    //���������Ԫ�ظ���
	a=get_pos(get_end())-get_pos(get_head())+1;
	printf("������Ԫ�ظ���%d\n",a);
    //��ջ  
    pop();  
    //������ױ��  
    printf("������%d\n",get_head());  
    //�����β���  
    printf("��β��%d\n",get_end());  
    //���������Ԫ�ظ���
	a=get_pos(get_end())-get_pos(get_head())+1;
	printf("������Ԫ�ظ���%d\n",a);
    return 0;  
}  