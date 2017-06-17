//a,b个存放n位2进制,他们相加存与c中
#include<stdio.h>
void add(int *a, int *b, int *c)
{
	int i = 0;
	int key = 0;
	int flag = 0;

	for(i = 0; i < 2; i++){
		key = c[i]+a[i]+flag;
		if(key > 1){
		
			flag = 1;
		}
		
		if(flag == 1){
			c[2+1] =  1;
		}
	}
}
int main()
{
	int i;
	int a[2] = {1,1};
	int b[2] = {1,1};
	int c[3] = {0};
	add(a,b,c);
	for(i = 0; i < 3; i++)
		printf("%d", c[i]);
}