#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//����һ
int count_binary1(int n)
{
 int count=0;
	while (n)
	{
		if (n % 2 == 1)//n%2�ж϶����Ƶ����һλ�Ƿ�Ϊ1
		{
			count++;
		}
		n /= 2;//n/2��,�൱������һλ
	}
	return count;
}//���㷨ֻ����������������%2��2��Ϊ0���޷�����


//������
int count_binary1(int n)
{
	int count = 0;
	int i;
	for (i = 0; i < 32; i++)
	{
		if (((n >> i)&1) == 1)//����n=5 ��ô5�Ķ���������Ϊ0000 0000 0000 0000 0000 0000 0000 0101
			//&1��������һλ��1����0                   //0000 0000 0000 0000 0000 0000 0000 0001
			//����������㵹���ڶ�λ����Ҫn>>1,ѭ��32�Σ��ж�����binary system�ϵ�1�ĸ���
			count++;
	}
	return count;
}//û�н����������㣬ֻ�ǲ���λ���Ը���Ҳ���Լ���



////������
int count_binary1(int n)
{
	int count = 0;
	while (n)
	{
		n = n&(n-1);//����2n=5 ��ô5��2��������Ϊ0000 0000 0000 0000 0000 0000 0000 0101
		                          //��n-1Ϊ    //0000 0000 0000 0000 0000 0000 0000 0100
		//nÿ��&n-1����ȥ��nbinarys_system���ұߵ�һ��1,��û1����0 ����ִ��n&(n-1)�Ĵ������1�ĸ���
		count++;
	}
	return count;
}//Ҳ��λ�Ĳ����������ڸ���
int main()
{
	int n = 0, count = 0;
	printf("������һ��ʮ������;");
	scanf("%d", &n);
	count = count_binary1(n);
	printf("��������1�ĸ���Ϊ%d", count);
	return 0;
}


//��չ�� ��m n������������λ��ͬ��λ���ж���
int count_diffbinary(int m, int n)
{
	n = m ^ n;//m^n����Ķ�����Ϊ1�����m n��λ�ö�����λ��ͬ�������1�ĸ������������m��n������λ��ͬ��λ��
	m = count_binary1(n);
	return m;
}
int main()
{
	int m = 0, n = 0, count = 0;
	printf("������������:");
	scanf("%d%d", &m, &n);
	count = count_diffbinary(m, n);
	printf("��ͬ��λ����%dλ", count);
	return 0;
}