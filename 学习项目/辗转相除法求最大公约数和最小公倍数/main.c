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
	printf("最大公因数为%d;最小公倍数为%d", a, total / a);
	return 0;
}