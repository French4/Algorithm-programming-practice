/*
	深度优先搜索解决迷宫问题
*/
#include<stdio.h>
struct note
{
	int x;//横坐标
	int y;//纵坐标
	int f;//父亲在队列中的标号
	int s;//步数
};
int main()
{
	struct note que[2501];

	int a[51][51] = {0};
	int book[51][51] = {0};
	//定义一个表示走方向的数组
	int next[4][2] = {{0,1},//向右走
					{1,0},//向下走
	{0, -1},//向左走
	{-1, 0}};//向上走

	int head, tail;
	int i,j,k,n,m,startx, starty,p,q,tx,ty,flag;

	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++)
		for(j=1; j<=m;j++)
			scanf("%d", &a[i][j]);
	scanf("%d %d %d %d", &startx, &starty, &p, &q);

	//队列的初始化
	head = 1;
	tail = 1;
	//往队列插入迷宫入口坐标
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].f = 0;
	que[tail].s = 0;
	tail++;
	book[startx][starty]=1;

	flag=0;//用来标记是否到达目标点,0表示暂时没有到达,1表示到达
	//当队列不为空的时候循环
	while(head<tail)
	{
		//枚举四个方向
		for(k=0; k<=3; k++)
		{
			//计算下一点的坐标
			tx = que[head].x+next[k][0];
			ty = que[head].y+next[k][1];
			//判断是否越界
			for(tx<1 || tx>n || ty<1 || ty>m)
				continue;
			//判断是否障碍物或者已经在路径中
			if(a[tx][ty]==0 && book[tx][ty]==0)
			{
				//将这个点标记为已经走过
				book[tx][ty]=1;
				//插入新的点到队列中
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].f=head;
				que[tail].s = que[head].s+1;//步数是父亲的步数加1
				tail++;
			}
			//如果到目标点了，停止扩展，任务结束，退出循环
			if(tx==p && ty==q)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			break;
		head++;//当一个点扩展完之后，才能对下一个点进行扩展
	}
	//打印末尾最后一个点
	printf("%d",que[tail-1].s);
	return 0;
}
