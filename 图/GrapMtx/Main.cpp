#include"GraphMtx.h"

void main()
{
	GraphMtx gm;//创建图
	initGraph(&gm); //gm是指向图的控住头
	insert(&gm, 'A');
	insert(&gm, 'B');
	insert(&gm, 'C');
	insert(&gm, 'D');
	insert(&gm, 'E');

	insertEdge(&gm,'A', 'B');//插入边
	insertEdge(&gm,'A', 'D');
	insertEdge(&gm,'B', 'C');
	insertEdge(&gm,'B', 'E');
	insertEdge(&gm,'C', 'E');
	insertEdge(&gm,'C', 'D');

	RemoveEdge(&gm,'B', 'C');//删除顶点
	showGraph(&gm);

	RemoveVertex(&gm , 'B'); //删除边
	showGraph(&gm);

	int p = GetFirstNeighbor(&gm, 'D');
	DestroyGraph(&gm);
}