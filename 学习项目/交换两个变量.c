#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//方法一
void exchange(int* m, int* n)
{
	int ret = 0;
	ret = *m;
	*m = *n;
	*n = ret;
}


//方法二
void exchange(int* m, int* n)
{
	*m = *m + *n;
	*n = *m - *n;
	*m = *m - *n;
}


//方法三
void exchange(int* m, int* n)
{
	*m = *m ^ *n;
	*n = *m ^ *n;
	*m = *m ^ *n;
}
int main()
{
	int m = 0, n = 0;
	printf("请输入m和n的值:");
	scanf("%d%d", &m, &n);
	exchange(&m, &n);
	printf("两个数的结果位%d %d", m, n);
}