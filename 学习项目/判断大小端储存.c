#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int check_sys(void)
{
	int a = 1;
	//0000 0000 0000 0000 0000 0000 0000 0001
	//0x00 00 00 00 01
	//大端储存为00 00 00 01
	//小端储存为01 00 00 00
	return *(char*)&a;//返回第一个字节的值
}
int main()
{
	int ret = check_sys();//返回1是小端返回0是大端
	if (ret == 1)
	{
		printf("小端");
	}
	else
	{
		printf("大端");
	}
	return 0;
}