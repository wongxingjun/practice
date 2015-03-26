#include<iostream>
using namespace std;
typedef struct person
{
	int num;
	int pass;
	struct person *next;
}Line;


Line* create(int n)
{
	Line *h,*p,*pn,*q,*q1;
	int i;
	h=new Line;
	h->next=NULL;
	pn=new Line;
	pn->num=n;
	pn->next=h->next;
	h->next=pn;
	for(i=n-1;i>0;--i)
	{
		p=new Line;
		p->num=i;
		p->next=h->next;
		h->next=p;
	}
	pn->next=h->next;
	delete h;
	q=pn->next;
	q1=q;
	cout<<"请依次输入"<<n<<"个成员的密码："<<endl;
	for(i=1;i<=n;i++)
	{
		cin>>q1->pass;
		q1=q1->next;
	}
	return(q);
}


void count(Line* h,int n)
{
	Line *p1,*p2;
	p1=h;
	int m=p1->pass;
	while(n>0)
	{
		for(int i=1;i<m;i++)
		{
			p2=p1;
			p1=p1->next;
		}
    cout<<p1->num<<"  ";
	m=p1->pass;
    p2->next=p1->next;
	delete p1;
	p1=p2->next;
	n--;
	}
}




int main()
{
	Line *start;
	int n;
	cout<<"请输入人数:"<<endl;
	cin>>n;
	start=create(n);
	cout<<"出列顺序为:"<<endl;
	count(start,n);
	getchar();
    return 0;
}



