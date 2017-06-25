#include"GraphMtx.h"

void initGraph(GraphMtx *g)
{
	int i = 0;
	g->MaxVertices = 10; //���Ķ������
	g->NumVertices = g->NumEdges = 0;//��ǰ�Ķ������


	g->VerticesList = (T*)malloc(sizeof(T)*(g->MaxVertices));//ÿ�������ŵ������ַ�����
	g->Edge = (int **)malloc(sizeof(int*)*g->MaxVertices);//ָ���ά����
	assert(g->Edge != NULL);

	for(i = 0; i < g->MaxVertices; i++){
		g->Edge[i] = (int *)malloc(sizeof(int) * g->MaxVertices);//����ÿһ�е���
	}

	for(i = 0; i < g->MaxVertices; i++){
		for(int j = 0; j < g->MaxVertices; j++){
			g->Edge[i][j] = 0;
		}
	}
}
/*
	��ӡ��ά�����״̬
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
		return;  //����ռ��Ѿ�����
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

	if(p1 == -1 || p2 == -1) //�ַ���ͼ�в�����
		return;

	if(g->Edge[p1][p2] != 0)  //�Ѿ����ڱ�
		return;
	g->Edge[p1][p2] = g->Edge[p2][p1] = 1;
}
void RemoveEdge(GraphMtx *g, T v1, T v2)//ɾ��һ����
{
	int p1 = GetVertexPos(g, v1);
	int p2 = GetVertexPos(g, v2);

	if(p1 == -1 || p2 == -1) //�ַ���ͼ�в�����
		return;

	if(g->Edge[p1][p2] == 0)  
		return;
	g->Edge[p1][p2] = g->Edge[p2][p1] = 0;
	g->NumEdges--;//����������
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
		if(g->Edge[p][i] != 0)  //p��ɾ���Ķ������ڵ�һ��
			numedges++; //ɾ���ı���
	}

	for(i = p; i < g->NumVertices-1; i++){//��һ�и�����һ��
		for(int j = 0; j < g->NumVertices; j++){
			g->Edge[i][j] = g->Edge[i+1][j];
		}
	}

	for(i = p; i < g->NumVertices; i++){ //��һ�и�����һ��
		for(int j = 0; j < g->NumVertices; j++){
			g->Edge[j][i] = g->Edge[j][i+1];
		}
	}
	g->NumVertices--;
	g->NumEdges -= numedges;
}
void DestroyGraph(GraphMtx *g)
{
	free(g->VerticesList); //�ͷŶ���
	g->VerticesList = NULL;
	for(int i = 0; i <g->NumVertices; i++){
		free(g->Edge[i]);//�ͷ�ÿһ��
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
	for(int i = 0; i < g->NumEdges; i++){ //�ڶ�ά�����һ���в��ҵ�һ������1���±�
		if(g->Edge[p][i] == 1)
			return i;
	}
	return -1;
}