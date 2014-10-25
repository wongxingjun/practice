/********************************************************************
	created:	2011-11-20
	created:	20:02
	filename: 	G:\DataSructure\ʵ�����\ҽԺѡַ\Graph.cpp
	file path:	G:\DataSructure\ʵ�����\ҽԺѡַ
	file base:	Graph
	file ext:	cpp
	author:		wangxingjun
	
	purpose:	�Ͻ�˼�����㷨֮ҽԺѡַ�������
*********************************************************************/
#include<iostream.h>
#define INFINITY  10000
#define MAX  20
typedef int PathMatrix[MAX][MAX];
typedef int ShortPathTable[MAX];
typedef struct
{
	char vexs[MAX];
	int arcs[MAX][MAX];
	int vexnum,arcnum;
}Graph;

int LocateVex(Graph &G,char &v)
{//ȷ��v�ڵ���ͼG�е�λ���Ա��ʼ��ͼ
	for(int i=0;i<G.vexnum;i++)
		if(G.vexs[i]==v)
			return i;
	return -1;
}

void CreatGraph(Graph &G)
{//��ʼ��ͼG�������ڽӾ���Ĵ洢��ʽ
	int i,j,k,w;
	char v1,v2;
	cout<<"����������ڵ����ͻ�������:"<<endl;
	cin>>G.vexnum>>G.arcnum;
	cout<<"��������������ڵ��Ӣ�ı��:"<<endl;
	for(i=0;i<G.vexnum;i++)
		cin>>G.vexs[i];
	for(i=0;i<G.vexnum;i++)//��ʼ������
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j]=INFINITY;
	cout<<"�����������������ڽڵ������֮�仡��Ȩֵ:"<<endl;
	for(k=0;k<G.arcnum;k++)
	{
		cin>>v1>>v2>>w;
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		G.arcs[i][j]=G.arcs[j][i]=w;//����ͼ�Գƾ���
	}
}


void ShortestPath(Graph &G,int v0,PathMatrix &P,ShortPathTable &D)
{//�õϽ�˼�����㷨���ͼG�е�v0���ڵ㵽�����ڵ�����·��
 //�洢������D��
	int v,w,i,min;
	int final[MAX];
	for(v=0;v<G.vexnum;v++)//��ʼ��
	{
		final[v]=0;
		D[v]=G.arcs[v0][v];
		for(w=0;w<G.vexnum;w++)
			P[v][w]=0;
		if(D[v]<INFINITY)
		{
			P[v][v0]=1;
			P[v][v]=1;
		}
	}
	D[v0]=0;
	final[v0]=1;
	for(i=1;i<G.vexnum;i++)
	{
		min=INFINITY;
		for(w=0;w<G.vexnum;w++)
			if(!final[w])
				if(D[w]<min)
				{
					v=w;
					min=D[w];
				}
				final[v]=1;
		for(w=0;w<G.vexnum;w++)
			if(!final[w]&&(min+G.arcs[v][w]<D[w]))
			{
				D[w]=min+G.arcs[v][w];
				for(int j=0;j<G.vexnum;j++)
                     P[w][j]=P[v][j];
				P[w][w]=1;
			}
	}
	//for(int n=0;n<G.vexnum;n++)
	//	cout<<D[n]<<endl;
}


void LongestShortestPath(int LSP[],Graph &G)
{
	PathMatrix P;
	ShortPathTable D;
	for(int i=0;i<G.vexnum;i++)
	{
		ShortestPath(G,i,P,D);
		//cout<<D[i];
		int max=D[0];
		for(int j=0;j<G.vexnum;j++)
			if(max<D[j])
				max=D[j];
		LSP[i]=max;
	}
}

void main()
{
	int i;
	Graph G;
	CreatGraph(G);
	int LSP[MAX];
	LongestShortestPath(LSP,G);
	for(i=0;i<G.vexnum;i++)
		cout<<G.vexs[i]<<"��ׯ��������ׯ���·�������ֵ��:"<<LSP[i]<<endl;
	int m=0;
	for(i=0;i<G.vexnum;i++)
		if(LSP[m]>LSP[i])
			m=i;
	cout<<"����Ӧ��ѡ��"<<G.vexs[m]<<"��ׯ��ΪҽԺ�Ľ���ص�"<<endl;
}
