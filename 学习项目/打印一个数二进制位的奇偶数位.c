#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n = 0, i = 0;
	printf("������һ��ʮ������;");
	scanf("%d", &n);
	printf("ż��λ:\n");
	for (i = 31; i >= 1; i -= 2)
	{
		int ret = (n >> i) & 1;
		printf("%d ", ret);
	}
	printf("\n����λ:\n");
	for (i = 30; i >= 0; i -= 2)
	{
		int ret = (n >> i) & 1;
		printf("%d ", ret);
	}
	printf("\nȫ��λ:\n");
	for (i = 31; i >= 0; i--)
	{
		int ret = (n >> i) & 1;
		printf("%d ", ret);
	}

	return 0;
}