#include"function.h"
void ListInit(SL* List)//初始化
{
	List->date = NULL;
	List->size = 0;
	List->capacity = 0;
}
void ListInsert(SL* List, int i, Elemtype x)//插入
{
	int j = 0;
	Addcapacity(List);
	assert(i-1 <= List->size);
	assert(List->size >= 0);
	for (j = List->size; j >= i; j--)
	{
		List->date[j] = List->date[j - 1];
	}
	List->date[i-1] = x;
	List->size++;
}
void Addcapacity(SL* List)//扩容
{
	if (List->size >= List->capacity)
	{
		int newcapacity =  2 * List->capacity;//容量扩大2倍
		if (newcapacity == 0)//要是第一次增加4个容量
			newcapacity = 4;
		Elemtype* tmp = realloc(List->date, newcapacity * sizeof(Elemtype));//realloc函数申请地址
		if (tmp == NULL)
		{
			printf("没地方了,扩容失败\n");
			return;
		}
		else
		{
			List->date = tmp;
			List->capacity = newcapacity;
		}
	}
}
void ListHomeInsert(SL* List,Elemtype x)//头插法
{

	ListInsert(List, 1, x);
}
void ListPrint(SL* List)
{
	for (int i = 0; i < List->size; i++)
	{
		printf("%d ", List->date[i]);
	}
	printf("\n");
}
void ListEndInsert(SL* List, Elemtype x)//尾插法
{
	ListInsert(List, List->size+1, x);
}
void ListDelete(SL* List, int i)//删除
{
	assert(List->size>0);
	assert(i > 0 && i <= List->size);
	for (int j = i; j<List->size; j++)
	{
		List->date[j - 1] = List->date[j];
	}
	List->size--;
}
void ListHomeDelete(SL* List)//头删除
{
	ListDelete(List, 1);
}
void ListEndDelete(SL* List)//尾删除
{
	ListDelete(List, List->size);
}
Elemtype ListSearch_byi(SL* List, int i)//按位查找
{
	assert(i > 0 && i <= List->size);
	assert(List->size > 0);
	return List->date[i - 1];
}
int ListSearch_byx(SL* List, Elemtype x)//按值查找
{
	assert(List->size > 0);
	for (int i = 0; i < List->size; i++)
	{
		if (List->date[i] == x)
			return i+1;
	}
	return -1;
}
void ListModify(SL* List, int i, Elemtype x)//修改第i个数为x
{
	assert(i > 0 && i <= List->size);
	assert(List->size > 0);
	List->date[i - 1] = x;
}
void ListDestroy(SL* List)//销毁
{
	assert(List);
	free(List->date);
	List->date = NULL;
	List->capacity = List->size = 0;
}