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
		printf("请选择;<");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("请输入操作数;<");
			scanf("%d%d", &x, &y);
			printf("结果是%d\n", p[input - 1](x, y));
		}
		else if (input == 0)
			printf("再见啦");
		else
			printf("请重新输入呢\n");
	} while (input);
	return 0;
}