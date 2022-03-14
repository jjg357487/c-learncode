#include<stdio.h>
void exchange(char* base, char* base1 ,int whith)
{
	for (int i = 0; i < whith; i++)
	{
		char tmp = *base;
		*base  = *base1 ;
		*base1 = tmp;
		base++;
		base1++;
	}

}
void bubble_sort(void* base, int n, int whith, int (*cmp)(const void*, const void*))
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if ((*cmp)((char*)base + j * whith, (char*)base + (j+1) * whith) > 0)
				exchange((char*)base + j * whith, (char*)base + (1 + j) * whith, whith);
		}
	}
}
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
int main()
{
	int arr[] = { 9,8,6,7,5,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	for (int i = 0; i < sz; i++)
		printf("%d ", arr[i]);
}