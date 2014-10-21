/*作 者：软件工程1003班  王行军
  时 间：2011-10-13-21:08
  说 明：本程序实现判断从键盘读入一串字符是否是回文，主要是训练自己关于队列和栈的使用技巧，
         同时作为课堂作业，程序中尚有不足或冗余之处，上交作业后本人也会再度进行修改，优化。
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
		cout<<"队列已满!"<<endl;
	Q.q[Q.rear]=c;
	Q.rear=(Q.rear+1)%MAX;
}


void OutSqQueue(SqQueue &Q,char &c)
{
	if(Q.rear==Q.front)
		cout<<"栈已满!"<<endl;
	c=Q.q[Q.front];
	Q.front=(Q.front+1)%MAX;
}

void PushSqStack(SqStack &S,char &c)
{
	if(S.top-S.base>=MAX)
		cout<<"栈满!"<<endl;
	*S.top++=c;
}

char GetTop(SqStack &S)
{
	return (*--S.top);
}

void InitSqQueue(SqQueue &Q)
{
	char c;
	cout<<"请依次输入字符以#号结束:"<<endl;
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
		cout<<"您输入的字符是回文"<<endl;
	else
		cout<<"您输入的字符不是回文"<<endl;
}


int main()
{
	Test();
	return 0;
}

