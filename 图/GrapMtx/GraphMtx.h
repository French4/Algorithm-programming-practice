#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define Default_Verticces_Size 10
#define T char //元素类型

typedef struct GraphMtx
{
	int MaxVertices; //最大的顶点数
	int NumVertices;//当前顶点数
	int NumEdges;//边数

	T *VerticesList;//存储顶点的结构，是真正存放图字符串
	int **Edge;//指向真正的二维数组，存放的是顶点和顶点之间的状态
}GraphMtx;

void initGraph(GraphMtx *g);//初始化图
void showGraph(GraphMtx *g); //显示图
void insert(GraphMtx *g, T v); //插入一个顶点
void insertEdge(GraphMtx *g, T v1, T v2);//插入一个边
void RemoveVertex(GraphMtx *g, T v);//删除顶点
void RemoveEdge(GraphMtx *g, T v1, T v2);//删除一个边
int GetFirstNeighbor(GraphMtx *g, T v);//获取周围顶点
int GetVertexPos(GraphMtx *g, T v);//获取顶点的位置
void DestroyGraph(GraphMtx *g);//释放图