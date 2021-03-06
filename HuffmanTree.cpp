#include<iostream>
#include<string>
#include<malloc.h>
const int N=4;
using namespace std;
using std::string;
typedef struct
{
	char symbol;
	int weight;
	int parent,lchild,rchild;
}HTnode,*HuffmanTree;
typedef char*  *HuffmanCode;

void Selectusing(HuffmanTree &HT,int &k,int &t)//Select函数将会调用的二级函数
{
	int j;
	for(j=1;j<=k;j++)
	{
		if(HT[j].parent==0)
		{
			t=j;
		    break;
		}
	}//找到第一个parent为0的节点编号作为t的初值
	for(j=1;j<=k;j++)
	{
		if(HT[j].parent==0)
			if(HT[j].weight<HT[t].weight)
				t=j;
	}//采用交换法搜索最小值
	
}

void Select(HuffmanTree &HT,int k,int& t1,int& t2)
{  //这也是Select函数的一种，只不过有点繁琐
	Selectusing(HT,k,t1);
	HT[t1].parent=1;//这是为了使得t1不对下一次筛选t2产生影响
	Selectusing(HT,k,t2);
	HT[t1].parent=0;//对上次为了消除t1对t2影响而做的修正，由于生成树过程会对其重新赋值，可以不要
}     


/*void Select(HuffmanTree HT,int u,int &s1,int &s2) 
{ //改进后的Select函数
    int j,k=1;                
   while(HT[k].parent!=0) 
       k++;
    s1=k;
    for(j=1;j<=u;++j)
       if(HT[j].parent==0&&HT[j].weight<HT[s1].weight)
    s1=j;
    k=1;
    while(HT[k].parent!=0||k==s1)
       k++;
    s2=k;
    for(j=1;j<=u;++j)
       if(HT[j].parent==0&&HT[j].weight<HT[s2].weight&&j!=s1)
    s2=j;
 } 
*/

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,char *c,int *w,int n)//编码函数
{
	int i,s1,s2,ch,f;
	char *cd;
	HuffmanTree p;
	if(n<=1)
		cout<<"Empty!"<<endl;
	int m=2*n-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTnode));
	for(p=HT+1,i=1;i<=n;++i,++p,++w,++c)
	{
		p->symbol=*c;
		p->weight=*w;
		p->parent=0;
		p->lchild=0;
		p->rchild=0;
	}
	//	*p={*c,*w,0,0,0};
	for(;i<=m;++i,++p)
	{
		p->symbol='0';
		p->parent=0;
	}
	//	*p={'\0',0,0,0,0};
	for(i=n+1;i<=m;++i)
	{
		Select(HT,i-1,s1,s2);
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
	cd=(char *)malloc(n*sizeof(char));
	cd[n-1]='0';
	int start;
	for(i=1;i<=n;++i)
	{
		start=n-1;
		for(ch=i,f=HT[i].parent;f!=0;ch=f,f=HT[f].parent)
			if(HT[f].lchild==ch)
				cd[--start]='0';
			else cd[--start]='1';
		HC[i]=(char*)malloc((n-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
	}
	free (cd);
}

void HuffmanDecoding(HuffmanTree &HT,int n)//译码函数
{
	string s;//以字符串来处理密码组较为简便
	cout<<"请依次输入二进制密码串:"<<endl;
	cin>>s;
	int i=0;
	HuffmanTree p=&HT[2*n-1];//搜索指针
	cout<<"译码结果是:"<<endl;
	while(i<s.size())
	{
      if(s[i]=='0')
		p=&HT[p->lchild];
	  else
		p=&HT[p->rchild];
	  if(p->lchild==0)//如果是叶节点则译出此字符
	  {
         cout<<p->symbol;
	     p=&HT[2*n-1];//必须将搜索指针重置到树根以进行下次搜索译码
	  }
	  i++;
	}
	
}

void main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int i;
	char symbol[N];
	char *c=symbol;
	int weight[N];
	int *w=weight;
	cout<<"请依次输入"<<N<<"个字符和其相应权值:"<<endl;
    for(i=0;i<N;i++)
	    cin>>symbol[i]>>weight[i];
	HuffmanCoding(HT,HC,c,w,N);
	cout<<"HuffmanTree静态存储结构如下:"<<endl;
	for(i=0;i<2*N-1;i++)
	     cout<<HT[i+1].symbol<<' '<<HT[i+1].weight<<' '<<HT[i+1].parent<<' '<<HT[i+1].lchild<<' '<<HT[i+1].rchild<<endl;
		 //用于测试HuffmanTree是否建成
	HuffmanDecoding(HT,N);
	cout<<endl;
}
