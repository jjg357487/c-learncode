#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int check_sys(void)
{
	int a = 1;
	//0000 0000 0000 0000 0000 0000 0000 0001
	//0x00 00 00 00 01
	//��˴���Ϊ00 00 00 01
	//С�˴���Ϊ01 00 00 00
	return *(char*)&a;//���ص�һ���ֽڵ�ֵ
}
int main()
{
	int ret = check_sys();//����1��С�˷���0�Ǵ��
	if (ret == 1)
	{
		printf("С��");
	}
	else
	{
		printf("���");
	}
	return 0;
}