#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n = 0, i = 0,t=0;
	printf("����Ϊ100������������;");
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
}//������ָֻ�ܱ�1�ͱ�������1�Ȳ�������Ҳ���Ǻ���