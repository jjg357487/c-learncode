#include<stdio.h>
int main()
{
	long long a = 4, b = 6;
	long long total = a * b;
	while (b)
	{
		long long q = a % b;
		a = b;
		b = q;
	}
	printf("�������Ϊ%d;��С������Ϊ%d", a, total / a);
	return 0;
}