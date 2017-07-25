/*
	有n个火柴棍，希望摆出A+B=C的等式，ABC均为拼出来的等式
	注意:加号和等号各自需要两根火柴棍
		 假如有m根火柴，可以拼出多少个不同的等式。
*/
#include<stdio.h>
int fun(int x)
{
	int num = 0;//用来计数的变量
	int f[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};//记录对应下标
	//需要多少根火柴
	while(x/10 != 0)//说明这个数字最少有两位数
	{
		//获得x末尾的数字并且将其所需要的加入num中
		num += f[x%10];
		x = x/10;//去掉x的末尾数字
	}
	//最后加上x所需要的火柴棍数字
	num += f[x];
	return num;//返回num需要的火柴棍总数
}
int main()
{
	int a,b,c, m, i, sum = 0; //sum用来计数
	scanf("%d", &m);//读入火柴棍的个数

	//开始枚举a和b
	for(a = 0; a < 1111; a++){
		for(b = 0; b < 1111; b++){
			c = a + b;//计算出c

			if(fun(a) + fun(b) + fun(c) == m-4){
				printf("%d+%d=%d\n", a,b,c);
				sum++;
			}
		}
	}
	printf("一共可以拼出%d个不同的等式", sum);
}