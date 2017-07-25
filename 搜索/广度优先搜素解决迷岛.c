/*
	0表示海洋，1-9表示陆地，求某一点的陆地面积
*/
#include<stdio.h>
typedef struct node
{
	int x;//横坐标
	int y;//纵坐标
}node;

int main(void)
{
	note que[2501];
	int head, tail;
	int a[51][51];
	int book[51][51] = {0};
	int i,j,k,sum,mx,my,n,m,startx,starty,tx,ty;
	int max = 0;
	//定义一个放向数组
	int next[4][2]={
		{0,1},
		{1,0},
		{0,-1},
		{-1, 0}
	
					};
	//读入n行m列
	scanf("%d %d %d %d", &n, &m, &startx, &starty);

	//读入地图
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			scanf("%d", &a[i][j]);

	//队列初始化
	head=1;
	tail=1;
	//往队列插入降落的起始坐标
	que[tail].x=startx;
	que[tail].y=starty;
	tail++;
	book[startx][starty]=1;
	sum=1;

	//当队列不为空的时候循环
	while(head<tail)
	{
		//枚举4个方向
		for(k=0; k<=3;k++)
		{
			//计算下一步的坐标
			tx = que[head].tx+next[k][0];
			ty = que[head].ty+mext[k][1];

			//判断是否越过边界
			if(tx<1 || tx>n || ty<1 || ty>m)
				continue;

			//判断是否是陆地或者是否走过
			if(a[tx][ty]>0 && book[tx][ty]==0)
			{
				sum++;
				//每个点只入队列一次
				book[tx][ty] = 1;
				//将新扩展的点加入队列
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