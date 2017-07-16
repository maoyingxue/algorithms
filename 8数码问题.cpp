#include <iostream>
#include <time.h>
#include <queue>
#include <stack>
#define N 9
using namespace std;
enum dir{Up,Down,Left,Right,None};//����
const int add[4]={-3,3,-1,1};

//���ṹ��ʾ
struct map
{
    int dig[N];
    dir lockDir;//�����η���
    map * last;//���ڵ�
};

//��ʾ8����״̬ͼ
void Print(map *Map)
{
    cout<<"******************"<<endl;
 for(int i=0;i<N;i++)
 {
  cout<<Map->dig[i]<<" ";
  if((i+1)%3==0) 
   cout<<endl;
 }
}

//���ư������н��Ƶ��ƶ�
map * Move(map * Map,dir Direct,bool CreateNewMap)
{
    map * NewMap; 
 //��ȡ���и�λ��
    int i;
 for(i=0;i<N;i++)
  if(Map->dig[i]==0)
   break;
    //�ƶ�����
 int j=i;
    bool AbleMove = true;
    switch(Direct)
    {    
 case Up:  
  if(i<3)
            AbleMove=false;
  i=i+add[0];
        break;
    case Down:  
  if(i>5)
   AbleMove=false;
  i=i+add[1];
        break;
    case Left:  
  if(i%3==0)
            AbleMove=false;
  i=i+add[2];
        break;
    case Right:  
  if(i%3==2)
            AbleMove=false;
  i=i+add[3];
        break;
    };
    if(!AbleMove)//�������ƶ��򷵻�ԭ�ڵ�
        return Map;
    if(CreateNewMap)
    {
        NewMap = new map();
  for(int x=0;x<N;x++)
  {
   NewMap->dig[x]=Map->dig[x];
  }
    }
    else
        NewMap = Map;
    NewMap->dig[j] = NewMap->dig[i];
 NewMap->dig[i]=0;
    return NewMap;
}

//�ж��Ƿ��ҵ������Ž�
bool ifSuccess(map * Map,map * end)
{
 bool suc = true;
 for(int i=0;i<N;i++)
 {
  if(Map->dig[i]!=end->dig[i])
  {
   suc = false;
   break;
  }
 }
 return suc;
}

//������������㷨BFS
map * BNFS(map * beg,map * end)
{
  map * p1, *p2, *p=NULL;
  
  
  queue<map *> Queue;
  if(ifSuccess(beg,end))
   return beg;
  Queue.push(beg);
  do
  {
   p1 = Queue.front();
   Queue.pop();
   for (int i = 0; i < 4; i++)
   {
    dir Direct=(dir)i;
             if(Direct==p1->lockDir)
     continue;
    p2 = Move(p1,Direct,true);
    if(p2 != p1)//�����Ƿ�����ƶ�
    { 
     p2->last = p1;
     switch(Direct)//�������η���
     {
     case Up:
      p2->lockDir = Down;
      break;
     case Down:
      p2->lockDir = Up;
      break;
     case Left:
      p2->lockDir = Right;
      break;
     case Right:
      p2->lockDir = Left;
      break;
     }
    if (ifSuccess(p2,end))
    {
      p = p2;
      return p;
    }
    Queue.push(p2);
    }
   }
  }
  while(!Queue.empty() || p==NULL);
  return p;
}

//����dig[9]�е����������Ӷ��ж����Ž��Ƿ����
int numDes(map *Map)
{
 int a=0;
 for(int i=0;i<N;i++)
 {
  if(Map->dig[i]==0) continue;
  for(int j=i+1;j<N;j++)
  {
   if(Map->dig[j]==0) continue;
   if(Map->dig[j] <Map->dig[i])
    a++;
  }
 }
 return a%2;
}

int main()
{
  map end;
  map *beg,*T;
  int numStep=0;
  beg=new map;
  cout<<"������������ʼ״̬��"<<endl;
  for(int j=0;j<N;j++)
   cin>>beg->dig[j];
  cout<<endl;
  cout<<"�����������Ŀ��״̬��"<<endl;
  for(int i=0;i<N;i++)
   cin>>end.dig[i];
  cout<<endl;
  beg->last = NULL;
  beg->lockDir = None;
  cout<<"�������ʼͼ:"<<endl;
  Print(beg);
  cout<<"������Ŀ��ͼ:"<<endl;
  Print(&end);
  int a1=numDes(&end);
  int a2=numDes(beg);
  if(a1!=a2)
   cout<<"ERROR:�����޽⣡"<<endl;
  else
  {
   double startTime=clock();
   T=BNFS(beg,&end);
   double endTime=clock();
   if(T != NULL)
   {
    map *p=T;
    stack<map *> Stack1;
    while(p->last != NULL)
    {
     Stack1.push(p);
     p=p->last;
    }
    cout<<endl;
    cout<<"��������:"<<endl;
    while(!Stack1.empty())
    {
     cout<<"��"<<numStep+1<<"��:"<<endl;
     Print(Stack1.top());
     cout<<endl;
     numStep++;
     Stack1.pop();
    }
             cout<<endl;
    cout<<"��������"<<numStep<<endl;
    cout<<"��ʱ��"<<endTime-startTime<<"����"<<endl;
   }
  }
  return 0;
}
