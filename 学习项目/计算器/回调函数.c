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
void cala(int (*p)(int, int))
{
	int x, y;
	printf("�����������");
	scanf("%d%d", &x, &y);
	printf("���Ϊ%d\n", p(x, y));
}
int main()
{
	int input = 0, x, y;
	do {
		menu();
		printf("��ѡ��;<");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			cala(add);
			break;
		case 2:
			cala(sub);
			break;
		case 3:
			cala(mul);
			break;
		case 4:
			cala(div);
			break;
		case 0:
			printf("�˳���");
			break;
		default:
			printf("��������\n");
			break;
		}
	} while (input);

	return 0;
}