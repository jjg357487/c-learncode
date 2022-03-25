#include"function.h"
void ListInit(SL* List)//��ʼ��
{
	List->date = NULL;
	List->size = 0;
	List->capacity = 0;
}
void ListInsert(SL* List, int i, Elemtype x)//����
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
void Addcapacity(SL* List)//����
{
	if (List->size >= List->capacity)
	{
		int newcapacity =  2 * List->capacity;//��������2��
		if (newcapacity == 0)//Ҫ�ǵ�һ������4������
			newcapacity = 4;
		Elemtype* tmp = realloc(List->date, newcapacity * sizeof(Elemtype));//realloc���������ַ
		if (tmp == NULL)
		{
			printf("û�ط���,����ʧ��\n");
			return;
		}
		else
		{
			List->date = tmp;
			List->capacity = newcapacity;
		}
	}
}
void ListHomeInsert(SL* List,Elemtype x)//ͷ�巨
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
void ListEndInsert(SL* List, Elemtype x)//β�巨
{
	ListInsert(List, List->size+1, x);
}
void ListDelete(SL* List, int i)//ɾ��
{
	assert(List->size>0);
	assert(i > 0 && i <= List->size);
	for (int j = i; j<List->size; j++)
	{
		List->date[j - 1] = List->date[j];
	}
	List->size--;
}
void ListHomeDelete(SL* List)//ͷɾ��
{
	ListDelete(List, 1);
}
void ListEndDelete(SL* List)//βɾ��
{
	ListDelete(List, List->size);
}
Elemtype ListSearch_byi(SL* List, int i)//��λ����
{
	assert(i > 0 && i <= List->size);
	assert(List->size > 0);
	return List->date[i - 1];
}
int ListSearch_byx(SL* List, Elemtype x)//��ֵ����
{
	assert(List->size > 0);
	for (int i = 0; i < List->size; i++)
	{
		if (List->date[i] == x)
			return i+1;
	}
	return -1;
}
void ListModify(SL* List, int i, Elemtype x)//�޸ĵ�i����Ϊx
{
	assert(i > 0 && i <= List->size);
	assert(List->size > 0);
	List->date[i - 1] = x;
}
void ListDestroy(SL* List)//����
{
	assert(List);
	free(List->date);
	List->date = NULL;
	List->capacity = List->size = 0;
}