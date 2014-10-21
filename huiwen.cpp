/*�� �ߣ��������1003��  ���о�
  ʱ �䣺2011-10-13-21:08
  ˵ ����������ʵ���жϴӼ��̶���һ���ַ��Ƿ��ǻ��ģ���Ҫ��ѵ���Լ����ڶ��к�ջ��ʹ�ü��ɣ�
         ͬʱ��Ϊ������ҵ�����������в��������֮�����Ͻ���ҵ����Ҳ���ٶȽ����޸ģ��Ż���
 */
#include<iostream>
using namespace std;
#define MAX 100
typedef struct
{
	char q[MAX-1];
	int front;
	int rear;
}SqQueue;
typedef struct
{
	char s[MAX-1];
	char *top;
	char *base;
}SqStack;

void InSqQueue(SqQueue &Q,char c)
{
	if((Q.rear+1)%MAX==Q.front)
		cout<<"��������!"<<endl;
	Q.q[Q.rear]=c;
	Q.rear=(Q.rear+1)%MAX;
}


void OutSqQueue(SqQueue &Q,char &c)
{
	if(Q.rear==Q.front)
		cout<<"ջ����!"<<endl;
	c=Q.q[Q.front];
	Q.front=(Q.front+1)%MAX;
}

void PushSqStack(SqStack &S,char &c)
{
	if(S.top-S.base>=MAX)
		cout<<"ջ��!"<<endl;
	*S.top++=c;
}

char GetTop(SqStack &S)
{
	return (*--S.top);
}

void InitSqQueue(SqQueue &Q)
{
	char c;
	cout<<"�����������ַ���#�Ž���:"<<endl;
	while(cin>>c&&c!='#')
		InSqQueue(Q,c);
}

void Test()
{
	SqQueue Q1,Q2;
	Q1.front=Q1.rear=0;
	Q2.front=Q2.rear=0;
	SqStack S;
	S.base=S.top=S.s;
	char e;
	int i=0;
	InitSqQueue(Q1);
	Q2=Q1;
	while(Q1.rear!=Q1.front)
	{
		OutSqQueue(Q1,e);
		PushSqStack(S,e);
	}
	
	for(;i<Q2.rear;i++)
	{
		char top=GetTop(S);
		if(Q2.q[i]!=top)
		break;
	}
	if(i==Q2.rear)
		cout<<"��������ַ��ǻ���"<<endl;
	else
		cout<<"��������ַ����ǻ���"<<endl;
}


int main()
{
	Test();
	return 0;
}

