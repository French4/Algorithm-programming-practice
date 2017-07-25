package dfs;

import java.awt.print.Book;
import java.util.Scanner;

public class dfs {
	static int[][] a = new int[51][51];
	static int[][] book = new int[51][51];
	static int n;
	static int m;
	static int sum;
	private static void dfs(int x, int y)
	{
		//定义一个方向数组
		int[][] next = {{0,1},
						{1,0},
						{0,-1},
						{-1, 0}};
		int k,tx,ty;
		
		//枚举4个方向
		for(k=0;k<=3;k++)
		{
			//计算下一步的坐标
			tx=x+next[k][0];
			ty=y+next[k][1];
			//判断是否越界
			if(tx<1 || tx>n || ty<1|| ty>m)
				continue;
			//判断是否是陆地
			if(a[tx][ty]>0 && book[tx][ty]==0)
			{
				sum++;
				book[tx][ty]=1;
				dfs(tx, ty);
			}
		}
		return;
	}
	public static void main(String[] args) {
		int i, j, startx, straty;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		startx = sc.nextInt();
		straty = sc.nextInt();
		//读入地图
		for(i=1; i<=n; i++)
			for(j=1; j<=n;j++)
				a[i][j] = sc.nextInt();
		book[startx][straty] = 1;
		sum=1;
		dfs(startx, straty);
		
		System.out.println(sum);
	}
}
