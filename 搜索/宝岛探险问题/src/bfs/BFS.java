package bfs;

import java.util.Scanner;
/*
 * 0表示海洋，1-9表示陆地
 * 求一点其陆地的大小
 * */
class note
{
	int x;//横坐标
	int y;//总坐标
};
public class BFS {
	public static void main(String[] args) {
		note[] que = new note[2501];
		int head, tail;
		int[][] a = new int[51][51];
		int[][] book = new int[51][51];
		int i,j,k,sum,max=0,mx,my,n,m,startx, starty,tx,ty;
		
		//定义一个方向数组
		int[][] next = {
				{0,1},//向右走
				{1,0},//向下走
				{0,-1},//向左走
				{-1, 0}//向下走
					
		};
		//读入n行m列以及小哼降落的坐标
		Scanner sc  =new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		startx = sc.nextInt();
		starty = sc.nextInt();
		
		//读入地图
		for(i=1; i<=n;i++)
			for(j=1; j<=m;j++)
				a[i][j] = sc.nextInt();
		//队列初始化
		head = 1;
		tail = 1;
		//向队列中插入起始坐标
		System.out.println(que[tail].x+":"+startx );
		que[tail].x = startx;
		que[tail].y = starty;
		tail++;
		
		book[startx][starty]=1;
		sum=1;
		
		//当队列不为空的时候循环
		while(head<tail)
		{
			//计算下一步的坐标
			for(k=0;k<=3;k++)
			{
				tx = que[head].x+next[k][0];
				ty = que[head].y+next[k][1];
					
				//判断是否越界
				if(tx<1 || tx>n || ty<1 || ty>m)
					continue;
				
				//判断是否陆地或者曾经是否走过
				if(a[tx][ty]>0 && book[tx][ty] == 0)
				{
					sum++;
					//每个点入队列一次
					book[tx][ty]=1;
					//将新扩展的点加入队列
					que[tail].x = tx;
					que[tail].y = ty;
					tail++;
				}
			}
			head++;
		}
		//输出岛屿的大小
		System.out.println(sum);
	}
}
