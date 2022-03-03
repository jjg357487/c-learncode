#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//方法一
int count_binary1(int n)
{
 int count=0;
	while (n)
	{
		if (n % 2 == 1)//n%2判断二进制的最后一位是否为1
		{
			count++;
		}
		n /= 2;//n/2后,相当于右移一位
	}
	return count;
}//该算法只适用于正数，负数%2、2后为0，无法运算


//方法二
int count_binary1(int n)
{
	int count = 0;
	int i;
	for (i = 0; i < 32; i++)
	{
		if (((n >> i)&1) == 1)//假设n=5 那么5的二进制序列为0000 0000 0000 0000 0000 0000 0000 0101
			//&1可算出最后一位是1还是0                   //0000 0000 0000 0000 0000 0000 0000 0001
			//计算完后再算倒数第二位，需要n>>1,循环32次，判断所有binary system上的1的个数
			count++;
	}
	return count;
}//没有进行有理运算，只是操作位所以负数也可以计算



////方法三
int count_binary1(int n)
{
	int count = 0;
	while (n)
	{
		n = n&(n-1);//假设2n=5 那么5的2进制序列为0000 0000 0000 0000 0000 0000 0000 0101
		                          //则n-1为    //0000 0000 0000 0000 0000 0000 0000 0100
		//n每次&n-1都会去掉nbinarys_system最右边的一个1,当没1后变成0 根据执行n&(n-1)的次数求出1的个数
		count++;
	}
	return count;
}//也是位的操作，可用于负数
int main()
{
	int n = 0, count = 0;
	printf("请输入一个十进制数;");
	scanf("%d", &n);
	count = count_binary1(n);
	printf("二进制种1的个数为%d", count);
	return 0;
}


//拓展题 求m n两个数二进制位不同的位数有多少
int count_diffbinary(int m, int n)
{
	n = m ^ n;//m^n算出的二进制为1则代表m n此位置二进制位不同，再求出1的个数，即可求出m和n二进制位不同的位数
	m = count_binary1(n);
	return m;
}
int main()
{
	int m = 0, n = 0, count = 0;
	printf("请输入两个数:");
	scanf("%d%d", &m, &n);
	count = count_diffbinary(m, n);
	printf("不同的位数共%d位", count);
	return 0;
}