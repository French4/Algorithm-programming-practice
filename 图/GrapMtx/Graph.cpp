#include"GraphMtx.h"

void initGraph(GraphMtx *g)
{
	int i = 0;
	g->MaxVertices = 10; //最大的顶点个数
	g->NumVertices = g->NumEdges = 0;//当前的顶点个数


	g->VerticesList = (T*)malloc(sizeof(T)*(g->MaxVertices));//每个顶点存放的最大的字符个数
	g->Edge = (int **)malloc(sizeof(int*)*g->MaxVertices);//指向二维数组
	assert(g->Edge != NULL);

	for(i = 0; i < g->MaxVertices; i++){
		g->Edge[i] = (int *)malloc(sizeof(int) * g->MaxVertices);//开辟每一行的列
	}

	for(i = 0; i < g->MaxVertices; i++){
		for(int j = 0; j < g->MaxVertices; j++){
			g->Edge[i][j] = 0;
		}
	}
}
/*
	打印二维数组的状态
*/
void showGraph(GraphMtx *g)
{
	int i = 0;
	int j = 0;
	printf(" ");
	for(i = 0; i < g->NumVertices; i++)
		printf("%c ", g->VerticesList[i]);
	printf("\n");
	for(i = 0; i < g->NumVertices; i++){
		printf("%c ", g->VerticesList[i]);
		for(j = 0; j < g->NumVertices; j++){
			printf("%d ", g->Edge[i][j]);
		}
	  printf("\n");
	}
	printf("\n");
}
void insert(GraphMtx *g, T v)
{
	if(g->NumEdges >= g->MaxVertices)
		return;  //顶点空间已经满了
	g->VerticesList[g->NumVertices++] = v; 
}
int GetVertexPos(GraphMtx *g, T v)
{
	for(int i = 0; i < g->NumVertices; i++){
		if(g->VerticesList[i] == v)
			return i;
	}

	return -1;
}
void insertEdge(GraphMtx *g, T v1, T v2)
{
	int p1 = GetVertexPos(g, v1);
	int p2 = GetVertexPos(g, v2);

	if(p1 == -1 || p2 == -1) //字符在图中不存在
		return;

	if(g->Edge[p1][p2] != 0)  //已经存在边
		return;
	g->Edge[p1][p2] = g->Edge[p2][p1] = 1;
}
void RemoveEdge(GraphMtx *g, T v1, T v2)//删除一个边
{
	int p1 = GetVertexPos(g, v1);
	int p2 = GetVertexPos(g, v2);

	if(p1 == -1 || p2 == -1) //字符在图中不存在
		return;

	if(g->Edge[p1][p2] == 0)  
		return;
	g->Edge[p1][p2] = g->Edge[p2][p1] = 0;
	g->NumEdges--;//将边数减少
}
void RemoveVertex(GraphMtx *g, T v)
{
	int p = GetVertexPos(g, v);
	int numedges = 0;
	if(p == -1)
		return;
	for(int i = p; i < g->NumVertices-1; ++i)
	{
		g->VerticesList[i] = g->VerticesList[i+1];
	}

	for(i=0; i<g->NumVertices; i++){
		if(g->Edge[p][i] != 0)  //p是删除的顶点所在的一行
			numedges++; //删除的边数
	}

	for(i = p; i < g->NumVertices-1; i++){//下一列覆盖上一列
		for(int j = 0; j < g->NumVertices; j++){
			g->Edge[i][j] = g->Edge[i+1][j];
		}
	}

	for(i = p; i < g->NumVertices; i++){ //下一行覆盖上一行
		for(int j = 0; j < g->NumVertices; j++){
			g->Edge[j][i] = g->Edge[j][i+1];
		}
	}
	g->NumVertices--;
	g->NumEdges -= numedges;
}
void DestroyGraph(GraphMtx *g)
{
	free(g->VerticesList); //释放顶点
	g->VerticesList = NULL;
	for(int i = 0; i <g->NumVertices; i++){
		free(g->Edge[i]);//释放每一行
	}
	free(g->Edge);
	g->Edge = NULL;
	g->MaxVertices = g->NumEdges = g->NumVertices = 0;
}

int GetFirstNeighbor(GraphMtx *g, T v)
{
	int p = GetVertexPos(g, v);

	if(p == -1)
		return -1;
	for(int i = 0; i < g->NumEdges; i++){ //在二维数组的一行中查找第一个等于1的下标
		if(g->Edge[p][i] == 1)
			return i;
	}
	return -1;
}