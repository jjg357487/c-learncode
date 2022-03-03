#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n = 0, i = 0,t=0;
	printf("下限为100请输入上限数;");
	scanf("%d", &n);
	for (t = 100; t <= n; t++)
	{
		for (i = 2; i < t; i++)
		{
			if (t % i == 0)
				break;
		}
		if (i == t)
			printf("%d ", t);
	}
}//素数是指只能被1和本身整除1既不是素数也不是合数