#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define Default_Verticces_Size 10
#define T char //Ԫ������

typedef struct GraphMtx
{
	int MaxVertices; //���Ķ�����
	int NumVertices;//��ǰ������
	int NumEdges;//����

	T *VerticesList;//�洢����Ľṹ�����������ͼ�ַ���
	int **Edge;//ָ�������Ķ�ά���飬��ŵ��Ƕ���Ͷ���֮���״̬
}GraphMtx;

void initGraph(GraphMtx *g);//��ʼ��ͼ
void showGraph(GraphMtx *g); //��ʾͼ
void insert(GraphMtx *g, T v); //����һ������
void insertEdge(GraphMtx *g, T v1, T v2);//����һ����
void RemoveVertex(GraphMtx *g, T v);//ɾ������
void RemoveEdge(GraphMtx *g, T v1, T v2);//ɾ��һ����
int GetFirstNeighbor(GraphMtx *g, T v);//��ȡ��Χ����
int GetVertexPos(GraphMtx *g, T v);//��ȡ�����λ��
void DestroyGraph(GraphMtx *g);//�ͷ�ͼ