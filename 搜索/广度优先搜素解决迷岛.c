/*
	0��ʾ����1-9��ʾ½�أ���ĳһ���½�����
*/
#include<stdio.h>
typedef struct node
{
	int x;//������
	int y;//������
}node;

int main(void)
{
	note que[2501];
	int head, tail;
	int a[51][51];
	int book[51][51] = {0};
	int i,j,k,sum,mx,my,n,m,startx,starty,tx,ty;
	int max = 0;
	//����һ����������
	int next[4][2]={
		{0,1},
		{1,0},
		{0,-1},
		{-1, 0}
	
					};
	//����n��m��
	scanf("%d %d %d %d", &n, &m, &startx, &starty);

	//�����ͼ
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			scanf("%d", &a[i][j]);

	//���г�ʼ��
	head=1;
	tail=1;
	//�����в��뽵�����ʼ����
	que[tail].x=startx;
	que[tail].y=starty;
	tail++;
	book[startx][starty]=1;
	sum=1;

	//�����в�Ϊ�յ�ʱ��ѭ��
	while(head<tail)
	{
		//ö��4������
		for(k=0; k<=3;k++)
		{
			//������һ��������
			tx = que[head].tx+next[k][0];
			ty = que[head].ty+mext[k][1];

			//�ж��Ƿ�Խ���߽�
			if(tx<1 || tx>n || ty<1 || ty>m)
				continue;

			//�ж��Ƿ���½�ػ����Ƿ��߹�
			if(a[tx][ty]>0 && book[tx][ty]==0)
			{
				sum++;
				//ÿ����ֻ�����һ��
				book[tx][ty] = 1;
				//������չ�ĵ�������
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;

			}
		}
		head++;
	}
	printf("%d\n",sum);
	return 0;
}