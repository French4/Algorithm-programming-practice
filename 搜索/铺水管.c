/*
	深度优先搜索解决铺水管问题
*/
#include<stdio.h>
int a[51][51];//假设土地的大小不超过50*50
int book[51][51];
int n, m,flag=0;
struct note
{
	int x;//横坐标
	int y;//纵坐标
}s[100];
int top;
void dfs(int x, int y, int front)
{
	int i;
	//判断是否到达了中点
	if(x==n && y==m+1){
		flag=1;//找到铺设方案
		return;
	}

	//判断是否越界
	if(x<1 || x>n || y<1 || y>m)
		return;
	//判断这个管道是否在路径中已经使用过了
	if(book[x][y]==1)
		return;
	book[x][y]=1;//标记使用当前得这个管道
	top++;
	s[top].x = x;
	s[top].y = y;

	//当前管道是直管的情况下
	if(a[x][y]>=5 && a[x][y]<=6)
	{
		if(front == 1)//进水口在左边的情况
		{
			dfs(x, y+1, 1);
		}
		if(front == 2)
		{
			dfs(x+1, y, 2);
		}
		if(front == 3)
		{
			dfs(x, y-1, 3);
		}
		if(front==4)
		{
			dfs(x-1,y,4);
		}
	}
		//当前水管是弯管的情况下
		if(a[x][y]>=1 && a[x][y]<=4)
		{
			if(front==1)//进水口在左边的情况下
			{
				dfs(x+1, y, 2);//三号状态
				dfs(x-1, y, 4);//四号状态
			}

			if(front==2)
			{
				dfs(x, y+1,1);//1号状态
				dfs(x, y-1,3);//4号状态
			}

			if(front==3)
			{
				dfs(x-1,y,4);//1号状态
				dfs(x+1,y,2);//2号状态
			}
			if(front==4)
			{
				dfs(x, y+1,1);//2号状态
				dfs(x, y-1,3);//3号状态
			}
		}
		book[x][y]=0;//取消标记
		top--;//出栈
		return;
}
int main()
{
		int i, j, num = 0;
		scanf("%d %d", &n, &m);

		//读入地图游戏
		for(i=1; i<=n; i++)
			for(j=1; j<=m;j++)
				scanf("%d", &a[i][j]);
		dfs(1,1,1);

		//判断是否找到了铺设方案
		if(flag == 0)
			printf("No");
		else{
			printf("ok");
		}
}