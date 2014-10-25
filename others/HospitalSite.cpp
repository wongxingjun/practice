/********************************************************************
	created:	2011-11-20
	created:	20:02
	filename: 	G:\DataSructure\实验代码\医院选址\Graph.cpp
	file path:	G:\DataSructure\实验代码\医院选址
	file base:	Graph
	file ext:	cpp
	author:		wangxingjun
	
	purpose:	迪杰思特拉算法之医院选址问题代码
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
{//确定v节点在图G中的位置以便初始化图
	for(int i=0;i<G.vexnum;i++)
		if(G.vexs[i]==v)
			return i;
	return -1;
}

void CreatGraph(Graph &G)
{//初始化图G，采用邻接矩阵的存储方式
	int i,j,k,w;
	char v1,v2;
	cout<<"请输入网络节点数和弧的条数:"<<endl;
	cin>>G.vexnum>>G.arcnum;
	cout<<"请依次输入各个节点的英文编号:"<<endl;
	for(i=0;i<G.vexnum;i++)
		cin>>G.vexs[i];
	for(i=0;i<G.vexnum;i++)//初始化矩阵
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j]=INFINITY;
	cout<<"请依次输入两个相邻节点和他们之间弧的权值:"<<endl;
	for(k=0;k<G.arcnum;k++)
	{
		cin>>v1>>v2>>w;
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		G.arcs[i][j]=G.arcs[j][i]=w;//无向图对称矩阵
	}
}


void ShortestPath(Graph &G,int v0,PathMatrix &P,ShortPathTable &D)
{//用迪杰思特拉算法求出图G中第v0个节点到其他节点的最短路径
 //存储在数组D中
	int v,w,i,min;
	int final[MAX];
	for(v=0;v<G.vexnum;v++)//初始化
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
		cout<<G.vexs[i]<<"村庄到其他村庄最短路径的最大值是:"<<LSP[i]<<endl;
	int m=0;
	for(i=0;i<G.vexnum;i++)
		if(LSP[m]>LSP[i])
			m=i;
	cout<<"所以应该选择"<<G.vexs[m]<<"村庄作为医院的建设地点"<<endl;
}
