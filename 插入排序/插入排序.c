#include<stdio.h>
void selSort(int *a, int len)
{
	int i, j;
	int min, k;
	for(i = 0; i < len-1; i++){
		min = i;
	//	min = a[i];���������±�,��Ϊ�������еĽ���
		for(j = i+1; j < len; j++){
			if(a[min] > a[j]){
				min = j;//��¼��Сֵ���±�
			}
		}
		if(a[min] != a[i]){//�͵�i������
			k = a[min];
			a[min] = a[i];
			a[i] = k;
		}
	}
}
void InsertSort(int *a, int n)
{
	int i = 0;
	int j = 0;
	int key;
	for(j = 1; j < n; j++){
		key = a[j];
		i = j-1;
		while(i>= 0 && key < a[i]){
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = key;
	}
}
int main()
{
	int a[10] = {0};
	int i = 0;
	for(i = 0; i < 3; i++){
		scanf("%d", &a[i]);
	}
	for(i = 0; i < 3; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	//sort(a, 10);
	selSort(a, 3);
	for(i = 0; i < 3; i++){
		printf("%d ", a[i]);
	}
}