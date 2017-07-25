/*
	�Թ���n��m�еĵ�Ԫ����ɣ�ÿ����Ԫ��Ҫô�ǿյأ�Ҫô���ϰ���
	��һ�����·����
	��������һ����ά����洢����Թ����տ�ʼ��ʱ����(1,1),
	Ŀ����(p,q),��(1,1)��(p,q)�����·�����տ�ʼ��(1,1)ֻ����
	�»��������ߡ��������ߣ�֪���߲�ͬ��ʱ��ص������ȥ����
	����һ�����򡣰���˳ʱ�뷽ʽ���ԡ�
*/
#include<stdio.h>
int m,n,p,q, min=99999999;
int a[51][51], book[51][51];
void dfs(int x, int y, int step)
{
	int next[4][2] = {
		{0,1},//������
		{1,0},//������
		{0,-1},//������
		{-1,0}//������
		};	
	int tx, ty, k;
	//�ж��Ƿ񵽴���С��λ��
	if(x==p && y==q){
		//������Сֵ
		if(step< min)
			min = step;
		return;
	}

	//ö�������߷�
	for(k=0; k<=3; k++){
		//������һ��������
		tx = x + next[k][0];
		ty = y + next[k][1];

		//�ж��Ƿ�Խ��
		if(tx<1 || tx>n || ty<1 || ty>m)
			continue;
		//�жϸõ��Ƿ�Ϊ�ϰ�������Ѿ��߹�
		if(a[tx][ty]==0 && book[tx][ty]==0)
		{
			book[tx][ty] = 1;//���������Ѿ��߹�
			dfs(tx, ty, step+1);
			book[tx][ty] = 0;
		}
	}
}
int main()
{
	int i, j, startx, starty;

	//����n��m, nΪ�У� mΪ��
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