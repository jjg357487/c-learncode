#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void menu()
{
	printf("******************************\n");
	printf("********1.add   2,sub*********\n");
	printf("********3.mul   4.div*********\n");
	printf("*************0.exit***********\n");
	printf("******************************\n");
}
int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	return x / y;
}
int main()
{
	int input = 0, x, y;
	int (*p[4])(int, int) = { add,sub,mul,div };
	do {
		menu();
		printf("��ѡ��;<");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("�����������;<");
			scanf("%d%d", &x, &y);
			printf("�����%d\n", p[input - 1](x, y));
		}
		else if (input == 0)
			printf("�ټ���");
		else
			printf("������������\n");
	} while (input);
	return 0;
}