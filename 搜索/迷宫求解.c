/*
	迷宫由n行m列的单元格组成，每个单元格要么是空地，要么是障碍物
	找一条最短路径。
	分析：用一个二维数组存储这个迷宫。刚开始的时候，在(1,1),
	目标在(p,q),找(1,1)到(p,q)的最短路径。刚开始在(1,1)只能向
	下或者向右走。先往右走，知道走不同的时候回到这里，再去尝试
	另外一个方向。按照顺时针方式尝试。
*/
#include<stdio.h>
int m,n,p,q, min=99999999;
int a[51][51], book[51][51];
void dfs(int x, int y, int step)
{
	int next[4][2] = {
		{0,1},//向右走
		{1,0},//向下走
		{0,-1},//向走左
		{-1,0}//向上走
		};	
	int tx, ty, k;
	//判断是否到达最小的位置
	if(x==p && y==q){
		//更新最小值
		if(step< min)
			min = step;
		return;
	}

	//枚举四种走法
	for(k=0; k<=3; k++){
		//计算下一个点坐标
		tx = x + next[k][0];
		ty = y + next[k][1];

		//判断是否越界
		if(tx<1 || tx>n || ty<1 || ty>m)
			continue;
		//判断该点是否为障碍物或者已经走过
		if(a[tx][ty]==0 && book[tx][ty]==0)
		{
			book[tx][ty] = 1;//标记这个点已经走过
			dfs(tx, ty, step+1);
			book[tx][ty] = 0;
		}
	}
}
int main()
{
	int i, j, startx, starty;

	//读入n和m, n为行， m为列
	scanf("%d %d", &n, &m);

	for(i=1;i<=n; i++)
		for(j=1; j<=m; j++)
			scanf("%d", &a[i][j]);

	scanf("%d %d %d %d", &startx, &starty, &p, &q);

	book[startx][starty] = 1;

	dfs(startx, starty, 0);

	printf("%d", min);

	return 0;
}