/*
	���б����1~9�ľ����˿��ƣ�����Ÿ��Ʒ��ھŸ�������ʹ��[][][]+
	[][][] = [][][]����
*/
#include<stdio.h>
int a[10], book[10], total = 0;
void dfs(int step)//step��ʾվ�ڵڼ���������ǰ
{
	int i;
	if(step == 10)//���վ���˵�10��������ǰ
	{
		//�ж��Ƿ������ʽ
		if(a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6]
			== a[7]*100+a[8]*10+a[9]
			){
			total++;
			printf("%d%d%d+%d%d%d=%d%d%d\n",a[1],a[2],a[3]
				,a[4],a[5],a[6],a[7],a[8],a[9]);
		}
		return;
	}

	//վ�ڵ�step������ǰ
	//����1,2,3,...n��˳��һһ����
	for(i=1; i<=9; i++)
	{
		if(book[i] == 0)
		{
			//��ʼ����ʹ���˿���i
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