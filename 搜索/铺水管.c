/*
	����������������ˮ������
*/
#include<stdio.h>
int a[51][51];//�������صĴ�С������50*50
int book[51][51];
int n, m,flag=0;
struct note
{
	int x;//������
	int y;//������
}s[100];
int top;
void dfs(int x, int y, int front)
{
	int i;
	//�ж��Ƿ񵽴����е�
	if(x==n && y==m+1){
		flag=1;//�ҵ����跽��
		return;
	}

	//�ж��Ƿ�Խ��
	if(x<1 || x>n || y<1 || y>m)
		return;
	//�ж�����ܵ��Ƿ���·�����Ѿ�ʹ�ù���
	if(book[x][y]==1)
		return;
	book[x][y]=1;//���ʹ�õ�ǰ������ܵ�
	top++;
	s[top].x = x;
	s[top].y = y;

	//��ǰ�ܵ���ֱ�ܵ������
	if(a[x][y]>=5 && a[x][y]<=6)
	{
		if(front == 1)//��ˮ������ߵ����
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
		//��ǰˮ������ܵ������
		if(a[x][y]>=1 && a[x][y]<=4)
		{
			if(front==1)//��ˮ������ߵ������
			{
				dfs(x+1, y, 2);//����״̬
				dfs(x-1, y, 4);//�ĺ�״̬
			}

			if(front==2)
			{
				dfs(x, y+1,1);//1��״̬
				dfs(x, y-1,3);//4��״̬
			}

			if(front==3)
			{
				dfs(x-1,y,4);//1��״̬
				dfs(x+1,y,2);//2��״̬
			}
			if(front==4)
			{
				dfs(x, y+1,1);//2��״̬
				dfs(x, y-1,3);//3��״̬
			}
		}
		book[x][y]=0;//ȡ�����
		top--;//��ջ
		return;
}
int main()
{
		int i, j, num = 0;
		scanf("%d %d", &n, &m);

		//�����ͼ��Ϸ
		for(i=1; i<=n; i++)
			for(j=1; j<=m;j++)
				scanf("%d", &a[i][j]);
		dfs(1,1,1);

		//�ж��Ƿ��ҵ������跽��
		if(flag == 0)
			printf("No");
		else{
			printf("ok");
		}
}