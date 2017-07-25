/*
	手中编号有1~9的九张扑克牌，将这九个牌放在九个盒子中使得[][][]+
	[][][] = [][][]成立
*/
#include<stdio.h>
int a[10], book[10], total = 0;
void dfs(int step)//step表示站在第几个盒子面前
{
	int i;
	if(step == 10)//如果站在了第10个盒子面前
	{
		//判断是否满足等式
		if(a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6]
			== a[7]*100+a[8]*10+a[9]
			){
			total++;
			printf("%d%d%d+%d%d%d=%d%d%d\n",a[1],a[2],a[3]
				,a[4],a[5],a[6],a[7],a[8],a[9]);
		}
		return;
	}

	//站在第step盒子面前
	//按照1,2,3,...n的顺序一一尝试
	for(i=1; i<=9; i++)
	{
		if(book[i] == 0)
		{
			//开始尝试使用扑克牌i
			a[step] = i;
			book[i] = 1;

			dfs(step+1);

			book[i]=0;
		}
	}
}
int main()
{
	dfs(1);
	printf("total=%d", total/2);
	return 0;
}