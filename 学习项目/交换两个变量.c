#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//����һ
void exchange(int* m, int* n)
{
	int ret = 0;
	ret = *m;
	*m = *n;
	*n = ret;
}


//������
void exchange(int* m, int* n)
{
	*m = *m + *n;
	*n = *m - *n;
	*m = *m - *n;
}


//������
void exchange(int* m, int* n)
{
	*m = *m ^ *n;
	*n = *m ^ *n;
	*m = *m ^ *n;
}
int main()
{
	int m = 0, n = 0;
	printf("������m��n��ֵ:");
	scanf("%d%d", &m, &n);
	exchange(&m, &n);
	printf("�������Ľ��λ%d %d", m, n);
}