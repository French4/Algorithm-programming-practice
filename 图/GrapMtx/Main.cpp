#include"GraphMtx.h"

void main()
{
	GraphMtx gm;//����ͼ
	initGraph(&gm); //gm��ָ��ͼ�Ŀ�סͷ
	insert(&gm, 'A');
	insert(&gm, 'B');
	insert(&gm, 'C');
	insert(&gm, 'D');
	insert(&gm, 'E');

	insertEdge(&gm,'A', 'B');//�����
	insertEdge(&gm,'A', 'D');
	insertEdge(&gm,'B', 'C');
	insertEdge(&gm,'B', 'E');
	insertEdge(&gm,'C', 'E');
	insertEdge(&gm,'C', 'D');

	RemoveEdge(&gm,'B', 'C');//ɾ������
	showGraph(&gm);

	RemoveVertex(&gm , 'B'); //ɾ����
	showGraph(&gm);

	int p = GetFirstNeighbor(&gm, 'D');
	DestroyGraph(&gm);
}